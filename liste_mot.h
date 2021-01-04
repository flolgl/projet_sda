#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <iomanip>
#include "mot.h"

struct Liste_mot {
	Mot* Liste_Mot;
	unsigned int nb_mots;
	unsigned int taille;
};


bool getMots(Liste_mot& liste);
void ajouter_mot(Liste_mot& liste, Mot& word);
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);
void supprimer(Liste_mot& liste);
void afficher(Liste_mot& liste, bool rtrligne);