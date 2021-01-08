#pragma once
#include "liste_mot.h"

// Structure d'un plateau de lettres. Contient un tableau de pointeurs des lettres du plateau, un tableau de pointeurs de bool�ens
// qui renseignent si la case lettre correspondante (en termes de coordonn�es) a �t� visit�e et la taille des lignes et colonnes du plateau.
struct plateau {
    char** lettre;
    bool** visitee;
    unsigned int taille;
};

// Structure de coordonn�es. Contient la coordonn�e en abscisse et celle en ordonn�e.
struct coords {
    unsigned int x;
    unsigned int y;
};

// brief : Initialisation en m�moire d'un plateau de lettres.
// [in] plateau_a_init ! plateau de lettres qui doit �tre initialis�e en m�moire.
// [in] taille : taille des colonnes et lignes que le plateau devra contenir.
// [out] plateau_a_init : plateau de lettres initialis� en m�moire.
void initialiser_plateau(plateau& plateau_a_init, unsigned int taille);

// brief : Lib�ration de l'espace m�moire d'un plateua de lettres.
// [in] plateau_to_delete : plateau de mots dont l'espace m�moire doit �tre lib�br�.
// [out] plateau_to_delete : plateau de mots dont l'espace m�moire a �t� lib�br�.
void supprimer_plateau(plateau& plateau_to_delete);

// brief : Initialisation des tableaux d'un plateau
// [out] plate : plateau � initialiser
void init_nil(plateau& plate);

// brief : Attribution des lettres d'un plateau.
// [in] plate : plateau dont les lettres doivent �tre initialis�es.
// [out] plate : plateau initialis�e avec les lettres entr�es.
void get_plateau(plateau& plate);

void ajouter_ligne_plateau(plateau& plate, std::string& word);
void ajout_lignes_colonnes(plateau& plate);

// brief : Recherche d'un mot dans un plateau. Renvoie vrai si trouv�, faux sinon.
// [in] plate : plateau dans lequel le mot doit �tre cherch�.
// [in] word : mot � chercher dans le plateau.
// return : �tat du r�sultat de la recherche. Vrai si trouv�, faux sinon.
bool recherche(plateau& plate, Mot& word);

// brief : sous-instance de la fonction de recherche d'un mot dans un plateau.
// V�rifie pour une coordon�e donn�e et une lettre d'un mot donn� si il sera possible
// de le construire en passant par les coordonn�es donn�es.
// Recherche � partir de coordonn�es pr�cises.
// Renvoie vrai si trouv�, faux sinon.
// [in] word : mot recherch�.
// [in] pos : position de la lettre du mot sur laquelle on se trouve.
// [in] plate : plateau dans lequel on effectue les recherches.
// [in] coord : coordonn�es pour lesquelles la recherche est effectu�e.
// return : �tat du r�sultat de la recherche. Vrai si trouv�, faux sinon.
bool sous_recherche(Mot& word, int pos, plateau& plate, coords& coord);

// brief : V�rifie si deux coordonn�es sont adjacentes
// [in] coord : premi�re coordn�es � v�rifier
// [in] coord_to_test : deuxi�me coordonn�es � tester
bool verif_adjacence(coords& coord, coords& coord_to_test);

void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result);
// brief : V�rifie la pr�sence des mots d'une liste dans un plateau.
// [in] liste : liste dont les mots sont cherch�s dans le plateau.
// [in] plate : plateau dans lequel on cherche les mots.
// [out] liste_result : liste des mots qui ont �t� trouv�s dans le plateau.
void getMots_plate(plateau& plate, Liste_mot& liste_result);

// brief : V�rifie si un mot peut �tre trouv� dans un plateau de lettres.
// [in] mot : mot recherch�
// [in] plate : plateau dans lequel chercher
// [in] liste_result : liste de mots pour v�rifier si word existe d�j�
void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result);


// brief : V�rifie si les coordonn�es sont pla�able dans les plateaux de Boggle.
// [in] coord : coordonn�es � tester.
// return : r�sultat du test. Vrai si valid�, faux sinon.
bool verif_limite(coords& coord);