#ifndef EMPRUNT_H  
#define EMPRUNT_H

#include "Emprunt.h"

Emprunt::Emprunt(int day, int month, int year, int ISBN, int unique_id, Nature nature) : _loan_date(day, month, year), _ISBN(ISBN), _unique_id(unique_id), _nature(nature) {
	
}

void Emprunt::display_loan_info() const {
	if (_nature == Nature::borrow) {
		std::cout << std::endl << "Il s'agit d'un emprunt. Les informations sur cette echange sont:" << std::endl << _loan_date.display_date() << std::endl << "Identifiant de l'emprunteur: " << _unique_id << std::endl << "ISBN du livre: " << _ISBN << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "Il s'agit d'un retour de livre. Les informations sur cette echange sont:" << std::endl << _loan_date.display_date() << std::endl << "Identifiant de l'emprunteur: " << _unique_id << std::endl << "ISBN du livre: " << _ISBN << std::endl << std::endl;
	}
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

#endif

