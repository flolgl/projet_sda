#include "liste_mot.h"

bool getMots(Liste_mot& liste, Mot& tmp, bool tri) {

	if (strcmp(tmp, "null") != 0) {
		ajouter_mot(liste, tmp);
		strcpy(tmp, "null");
	}
	Mot word;
	bool continuer = true;

	std::cin >> word;

	if (strcmp(word, "*") == 0)
		return true;

	while (continuer) {

		if (tri){
			if (mot_existant(liste, word) == false) {
				ajouter_mot(liste, word);
			}
		}
		else {
			ajouter_mot(liste, word);
		}

		std::cin >> std::setw(LGMOT) >> word;

		if (word[0] == '*') {
			continuer = false;
			if (strlen(word) > 1) {
				strcpy(tmp, strtok(word, "*"));
			}
		}
	}
	return false;
}

bool mot_existant(Liste_mot& liste, Mot mot_a_verifier) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.Liste_Mot[i], mot_a_verifier) == 0) {
			return true;
		}
	}
	return false;
}

void ajouter_mot(Liste_mot& liste, Mot& word) {

	if  (liste.taille == liste.nb_mots){
		Mot* nouveau_liste_word = new Mot[liste.taille*2];


		for (unsigned int i = 0; i < liste.nb_mots; i++)
			strcpy(nouveau_liste_word[i], liste.Liste_Mot[i]);

		delete[] liste.Liste_Mot;
		liste.Liste_Mot = nouveau_liste_word;
		liste.taille = liste.taille * 2;
	}
	strcpy(liste.Liste_Mot[liste.nb_mots], word);
	liste.nb_mots++;
}


void initialiser_liste_mot(Liste_mot& liste, unsigned int taille) {
	liste.nb_mots = 0;
	liste.Liste_Mot = new Mot[taille];
	liste.taille = taille;
}

void supprimer(Liste_mot& liste) {
	delete[] liste.Liste_Mot;
}

void afficher(Liste_mot& liste, bool rtrligne) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		if (strcmp(liste.Liste_Mot[i], "NULL") != 0)
			std::cout << liste.Liste_Mot[i] << std::endl;
	}
	std::cout << "*";
	if (rtrligne)
		std::cout << std::endl;
}

int compter_points(Liste_mot& liste) {
	int nb_points = 0;
	size_t taille;
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		taille = strnlen(liste.Liste_Mot[i], LGMOT + 1);
		switch (taille) {
		case 0: break;
		case 1: break;
		case 2: break;
		case 3: nb_points += 1; break;
		case 4: nb_points += 1; break;
		case 5: nb_points += 2; break;
		case 6: nb_points += 3; break;
		case 7: nb_points += 5; break;
		default: nb_points += 11;
		}
	}

	return nb_points;
}

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

void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste_result) {
	Mot word;
	bool continuer = true;

	std::cin >> std::setw(LGMOT) >> word;

	if (strcmp(word, "*") == 0) {
		return;
	}

	while (continuer) {


		for (unsigned int j = 0; j < liste1.nb_mots; j++) {
			if (word[0] < liste1.Liste_Mot[j][0]) {
				break;
			}

			if (strcmp(word, liste1.Liste_Mot[j]) == 0) {
				//if (!mot_existant(liste_result, word)) {
					ajouter_mot(liste_result, word);
					break;
				//}
			}
		}


		std::cin >> std::setw(LGMOT) >> word;
		if (strcmp(word, "*") == 0)
			continuer = false;
	}
}

void swap(Liste_mot& liste, unsigned int i, unsigned int j) {
	Mot tmp;
	strcpy(tmp, liste.Liste_Mot[i]);
	strcpy(liste.Liste_Mot[i], liste.Liste_Mot[j]);
	strcpy(liste.Liste_Mot[j], tmp);
}

void trie_n(Liste_mot& liste, bool doublon, bool ordre) {
	if (!doublon && !ordre) return;
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		for (unsigned int j = i + 1; j < liste.nb_mots; j++) {
			if (ordre)
				if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) > 0) 
						swap(liste, i, j);
			if (doublon)
				if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) == 0) 
					strcpy(liste.Liste_Mot[j], "NULL");
			
		}
	}
}

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

void rm_doublons(Liste_mot& liste) {
	for (unsigned int i = 0; i < liste.nb_mots; i++) {
		for (unsigned int j = i + 1; j < liste.nb_mots; j++) {
			if (strcmp(liste.Liste_Mot[i], liste.Liste_Mot[j]) == 0) {
				strcpy(liste.Liste_Mot[j], "NULL");
			}
		}
	}
}