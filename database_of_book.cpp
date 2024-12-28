#include 'database_of_book.h'


Database_of_book::Database_of_book( const initialiser<Livre> books): _books(books) {

}

// std::string Database_of_book::add_book_online(std::string title, std::string author, std::string language, int day, int month, int year, int ISBN, std::vector<Lecteur> _emprunteurs) {
void Database_of_book::add_book_online(const Livre& book) {
	_books.push_back(book);
	std::cout << "votre livre " << livre.get_title() << " a été ajouté avec succes" << std::endl;
}

std::