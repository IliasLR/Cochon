#include "robot.h"
#include <time.h>
#include <stdio.h>

// FICHIER POUR LE FONCTIONNEMENT DES ROBOTS
// RENDRE LE FONCTIONNEMENT PLUS COMPLEXE, LA ON SE BASE SUR DES SEUILS, IL FAUDRAIT LE FAIRE CALCULER PAR RAPPORT A TOUT LES POINTS DES AUTRES JOUEURS

char decision_robot(JeuDeCochon *jeu, int joueurIndex, int pointsTour) {
    Joueur *joueur = &jeu->joueurs[joueurIndex];
    
    int seuil = 20; // Le bot essaye d'avoir 20 points avants de "réfléchire"
    
    int meilleurScoreAdversaire = 0;
    int secondMeilleurScore = 0;
    int pointsNecessairesPourGagner = SCORE_GAGNANT - joueur->points;
    
    for (int i = 0; i < jeu->nbJoueurs; i++) {
        if (i != joueurIndex && jeu->joueurs[i].points > meilleurScoreAdversaire) {
            secondMeilleurScore = meilleurScoreAdversaire;
            meilleurScoreAdversaire = jeu->joueurs[i].points;
        } else if (i != joueurIndex && jeu->joueurs[i].points > secondMeilleurScore) {
            secondMeilleurScore = jeu->joueurs[i].points;
        }
    }
    
    int ecartAvecMeilleur = meilleurScoreAdversaire - joueur->points;
    
    if (pointsNecessairesPourGagner <= 20 && meilleurScoreAdversaire >= SCORE_GAGNANT - 20) {
        seuil = 100;
        printf("%s%s (Robot) prend TOUS les risques car c'est une course à la victoire!%s\n", 
               red, joueur->pseudo, reset);
               
        if (joueur->points + pointsTour >= SCORE_GAGNANT) {
            return 'S';
        }
        
        return pointsTour > 35 ? 'S' : 'R';
    }
    
    else if (meilleurScoreAdversaire >= SCORE_GAGNANT - 20) {
        seuil = 30;
        printf("%s%s (Robot) est plus agressif car un adversaire est proche de la victoire.%s\n", yellow, joueur->pseudo, reset);
    } else if (ecartAvecMeilleur > 30) {
        seuil = 25;
        printf("%s%s (Robot) prend des risques pour rattraper son retard.%s\n", yellow, joueur->pseudo, reset);
    } else if (joueur->points > meilleurScoreAdversaire + 20) {
        seuil = 15;
        printf("%s%s (Robot) joue prudemment pour conserver son avance.%s\n", yellow, joueur->pseudo, reset);
    } else if (ecartAvecMeilleur >= -5 && ecartAvecMeilleur <= 10) {
        seuil = 22;
        printf("%s%s (Robot) cherche à prendre l'avantage sur ses adversaires.%s\n", cyan, joueur->pseudo, reset);
        
        if (joueur->points + pointsTour > meilleurScoreAdversaire + 5) {
            return 'S';
        }
    }
    
    if (joueur->points + pointsTour >= SCORE_GAGNANT) {
        return 'S';
    }
    
    if (pointsTour >= seuil) {
        return 'S';
    }
    
    if (joueur->points + pointsTour >= meilleurScoreAdversaire - 5) {
        return 'S';
    }
    
    return 'R';
}

char executer_tour_robot(JeuDeCochon *jeu, int joueurIndex, int pointsTour) {
    Joueur *joueur = &jeu->joueurs[joueurIndex];
    char choix = decision_robot(jeu, joueurIndex, pointsTour);
    
    if (choix == 'S') {
        printf("%s%s (Robot) decide de sauvegarder ses points.%s\n", yellow, joueur->pseudo, reset);
    } else {
        printf("%s%s (Robot) decide de relancer le de.%s\n", yellow, joueur->pseudo, reset);

        struct timespec ts;
        ts.tv_sec = 1;
        ts.tv_nsec = 0;
        nanosleep(&ts, NULL);
    }
    
    return choix;
}
