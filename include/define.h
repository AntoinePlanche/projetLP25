#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <string.h>
#include <stdbool.h>
#define lengthName 20

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

typedef ligne* mastermind;

typedef struct joueur
{
    char nom[lengthName];
    mastermind proposition;
    int score;
} joueur;

extern int nombreColonne;
extern int nombreEssais;
extern int essaisRestants;

void process_field(int field_count, char *value);

#endif // DEFINE_H_INCLUDED
