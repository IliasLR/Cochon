#include "initialisation.h"

void initialiser_jeu(JeuDeCochon *jeu) {
    printf("%sNombre de Joueurs : %s", cyan, reset);
    scanf("%d", &jeu->nbJoueurs);

    if (jeu->nbJoueurs <= 0 || jeu->nbJoueurs > MAX_NUMBER_JOUEURS) {
        printf("%sNombre de joueurs invalide (1-%d)%s\n", red, MAX_NUMBER_JOUEURS, reset);
        exit(1);
    }

    while (getchar() != '\n');

    for (int i = 0; i < jeu->nbJoueurs; i++) {
        printf("%sEntrez le pseudo du joueur %d : %s", blue, i + 1, reset);
        fgets(jeu->joueurs[i].pseudo, MAX_SIZE_PSEUDO, stdin);
        jeu->joueurs[i].points = 0;

        for (int j = 0; jeu->joueurs[i].pseudo[j] != '\0'; j++) {
            if (jeu->joueurs[i].pseudo[j] == '\n') {
                jeu->joueurs[i].pseudo[j] = '\0';
                break;
            }
        }
        
        char estRobot;
        printf("%sEst-ce que %s est un robot ? (Y/N) : %s", yellow, jeu->joueurs[i].pseudo, reset);
        scanf(" %c", &estRobot);
        jeu->joueurs[i].estRobot = (estRobot == 'Y' || estRobot == 'y');
        if (jeu->joueurs[i].estRobot) {
            printf("%s%s est un robot%s\n", yellow, jeu->joueurs[i].pseudo, reset);
            // faire joueur le bot ou les bots en fonction du nombre de bot définie
        }
        
        while (getchar() != '\n');
    }
    
    jeu->joueurActuel = 0;
    jeu->partieTerminee = 0;
}