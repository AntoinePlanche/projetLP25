#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "define.h"

/**
 * @brief Cette fonction permet au joueur de proposer une nouvelle ligne
 *
 * @param joueur
 * @param combinaison
 */
void playerInput(joueur *joueur, Couleur *combinaison, int numeroEssai);

/**
 * @brief Cette fonction permet d'afficher le choix du joueur au fur et à mesure que celui-ci rempli la ligne
 *
 * @param proposition
 */
void displayChoice(Couleur *proposition);

/**
 * @brief
 *
 * @param choix
 */
void initalizePion(Couleur* combinaison);

/**
 * @brief Cette fonction permet de savoir si la ligne est remplie ou non
 *
 * @param choix
 * @return true si la ligne est remplie
 * @return false si il y a des cases vides dans la ligne
 */
bool isFull(Couleur* combinaison);

/**
 * @brief Cette fonction permet de completer la ligne en fonction de la chaine de caractere representant la couleur donnée par le joueur
 *
 * @param choix ligne actuellement en jeu
 * @param index index de la position de la couleur choisie
 * @param colorName chaine de caractere representant la couleur
 */
void fillChoixWithColor(Couleur *choix, int index, char *colorName);

/**
 * @brief Cette fonction permet de convertir la couleur donnée par l'utilisateur en majuscule afin d'eviter les malentendus
 *
 * @param name
 * @return char*
 */
char *charPointerToUpperCase(char *name);

/**
 * @brief Cette fonction permet d'afficher ce que vient de jouer le joueur
 * Cette fonction peut etre utiliser pour faire du debug ou de l'affichage
 *
 * @param joueur
 */
void displayPlayerChoice(joueur *joueur);

/**
 * @brief Cette fonction permet de connaitre le mode de jeu choisi par le joueur
 *
 * @return true si le JoueurVSJoueur
 * @return false si JoueurVSOrdinateur
 */
bool modeChoice();

/**
 * @brief Cette fonction permet d'initaliser le nombre de colonne dans le jeu
 *
 */
void numberColorChoice();

/**
 * @brief Cette fonction permet de determiner le nombre d'essais pour le jeu
 *
 */
void essaisNumberChoice();

/**
 * @brief Cette fonction permet de donner rentrer la combiniason secrete qui sera utilisée pour le jeu
 *
 * @param combinaison
 */
void combinaisonInput(Couleur *combinaison, joueur *joueur);

/**
 * @brief Cette fonction permet de verifier si le joueur a trouvé ou non la bonne combinaison. Elle retournera un boolean en fonction de la reussite ou non.
 *
 * @param targetLigne
 * @param input
 * @param lengthLine
 * @return true
 * @return false
 */
bool checkLineContent(Couleur *targetLigne, ligne *input);

/**
 * @brief Cette fonction permet d'initialiser une strucure joueur
 *
 * @param targetLigne
 * @param input
 * @param lengthLine
 * @return true
 * @return false
 */


#endif
