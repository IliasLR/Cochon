#include "jeu.h"
#include "utils.h"
#include "robot.h"

void jouer_tour(JeuDeCochon *jeu) {
    int pointTour = 0;
    char choix;
    Joueur *joueurActuel = &jeu->joueurs[jeu->joueurActuel];

    printf("\n%s--- Tour de %s%s%s ---%s\n", purple, bold, joueurActuel->pseudo, purple, reset);
    printf("%sPoints en banque : %s%d%s\n", blue, green, joueurActuel->points, reset);

    while (1) {
        int de = get_random_number(1, 6);
        printf("%sVous avez lance un %s%d%s\n", white, yellow, de, reset);

        if (de == 1) {
            printf("%sDommage! Vous perdez les points de ce tour.%s\n", red, reset);
            break;
        }

        pointTour += de;
        printf("%sPoints de ce tour: %s%d%s\n", white, green, pointTour, reset);
        printf("%sTotal potentiel: %s%d%s\n", white, green, joueurActuel->points + pointTour, reset);

        if (joueurActuel -> estRobot) {
            choix = executer_tour_robot(jeu, jeu->joueurActuel, pointTour);
        } else {
            printf("%sVoulez-vous %s(R)elancer%s le de ou %s(S)auvegarder%s vos points ? %s", 
                   white, yellow, white, green, white, reset);
            scanf(" %c", &choix);
        }

        if (choix == 's' || choix == 'S') {
            joueurActuel -> points += pointTour;
            printf("%sPoints sauvegardes ! Vous avez maintenant %s%d%s points.%s\n", green, bold, joueurActuel->points, green, reset);
            break;
        }
    }

    if (joueurActuel -> points >= SCORE_GAGNANT) {
        printf("\n%s%s%s a gagne avec %s%d%s points!%s\n", purple, bold, joueurActuel -> pseudo, green, joueurActuel->points, purple, reset);
        jeu->partieTerminee = 1;
    } else {
        jeu->joueurActuel = (jeu -> joueurActuel + 1) % jeu->nbJoueurs;
    }
}