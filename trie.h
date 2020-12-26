#pragma once

#include "liste_mot.h"

void trie(Liste_mot& liste);
void swap(Liste_mot& liste, unsigned int i, unsigned int j);
void getMots_trie(Liste_mot& liste);
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);