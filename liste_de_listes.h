#pragma once

#include "liste_mot.h"

struct Liste_de_listes_mot {
	Liste_mot* Liste_de_listes;
	unsigned int nb_listes;
	unsigned int taille;
};

void initialiser_liste(Liste_de_listes_mot& liste, unsigned int taille);
void ajouter_liste(Liste_de_listes_mot& liste_principale, Liste_mot& liste_to_add);
void get_listes(Liste_de_listes_mot& liste_principale);
void check_communs_2_listes(Liste_de_listes_mot& liste_principale, Liste_mot& liste_result);
void supprimer_liste_de_listes(Liste_de_listes_mot& liste);
