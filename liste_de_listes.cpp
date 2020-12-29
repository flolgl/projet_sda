#include "liste_de_listes.h"
#include "test_presence.h"
#include "trie.h"

void initialiser_liste(Liste_de_listes_mot& liste, unsigned int taille) {
	liste.Liste_de_listes = new Liste_mot[taille];
	liste.nb_listes = 0;
	liste.taille = taille;
}

void ajouter_liste(Liste_de_listes_mot& liste_principale, Liste_mot& liste_to_add) {
	if (liste_principale.taille == liste_principale.nb_listes) {
		Liste_mot* new_liste = new Liste_mot[liste_principale.taille * 2];


		for (unsigned int i = 0; i < liste_principale.nb_listes; i++)
			new_liste[i] = liste_principale.Liste_de_listes[i];

		delete[] liste_principale.Liste_de_listes;
		liste_principale.Liste_de_listes = new_liste;
		liste_principale.taille = liste_principale.taille * 2;
	}
	liste_principale.Liste_de_listes[liste_principale.nb_listes] = liste_to_add;
	liste_principale.nb_listes += 1;
}

void get_listes(Liste_de_listes_mot& liste_principale) {
	Liste_mot liste_to_add;
	initialiser_liste_mot(liste_to_add, 50);
	bool continuer;

	continuer = getMots_trie(liste_to_add);

	while (!continuer) {
		ajouter_liste(liste_principale, liste_to_add);

		//supprimer(liste_to_add);
		initialiser_liste_mot(liste_to_add, 50);

		continuer = getMots_trie(liste_to_add);
	}
}

void supprimer_liste_de_listes(Liste_de_listes_mot& liste) {
	while (liste.nb_listes != 0) {
		supprimer(liste.Liste_de_listes[liste.nb_listes - 1]);
		liste.nb_listes -= 1;
	}
	delete[] liste.Liste_de_listes;
}

void check_communs_2_listes(Liste_de_listes_mot& liste_principale, Liste_mot& liste_result) {
	for (unsigned int i = 0; i < liste_principale.nb_listes; i++) {
		for (unsigned int j = i + 1; j < liste_principale.nb_listes; j++) {
			test_mots_communs(liste_principale.Liste_de_listes[i], liste_principale.Liste_de_listes[j], liste_result);
		}
	}
}