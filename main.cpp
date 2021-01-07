#include <fstream>
#include "boggle.h"

void sprint1() {
	Liste_mot liste;
	initialiser_liste_mot(liste, 50);
	getMots(liste);
	unsigned int points = compter_points(liste);
	std::cout << points;
	supprimer(liste);
}

void sprint2() {
	Liste_mot liste;
	Mot tmp = "null";
	initialiser_liste_mot(liste, 3);
	getMots_trie(liste, tmp);
	trie(liste);
	afficher(liste, true);
	supprimer(liste);
}

void sprint3() {
	// D�claration des deux listes utilis�es 
	Liste_mot liste1;
	Liste_mot liste2;
	Mot tmp = "null";
	// Initialisation, d�claration et tri de la premi�re liste
	initialiser_liste_mot(liste1, 50);
	getMots_trie(liste1, tmp);
	trie(liste1);
	// Initialisation, d�claration et tri de la deuxi�me liste
	initialiser_liste_mot(liste2, 50);
	getMots_trie(liste2, tmp);
	trie(liste2);
	// Affichage des mots de la deuxi�me liste qui ne sont pas pr�sents dans la premi�re
	test_presence(liste1, liste2);
	// Lib�ration des espaces m�moire des deux listes
	supprimer(liste1);
	supprimer(liste2);
}
void getMots_compare(Liste_mot& liste_result);
void get_liste_to_file();
bool check_file_word_commun(Mot& word);

void sprint4() {
	//Liste_mot liste1;
	Liste_mot liste_result;
	//initialiser_liste_mot(liste1, 25);


	//std::cout << "get_liste_to_file" << std::endl;
	get_liste_to_file();
	//std::cout << "initialiser_liste_mot" << std::endl;
	initialiser_liste_mot(liste_result, 20);

	//getMots(liste1);
	getMots_compare(liste_result);

	//test_mots_communs_cout(liste1, liste2);
	//supprimer(liste1);
	trie(liste_result);
	afficher(liste_result, true);
	supprimer(liste_result);
}


void get_liste_to_file() {
	std::ofstream file("tmp_boggle.txt");
	Mot word;

	bool continuer = true;

	std::cin >> std::setw(LGMOT) >> word;

	if (strcmp(word, "*") == 0)
		continuer = false;

	while (continuer) {
		
		file << word << std::endl;

		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
	file.close();
}

void getMots_compare(Liste_mot& liste_result) {


	Mot word;
	bool continuer = true;

	std::cin >> std::setw(LGMOT) >> word;

	if (strcmp(word, "*") == 0)
		continuer = false;

	while (continuer) {

		if (check_file_word_commun(word))
			if (!mot_existant(liste_result, word))
				ajouter_mot(liste_result, word);

		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
}

bool check_file_word_commun(Mot& word) {
	Mot mot;
	std::ifstream file("tmp_boggle.txt");
	file >> mot;
	while (!file.eof()) {
		if (strcmp(mot, word) == 0)
			return true;
		file >> mot;
	}
	file.close();
	return false;
}


void sprint5() {
	Liste_de_listes_mot liste_principale;
	Liste_mot liste_result;
	initialiser_liste(liste_principale, 5);
	initialiser_liste_mot(liste_result, 5);
	get_listes(liste_principale);
	check_communs_2_listes(liste_principale, liste_result);
	trie(liste_result);
	rm_doublons(liste_result);
	afficher(liste_result, false);
	supprimer(liste_result);
	supprimer_liste_de_listes(liste_principale);
}

void sprint6(){
	Liste_mot liste_result;
	plateau plate;
	Mot tmp = "null";
	initialiser_liste_mot(liste_result, 50);
	initialiser_plateau(plate, 2);
	get_plateau(plate);

	getMots_plate(plate, liste_result);
	//getMots_trie(liste, tmp);
	//trie(liste);	
	//check_liste_dans_plateau(liste, plate, liste_result);
	trie(liste_result);
	afficher(liste_result, false);
	supprimer(liste_result);
	supprimer_plateau(plate);
}

int main() {
	int num;
	std::cin >> num;
	switch (num) {
	case 1:
		sprint1(); break; // correspond au main du premier programme
	case 2:
		sprint2(); break; // correspond au main du second programme
	case 3:
		sprint3(); break; // correspond au main du troisi�me programme	
	case 4:
		sprint4(); break; // correspond au main du troisi�me programme	
	case 5:
		sprint5(); break; // correspond au main du troisi�me programme
	case 6:
		sprint6(); break; // correspond au main du troisi�me programme
	}
}
//(echo 5 & type in5.txt) | SDA_Projet.exe > out5