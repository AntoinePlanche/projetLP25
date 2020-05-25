#include <stdio.h>
#include <stdlib.h>
#include "define.h"

extern Couleur *combinaison;
extern int nombreEssais;

/**
 * @brief Cette fonction permet de connaitre le mode de jeu choisi par le joueur 
 * 
 * @return true si le JoueurVSJoueur 
 * @return false si JoueurVSOrdinateur
 */
bool modeChoice();