#include "boggle.h"

// Main du premier sprint.
void sprint1() {
	// Déclaration de la liste
	Liste_mot liste;
	// Initialisation en mémoire de la liste
	initialiser_liste_mot(liste, 50);
	// Enregistrement dans la liste des mots entrés
	getMots(liste);
	// Comptage et affichage des points de la liste
	unsigned int points = compter_points(liste);
	std::cout << points;
	// Libération de l'espace mémoire de la liste
	supprimer(liste);
}

// Main du deuxième sprint.
void sprint2() {
	// Déclaration de la liste
	Liste_mot liste;
	// Déclaration d'un mot temporaire qui devra contenir le premier mot de
	// la deuxième ligne si il n'y a pas de retour à la ligne après '*' 
	Mot tmp = "null";
	// Initialisation en mémoire de la liste
	initialiser_liste_mot(liste, 3);
	// Enregistrement dans la liste des mots entrés en enlevant les doublons
	getMots_trie(liste, tmp);
	// Tri de la liste
	trie(liste);
	// Affichage des éléments de a liste
	afficher(liste, true);
	// Libération de la mémoire et suppression de la liste
	supprimer(liste);
}

// Main du troisième sprint.
void sprint3() {
	// D�claration des deux listes utilis�es 
	Liste_mot liste1;
	Liste_mot liste2;
	// Déclaration d'un mot temporaire qui devra contenir le premier mot de
	// la deuxième ligne si il n'y a pas de retour à la ligne après '*' 
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

// Main du quatrième sprint.
void sprint4() {
	// Initialisation et allocation mémoire des listes
	Liste_mot liste1;
	Liste_mot liste_result;
	initialiser_liste_mot(liste1, 20);
	initialiser_liste_mot(liste_result, 20);
	// Enregistrement dans la liste1 des mots entrés
	getMots(liste1);
	// Vérifie si les mots entrés sont en commun avec la lste1, si oui, enregistrement dans liste_result
	test_mots_communs_cout(liste1, liste_result);
	// Tri de la liste des mots en commun
	trie(liste_result);
	// Affichage des mots de la liste des mots en commun.
	afficher(liste_result, true);
	// Suppression et libération de la mémoire des listes de mots
	supprimer(liste1);
	supprimer(liste_result);
}

// Main du cinquième sprint.
void sprint5() {
	// Déclaration d'une liste de listes de mots
	Liste_de_listes_mot liste_principale;
	// Déclaration de la liste qui contiendra les mots en commun des listes
	Liste_mot liste_result;
	// Initialisation des deux listes
	initialiser_liste(liste_principale, 5);
	initialiser_liste_mot(liste_result, 5);
	// Enregistrement des listes entrées dans la liste de listes
	get_listes(liste_principale);
	// Vérification des mots en commun dans les listes
	check_communs_2_listes(liste_principale, liste_result);
	// Tri et suppression des doublons de la liste des mots en commun
	trie(liste_result);
	rm_doublons(liste_result);
	// Affichage des mots de la liste contenant les mots en commun des autres listes
	afficher(liste_result, false);
	// Suppression et désallocation en mémore des listes
	supprimer(liste_result);
	supprimer_liste_de_listes(liste_principale);
}

// Main du sixième sprint.
void sprint6(){
	// Déclaration de la liste des mots qui seront comptés
	Liste_mot liste_result;
	// Déclaration du plateau de lettres
	plateau plate;
	
	// Initialisation en mémoire de la liste résultat et du plateau
	initialiser_liste_mot(liste_result, 50);
	//initialiser_plateau(plate, 2);
	// Enregistrement des lettres du plateau
	get_plateau(plate);
	// Enregistrement de tous les mots trouvables dans le plateau dans la liste résultat
	getMots_plate(plate, liste_result);
	// Tri et affichage de la liste résultat
	trie(liste_result);
	afficher(liste_result, false);
	// Suppression et désallocation mémoire des listes
	supprimer(liste_result);
	//supprimer_plateau(plate);
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
