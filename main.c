#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_JOUEURS 6
#define MAX_SIZE_PSEUDO 50
#define SCORE_GAGNANT 100

typedef struct {
    char pseudo[MAX_SIZE_PSEUDO];
    int points;
} Joueur;

typedef struct {
    Joueur joueurs[MAX_NUMBER_JOUEURS];
    int nbJoueurs;
    int joueurActuel;
    int partieTerminee;
} JeuDeCochon;

int get_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void initialiser_jeu(JeuDeCochon *jeu) {
    printf("Nombre de Joueurs : ");
    scanf("%d", &jeu->nbJoueurs);

    if (jeu->nbJoueurs <= 0 || jeu->nbJoueurs > MAX_NUMBER_JOUEURS) {
        printf("Nombre de joueurs invalide (1-%d)\n", MAX_NUMBER_JOUEURS);
        exit(1);
    }

    while (getchar() != '\n');

    for (int i = 0; i < jeu->nbJoueurs; i++) {
        printf("Entrez le pseudo du joueur %d : ", i + 1);
        fgets(jeu->joueurs[i].pseudo, MAX_SIZE_PSEUDO, stdin);
        jeu->joueurs[i].points = 0;

        for (int j = 0; jeu->joueurs[i].pseudo[j] != '\0'; j++) {
            if (jeu->joueurs[i].pseudo[j] == '\n') {
                jeu->joueurs[i].pseudo[j] = '\0';
                break;
            }
        }
    }
}

void jouer_tour(JeuDeCochon *jeu) {
    int pointsTour = 0;
    char choix;
    Joueur *joueurActuel = &jeu->joueurs[jeu->joueurActuel];

    printf("\n--- Tour de %s ---\n", joueurActuel->pseudo);
    printf("Points en banque : %d\n", joueurActuel->points);

    while (1) {
        int de = get_random_number(1, 6);
        printf("Vous avez lance un %d\n", de);

        if (de == 1) {
            printf("Dommage! Vous perdez les points de ce tour.\n");
            break;
        }

        pointsTour += de;
        printf("Points de ce tour: %d\n", pointsTour);
        printf("Total potentiel: %d\n", joueurActuel->points + pointsTour);

        printf("Voulez-vous (R)elancer le de ou (S)auvegarder vos points ? ");
        scanf(" %c", &choix);

        if (choix == 's' || choix == 'S') {
            joueurActuel->points += pointsTour;
            printf("Points sauvegardes ! Vous avez maintenant %d points.\n", joueurActuel->points);
            break;
        }
    }

    if (joueurActuel->points >= SCORE_GAGNANT) {
        printf("\n%s a gagne avec %d points!\n", joueurActuel->pseudo, joueurActuel->points);
        jeu->partieTerminee = 1;
    } else {
        jeu->joueurActuel = (jeu->joueurActuel + 1) % jeu->nbJoueurs;
    }
}

int main(void) {
    srand(time(NULL));
    JeuDeCochon jeu = {0};

    printf("Jeu de Cochons\n");
    initialiser_jeu(&jeu);

    printf("\nLe premier joueur a atteindre %d points gagne !\n\n", SCORE_GAGNANT);

    while (!jeu.partieTerminee) {
        jouer_tour(&jeu);
    }

    printf("\nScores finaux:\n");
    for (int i = 0; i < jeu.nbJoueurs; i++) {
        printf("%s: %d points\n", jeu.joueurs[i].pseudo, jeu.joueurs[i].points);
    }

    return 0;
}