#pragma once

#include "liste_mot.h"
#include "trie.h"

/** brief : Affiche les mots de la deuxième liste qui ne sont pas présents dans la première.
* [in] liste1 : première liste du test.
* [in] liste2 : seconde liste du test.*/
void test_presence(Liste_mot& liste1, Liste_mot& liste2);

/** brief : Enregistre les mots en commun de deux listes.
* [in] liste1 : première liste du test.
* [in] liste2 : seconde liste du test.
* [out] liste_result : liste dans laquelle les mots en communs sont enregistrés.*/
void test_mots_communs(Liste_mot& liste1, Liste_mot& liste2, Liste_mot& liste_result);

/** brief : Affiche les mots en commun de deux listes.
* [in] liste1 : première liste du test.
* [in] liste2 : seconde liste du test.*/
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste2);