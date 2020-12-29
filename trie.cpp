#include "trie.h"

void trie(Liste_mot& liste) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {

		if (strcmp(liste.Liste_Mot[i], "*") == 0) {
			break;
		}

		for (unsigned int j = i + 1; j < liste.nb_mots; j++) {

			/* //Jme fais chier pour rien...
			if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) == 0) {
				strcpy(liste.Liste_Mot[j], "NULL");
			}
			*/

			if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) > 0) {
				//std::cout << "result < 0 / " << liste.Liste_Mot[i] << " < " <<liste.Liste_Mot[j] << std::endl;
				swap(liste, i, j);
			}

		}
	}
}

void swap(Liste_mot& liste, unsigned int i, unsigned int j) {
	Mot tmp;
	strcpy(tmp, liste.Liste_Mot[i]);
	strcpy(liste.Liste_Mot[i], liste.Liste_Mot[j]);
	strcpy(liste.Liste_Mot[j], tmp);
}

bool getMots_trie(Liste_mot& liste) {
	//std::cout << "ici";
	Mot word;
	bool continuer = true;

	std::cin >> word;

	if (strcmp(word, "*") == 0)
		return true;

	while (continuer) {

		if (mot_existant(liste, word) == false) {
			ajouter_mot(liste, word);
		}

		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
	return false;
}


bool mot_existant(Liste_mot& liste, Mot mot_a_verifier) {
	for (int i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.Liste_Mot[i], mot_a_verifier) == 0) {
			//std::cout << "Mot existant";
			return true;
		}
	}
	return false;
}

void rm_doublons(Liste_mot& liste) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		for (unsigned int j = i+1; j < liste.nb_mots; j++) {
			if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) == 0) {
				strcpy(liste.Liste_Mot[j], "NULL");
			}
		}
	}
}