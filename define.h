#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <string.h>
#include <stdbool.h>

typedef enum couleur
{
    ROUGE,
    JAUNE,
    BLEU,
    ORANGE,
    VERT,
    BLANC,
    VIOLET,
    ROSE,
    NONE
} Couleur;

typedef struct ligne
{
    Couleur *pion; //on allouera dynamiquement en fonction de la taille de la ligne que propose l'utilisateur
    int nbrBonneCouleurBonEndroit;
    int nbrBonneCouleurMauvaisEndroit;
} ligne;

typedef ligne *mastermind; // je sais pas trop à quoi ca peut servir pour l'instant mais on sait jamais

typedef struct joueur
{
    char *nom;
    ligne *proposition;
    int score;
} joueur;

/**
 * @brief Cette fonction permet de prendre en comtpe les interactions avec le joueur et d'assigner dynamique le tableau de point dans la champ ligne.
 * 
 * @param joueur 
 */
void playerInput(joueur *joueur);

/**
 * @brief Cette fonction permet de verifier si le joueur a trouvé ou non la bonne combinaison. Elle retournera un boolean en fonction de la reussite ou non.
 * 
 * @param targetLigne 
 * @param input 
 * @param lengthLine 
 * @return true 
 * @return false 
 */
bool checkLineContent(Couleur *targetLigne, ligne *input, int lengthLine);

/**
 * @brief Cette fonction a pour but de créer un fichier ayant pour nom le nom du joueur et de son adversaire si le fichier existe deja nous demandons au  joueur de donner un nom au fichier
 * 
 * @param joueur 
 */
void createGameFile(joueur *joueur);

/**
 * @brief Cette fonction a pour but d'ajouter au fichier crée préalablement la ligne que vient de rentrer le joueur ainsi que les nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit.
 * 
 * @param proposition 
 */
void addLigneToFile(ligne *proposition);

/**
 * @brief  Cette fonction a pour objectif de retrouver le nom du fichier dans le dossier Previous-Game.
 * 
 * @return char* 
 */
char *findFileName();

/**
 * @brief Cette fonction a pour objectif de creer une nouvelle ligne objectif et d'afficher les anciennes decisions qui ont été prises par le joueur afin qu'il se retrouve dans le jeu.
 * 
 */
void createGameFromFile();

#endif // DEFINE_H_INCLUDED
