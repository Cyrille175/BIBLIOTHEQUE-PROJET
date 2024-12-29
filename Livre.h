#include <vector>
#include "author.h"


class Livre {
private:
	std::string _title, _genre, _language ;
	Date _publication_date;
	int _ISBN;
	//std::vector<Lecteur> _borrowers;
	bool _state;
	Author _author;


public:
	Livre(std::string title, std::string author, std::string language, int dayp, int monthp, int yearp, int _ISBN, std::string full_name, int day, int month, int year, int author_id); 
	std::string get_title() const;
	int get_ISBN() const;
	std::string get_state() const;
	void display_info_book() const;
	void display_info_a() const;
	//void add_borrower(const Lecteur& borrower);
	void change_state();
};

