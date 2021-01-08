#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <iomanip>
#include "mot.h"

// Structure d'une liste de mots. Contient également le nombre de mots qu'elle contient et sa capacité maximum.
struct Liste_mot {
	Mot* Liste_Mot;
	unsigned int nb_mots;
	unsigned int taille;
};

/** 
* @brief : Ajout de mots entrés dans une liste de mots.
* @param[in] : liste de mots dans laquelle les mots doivent être enregistrés.
* @param[in] : mot temporaire contenant le premier la liste si il n'y avait pas de retour à la ligne après '*' dans la saisée précédente.
* @param[out] tmp : mot temporaire contenant le premier mot d'une liste suivante si il n'y avait pas de retour à la ligne après '*'.
* @param[out] liste : liste actualisée avec les mots rentrés.
*/
bool getMots(Liste_mot& liste, Mot& tmp, bool tri);

/**
* @brief : Vérifie si un mot existe déjà dans une liste.
* @param[in] liste : liste dans laquelle la recherche est effectuée.
* @param[in] mot_a_verifier : mot à chercher dans la liste.
* @return : résultat de la recherche. Vrai si trouvé, faux sinon.
*/
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);

/** 
* @brief : Ajout d'un mot dans une liste de mots.
* @param[in] liste : liste dans laquelle le mot doit être ajouté.
* @param[in] word : Mot à ajouter dans la liste.
* @param[out] liste : liste de mots actualisée avec word.
*/
void ajouter_mot(Liste_mot& liste, Mot& word);

/** 
* @brief : Initialisation en mémoire d'une liste de mots.
* @param[in] liste : liste à initialiser en mémoire.
* @param[in] taille : capacité avec la liste est initialisée.
* @param[out] liste : liste maintenant initialisée en mémoire.
*/
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);

/** 
* @brief : Libération de la mémoire allouée à une liste.
* @param[in] liste : liste dont la mémoire doit être libérée.
* @param[out] liste : liste désallouée en mémoire.
*/
void supprimer(Liste_mot& liste);

/** 
* @brief : Affichage en retour des mots d'une liste de mots.
* @param[in] liste : liste dont les éléments doivent être affichés.
* @param[in]trtligne : besoin de retour à la ligne ou non après l'affichage complet.
*/
void afficher(Liste_mot& liste, bool rtrligne);

/**
* @brief : Compte les points d'une liste de mots selon les règles du Boggle.
* @param[in] liste : liste dont les points sont comptés.
*/
int compter_points(Liste_mot& liste);


/** 
* @brief : Affiche les mots de la deuxième liste qui ne sont pas présents dans la première.
* @param[in] liste1 : première liste du test.
* @param[in] liste2 : seconde liste du test.
*/
void test_presence(Liste_mot& liste1, Liste_mot& liste2);

/** 
* @brief : Enregistre les mots en commun de deux listes.
* @param[in] liste1 : première liste du test.
* @param[in] liste2 : seconde liste du test.
* @param[out] liste_result : liste dans laquelle les mots en communs sont enregistrés.
*/
void test_mots_communs(Liste_mot& liste1, Liste_mot& liste2, Liste_mot& liste_result);

/** 
* @brief : Affiche les mots en commun de deux listes.
* @param[in] liste1 : première liste du test.
* @param[in] liste2 : seconde liste du test.
*/
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste2);

/** 
* @brief : Tri dans l'ordre lexicographique des mots d'une liste.
* @param[in] liste : liste à trier.
* @param[out] liste : liste triée.
* @param[in] doublon : remplace les doublons par "NULL" si true.
* @param[in] ordre : met la liste dans l'ordre si true.
* @pre ordre ou doublon true.
*/
void trie_n(Liste_mot& liste, bool doublon, bool ordre);

/** 
* @brief : Tri dans l'ordre lexicographique des mots d'une liste.
* @param[in] liste : liste à trier.
* @param[out] liste : liste triée.
* @param[in] doublon : remplace les doublons par "NULL" si true.
* @param[in] ordre : met la liste dans l'ordre si true.
* @pre ordre ou doublon true.
*/
void trie(Liste_mot& liste);

/** 
* @brief échange la position de deux éléments dans une liste de mots.
* @param[in] liste : liste dans alquelle les éléments doivent être échangés.
* @param[in] i : position du premier élément dans la liste.
* @param[in] j : position du deuxième élément dans la liste.
* @param[out] liste : liste avec les deux éléments échangés.
*/
void swap(Liste_mot& liste, unsigned int i, unsigned int j);

/** 
* @brief : Supprime les doublons d'une liste.
* @param[in] liste : liste dans laquelle les doublons seront supprimés.
* @param[out] liste : liste sans doublons.
*/
void rm_doublons(Liste_mot& liste);