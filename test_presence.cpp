#include "test_presence.h"

void test_presence(Liste_mot& liste1, Liste_mot& liste2) {
	for (unsigned int i = 0; i < liste2.nb_mots; i++) {
		for (unsigned int j = 0; j <= liste1.nb_mots; j++) {
			if (strcmp(liste2.Liste_Mot[i], liste1.Liste_Mot[j]) == 0) {
				break;
			}
			if (j == liste1.nb_mots) {
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
/*
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste2) {
	for (unsigned int i = 0; i < liste1.nb_mots; i++) {
		for (unsigned int j = 0; j < liste2.nb_mots; j++) {
			if (liste1.Liste_Mot[i][0] > liste2.Liste_Mot[j][0])
				break;
			if (strcmp(liste1.Liste_Mot[i], liste2.Liste_Mot[j]) == 0) {
				std::cout << liste1.Liste_Mot[i] << std::endl;
				break;
			}
		}
	}
	std::cout << "*" << std::endl;
}
*/
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste_result) {
	Mot word;
	bool continuer = true;

	std::cin >> std::setw(LGMOT) >> word;

	if (strcmp(word, "*") == 0) {
		return;
	}

	while (continuer) {
		//std::cout << " aussi ici";


		for (unsigned int j = 0; j < liste1.nb_mots; j++) {
			if (word[0] < liste1.Liste_Mot[j][0]) {
				//std::cout << word[0] << "out by " << liste1.Liste_Mot[j][0] << std::endl;
				break;
			}
			if (strcmp(word, liste1.Liste_Mot[j]) == 0) {
				if (!mot_existant(liste_result, word)) {
					ajouter_mot(liste_result, word);
					break;
				}
			}
		}


		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
}