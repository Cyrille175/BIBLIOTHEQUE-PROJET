#include <iostream>
#include <string.h>

class Date {
private:
    int _day;
    int _month;
    int _year;
    bool _check; //cette variable sera vraie quand la date sera correcte et fausse quand la date sera incorrecte 

public:

    Date(int day, int month, int year);

    bool IsDate(int day, int month, int year) const;

    std::string display_date() const;

    std::string edit_date(int day, int month, int year);
};