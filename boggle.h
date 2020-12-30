#pragma once

#include "points_boggle.h"
#include "trie.h"
#include "test_presence.h"
#include "liste_de_listes.h"

struct plateau{
    char** lettre;
    bool** visiste;
    unsigned int taille;
};