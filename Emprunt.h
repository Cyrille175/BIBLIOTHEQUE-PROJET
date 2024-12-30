#include "date.h"
#include <iostream>

enum class Nature {
	borrow, returne
};

class Emprunt {
	private:
		Date _loan_date; 
		int _ISBN;
		int _unique_id;
		Nature _nature;

	public:
		Emprunt(int day, int month, int year, int _ISBN, int _unique_id, Nature nature);
		void display_loan_info() const;
		int get_ISBN() const;
		int get_unique_id() const;
		Nature get_nature() const;
		Date get_loan_date() const;
};