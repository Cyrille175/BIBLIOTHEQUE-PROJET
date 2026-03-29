#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>

class Member {
public:
    Member(std::string id, std::string name, std::size_t maxLoans = 3);

    const std::string& id() const;
    const std::string& name() const;

    bool canBorrow() const;
    bool addLoan(const std::string& loanId);
    void removeLoan(const std::string& loanId);

    const std::unordered_set<std::string>& currentLoanIds() const;

    void addFine(double amount);
    void payFine(double amount);
    double outstandingFine() const;

    void recordGenre(const std::string& genre);
    std::string favoriteGenre() const;

private:
    std::string id_;
    std::string name_;
    std::size_t maxLoans_;
    std::unordered_set<std::string> currentLoanIds_;
    double outstandingFine_ = 0.0;
    std::unordered_map<std::string, int> genreHistory_;
};

#endif