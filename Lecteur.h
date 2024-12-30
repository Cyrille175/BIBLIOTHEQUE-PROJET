#ifndef LECTEUR_H  
#define LECTEUR_H

#include <string.h>
#include <iostream>
#include <vector>
#include "date.h"

class Lecteur {
private:
	int _unique_id;
	std::string _first_name, _last_name;
	Date _birthday;
	std::vector<int> _ISBNs;

public: 
	Lecteur(int unique_id, std::string first_name, std::string last_name, int day, int month, int year); 
	std::string get_first_name() const;
	std::string get_last_name() const;
	int get_unique_id() const;
	Date get_birthday() const;
	void display_birthday() const;
	void display_ISBN_list() const;
	void add_ISBN(int ISBN);
	void set_first_name(std::string fn);
	void set_last_name(std::string ln);
	void set_id(int id);
	void set_birthday(int day, int month, int year);
};

#endif