#ifndef ROBOT_H
#define ROBOT_H

#include "cochon.h"

char decision_robot(JeuDeCochon *jeu, int joueurIndex, int pointsTour);

char executer_tour_robot(JeuDeCochon *jeu, int joueurIndex, int pointsTour);

#endif
