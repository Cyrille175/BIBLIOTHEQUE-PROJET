#include "date.h"

bool Date::IsDate(int day, int month, int year) const {

    bool is_date = true;
    if (month < 1 || month > 12) {
        is_date = false;
    }



    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day < 1) {
            is_date = false;
        }
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31 || day < 1) {
            is_date = false;
        }
    }

    //Gestion du mois de fevrier

    if (year % 4 == 0) {
        if (month == 2 && day > 28) {
            is_date = false;
        }
    }
    else if (month == 2 && day > 29) {
        is_date = false;
    }
    return is_date;
}

int Date::get_day() const {
    return _day;
}

int Date::get_month() const {
    return _month;
}

int Date::get_year() const {
    return _year;
}

Date::Date(int day, int month, int year) {
    if (IsDate(day, month, year)) {
        _day = day;
        _month = month;
        _year = year;
        _check = true;
    }
    else {
        std::cout << "votre date n'est pas correcte" << std::endl;
        _check = false;
    }
}

std::string Date::display_date() const {
    if (_check) {
        return std::to_string(_day) + "/" + std::to_string(_month) + "/" + std::to_string(_year);
    }
    else return "Date non fournie";
}

void Date::edit_date(int day, int month, int year) {
    std::string info;
    if (IsDate(day, month, year)) {
        _month = month;
        _day = day;
        _year = year;
        std::cout << "Votre date a bien ete modifiee" << std::endl;
    }

    else {
        std::cout << "Votre date n'est pas conforme a une date valide" << std::endl;
    }
}

