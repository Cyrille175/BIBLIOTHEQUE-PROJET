#include "Livre.h"


Livre::Livre(std::string title, std::string genre, std::string language, int dayp, int monthp, int yearp, int ISBN, std::string full_name, int day, int month, int year, int author_id) : _title(title), _genre(genre), _language(language), _publication_date(dayp, monthp, yearp), _ISBN(ISBN), _author(full_name, day, month, year, author_id) {
	_state = false;
}

std::string Livre::get_title() const {
	return _title;
}

int Livre::get_ISBN() const {
	return _ISBN;
}

void Livre::display_info_book() const {
	std::cout  << std::endl <<"Les informatiosn sur ce livre sont: " << std::endl << "Titre du livre: " << _title << std::endl << "Genre du livre: " << _genre << std::endl << "Language: " << _language << std::endl << "Date de publication: " << _publication_date.display_date() << std::endl << "ISBN: " << _ISBN << std::endl << std::endl;
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

void Livre::display_info_a() const {
	_author.display_info_author();
}

int main() {
	Livre a("Reseaux", "Pour ingenieur", "English", 10, 32, 2003, 234, "Cyrille Anda", 31, 3, 2006, 1);
	Livre b("Quete de soi", "Sagesse profonde", "English", 10, 04, 2026, 244, "Cyrille Anda", 31, 3, 2006, 1);
	Livre c("Vie de foi", "Sagesse profonde", "English", 10, 04, 2026, 2233, "Kamta Yannick", 8, 1, 1999, 1);

	std::cout << b.get_title() << std::endl;;
	std::cout << a.get_ISBN() << std::endl;;
	a.display_info_book();
	a.display_info_a();
	b.display_info_a();
	std::cout << a.get_state() << std::endl;;
	a.change_state();
	std::cout << a.get_state() << std::endl;;
	b.display_info_a();
	c.display_info_a();

	return 0;
}

