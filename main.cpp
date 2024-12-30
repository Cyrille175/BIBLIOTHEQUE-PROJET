#include "Library.h"


int main() {
	Library cortex;

	Livre a("Reseaux", "Pour ingenieur", "English", 10, 32, 2027, 1, "Cyrille Anda", 31, 3, 2006, 1);
	Livre b("Quete de soi", "Sagesse profonde", "English", 10, 4, 2026, 2, "Cyrille Anda", 31, 3, 2006, 1);
	Livre c("Vie de foi", "Sagesse profonde", "English", 10, 4, 2026, 3, "Kamta Yannick", 8, 1, 1999, 2);
	Livre d("Foi folle", "Spirituelle", "French", 10, 12, 2025, 4, "Cyrille Anda", 31, 3, 2006, 1);
	Livre e("Quete de soi", "Crazy faith", "English", 10, 4, 2017, 5, "Michael Todd", 31, 5, 1990, 3);
	Livre f("Vie de foi", "Puissance du caractere", "English", 10, 4, 2016, 6, "Smiles Munroe", 8, 10, 1979, 4);
	Livre g("La puissance de l'Esprit Saint", "Christianisme", "English", 10, 32, 2003, 7, "Smiles Monroe", 8, 10, 1979, 4);
	Livre h("Le leadership", "Sagesse profonde", "English", 10, 8, 2008, 9, "Smiles Munroe", 8, 10, 1979, 4);
	Livre i("Devenez un grand leader", "Pour tous", "English", 10, 12, 2029, 10, "Cyrille Anda", 31, 3, 2006, 1);
	Livre j("C'est quoi la vie?", "Sagesse profonde", "English", 1, 5, 2027, 11, "Cyrille Anda", 31, 3, 2006, 1);
	Livre k("La theorie de la divergence", "Sagesse profonde", "English", 12, 6, 2027, 12, "Kamta Yannick", 8, 1, 1999, 2);


	Lecteur Anda(12, "Cyrille", "Anda", 31, 3, 2006);
	Lecteur Jessica(13, "Jessica", "Andje", 28, 8, 2001);
	Lecteur Emma(14, "Emma", "Tchatchouang", 22, 12, 2004);
	Lecteur Marie(15, "Marie", "Ntep", 23, 9, 2005);
	Lecteur Darren(16, "Darren", "Tchouopi", 11, 5, 2005);
	Lecteur Esteban(17, "Esteban", "Junior", 23, 8, 2003);

	cortex.add_book_online(a);
	cortex.add_book_online(b);
	cortex.add_book_online(c);
	cortex.add_book_online(d);
	cortex.add_book_online(e);
	cortex.add_book_online(f);
	cortex.add_book_online(g);
	cortex.add_book_online(h);
	cortex.add_book_online(i);
	cortex.add_book_online(j);
	cortex.add_book_online(k);

	cortex.add_lecteur_online(Anda);
	cortex.add_lecteur_online(Jessica);
	cortex.add_lecteur_online(Emma);
	cortex.add_lecteur_online(Marie);
	cortex.add_lecteur_online(Darren);
	cortex.add_lecteur_online(Esteban);

	cortex.lecteur_loan_book(12, 1, 1, 1, 2025);
	cortex.lecteur_loan_book(16, 1, 2, 1, 2025);
	cortex.lecteur_return_book(13, 3, 3, 1, 2025);
	cortex.lecteur_loan_book(14, 2, 4, 1, 2025);
	cortex.lecteur_loan_book(15, 12, 5, 1, 2025);
	cortex.lecteur_loan_book(17, 12, 6, 1, 2025);
	cortex.lecteur_return_book(13, 4, 7, 1, 2025);
	cortex.lecteur_loan_book(12, 2, 8, 1, 2025);
	cortex.lecteur_loan_book(15, 11, 9, 1, 2025);
	cortex.lecteur_return_book(12, 1, 10, 1, 2025);
	cortex.lecteur_loan_book(17, 1, 11, 1, 2025);
	cortex.lecteur_return_book(17, 1, 12, 1, 2025);
	cortex.lecteur_loan_book(16, 11, 1, 13, 2025);
	cortex.lecteur_return_book(18, 11, 14, 1, 2025);
	cortex.lecteur_loan_book(10, 6, 1, 15, 2025);
	cortex.lecteur_return_book(15, 4, 16, 1, 2025);
	cortex.lecteur_loan_book(12, 9, 17, 1, 2025);
	cortex.lecteur_return_book(15, 11, 18, 1, 2025);

	cortex.display_historic();
	return 0;
}