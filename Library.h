#include "Livre.h"
#include "Lecteur.h"
#include "Emprunt.h"
#include "date.h"


class Library {

private: 
	std::vector<Livre> _books;
	std::vector<Lecteur> _lecteurs;
	std::vector<Emprunt> _emprunts;


public:

	//std::string add_book_online(std::string title, std::string author, std::string language, int day, int month, int year, int ISBN, std::vector<Lecteur> _emprunteurs);
	void add_book_online(const Livre& livre);
	void add_lecteur_online(const Lecteur& lecteur);
	void add_emprunt_online(const Emprunt& emprunt);
	void lecteur_loan_book(int unique_id, int ISBN, int day, int month, int year); // verifie d'abord si le livre est dispo, ensuite si non je renvoie un message qu'il ne peut pas, dans le cas contraire je cree un ojet emprunt et je l'ajoute dans mon tableau emprunt, je change l'etat du livre
	void lecteur_return_book(int unique_id, int ISBN, int day, int month, int year);
	void display_historic() const;
};
