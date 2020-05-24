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
    ligne proposition;
    int score;
} joueur;

void playerInput(joueur *joueur); //Cette fonction permet de prendre en comtpe les interactions avec le joueur et d'assigner dynamique le tableau de point dans la champ ligne.

bool checkLigneContent(ligne &objectif, joueur *joueur); // Cette fonction permet de verifier si le joueur a trouvé ou non la bonne combinaison. Elle retournera un boolean en fonction de la reussite ou non.

void createGameFile(joueur &joueur); // Cette fonciton a pour but de créer un fichier ayant pour nom le nom du joueur et de son adversaire si le fichier existe deja nous demandons au joueur de donner un nom au fichier

void addLigneToFile(ligne &proposition); // Cette fonction a pour but d'ajouter au fichier crée préalablement la ligne que vient de rentrer le joueur ainsi que les nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit.

string findFileName(); // Cette fonction a pour objectif de retrouver le nom du fichier dans le dossier Previous-Game.

void createGameFromFile(); // Cette fonction a pour objectif de creer une nouvelle ligne objectif et d'afficher les anciennes decisions qui ont été prises par le joueur afin qu'il se retrouve dans le jeu.

// il y a 2 grosses fonctions à coder : une fonction qui prend en parametre la ligne "objectif" (juste un tableau de couleur, pas besoin de
// nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit) et une autre ligne x et qui remplie nbrBonneCouleurBonEndroit, nbrBonneCouleurMauvaisEndroit
// de la ligne x. Il restera la fonction qui recoit une structure ligne et qui enregistre les information dans un fichier ( ca fera une sorte de sauvegarde pour
// reprendre la partie si jamais on arrete le programme en cour de partie).

#endif // DEFINE_H_INCLUDED
