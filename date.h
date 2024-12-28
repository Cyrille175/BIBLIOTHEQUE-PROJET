#include <iostream>
#include <string.h>

class Date {
private:
    int _day;
    int _month;
    int _year;

public:

    Date(int day, int month, int year);

    bool IsDate(int day, int month, int year) const;

    std::string display_date() const;

    std::string edit_date(int day, int month, int year);
};