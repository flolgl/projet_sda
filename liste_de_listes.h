/*******************************************************
Nom ......... : liste_de_listes.h
Auteurs ..... : Florian LE GAL & Raphaël BOUCHEZ
Version ..... : 1.Release
********************************************************/
#pragma once

#include "liste_mot.h"

// Structure d'une liste contenant des listes de mots. Contient également le nombre de
// listes actuellement enregistrée ainsi que le nombre maximum de listes enregistrables.
struct Liste_de_listes_mot {
	Liste_mot* Liste_de_listes;
	unsigned int nb_listes;
	unsigned int taille;
};

/** Prototypes des fonctions concernant les listes de listes.
* @brief Initialisation en mémoire d'une liste de liste de mots dynamique.
* @param[in] liste : nom de la liste à initialiser.
* @param[in] taille : nombre de listes enrgesitrables.
* @param[out] liste : liste initialisée en tant que tableau dynamique.
*/
void initialiser_liste(Liste_de_listes_mot& liste, unsigned int taille);

/** 
* @brief Ajout d'une liste de mots dans une liste les contenant.
* @param[in] liste_principale : liste de listes dans laquelle il faut ajouter la liste de mots.
* @param[in] liste_to_add : liste à ajouter dans la liste_principale.
* @param[out] liste_principale : liste de listes de mots actualisée avec la nouvelle liste de mots.
*/
void ajouter_liste(Liste_de_listes_mot& liste_principale, Liste_mot& liste_to_add);

/** 
* @brief Déclaration des listes de mots à placer dans une liste les contenant.
* @param[in] liste_principale : liste de listes de mots dans laquelle on ajoute les listes de mots.
* @param[out] liste_principale : liste de listes de mots actualisée avec les listes de mots entrées.
*/
void get_listes(Liste_de_listes_mot& liste_principale);

/** 
* @brief Vérification des mots en communs dans un ensemble de listes.
* [in] liste_princiapale : liste de listes de mots dans laquelle les mots communs doivent être trouvés.
* [out] liste result : liste actualisée avec les résultats.
*/
void check_communs_2_listes(Liste_de_listes_mot& liste_principale, Liste_mot& liste_result);

/** 
* @brief Libération de la mémoire d'une liste de listes de mots.
* @param[in] liste : liste de listes de mots dont la mémoire doit être libérée.
* @param[out] liste : liste de listes de mots désallouée en mémoire.
*/
void supprimer_liste_de_listes(Liste_de_listes_mot& liste);
