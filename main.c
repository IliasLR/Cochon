#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


#define MAX_NUMBER_JOUEURS 6
#define MAX_SIZE_PSEUDO 50

int get_random_number(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main(void) {
    int nbJoueurs;
    char pseudos[MAX_NUMBER_JOUEURS][MAX_SIZE_PSEUDO];

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

    printf("%d",get_random_number(1,6));
    return 0;
}