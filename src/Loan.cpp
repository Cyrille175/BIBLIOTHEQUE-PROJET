#include "Loan.hpp"

Loan::Loan(std::string id,
           std::string bookId,
           std::string memberId,
           Date borrowedOn,
           Date dueOn)
    : id_(std::move(id)),
      bookId_(std::move(bookId)),
      memberId_(std::move(memberId)),
      borrowedOn_(borrowedOn),
      dueOn_(dueOn) {}

const std::string& Loan::id() const { return id_; }
const std::string& Loan::bookId() const { return bookId_; }
const std::string& Loan::memberId() const { return memberId_; }
const Date& Loan::borrowedOn() const { return borrowedOn_; }
const Date& Loan::dueOn() const { return dueOn_; }
const std::optional<Date>& Loan::returnedOn() const { return returnedOn_; }

bool Loan::isReturned() const {
    return returnedOn_.has_value();
}

void Loan::markReturned(const Date& date) {
    returnedOn_ = date;
}

int Loan::overdueDays(const Date& today) const {
    Date effectiveDate = returnedOn_.has_value() ? *returnedOn_ : today;
    int diff = dueOn_.daysUntil(effectiveDate);
    return diff > 0 ? diff : 0;
}