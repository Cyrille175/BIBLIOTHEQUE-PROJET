#include "Member.hpp"

#include <algorithm>

Member::Member(std::string id, std::string name, std::size_t maxLoans)
    : id_(std::move(id)),
      name_(std::move(name)),
      maxLoans_(maxLoans) {}

const std::string& Member::id() const { return id_; }
const std::string& Member::name() const { return name_; }

bool Member::canBorrow() const {
    return currentLoanIds_.size() < maxLoans_;
}

bool Member::addLoan(const std::string& loanId) {
    if (!canBorrow()) {
        return false;
    }
    return currentLoanIds_.insert(loanId).second;
}

void Member::removeLoan(const std::string& loanId) {
    currentLoanIds_.erase(loanId);
}

const std::unordered_set<std::string>& Member::currentLoanIds() const {
    return currentLoanIds_;
}

void Member::addFine(double amount) {
    if (amount > 0.0) {
        outstandingFine_ += amount;
    }
}

void Member::payFine(double amount) {
    if (amount <= 0.0) {
        return;
    }
    outstandingFine_ -= amount;
    if (outstandingFine_ < 0.0) {
        outstandingFine_ = 0.0;
    }
}

double Member::outstandingFine() const {
    return outstandingFine_;
}

void Member::recordGenre(const std::string& genre) {
    if (!genre.empty()) {
        ++genreHistory_[genre];
    }
}

std::string Member::favoriteGenre() const {
    if (genreHistory_.empty()) {
        return {};
    }

    auto it = std::max_element(
        genreHistory_.begin(),
        genreHistory_.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    return it->first;
}