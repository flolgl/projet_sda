#include "plateau.h"

void init_false(plateau& plate) {
    for (unsigned int i = 0; i < plate.taille; i++) {
        for (unsigned int j = 0; j < plate.taille; j++) {
            plate.visitee[i][j] = false;
        }
    }
}

void get_plateau(plateau& plate) {
    char lettre;
    coords coord = { 0,0 };

    while (coord.x <= 3 && coord.y <= 3) {
        std::cin >> lettre;

        plate.lettre[coord.y][coord.x] = lettre;
        plate.visitee[coord.y][coord.x] = false;
        coord.x += 1;
        if (coord.x == 4) {
            coord.x = 0;
            coord.y += 1;
        }

    }
    plate.taille = 4;
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

bool sous_recherche(Mot& word, unsigned int pos, plateau& plate, coords& coord) {
    //std::cout << "Comparaison: "<< plate.lettre[coord.x][coord.y] << " et " << word[pos] << std::endl;
    //std::cout << "Coordonnees x: " << coord.x << " et y: " << coord.y << std::endl;

    if (pos >= strlen(word))
        //std::cout << "true ligne 98, Mot: " << word << std::endl;
        return true;
    if (!verif_limite(coord))
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
            if (verif_adjacence(coord, coord_test)){
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

bool verif_adjacence(coords& coord, coords& coord_to_test) {
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

    if (recherche(plate, mot)) {
        ajouter_mot(liste_result, mot);

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

bool verif_limite(coords& coord) {
    bool tailleX = false, tailleY = false;
    switch (coord.x) {
    case 0:
    case 1:
    case 2:
    case 3: tailleX = true; break;
    }

    switch (coord.y) {
    case 0:
    case 1:
    case 2:
    case 3: tailleY = true; break;
    }

    if (tailleX && tailleY) {
        return true;
    }
    return false;
}