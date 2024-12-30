#include "Lecteur.h"


Lecteur::Lecteur(int unique_id, std::string first_name, std::string last_name, int day, int month, int year) : _unique_id(unique_id), _first_name(first_name), _last_name(last_name), _birthday(day, month, year) {

}

std::string Lecteur::get_first_name() const {
	return _first_name;
}

std::string Lecteur::get_last_name() const {
	return _last_name;
}

int Lecteur::get_unique_id() const {
	return _unique_id;
}

Date Lecteur::get_birthday() const {
	return _birthday;
}

void Lecteur::display_birthday() const {
	_birthday.display_date();
}

void Lecteur::display_ISBN_list() const {
	if (_ISBNs.size() == 0) {
		std::cout << "Il n'y a pas de livres empruntes par ce lecteur" << std::endl;
	}
	else {
		std::cout << "Les ISBN des livres empruntes par cet utilisateur sont: " << std::endl;
		for (size_t i = 0; i < _ISBNs.size(); i++) {
			std::cout << _ISBNs[i] << std::endl;
		}
	}
}

void Lecteur::add_ISBN(int ISBN) {
	_ISBNs.push_back(ISBN);
}

void Lecteur::set_first_name(std::string fn) {
	_first_name = fn;
}

void Lecteur::set_last_name(std::string ln) {
	_last_name = ln;
}

void Lecteur::set_id(int id) {
	_unique_id = id;
}

void Lecteur::set_birthday(int day, int month, int year) {
	_birthday.edit_date(day, month, year);
}