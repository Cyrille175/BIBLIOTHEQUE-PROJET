#include "date.h"
#include <iostream>

class Emprunt {
	private:
		Date _loan_date; 
		int _ISBN;
		int _unique_id;

	public:
		Emprunt(int day, int month, int year, int _ISBN, int _unique_id);
		void display_loan_info() const;
		int get_ISBN() const;
		int get_unique_id() const;
		Date get_loan_date() const;
};