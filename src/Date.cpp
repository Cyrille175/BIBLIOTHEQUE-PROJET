#include "Date.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

namespace {
std::tm toTm(int year, int month, int day) {
    std::tm tm{};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 12;
    return tm;
}
}

Date::Date() : year_(1970), month_(1), day_(1) {}

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}

Date Date::today() {
    std::time_t now = std::time(nullptr);
    std::tm local{};
#if defined(_WIN32)
    localtime_s(&local, &now);
#else
    local = *std::localtime(&now);
#endif
    return Date(local.tm_year + 1900, local.tm_mon + 1, local.tm_mday);
}

int Date::year() const { return year_; }
int Date::month() const { return month_; }
int Date::day() const { return day_; }

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(4) << year_ << "-"
        << std::setw(2) << month_ << "-"
        << std::setw(2) << day_;
    return oss.str();
}

Date Date::addDays(int days) const {
    std::tm tm = toTm(year_, month_, day_);
    std::time_t t = std::mktime(&tm);
    t += static_cast<long long>(days) * 24 * 60 * 60;

    std::tm result{};
#if defined(_WIN32)
    localtime_s(&result, &t);
#else
    result = *std::localtime(&t);
#endif

    return Date(result.tm_year + 1900, result.tm_mon + 1, result.tm_mday);
}

int Date::daysUntil(const Date& other) const {
    std::tm tm1 = toTm(year_, month_, day_);
    std::tm tm2 = toTm(other.year_, other.month_, other.day_);

    std::time_t t1 = std::mktime(&tm1);
    std::time_t t2 = std::mktime(&tm2);

    double seconds = std::difftime(t2, t1);
    return static_cast<int>(seconds / (24 * 60 * 60));
}

bool Date::operator<(const Date& other) const {
    if (year_ != other.year_) return year_ < other.year_;
    if (month_ != other.month_) return month_ < other.month_;
    return day_ < other.day_;
}

bool Date::operator==(const Date& other) const {
    return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
}

bool Date::operator!=(const Date& other) const { return !(*this == other); }
bool Date::operator<=(const Date& other) const { return *this < other || *this == other; }
bool Date::operator>(const Date& other) const { return other < *this; }
bool Date::operator>=(const Date& other) const { return !(*this < other); }