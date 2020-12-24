#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <iomanip>

#include "CompteurPoints(1).h"


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


bool mot_existant(Liste_mot& liste, Mot mot_a_verifier) {
	for (int i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.Liste_Mot[i], mot_a_verifier) == 0) {
			//std::cout << "Mot existant";
			return true;
		}
	}
	return false;
}


int compter_points(Liste_mot& liste){
	int nb_points = 0;
	size_t taille;
	for (int i = 0; i < liste.nb_mots; i++) {
		taille = strnlen(liste.Liste_Mot[i], LGMOT+1);
		switch (taille){
			case 0: break;
			case 1: break;
			case 2: break;
			case 3: nb_points += 1; break;
			case 4: nb_points += 1; break;
			case 5: nb_points += 2; break;
			case 6: nb_points += 3; break;
			case 7: nb_points += 5; break;
			default: nb_points += 11;
		}
	}

	return nb_points;
}

void initialiser_liste_mot(Liste_mot& liste, unsigned int taille) {
	liste.nb_mots = 0;
	liste.Liste_Mot = new Mot[taille];
	liste.taille = taille;
}

void supprimer(Liste_mot& liste) {
	delete[] liste.Liste_Mot;
}