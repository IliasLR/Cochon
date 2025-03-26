#ifndef COCHON_H
#define COCHON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_JOUEURS 6
#define MAX_SIZE_PSEUDO 50
#define SCORE_GAGNANT 100

extern const char* const red;
extern const char* const yellow;
extern const char* const blue;
extern const char* const green;
extern const char* const purple;
extern const char* const cyan;
extern const char* const white;
extern const char* const bold;
extern const char* const reset;

typedef struct Joueur Joueur;
struct Joueur {
    char pseudo[MAX_SIZE_PSEUDO];
    int points;
    int estRobot; 
};
typedef struct JeuDeCochon JeuDeCochon;
struct JeuDeCochon {
    Joueur joueurs[MAX_NUMBER_JOUEURS];
    int nbJoueurs;
    int joueurActuel;
    int partieTerminee;
};

#endif