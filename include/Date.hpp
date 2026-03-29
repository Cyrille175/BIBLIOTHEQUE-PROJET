#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
public:
    Date();
    Date(int year, int month, int day);

    static Date today();

    int year() const;
    int month() const;
    int day() const;

    std::string toString() const;

    Date addDays(int days) const;
    int daysUntil(const Date& other) const;

    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;

private:
    int year_;
    int month_;
    int day_;
};

#endif