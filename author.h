#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <iostream>
#include "date.h"


class Author {
private:
    std::string _full_name;
    Date _birthday;
    int _author_id;

public:
    Author(std::string full_name, int day, int monht, int year, int author_id);
    std::string get_full_name() const;
    int get_author_id() const;
    void display_info_author() const;
};

#endif