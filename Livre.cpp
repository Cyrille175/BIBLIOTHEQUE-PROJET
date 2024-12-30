#include "Livre.h"


Livre::Livre(std::string title, std::string genre, std::string language, int dayp, int monthp, int yearp, int ISBN, std::string full_name, int day, int month, int year, int author_id) : _title(title), _genre(genre), _language(language), _publication_date(dayp, monthp, yearp), _ISBN(ISBN), _author(full_name, day, month, year, author_id), _current_borrower(0, "Anda", "Cyrille", 31, 3, 2006) {
	_state = false;
	//Lecteur _current_borrower(0, "Anda", "Cyrille", 31, 3, 2006);
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

std::string Livre::display_state() const {
	std::string state;
	if (_state)
		state = "Votre livre est emprunte";
	else state = "Votre livre est toujours dans les rayons et n'est pas emprunte";
	return state;
}

void Livre::change_state() {
	_state = !_state;
}

bool Livre::get_state() const {
	return _state;
}

void Livre::display_info_a() const {
	_author.display_info_author();
}

void Livre::add_borrower(const Lecteur& borrower) {
	_borrowers.push_back(borrower);
}

void Livre::list_borrowers() const {
	if (_borrowers.size() != 0) {
		std::cout << "les emprunteurs de ce livre sont:" << std::endl;
		for (size_t i = 0; i < _borrowers.size(); i++) {
			std::cout << _borrowers[i].get_first_name() << " " << _borrowers[i].get_last_name() << std::endl;
		}
	}
	else std::cout << "Personne n'a jamais emprunté ce livre" << std::endl;
}

void Livre::change_current_borrower(const Lecteur& lecteur) {
	_current_borrower.set_id( lecteur.get_unique_id() );
	_current_borrower.set_first_name( lecteur.get_first_name() );
	_current_borrower.set_last_name( lecteur.get_last_name() );
	_current_borrower.set_birthday( lecteur.get_birthday().get_day(), lecteur.get_birthday().get_month(), lecteur.get_birthday().get_year());
}

Lecteur Livre::get_current_borrower() const {
	return _current_borrower;
}

