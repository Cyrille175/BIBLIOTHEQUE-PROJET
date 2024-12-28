#include "Lecteur.h"


Lecteur::Lecteur(int unique_id, std::string first_name, std::string last_name, int day, int month, int year) : _unique_id(unique_id), _first_name(first_name), _last_name(last_name), _birthday(day, month, year) {

}

std::string Lecteur::get_first_name() const {
	return _first_name;
}

std::string Lecteur::get_last_name() const {
	return _last_name;
}

void Lecteur::display_birthday() const {
	_birthday.display_date();
}

void Lecteur::display_ISBN_list() const {
	std::cout << "Les ISBN des livres empruntés par cet utilisateur sont: " << std::endl;
	for (size_t i = 0; i < _ISBNs.size(); i++) {
		std::cout << _ISBNs[i] << std::endl;
	}
}

void Lecteur::add_ISBN(int ISBN) {
	_ISBNs.push_back(ISBN);
}

int main() {
	Lecteur anda(12, "cyrille", "anda", 31, 03, 2006);
	std::cout << anda.get_first_name();
	std::cout << anda.get_last_name();
	anda.display_birthday();
	anda.display_ISBN_list();
	anda.add_ISBN(23);
	anda.add_ISBN(24);
	anda.add_ISBN(25);
	anda.add_ISBN(26);
	anda.display_ISBN_list();
	return 0;
}