#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include "Loan.hpp"
#include "Member.hpp"
#include "NotificationService.hpp"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Library {
public:
    explicit Library(std::shared_ptr<NotificationService> notifier);

    bool addBook(std::unique_ptr<Book> book);
    bool addMember(std::unique_ptr<Member> member);

    Book* findBook(const std::string& bookId);
    Member* findMember(const std::string& memberId);
    Loan* findLoan(const std::string& loanId);

    std::vector<Book*> searchBooks(const std::string& keyword);
    std::vector<Book*> recommendBooks(const std::string& memberId);

    bool borrowBook(const std::string& bookId, const std::string& memberId);
    bool returnBook(const std::string& loanId);
    bool reserveBook(const std::string& bookId, const std::string& memberId);
    bool renewLoan(const std::string& loanId, int extraDays = 7);

    double memberFine(const std::string& memberId) const;
    bool payFine(const std::string& memberId, double amount);

    std::vector<Book*> allBooks() const;
    std::vector<Member*> allMembers() const;
    std::vector<Loan*> activeLoans() const;
    const std::vector<std::string>& eventLog() const;

private:
    std::unordered_map<std::string, std::unique_ptr<Book>> books_;
    std::unordered_map<std::string, std::unique_ptr<Member>> members_;
    std::unordered_map<std::string, std::unique_ptr<Loan>> loans_;
    std::shared_ptr<NotificationService> notifier_;
    std::vector<std::string> eventLog_;
    int nextLoanNumber_ = 1;

    std::string generateLoanId();
    void log(const std::string& message);
};

#endif