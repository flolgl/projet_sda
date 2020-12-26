#include "boggle.h"

void sprint1() {
	Liste_mot liste;
	initialiser_liste_mot(liste, 50);
	getMots(liste);
	unsigned int points = compter_points(liste);
	std::cout << points;
	supprimer(liste);
}

void sprint2() {
	Liste_mot liste;
	initialiser_liste_mot(liste, 50);
	getMots_trie(liste);
	trie(liste);
	afficher(liste);
	supprimer(liste);
}

int main() {
	int num;
	std::cin >> num;
	switch (num) {
	case 1:
		sprint1(); break; // correspond au main du premier programme
	case 2:
		sprint2(); break; // correspond au main du second programme 
	}
}