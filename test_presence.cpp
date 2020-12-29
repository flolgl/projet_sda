#include "test_presence.h"

void test_presence(Liste_mot& liste1, Liste_mot& liste2) {
	for (unsigned int i = 0; i < liste2.nb_mots; i++) {
		for (unsigned int j = 0; j < liste1.nb_mots; j++) {
			if (strcmp(liste2.Liste_Mot[i], liste1.Liste_Mot[j]) == 0) {
				break;
			}
			if (j == liste1.nb_mots - 1) {
				std::cout << liste2.Liste_Mot[i] << std::endl;
			}
		}
	}
	std::cout << "*" << std::endl;
}

void test_mots_communs(Liste_mot& liste1, Liste_mot& liste2, Liste_mot& liste_result) {
	for (unsigned int i = 0; i < liste1.nb_mots; i++) {
		for (unsigned int j = 0; j < liste2.nb_mots; j++) {
			if (strcmp(liste1.Liste_Mot[i], liste2.Liste_Mot[j]) == 0) {
				ajouter_mot(liste_result, liste1.Liste_Mot[i]);
				break;
			}
		}
	}
}