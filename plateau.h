#pragma once
#include "liste_mot.h"

// Structure d'un plateau de lettres. Contient un tableau de pointeurs des lettres du plateau, un tableau de pointeurs de bool�ens
// qui renseignent si la case lettre correspondante (en termes de coordonn�es) a �t� visit�e et la taille des lignes et colonnes du plateau.
struct plateau {
    char lettre[4][4];
    bool visitee[4][4];
    unsigned int taille;
};

// Structure de coordonn�es. Contient la coordonn�e en abscisse et celle en ordonn�e.
struct coords {
    unsigned int x;
    unsigned int y;
};


/** 
* @brief : Attribution des lettres d'un plateau.
* @param[in] plate : plateau dont les lettres doivent �tre initialis�es.
* @param[out] plate : plateau initialis�e avec les lettres entr�es.
*/
void get_plateau(plateau& plate);


/** 
* @brief : Recherche d'un mot dans un plateau. Renvoie vrai si trouv�, faux sinon.
* @param[in] plate : plateau dans lequel le mot doit �tre cherch�.
* @param[in] word : mot � chercher dans le plateau.
* @return : �tat du r�sultat de la recherche. Vrai si trouv�, faux sinon.
*/
bool recherche(plateau& plate, Mot& word);

/** 
* @brief : sous-instance de la fonction de recherche d'un mot dans un plateau.
* V�rifie pour une coordon�e donn�e et une lettre d'un mot donn� si il sera possible
* de le construire en passant par les coordonn�es donn�es.
* Recherche � partir de coordonn�es pr�cises.
* Renvoie vrai si trouv�, faux sinon.
* @param[in] word : mot recherch�.
* @param[in] pos : position de la lettre du mot sur laquelle on se trouve.
* @param[in] plate : plateau dans lequel on effectue les recherches.
* @param[in] coord : coordonn�es pour lesquelles la recherche est effectu�e.
* @return : �tat du r�sultat de la recherche. Vrai si trouv�, faux sinon.
*/
bool sous_recherche(Mot& word, unsigned int pos, plateau& plate, coords& coord);

/** 
* @brief V�rifie si deux coordonn�es sont adjacentes
* @param[in] coord : premi�re coordn�es � v�rifier
* @param[in] coord_to_test : deuxi�me coordonn�es � tester
*/
bool verif_adjacence(coords& coord, coords& coord_to_test);

/** @brief V�rifie si les mots d'une liste sont dans un plateau
* @param[in] liste : liste pour laquelle on effectue la recherche
* @param[in] plate : plateau dans lequel on effectue la recherche
* @param[out] liste_result : liste dans laquelle les mots pr�sents dans le plateau seront enregistr�s
*/
void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result);

/** 
* @brief V�rifie la pr�sence des mots d'une liste dans un plateau.
* @param[in] liste : liste dont les mots sont cherch�s dans le plateau.
* @param[in] plate : plateau dans lequel on cherche les mots.
* @param[out] liste_result : liste des mots qui ont �t� trouv�s dans le plateau.
*/
void getMots_plate(plateau& plate, Liste_mot& liste_result);

/** 
* @brief V�rifie si un mot peut �tre trouv� dans un plateau de lettres.
* @param[in] mot : mot recherch�
* @param[in] plate : plateau dans lequel chercher
* @param[in] liste_result : liste de mots pour v�rifier si word existe d�j�
*/
void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result);


/** 
* @brief V�rifie si les coordonn�es sont pla�able dans les plateaux de Boggle.
* @param[in] coord : coordonn�es � tester.
* @return : r�sultat du test. Vrai si valid�, faux sinon.
*/
bool verif_limite(coords& coord);