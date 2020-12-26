#include "points_boggle.h"

int compter_points(Liste_mot& liste) {
	int nb_points = 0;
	size_t taille;
	for (int i = 0; i < liste.nb_mots; i++) {
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