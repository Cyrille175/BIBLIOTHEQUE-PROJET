

bool Lecteur::is_password(std::string password) {
	if (password == _password) {
		return true;
	}
	else return false;
}

Lecteur(std::string unique_id, std::string first_name, std::string last_name, std::string password, int day, int month, int year) : _unique_id(unique_id), _first_name(first_name), _last_name(last_name), _password(password), _birthday(day, month, year) {

}


