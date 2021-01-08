#pragma once

#include "liste_mot.h"

/** brief : Tri dans l'ordre lexicographique des mots d'une liste.
* [in] liste : liste à trier.
* [out] liste : liste triée.*/
void trie(Liste_mot& liste);

/** brief : échange la position de deux éléments dans une liste de mots.
* [in] liste : liste dans alquelle les éléments doivent être échangés.
* [in] i : position du premier élément dans la liste.
* [in] j : position du deuxième élément dans la liste.
* [out] liste : liste avec les deux éléments échangés.*/
void swap(Liste_mot& liste, unsigned int i, unsigned int j);

/** brief : Ajout de mots entrés dans une liste de mots en enlevant les doublons.
* [in] liste : liste de mots dans laquelle les mots doivent être enregistrés.
* [in] tmp : mot temporaire contenant le premier la liste si il n'y avait pas de retour à la ligne après '*' dans la saisée précédente.
* [out] tmp : mot temporaire contenant le premier mot d'une liste suivante si il n'y avait pas de retour à la ligne après '*'.
* [out] liste : liste actualisée avec les mots rentrés.*/
bool getMots_trie(Liste_mot& liste, Mot& tmp);

/** brief : Vérifie si un mot existe déjà dans une liste.
* [in] liste : liste dans laquelle la recherche est effectuée.
* [in] mot_a_verifier : mot à chercher dans la liste.
* return : résultat de la recherche. Vrai si trouvé, faux sinon.*/
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);

/** brief : Supprime les doublons d'une liste.
* [in] liste : liste dans laquelle les doublons seront supprimés.
* [out] liste : liste sans doublons.*/
void rm_doublons(Liste_mot& liste);