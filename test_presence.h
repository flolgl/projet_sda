#pragma once

#include "liste_mot.h"

void test_presence(Liste_mot& liste1, Liste_mot& liste2);
void test_mots_communs(Liste_mot& liste1, Liste_mot& liste2, Liste_mot& liste_result);
void test_mots_communs_cout(Liste_mot& liste1, Liste_mot& liste2);
bool check_word_commun(Liste_mot& liste1, Mot& word);
