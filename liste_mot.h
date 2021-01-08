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

/** brief : Ajout de mots entrés dans une liste de mots.
* [in] liste : liste de mots dans laquelle les mots doivent être enregistrés.
* [out] liste : liste actualisée avec les mots rentrés.*/
bool getMots(Liste_mot& liste);

/** brief : Ajout d'un mot dans une liste de mots.
* [in] liste : liste dans laquelle le mot doit être ajouté.
* [in] word : Mot à ajouter dans la liste.
* [out] liste : liste de mots actualisée avec word.*/
void ajouter_mot(Liste_mot& liste, Mot& word);

/** brief : Initialisation en mémoire d'une liste de mots.
* [in] liste : liste à initialiser en mémoire.
* [in] taille : capacité avec la liste est initialisée.
* [out] liste : liste maintenant initialisée en mémoire.*/
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);

/** brief : Libération de la mémoire allouée à une liste.
* [in] liste : liste dont la mémoire doit être libérée.
* [out] liste : liste désallouée en mémoire.*/
void supprimer(Liste_mot& liste);

/** brief : Affichage en retour des mots d'une liste de mots.
* [in] liste : liste dont les éléments doivent être affichés.
* [in]trtligne : besoin de retour à la ligne ou non après l'affichage complet.*/
void afficher(Liste_mot& liste, bool rtrligne);