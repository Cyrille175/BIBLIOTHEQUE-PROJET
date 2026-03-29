#ifndef LOAN_HPP
#define LOAN_HPP

#include "Date.hpp"
#include <optional>
#include <string>

class Loan {
public:
    Loan(std::string id,
         std::string bookId,
         std::string memberId,
         Date borrowedOn,
         Date dueOn);

    const std::string& id() const;
    const std::string& bookId() const;
    const std::string& memberId() const;
    const Date& borrowedOn() const;
    const Date& dueOn() const;
    const std::optional<Date>& returnedOn() const;

    bool isReturned() const;
    void markReturned(const Date& date);

    int overdueDays(const Date& today) const;

private:
    std::string id_;
    std::string bookId_;
    std::string memberId_;
    Date borrowedOn_;
    Date dueOn_;
    std::optional<Date> returnedOn_;
};

#endif