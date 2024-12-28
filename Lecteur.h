

class Lecteur {

private:
	std::string _unique_id, _first_name, _last_name, _password;
	Date _birthday;
	std::vector<Livre> _borrowed_book;
	bool is_password(std::string password);

public: 
	Lecteur(std::string unique_id, std::string first_name, std::string last_name, std::string password, int day, int month, int year); 
	

	std::string get_personal_info(password) const;

	std::string loan_a_book(int _ISBN); // parmi la base de donnees des livres	aller chercher le livre donc l'id correspond et l'enregistrer dans la structure vector, si je peux je vais une fois modifier ici la liste des emprunteurs associés au livre dont on parle
	// dans cette methode, je dois verifier si le livre est disponible dans la bibliotheque, je dois donc verifier l'etat de chaque livre
	// je dois etre capable ici d'extraire des elements de la base de donnees des livres et les renvoyer dans la table associée au lecteur 



};