#include "Livre.h"


Livre::Livre(std::string title, std::string genre, std::string language, int day, int month, int year, int ISBN) : _title(title), _genre(genre), _language(language), _publication_date(day, month, year), _ISBN(ISBN) {
	_state = false;
}

std::string Livre::get_title() const {
	return _title;
}

int Livre::get_ISBN() const {
	return _ISBN;
}

void Livre::display_info_book() const {
	std::cout << "Titre du livre: " << _title << std::endl << "Genre du livre: " << _genre << std::endl << "Language: " << _language << std::endl << "Date de publication: " << _publication_date.display_date() << std::endl << "ISBN: " << _ISBN << std::endl;
}

std::string Livre::get_state() const {
	std::string state;
	if (_state)
		state = "Votre livre est emprunte";
	else state = "Votre livre est toujours dans les rayons et n'est pas emprunte";
	return state;
}

void Livre::change_state() {
	_state = !_state;
}
