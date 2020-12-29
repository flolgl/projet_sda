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
	initialiser_liste_mot(liste, 50);
	getMots_trie(liste);
	trie(liste);
	afficher(liste);
	supprimer(liste);
}

void sprint3() {
	// Déclaration des deux listes utilisées 
	Liste_mot liste1;
	Liste_mot liste2;
	// Initialisation, déclaration et tri de la première liste
	initialiser_liste_mot(liste1, 50);
	getMots_trie(liste1);
	trie(liste1);
	// Initialisation, déclaration et tri de la deuxième liste
	initialiser_liste_mot(liste2, 50);
	getMots_trie(liste2);
	trie(liste2);
	// Affichage des mots de la deuxième liste qui ne sont pas présents dans la première
	test_presence(liste1, liste2);
	// Libération des espaces mémoire des deux listes
	supprimer(liste1);
	supprimer(liste2);
}

void sprint4() {
	Liste_mot liste1;
	Liste_mot liste2;
	Liste_mot liste_result;
	initialiser_liste_mot(liste1, 50);
	initialiser_liste_mot(liste2, 50);
	initialiser_liste_mot(liste_result, 50);

	getMots(liste1);
	getMots(liste2);

	test_mots_communs(liste1, liste2, liste_result);
	afficher(liste_result);
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
		sprint3(); break; // correspond au main du troisième programme	
	case 4:
		sprint4(); break; // correspond au main du troisième programme
	}
}