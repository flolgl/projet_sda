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
	initialiser_liste_mot(liste, 3);
	getMots_trie(liste);
	trie(liste);
	afficher(liste, true);
	supprimer(liste);
}

void sprint3() {
	// D�claration des deux listes utilis�es 
	Liste_mot liste1;
	Liste_mot liste2;
	// Initialisation, d�claration et tri de la premi�re liste
	initialiser_liste_mot(liste1, 50);
	getMots_trie(liste1);
	trie(liste1);
	// Initialisation, d�claration et tri de la deuxi�me liste
	initialiser_liste_mot(liste2, 50);
	getMots_trie(liste2);
	trie(liste2);
	// Affichage des mots de la deuxi�me liste qui ne sont pas pr�sents dans la premi�re
	test_presence(liste1, liste2);
	// Lib�ration des espaces m�moire des deux listes
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
	afficher(liste_result, true);
	supprimer(liste1);
	supprimer(liste2);
	supprimer(liste_result);
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
	Liste_mot liste;
	Liste_mot liste_result;
	plateau plate;
	initialiser_plateau(plate, 2);
	get_plateau(plate);

	initialiser_liste_mot(liste, 50);
	getMots_trie(liste);
	trie(liste);	
	
	initialiser_liste_mot(liste_result, 50);
	check_liste_dans_plateau(liste, plate, liste_result);
	afficher(liste_result, true);
	supprimer(liste);
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