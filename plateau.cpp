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