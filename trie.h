#pragma once

#include "liste_mot.h"

void trie(Liste_mot& liste);
void swap(Liste_mot& liste, unsigned int i, unsigned int j);
bool getMots_trie(Liste_mot& liste, Mot& tmp);
bool mot_existant(Liste_mot& liste, Mot mot_a_verifier);
void rm_doublons(Liste_mot& liste);