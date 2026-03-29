#include "Library.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace {
std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

bool containsInsensitive(const std::string& text, const std::string& keyword) {
    return toLower(text).find(toLower(keyword)) != std::string::npos;
}
}

Library::Library(std::shared_ptr<NotificationService> notifier)
    : notifier_(std::move(notifier)) {}

bool Library::addBook(std::unique_ptr<Book> book) {
    if (!book) return false;
    const std::string key = book->id();
    return books_.emplace(key, std::move(book)).second;
}

bool Library::addMember(std::unique_ptr<Member> member) {
    if (!member) return false;
    const std::string key = member->id();
    return members_.emplace(key, std::move(member)).second;
}

Book* Library::findBook(const std::string& bookId) {
    auto it = books_.find(bookId);
    return it == books_.end() ? nullptr : it->second.get();
}

Member* Library::findMember(const std::string& memberId) {
    auto it = members_.find(memberId);
    return it == members_.end() ? nullptr : it->second.get();
}

Loan* Library::findLoan(const std::string& loanId) {
    auto it = loans_.find(loanId);
    return it == loans_.end() ? nullptr : it->second.get();
}

std::vector<Book*> Library::searchBooks(const std::string& keyword) {
    std::vector<Book*> result;

    for (auto& [id, book] : books_) {
        if (containsInsensitive(book->title(), keyword) ||
            containsInsensitive(book->author(), keyword) ||
            containsInsensitive(book->genre(), keyword)) {
            result.push_back(book.get());
        }
    }

    std::sort(result.begin(), result.end(),
              [](Book* a, Book* b) { return a->title() < b->title(); });

    return result;
}

std::vector<Book*> Library::recommendBooks(const std::string& memberId) {
    Member* member = findMember(memberId);
    if (!member) return {};

    std::string favorite = member->favoriteGenre();
    std::vector<Book*> result;

    for (auto& [id, book] : books_) {
        if (!favorite.empty() && book->genre() == favorite) {
            result.push_back(book.get());
        }
    }

    std::sort(result.begin(), result.end(),
              [](Book* a, Book* b) { return a->availableCopies() > b->availableCopies(); });

    return result;
}

bool Library::borrowBook(const std::string& bookId, const std::string& memberId) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);

    if (!book || !member) return false;
    if (!member->canBorrow()) return false;
    if (!book->isAvailable()) return reserveBook(bookId, memberId);

    const std::string loanId = generateLoanId();
    Date today = Date::today();
    Date dueDate = today.addDays(14);

    if (!book->borrowOne()) {
        return false;
    }

    auto loan = std::make_unique<Loan>(loanId, bookId, memberId, today, dueDate);
    loans_.emplace(loanId, std::move(loan));
    member->addLoan(loanId);
    member->recordGenre(book->genre());

    std::ostringstream oss;
    oss << member->name() << " borrowed \"" << book->title()
        << "\" until " << dueDate.toString();
    log(oss.str());

    return true;
}

bool Library::returnBook(const std::string& loanId) {
    Loan* loan = findLoan(loanId);
    if (!loan || loan->isReturned()) return false;

    Book* book = findBook(loan->bookId());
    Member* member = findMember(loan->memberId());

    if (!book || !member) return false;

    Date today = Date::today();
    loan->markReturned(today);
    book->returnOne();
    member->removeLoan(loanId);

    int overdue = loan->overdueDays(today);
    if (overdue > 0) {
        double fine = overdue * 0.75;
        member->addFine(fine);

        std::ostringstream fineMsg;
        fineMsg << member->name() << " returned \"" << book->title()
                << "\" late by " << overdue << " day(s). Fine added: " << fine << " EUR";
        log(fineMsg.str());
    } else {
        std::ostringstream okMsg;
        okMsg << member->name() << ' ' << "returned \"" << book->title() << "\" on time";
        log(okMsg.str());
    }

    if (book->isAvailable() && book->hasReservations()) {
        std::string nextMemberId = book->popNextReservation();
        Member* nextMember = findMember(nextMemberId);
        if (nextMember && notifier_) {
            notifier_->notify(nextMember->name(),
                              "The book \"" + book->title() + "\" is now available for you.");
        }
    }

    return true;
}

bool Library::reserveBook(const std::string& bookId, const std::string& memberId) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);

    if (!book || !member) return false;

    bool added = book->addReservation(memberId);
    if (added) {
        log(member->name() + " reserved \"" + book->title() + "\"");
    }

    return added;
}

bool Library::renewLoan(const std::string& loanId, int extraDays) {
    Loan* loan = findLoan(loanId);
    if (!loan || loan->isReturned()) return false;

    Book* book = findBook(loan->bookId());
    if (!book) return false;

    if (book->hasReservations()) {
        return false;
    }

    auto renewed = std::make_unique<Loan>(
        loan->id(),
        loan->bookId(),
        loan->memberId(),
        loan->borrowedOn(),
        loan->dueOn().addDays(extraDays));

    if (loan->isReturned()) {
        renewed->markReturned(*loan->returnedOn());
    }

    loans_[loanId] = std::move(renewed);
    log("Loan " + loanId + " renewed by " + std::to_string(extraDays) + " days");
    return true;
}

double Library::memberFine(const std::string& memberId) const {
    auto it = members_.find(memberId);
    return it == members_.end() ? 0.0 : it->second->outstandingFine();
}

bool Library::payFine(const std::string& memberId, double amount) {
    auto it = members_.find(memberId);
    if (it == members_.end()) return false;

    it->second->payFine(amount);
    log(it->second->name() + " paid " + std::to_string(amount) + " EUR of fines");
    return true;
}

std::vector<Book*> Library::allBooks() const {
    std::vector<Book*> result;
    result.reserve(books_.size());

    for (const auto& [id, book] : books_) {
        result.push_back(book.get());
    }

    std::sort(result.begin(), result.end(),
              [](Book* a, Book* b) { return a->title() < b->title(); });

    return result;
}

std::vector<Member*> Library::allMembers() const {
    std::vector<Member*> result;
    result.reserve(members_.size());

    for (const auto& [id, member] : members_) {
        result.push_back(member.get());
    }

    std::sort(result.begin(), result.end(),
              [](Member* a, Member* b) { return a->name() < b->name(); });

    return result;
}

std::vector<Loan*> Library::activeLoans() const {
    std::vector<Loan*> result;

    for (const auto& [id, loan] : loans_) {
        if (!loan->isReturned()) {
            result.push_back(loan.get());
        }
    }

    std::sort(result.begin(), result.end(),
              [](Loan* a, Loan* b) { return a->dueOn() < b->dueOn(); });

    return result;
}

const std::vector<std::string>& Library::eventLog() const {
    return eventLog_;
}

std::string Library::generateLoanId() {
    return "L" + std::to_string(nextLoanNumber_++);
}

void Library::log(const std::string& message) {
    eventLog_.push_back(message);
}