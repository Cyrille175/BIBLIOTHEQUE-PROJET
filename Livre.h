#ifndef LIVRE_H  
#define LIVRE_H

#include <vector>
#include "author.h"
#include "Lecteur.h"

class Livre {
private:
	std::string _title, _genre, _language ;
	Date _publication_date;
	int _ISBN;
	std::vector<Lecteur> _borrowers;
	Lecteur _current_borrower;
	bool _state; // si ce booleen est true alors le livre est emprunté
	Author _author;
	

public:
	Livre(std::string title, std::string author, std::string language, int dayp, int monthp, int yearp, int _ISBN, std::string full_name, int day, int month, int year, int author_id); 
	std::string get_title() const;
	int get_ISBN() const;
	bool get_state() const;
	std::string display_state() const;
	void display_info_book() const;
	void display_info_a() const;
	void add_borrower(const Lecteur& borrower);
	void list_borrowers() const;
	void change_current_borrower(const Lecteur& lecteur);
	Lecteur get_current_borrower() const;
	void change_state();
};

#endif