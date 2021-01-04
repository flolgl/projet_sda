#include "liste_mot.h"

/** 
* @return true si liste est vide, false si au moins 1 mot
*/
bool getMots(Liste_mot& liste) {
	//std::cout << "ici";
	Mot word;
	bool continuer = true;

	std::cin >> word;

	if (strcmp(word,"*") == 0){
		return true;
	}

	while (continuer) {
		//std::cout << " aussi ici";

		// Pas de vérification de doublon pour sprint 1
		/* 
		if (mot_existant(liste, word) == false){
			ajouter_mot(liste, word);
		}
		*/
		ajouter_mot(liste, word);


		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
	return false;

}



void ajouter_mot(Liste_mot& liste, Mot& word) {

	if  (liste.taille == liste.nb_mots){
		Mot* nouveau_liste_word = new Mot[liste.taille*2];


		for (unsigned int i = 0; i < liste.nb_mots; i++)
			strcpy(nouveau_liste_word[i], liste.Liste_Mot[i]);

		delete[] liste.Liste_Mot;
		liste.Liste_Mot = nouveau_liste_word;
		liste.taille = liste.taille * 2;
	}
	strcpy(liste.Liste_Mot[liste.nb_mots], word);
	liste.nb_mots++;
}




void initialiser_liste_mot(Liste_mot& liste, unsigned int taille) {
	liste.nb_mots = 0;
	liste.Liste_Mot = new Mot[taille];
	liste.taille = taille;
}

void supprimer(Liste_mot& liste) {
	delete[] liste.Liste_Mot;
}

void afficher(Liste_mot& liste, bool rtrligne) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.Liste_Mot[i], "NULL") != 0)
			std::cout << liste.Liste_Mot[i] << std::endl;
	}
	std::cout << "*";
	if (rtrligne)
		std::cout << std::endl;
}