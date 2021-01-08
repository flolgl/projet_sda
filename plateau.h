#pragma once
#include "liste_mot.h"

// Structure d'un plateau de lettres. Contient un tableau de pointeurs des lettres du plateau, un tableau de pointeurs de booléens
// qui renseignent si la case lettre correspondante (en termes de coordonnées) a été visitée et la taille des lignes et colonnes du plateau.
struct plateau {
    char lettre[4][4];
    bool visitee[4][4];
    unsigned int taille;
};

// Structure de coordonnées. Contient la coordonnée en abscisse et celle en ordonnée.
struct coords {
    unsigned int x;
    unsigned int y;
};


/** 
* @brief : Attribution des lettres d'un plateau.
* @param[in] plate : plateau dont les lettres doivent être initialisées.
* @param[out] plate : plateau initialisée avec les lettres entrées.
*/
void get_plateau(plateau& plate);


/** 
* @brief : Recherche d'un mot dans un plateau. Renvoie vrai si trouvé, faux sinon.
* @param[in] plate : plateau dans lequel le mot doit être cherché.
* @param[in] word : mot à chercher dans le plateau.
* @return : état du résultat de la recherche. Vrai si trouvé, faux sinon.
*/
bool recherche(plateau& plate, Mot& word);

/** 
* @brief : sous-instance de la fonction de recherche d'un mot dans un plateau.
* Vérifie pour une coordonée donnée et une lettre d'un mot donné si il sera possible
* de le construire en passant par les coordonnées données.
* Recherche à partir de coordonnées précises.
* Renvoie vrai si trouvé, faux sinon.
* @param[in] word : mot recherché.
* @param[in] pos : position de la lettre du mot sur laquelle on se trouve.
* @param[in] plate : plateau dans lequel on effectue les recherches.
* @param[in] coord : coordonnées pour lesquelles la recherche est effectuée.
* @return : état du résultat de la recherche. Vrai si trouvé, faux sinon.
*/
bool sous_recherche(Mot& word, unsigned int pos, plateau& plate, coords& coord);

/** 
* @brief Vérifie si deux coordonnées sont adjacentes
* @param[in] coord : première coordnées à vérifier
* @param[in] coord_to_test : deuxième coordonnées à tester
*/
bool verif_adjacence(coords& coord, coords& coord_to_test);

/** @brief Vérifie si les mots d'une liste sont dans un plateau
* @param[in] liste : liste pour laquelle on effectue la recherche
* @param[in] plate : plateau dans lequel on effectue la recherche
* @param[out] liste_result : liste dans laquelle les mots présents dans le plateau seront enregistrés
*/
void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result);

/** 
* @brief Vérifie la présence des mots d'une liste dans un plateau.
* @param[in] liste : liste dont les mots sont cherchés dans le plateau.
* @param[in] plate : plateau dans lequel on cherche les mots.
* @param[out] liste_result : liste des mots qui ont été trouvés dans le plateau.
*/
void getMots_plate(plateau& plate, Liste_mot& liste_result);

/** 
* @brief Vérifie si un mot peut être trouvé dans un plateau de lettres.
* @param[in] mot : mot recherché
* @param[in] plate : plateau dans lequel chercher
* @param[in] liste_result : liste de mots pour vérifier si word existe déjà
*/
void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result);


/** 
* @brief Vérifie si les coordonnées sont plaçable dans les plateaux de Boggle.
* @param[in] coord : coordonnées à tester.
* @return : résultat du test. Vrai si validé, faux sinon.
*/
bool verif_limite(coords& coord);