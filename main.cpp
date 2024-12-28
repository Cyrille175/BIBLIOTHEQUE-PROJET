#include "Livre.h"

int main() {
	Livre a("Introduction aux reseaux", "Pour ingenieur", "English", 30, 3, 2023, 234);
	Livre b("Introduction aux signaux", "Pour ingenieur", "English", 28, 7, 2023, 235);
	Livre c("Statistiques", "Pour ingenieur et medecins", "Spain", 20, 7, 2023, 236);
	Livre d("Introduction a l'IA", "Pour ingenieur", "French", 310, 3, 2023, 237);
	Livre f("Introduction au management", "Pour ingenieur", "English", -1, 3, 2022, 238);

	std::cout << a.get_title() << std::endl;
	std::cout << d.get_title() << std::endl;
	std::cout << f.get_title() << std::endl;
	std::cout << f.get_ISBN() << std::endl;

	f.display_info_book();

	a.display_info_book();
	std::cout << a.get_state() << std::endl;
	a.change_state();
	std::cout << a.get_state() << std::endl;
	
	return 0;
}