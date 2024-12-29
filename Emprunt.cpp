#include "Emprunt.h"

Emprunt::Emprunt(int day, int month, int year, int ISBN, int unique_id) : _loan_date(day, month, year), _ISBN(ISBN), _unique_id(unique_id) {

}

void Emprunt::display_loan_info() const {
	std::cout << std::endl << "Les informations sur l'emprunt est:" << _loan_date.display_date() << std::endl << "Identifiant de l'emprunteur: " << _unique_id << std::endl << "ISBN du livre: " << _ISBN << std::endl << std::endl;
}

int Emprunt::get_ISBN() const {
	return _ISBN;
}

int Emprunt::get_unique_id() const {
	return _unique_id;
}

Date Emprunt::get_loan_date() const {
	return _loan_date;
}

int main() {
	Emprunt preter(2, 3, 2024, 23, 23);
	preter.display_loan_info();
	std::cout << preter.get_ISBN();
	std::cout << preter.get_unique_id();
	std::cout << preter.get_loan_date().display_date();
	return 0;
}