#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <iomanip>
#include "mot.h"

// Structure d'une liste de mots. Contient �galement le nombre de mots qu'elle contient et sa capacit� maximum.
struct Liste_mot {
	Mot* Liste_Mot;
	unsigned int nb_mots;
	unsigned int taille;
};

/** brief : Ajout de mots entr�s dans une liste de mots.
* [in] liste : liste de mots dans laquelle les mots doivent �tre enregistr�s.
* [out] liste : liste actualis�e avec les mots rentr�s.*/
bool getMots(Liste_mot& liste);

/** brief : Ajout d'un mot dans une liste de mots.
* [in] liste : liste dans laquelle le mot doit �tre ajout�.
* [in] word : Mot � ajouter dans la liste.
* [out] liste : liste de mots actualis�e avec word.*/
void ajouter_mot(Liste_mot& liste, Mot& word);

/** brief : Initialisation en m�moire d'une liste de mots.
* [in] liste : liste � initialiser en m�moire.
* [in] taille : capacit� avec la liste est initialis�e.
* [out] liste : liste maintenant initialis�e en m�moire.*/
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);

/** brief : Lib�ration de la m�moire allou�e � une liste.
* [in] liste : liste dont la m�moire doit �tre lib�r�e.
* [out] liste : liste d�sallou�e en m�moire.*/
void supprimer(Liste_mot& liste);

/** brief : Affichage en retour des mots d'une liste de mots.
* [in] liste : liste dont les �l�ments doivent �tre affich�s.
* [in]trtligne : besoin de retour � la ligne ou non apr�s l'affichage complet.*/
void afficher(Liste_mot& liste, bool rtrligne);