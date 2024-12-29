#include "author.h"

Author::Author(std::string full_name, int day, int month, int year, int author_id): _full_name(full_name), _birthday(day, month, year), _author_id(author_id) {

}
            
std::string Author::get_full_name() const {
    return _full_name;
}

int Author::get_author_id() const {
    return _author_id;
}

void Author::display_info_author() const{
    std::cout << "Full name: " << _full_name << std::endl << "Date of birth: " << _birthday.display_date() << std::endl << "Id: " << _author_id << std::endl;
}
