#include <string>
#include "plateau.h"
#include "trie.h"

void initialiser_plateau(plateau& plateau_a_init, unsigned int taille){
    //std::cout << "la taille est de: " << taille << std::endl;
    plateau_a_init.lettre = new char*[taille];
    plateau_a_init.visitee = new bool*[taille];
    for (unsigned int i=0; i<taille; i++){
        plateau_a_init.lettre[i] = new char[taille];
        plateau_a_init.visitee[i] = new bool[taille];
    }
    plateau_a_init.taille = taille;
    init_nil(plateau_a_init);
}

void supprimer_plateau(plateau& plateau_to_delete) {
    for (unsigned int i = 0; i < plateau_to_delete.taille; i++) {
        delete[] plateau_to_delete.lettre[i];
        delete[] plateau_to_delete.visitee[i];
    }
    delete[] plateau_to_delete.lettre;
    delete[] plateau_to_delete.visitee;
}

void init_nil(plateau& plate) {
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            plate.lettre[i][j] = ' ';
            plate.visitee[i][j] = false;
        }
    }
}

void init_false(plateau& plate) {
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            plate.visitee[i][j] = false;
        }
    }
}

void get_plateau(plateau& plate) {
    std::string word;
    std::cin >> std::ws;
    std::getline(std::cin, word);
    //std::cout << "la ligne: " << word << std::endl;  
    ajouter_ligne_plateau(plate, word);

}

void ajouter_ligne_plateau(plateau& plate, std::string& word) {
    unsigned int x = 0, y = 0;

    for (unsigned int i = 0; i < word.length(); i++) {
        //std::cout << word[i] << std::endl;
        if (word.compare(i, 1, " ") != 0) {

            if (y > plate.taille-1)
                ajout_lignes_colonnes(plate);

            //std::cout << "Ajout de la lettre: " << word[i] << " aux coords: x= " << x << " y= " << y << std::endl;
            plate.lettre[x][y] = word[i];
            //std::cout << "Verification: " << plate.lettre[x][y] << std::endl;
            y += 1;
        }
        else {
            if (x > plate.taille - 1)
                ajout_lignes_colonnes(plate);
            x += 1;
            y = 0;
        }
    }
}

void ajout_lignes_colonnes(plateau& plate){
    plateau new_plate;
    initialiser_plateau(new_plate, plate.taille + 1);
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
    //std::cout << std::endl << std::endl << "Taille: " <<plate.taille << std::endl << std::endl;
    init_false(plate);
    for (coord.x = 0; coord.x < plate.taille; coord.x++) {
        for (coord.y= 0; coord.y < plate.taille; coord.y++) {
            //plate.visiste[coord.x][coord.y] = false;
            if (sous_recherche(word, 0, plate, coord))
                //std::cout << "c true" << std::endl;
                return true;
        }
    }
    return false;
}

bool sous_recherche(Mot& word, int pos, plateau& plate, coords& coord) {
    //std::cout << "Comparaison: "<< plate.lettre[coord.x][coord.y] << " et " << word[pos] << std::endl;
    //std::cout << "Coordonnees x: " << coord.x << " et y: " << coord.y << std::endl;

    if (pos >= strlen(word))
        //std::cout << "true ligne 98, Mot: " << word << std::endl;
        return true;
    if ((coord.x > plate.taille - 1) | (coord.y > plate.taille - 1))
        //std::cout << "false ligne 101, Mot: " << word << std::endl;
        return false;
    if (plate.lettre[coord.x][coord.y] != word[pos])
        //std::cout << "false ligne 104, Mot: " << word << std::endl;
        return false;
    if (plate.visitee[coord.x][coord.y])
        //std::cout << "false ligne 107, Mot: " << word << std::endl;
        return false;
    coords coord_test;
    plate.visitee[coord.x][coord.y] = true;
    for (coord_test.x = 0; coord_test.x < plate.taille; coord_test.x++) {
        for (coord_test.y = 0; coord_test.y < plate.taille; coord_test.y++) {
            if (verif_adjacence(plate, coord, coord_test)){
                if (sous_recherche(word, pos+1, plate, coord_test)){
                    //std::cout << "c aussi true" << std::endl;
                    return true;
                }
            }
        }
    }
    plate.visitee[coord.x][coord.y] = false;
    return false;

}

bool verif_adjacence(plateau& plate, coords& coord, coords& coord_to_test) {
    //if ( (coord_to_test.x < 0) | (coord_to_test.y < 0) | (coord_to_test.x >= plate.taille-1) | (coord_to_test.y >= plate.taille-1))
    //    return false;
    //if ((-1 <= coord.x - coord_to_test.x <= 1) && (-1 <= coord.y - coord_to_test.y <= 1))
    //    return true;
    bool adjacenceX = false, adjacenceY  = false;
    int diffx = coord.x - coord_to_test.x, diffy = coord.y - coord_to_test.y;
    switch (diffx) {
        case -1:      
        case 0:     
        case 1: 
            adjacenceX = true;
            break;
    }    
    switch (diffy) {
        case -1:      
        case 0:     
        case 1: 
            adjacenceY = true;
            break;
    }

    if (adjacenceX && adjacenceY)
        return true;

    return false;
}

void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result) {
    for (unsigned int i = 0; i < liste.nb_mots; i++) {
        if (strcmp(liste.Liste_Mot[i], "NULL") != 0) {
            if (recherche(plate, liste.Liste_Mot[i])){
                //std::cout << "ajout mot: " << liste.Liste_Mot[i] << std::endl;
                ajouter_mot(liste_result, liste.Liste_Mot[i]);

            }
        }
    }
}

void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result) {

    if (mot_existant(liste_result, mot) == false) {
        if (recherche(plate, mot)) {
            //std::cout << "ajout mot: " << liste.Liste_Mot[i] << std::endl;
            ajouter_mot(liste_result, mot);

        }
    }
}

void getMots_plate(plateau& plate, Liste_mot& liste_result) {
    Mot word;
    bool continuer = true;

    std::cin >> word;

    if (strcmp(word, "*") == 0)
        continuer = false;

    while (continuer) {

        check_mot_dans_plateau(word, plate, liste_result);

        std::cin >> std::setw(LGMOT) >> word;
        if (strcmp(word, "*") == 0)
            continuer = false;
    }


}