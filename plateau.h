#pragma once
#include "liste_mot.h"

struct plateau {
    char** lettre;
    bool** visitee;
    unsigned int taille;
};

struct coords {
    unsigned int x;
    unsigned int y;
};

void initialiser_plateau(plateau& plateau_a_init, unsigned int taille);
void supprimer_plateau(plateau& plateau_to_delete);
void init_nil(plateau& plate);
void get_plateau(plateau& plate);
void ajouter_ligne_plateau(plateau& plate, std::string& word);
void ajout_lignes_colonnes(plateau& plate);
bool recherche(plateau& plate, Mot& word);
bool sous_recherche(Mot& word, int pos, plateau& plate, coords& coord);
bool verif_adjacence(plateau& plate, coords& coord, coords& coord_to_test);
void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result);
void getMots_plate(plateau& plate, Liste_mot& liste_result);
void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result);
bool verif_limite(coords& coord);