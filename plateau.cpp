#include <string>
#include "boggle.h"

void initialiser_plateau(plateau& plateau_a_init, unsigned int taille){
    plateau_a_init.lettre = new char*[taille];
    plateau_a_init.visiste = new bool*[taille];
    for (unsigned int i=0; i<taille; i++){
        plateau_a_init.lettre[i] = new char[taille];
        plateau_a_init.visiste[i] = new bool[taille];
    }
    plateau_a_init.taille = taille;
    init_nil(plateau_a_init);
}

void supprimer_plateau(plateau& plateau_to_delete) {
    for (unsigned int i = 0; i < plateau_to_delete.taille; i++) {
        delete[] plateau_to_delete.lettre[i];
        delete[] plateau_to_delete.visiste[i];
    }
    delete[] plateau_to_delete.lettre;
    delete[] plateau_to_delete.visiste;
}

void init_nil(plateau& plate) {
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            plate.lettre[i][j] = ' ';
            plate.visiste[i][j] = false;
        }
    }
}

void init_false(plateau& plate) {
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            plate.visiste[i][j] = false;
        }
    }
}


void get_plateau(plateau& plate) {
    std::string word;
    std::getline(std::cin, word);
    ajouter_ligne_plateau(plate, word);

}

void ajouter_ligne_plateau(plateau& plate, std::string& word) {
    unsigned int x = 0, y = 0;
    if (plate.lettre[plate.taille][plate.taille] == ' '){
        ajout_lignes_colonnes(plate);
    }

    for (unsigned int i = 0; i < word.length(); i++) {
        if (x > plate.taille | y > plate.taille) {
            ajout_lignes_colonnes(plate);
        }
        if (word.compare(i, 1, " ") != 0) {
            plate.lettre[x][y] = word[i];
            y += 1;
        }
        else {
            x += 1;
            y = 0;
        }
    }
}

void ajout_lignes_colonnes(plateau& plate){
    plateau new_plate;
    initialiser_plateau(new_plate, plate.taille * 2);
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            new_plate.lettre[i][j] = plate.lettre[i][j];
        }
    }
    supprimer_plateau(plate);
    plate = new_plate;
}

bool recherche(plateau& plate, Mot& word) {
    coords coord;
    for (coord.x = 0; coord.x < plate.taille; coord.x++) {
        for (coord.y= 0; coord.y < plate.taille; coord.y++) {
            plate.visiste[coord.x][coord.y] = false;
            if (sous_recherche(word, 0, plate, coord))
                return true;
        }
    }
    return false;
}

bool sous_recherche(Mot& word, int pos, plateau& plate, coords coord) {
    if (pos >= strlen(word))
        return false;
    if (coord.x >= plate.taille | coord.y >= plate.taille)
        return false;
    if (plate.lettre[coord.x][coord.y] != word[pos])
        return false;
    if (plate.visiste[coord.x][coord.y])
        return false;
    coords coord_test;
    plate.visiste[coord.x][coord.y] = true;
    for (coord_test.x = 0; coord_test.x < plate.taille; coord_test.x++) {
        for (coord_test.y = 0; coord_test.y < plate.taille; coord_test.y++) {
            if (verif_adjacence(plate, coord, coord_test)){
                if (sous_recherche(word, pos+1, plate, coord_test)){
                    return true;
                }
            }
        }
    }
    plate.visiste[coord.x][coord.y] = false;
    return false;

}

bool verif_adjacence(plateau& plate, coords coord, coords coord_to_test) {
    if (coord_to_test.x < 0 | coord_to_test.y < 0 | coord_to_test.x >= plate.taille | coord_to_test.y >= plate.taille)
        return false;
    if (-1 <= coord.x - coord_to_test.x <= 1 && -1 <= coord.y - coord_to_test.y <= 1)
        return true;
}

Liste_mot check_liste_dans_plateau(Liste_mot liste, plateau& plate) {
    Liste_mot liste_result;
    initialiser_liste_mot(liste_result, 25);
    for (unsigned int i = 0; i < liste.nb_mots; i++) {
        if (strcmp(liste.Liste_Mot[i], "NULL") != 0)
            recherche(plate, liste.Liste_Mot[i]);
    }

}