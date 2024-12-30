
class Database_of_book {

private: 
	std::vector<Livre> _books;

public:
	Database_of_book(const &initialiser<Livre> books);

	//std::string add_book_online(std::string title, std::string author, std::string language, int day, int month, int year, int ISBN, std::vector<Lecteur> _emprunteurs);
	void add_book_online(const Livre& livre);
	
	std::string find_author_books(std::string author) const;




};