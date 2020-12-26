#include "liste_mot.h"


void getMots(Liste_mot& liste) {
	//std::cout << "ici";
	Mot word;
	bool continuer = true;

	std::cin >> word;

	if (strcmp(word,"*") == 0)
		continuer = false;

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
}



void ajouter_mot(Liste_mot& liste, Mot word) {

	if  (liste.taille == liste.nb_mots){
		Mot* nouveau_liste_word = new Mot[liste.nb_mots*2];


		for (unsigned int i = 0; i < liste.nb_mots; i++)
			strcpy(nouveau_liste_word[i], liste.Liste_Mot[i]);

		delete[] liste.Liste_Mot;
		liste.Liste_Mot = nouveau_liste_word;
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

void afficher(Liste_mot& liste) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		std::cout << liste.Liste_Mot[i] << std::endl;
	}
	std::cout << "*";
}