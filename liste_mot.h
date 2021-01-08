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

/** 
* @brief : Ajout de mots entr�s dans une liste de mots.
* @param[in] : liste de mots dans laquelle les mots doivent �tre enregistr�s.
* @param[in] : mot temporaire contenant le premier la liste si il n'y avait pas de retour � la ligne apr�s '*' dans la sais�e pr�c�dente.
* @param[out] tmp : mot temporaire contenant le premier mot d'une liste suivante si il n'y avait pas de retour � la ligne apr�s '*'.
* @param[out] liste : liste actualis�e avec les mots rentr�s.
*/
bool getMots(Liste_mot& liste, Mot& tmp, bool tri);

/**
* @brief : V�rifie si un mot existe d�j� dans une liste.
* @param[in] liste : liste dans laquelle la recherche est effectu�e.
* @param[in] mot_a_verifier : mot � chercher dans la liste.
* @return : r�sultat de la recherche. Vrai si trouv�, faux sinon.
*/
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);

/** 
* @brief : Ajout d'un mot dans une liste de mots.
* @param[in] liste : liste dans laquelle le mot doit �tre ajout�.
* @param[in] word : Mot � ajouter dans la liste.
* @param[out] liste : liste de mots actualis�e avec word.
*/
void ajouter_mot(Liste_mot& liste, Mot& word);

/** 
* @brief : Initialisation en m�moire d'une liste de mots.
* @param[in] liste : liste � initialiser en m�moire.
* @param[in] taille : capacit� avec la liste est initialis�e.
* @param[out] liste : liste maintenant initialis�e en m�moire.
*/
void initialiser_liste_mot(Liste_mot& liste, unsigned int taille);

/** 
* @brief : Lib�ration de la m�moire allou�e � une liste.
* @param[in] liste : liste dont la m�moire doit �tre lib�r�e.
* @param[out] liste : liste d�sallou�e en m�moire.
*/
void supprimer(Liste_mot& liste);

/** 
* @brief : Affichage en retour des mots d'une liste de mots.
* @param[in] liste : liste dont les �l�ments doivent �tre affich�s.
* @param[in]trtligne : besoin de retour � la ligne ou non apr�s l'affichage complet.
*/
void afficher(Liste_mot& liste, bool rtrligne);

/**
* @brief : Compte les points d'une liste de mots selon les r�gles du Boggle.
* @param[in] liste : liste dont les points sont compt�s.
*/
int compter_points(Liste_mot& liste);


/** 
* @brief : Affiche les mots de la deuxi�me liste qui ne sont pas pr�sents dans la premi�re.
* @param[in] liste1 : premi�re liste du test.
* @param[in] liste2 : seconde liste du test.
*/
void test_presence(Liste_mot& liste1, Liste_mot& liste2);

/** 
* @brief : Enregistre les mots en commun de deux listes.
* @param[in] liste1 : premi�re liste du test.
* @param[in] liste2 : seconde liste du test.
* @param[out] liste_result : liste dans laquelle les mots en communs sont enregistr�s.
*/
void test_mots_communs(Liste_mot& liste1, Liste_mot& liste2, Liste_mot& liste_result);

/** 
* @brief : Affiche les mots en commun de deux listes.
* @param[in] liste1 : premi�re liste du test.
* @param[in] liste2 : seconde liste du test.
*/
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste2);

/** 
* @brief : Tri dans l'ordre lexicographique des mots d'une liste.
* @param[in] liste : liste � trier.
* @param[out] liste : liste tri�e.
* @param[in] doublon : remplace les doublons par "NULL" si true.
* @param[in] ordre : met la liste dans l'ordre si true.
* @pre ordre ou doublon true.
*/
void trie_n(Liste_mot& liste, bool doublon, bool ordre);

/** 
* @brief : Tri dans l'ordre lexicographique des mots d'une liste.
* @param[in] liste : liste � trier.
* @param[out] liste : liste tri�e.
* @param[in] doublon : remplace les doublons par "NULL" si true.
* @param[in] ordre : met la liste dans l'ordre si true.
* @pre ordre ou doublon true.
*/
void trie(Liste_mot& liste);

/** 
* @brief �change la position de deux �l�ments dans une liste de mots.
* @param[in] liste : liste dans alquelle les �l�ments doivent �tre �chang�s.
* @param[in] i : position du premier �l�ment dans la liste.
* @param[in] j : position du deuxi�me �l�ment dans la liste.
* @param[out] liste : liste avec les deux �l�ments �chang�s.
*/
void swap(Liste_mot& liste, unsigned int i, unsigned int j);

/** 
* @brief : Supprime les doublons d'une liste.
* @param[in] liste : liste dans laquelle les doublons seront supprim�s.
* @param[out] liste : liste sans doublons.
*/
void rm_doublons(Liste_mot& liste);