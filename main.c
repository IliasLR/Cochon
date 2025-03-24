#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_JOUEURS 6
#define MAX_SIZE_PSEUDO 50
#define SCORE_GAGNANT 100

int get_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main(void) {
    int nbJoueurs;
    char pseudos[MAX_NUMBER_JOUEURS][MAX_SIZE_PSEUDO];
    int bank[MAX_NUMBER_JOUEURS] = {0};
    int pointsTour;
    int joueurActuel = 0;
    int de;
    char choix;
    int partieTerminee = 0;

    srand(time(NULL));

    printf("Jeu de Cochons\n");
    printf("Nombre de Joueur : ");
    scanf("%d", &nbJoueurs);

    if (nbJoueurs <= 0 || nbJoueurs > MAX_NUMBER_JOUEURS) {
        printf("Nombre de joueurs invalide (1-%d)\n", MAX_NUMBER_JOUEURS);
        return 1;
    }

    while (getchar() != '\n');

    for (int i = 0; i < nbJoueurs; i++) {
        printf("Entrez le pseudo du joueur %d : ", i + 1);
        fgets(pseudos[i], MAX_SIZE_PSEUDO, stdin);

        for (int j = 0; pseudos[i][j] != '\0'; j++) {
            if (pseudos[i][j] == '\n') {
                pseudos[i][j] = '\0';
                break;
            }
        }
    }

    printf("\nListe des joueurs :\n");
    for (int i = 0; i < nbJoueurs; i++) {
        printf("Joueur %d : %s\n", i + 1, pseudos[i]);
    }

    printf("\nLe premier joueur a atteindre %d points gagne !\n\n", SCORE_GAGNANT);

    while (!partieTerminee) {
        pointsTour = 0;
        int continuerTour = 1;

        printf("\n--- Tour de %s ---\n", pseudos[joueurActuel]);
        printf("Points en banque : %d\n", bank[joueurActuel]);

        while (continuerTour) {
            de = get_random_number(1, 6);
            printf("Vous avez lancé un %d\n", de);

            if (de == 1) {
                printf("Dommage! Vous perdez les points de ce tour.\n");
                pointsTour = 0;
                continuerTour = 0;
            } else {
                pointsTour += de;
                printf("Points de ce tour: %d\n", pointsTour);
                printf("Total potentiel: %d\n", bank[joueurActuel] + pointsTour);

                printf("Voulez-vous (R)elancer le de ou (S)auvegarder vos points ? ");
                scanf(" %c", &choix);

                if (choix == 's' || choix == 'S') {
                    bank[joueurActuel] += pointsTour;
                    printf("Points sauvegardes ! Vous avez maintenant %d points.\n", bank[joueurActuel]);
                    continuerTour = 0;
                }
            }

            if (bank[joueurActuel] >= SCORE_GAGNANT) {
                printf("\n %s a gagne avec %d points! \n", pseudos[joueurActuel], bank[joueurActuel]);
                partieTerminee = 1;
                continuerTour = 0;
            }
        }

        if (!partieTerminee) {
            joueurActuel = (joueurActuel + 1) % nbJoueurs;
        }
    }

    printf("\nScores finaux:\n");
    for (int i = 0; i < nbJoueurs; i++) {
        printf("%s: %d points\n", pseudos[i], bank[i]);
    }

    return 0;
}