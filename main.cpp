#include <iostream>

#include "CompteurPoints(1).h"

int main() {
	Liste_mot liste;
	initialiser_liste_mot(liste, 50);
	getMots(liste);
	unsigned int points = compter_points(liste);
	std::cout << points;
	supprimer(liste);
	return 0;
}