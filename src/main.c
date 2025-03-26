#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cochon.h"
#include "initialisation.h"
#include "jeu.h"
#include "utils.h"

int main(void) {
    srand(time(NULL));
    JeuDeCochon jeu = {0};

    printf("%s%s%s%s", red, bold, "Jeu de Cochons\n", reset);
    initialiser_jeu(&jeu);

    printf("\n%sLe premier joueur a atteindre %s%d%s points gagne !%s\n\n", 
           yellow, green, SCORE_GAGNANT, yellow, reset);

    while (!jeu.partieTerminee) {
        jouer_tour(&jeu);
    }

    printf("\n%s%sScores finaux:%s\n", bold, cyan, reset);
    for (int i = 0; i < jeu.nbJoueurs; i++) {
        const char* playerColor = (i % 2 == 0) ? blue : purple;
        printf("%s%s: %s%d%s points%s\n", playerColor, jeu.joueurs[i].pseudo, green, jeu.joueurs[i].points, playerColor, reset);
    }

    return 0;
}