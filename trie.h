#pragma once

#include "liste_mot.h"

/** brief : Tri dans l'ordre lexicographique des mots d'une liste.
* [in] liste : liste � trier.
* [out] liste : liste tri�e.*/
void trie(Liste_mot& liste);

/** brief : �change la position de deux �l�ments dans une liste de mots.
* [in] liste : liste dans alquelle les �l�ments doivent �tre �chang�s.
* [in] i : position du premier �l�ment dans la liste.
* [in] j : position du deuxi�me �l�ment dans la liste.
* [out] liste : liste avec les deux �l�ments �chang�s.*/
void swap(Liste_mot& liste, unsigned int i, unsigned int j);

/** brief : Ajout de mots entr�s dans une liste de mots en enlevant les doublons.
* [in] liste : liste de mots dans laquelle les mots doivent �tre enregistr�s.
* [in] tmp : mot temporaire contenant le premier la liste si il n'y avait pas de retour � la ligne apr�s '*' dans la sais�e pr�c�dente.
* [out] tmp : mot temporaire contenant le premier mot d'une liste suivante si il n'y avait pas de retour � la ligne apr�s '*'.
* [out] liste : liste actualis�e avec les mots rentr�s.*/
bool getMots_trie(Liste_mot& liste, Mot& tmp);

/** brief : V�rifie si un mot existe d�j� dans une liste.
* [in] liste : liste dans laquelle la recherche est effectu�e.
* [in] mot_a_verifier : mot � chercher dans la liste.
* return : r�sultat de la recherche. Vrai si trouv�, faux sinon.*/
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);

/** brief : Supprime les doublons d'une liste.
* [in] liste : liste dans laquelle les doublons seront supprim�s.
* [out] liste : liste sans doublons.*/
void rm_doublons(Liste_mot& liste);