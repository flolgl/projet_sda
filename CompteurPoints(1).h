#pragma once

const int LGMOT = 30;
typedef char Mot[LGMOT + 1];

struct Liste_mot {
	Mot* Liste_Mot;
	unsigned int nb_mots;
	unsigned int taille;
};


void getMots(Liste_mot& liste);
void ajouter_mot(Liste_mot& liste, Mot word);
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);
int compter_points(Liste_mot& liste);
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);
void supprimer(Liste_mot& liste);