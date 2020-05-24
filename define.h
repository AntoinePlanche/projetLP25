#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

typedef enum couleur
{
    ROUGE,
    JAUNE,
    BLEU,
    ORANGE,
    VERT,
    BLANC,
    VIOLET,
    ROSE
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
    Couleur *pions;
    int score;
} joueur;

// il y a 2 grosses fonctions à coder : une fonction qui prend en parametre la ligne "objectif" (juste un tableau de couleur, pas besoin de
// nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit) et une autre ligne x et qui remplie nbrBonneCouleurBonEndroit, nbrBonneCouleurMauvaisEndroit
// de la ligne x. Il restera la fonction qui recoit une structure ligne et qui enregistre les information dans un fichier ( ca fera une sorte de sauvegarde pour
// reprendre la partie si jamais on arrete le programme en cour de partie).

#endif // DEFINE_H_INCLUDED
