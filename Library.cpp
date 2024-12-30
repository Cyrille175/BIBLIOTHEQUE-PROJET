
#include "Library.h"

void Library::add_book_online(const Livre& livre) {
	_books.push_back(livre);
}

void Library::add_lecteur_online(const Lecteur& lecteur) {
	_lecteurs.push_back(lecteur);
}

void Library::add_emprunt_online(const Emprunt& emprunt) {
	_emprunts.push_back(emprunt);
}

void Library::lecteur_loan_book(int unique_id, int ISBN, int day, int month, int year) {
	int a;
	int b;
	// Je dois d"abord recuperer la valeur state du livre concerné
	bool track = false;
	for (size_t i = 0; i < _books.size(); i++) {
		if (_books[i].get_ISBN() == ISBN) {
			a = i;
			track = true;
		}
	}
	if (!track) {
		std::cout << std::endl << "Il n'y a pas de livre possedant cet ISBN" << std::endl;
	}

	bool tracki = false;
	for (size_t i = 0; i < _lecteurs.size(); i++) {
		if (_lecteurs[i].get_unique_id() == unique_id) {
			b = i;
			tracki = true;
		}
	}
	
	if (!tracki) {
		std::cout << std::endl << "Il n'y a pas de lecteurs possedant cet identifiant" << std::endl;
	}

	if(track && tracki) {
		if (!(_books[a].get_state())) {
			Emprunt loan(day, month, year, ISBN, unique_id, Nature::borrow);
			_books[a].change_state();
			_emprunts.push_back(loan);
			_books[a].add_borrower(_lecteurs[b]);
			_lecteurs[b].add_ISBN(ISBN);
			_books[a].change_current_borrower(_lecteurs[b]);
			std::cout << std::endl << _lecteurs[b].get_first_name() << " " << _lecteurs[b].get_last_name() << " a emprunte le livre dont le titre est: " << _books[a].get_title() << " le " << loan.get_loan_date().display_date() << std::endl;
		}

		else {
			std::cout << std::endl << "Nous sommes desoles mais nous sommes dans l'incapacite de vous preter ce livre car il est deja emprunte" << std::endl;
		}
	}	
}


void Library::lecteur_return_book(int unique_id, int ISBN, int day, int month, int year) {
	int a;
	int b;
	bool track = false;
	for (size_t i = 0; i < _books.size(); i++) {
		if (_books[i].get_ISBN() == ISBN) {
			a = i;
			track = true;
		}
	}
	if (!track) {
		std::cout << std::endl << "Il n'y a pas de livre possedant cet ISBN" << std::endl;
	}

	bool tracki = false;
	for (size_t i = 0; i < _lecteurs.size(); i++) {
		if (_lecteurs[i].get_unique_id() == unique_id) {
			b = i;
			tracki = true;
		}
	}
	if (!tracki) {
		std::cout << std::endl << "Il n'y a pas de lecteurs possedant cet identifiant" << std::endl;
	}
	if (!(_books[a].get_state())) {
		std::cout << std::endl << "Ce livre n'a pas ete prete" << std::endl;
	}

	if (track && tracki && (_books[a].get_state())) {
		if ( _books[a].get_current_borrower().get_unique_id() == unique_id ) {
			Emprunt loan(day, month, year, unique_id, ISBN, Nature::returne);
			_books[a].change_state();
			_lecteurs[b].add_ISBN(ISBN);
			std::cout << std::endl << _lecteurs[b].get_first_name() << " " << _lecteurs[b].get_last_name() << " a rendu le livre dont le titre est: " << _books[a].get_title() << " le " << loan.get_loan_date().display_date() << std::endl;
		}
		
		if ( !(_books[a].get_current_borrower().get_unique_id() == unique_id) ) {
			std::cout << std::endl << "Ce livre a bel et bien ete prete mais par pas vous donc vous ne pouvez pas le rendre" << std::endl;
		}	
	}
	 
}

void Library::display_historic() const{
	std::cout << std::endl << "Voici la liste de tous les echanges qui ont eu lieu: " << std::endl;
	for (size_t i = 0; i < _emprunts.size(); i++) {
		_emprunts[i].display_loan_info();
	}
}


