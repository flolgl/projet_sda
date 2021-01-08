#pragma once
#include "liste_mot.h"

// Structure d'un plateau de lettres. Contient un tableau de pointeurs des lettres du plateau, un tableau de pointeurs de booléens
// qui renseignent si la case lettre correspondante (en termes de coordonnées) a été visitée et la taille des lignes et colonnes du plateau.
struct plateau {
    char** lettre;
    bool** visitee;
    unsigned int taille;
};

// Structure de coordonnées. Contient la coordonnée en abscisse et celle en ordonnée.
struct coords {
    unsigned int x;
    unsigned int y;
};

// brief : Initialisation en mémoire d'un plateau de lettres.
// [in] plateau_a_init ! plateau de lettres qui doit être initialisée en mémoire.
// [in] taille : taille des colonnes et lignes que le plateau devra contenir.
// [out] plateau_a_init : plateau de lettres initialisé en mémoire.
void initialiser_plateau(plateau& plateau_a_init, unsigned int taille);

// brief : Libération de l'espace mémoire d'un plateua de lettres.
// [in] plateau_to_delete : plateau de mots dont l'espace mémoire doit être libébré.
// [out] plateau_to_delete : plateau de mots dont l'espace mémoire a été libébré.
void supprimer_plateau(plateau& plateau_to_delete);

// brief : Initialisation des tableaux d'un plateau
// [out] plate : plateau à initialiser
void init_nil(plateau& plate);

// brief : Attribution des lettres d'un plateau.
// [in] plate : plateau dont les lettres doivent être initialisées.
// [out] plate : plateau initialisée avec les lettres entrées.
void get_plateau(plateau& plate);

void ajouter_ligne_plateau(plateau& plate, std::string& word);
void ajout_lignes_colonnes(plateau& plate);

// brief : Recherche d'un mot dans un plateau. Renvoie vrai si trouvé, faux sinon.
// [in] plate : plateau dans lequel le mot doit être cherché.
// [in] word : mot à chercher dans le plateau.
// return : état du résultat de la recherche. Vrai si trouvé, faux sinon.
bool recherche(plateau& plate, Mot& word);

// brief : sous-instance de la fonction de recherche d'un mot dans un plateau.
// Vérifie pour une coordonée donnée et une lettre d'un mot donné si il sera possible
// de le construire en passant par les coordonnées données.
// Recherche à partir de coordonnées précises.
// Renvoie vrai si trouvé, faux sinon.
// [in] word : mot recherché.
// [in] pos : position de la lettre du mot sur laquelle on se trouve.
// [in] plate : plateau dans lequel on effectue les recherches.
// [in] coord : coordonnées pour lesquelles la recherche est effectuée.
// return : état du résultat de la recherche. Vrai si trouvé, faux sinon.
bool sous_recherche(Mot& word, int pos, plateau& plate, coords& coord);

// brief : Vérifie si deux coordonnées sont adjacentes
// [in] coord : première coordnées à vérifier
// [in] coord_to_test : deuxième coordonnées à tester
bool verif_adjacence(coords& coord, coords& coord_to_test);

void check_liste_dans_plateau(Liste_mot& liste, plateau& plate, Liste_mot& liste_result);
// brief : Vérifie la présence des mots d'une liste dans un plateau.
// [in] liste : liste dont les mots sont cherchés dans le plateau.
// [in] plate : plateau dans lequel on cherche les mots.
// [out] liste_result : liste des mots qui ont été trouvés dans le plateau.
void getMots_plate(plateau& plate, Liste_mot& liste_result);

// brief : Vérifie si un mot peut être trouvé dans un plateau de lettres.
// [in] mot : mot recherché
// [in] plate : plateau dans lequel chercher
// [in] liste_result : liste de mots pour vérifier si word existe déjà
void check_mot_dans_plateau(Mot& mot, plateau& plate, Liste_mot& liste_result);


// brief : Vérifie si les coordonnées sont plaçable dans les plateaux de Boggle.
// [in] coord : coordonnées à tester.
// return : résultat du test. Vrai si validé, faux sinon.
bool verif_limite(coords& coord);