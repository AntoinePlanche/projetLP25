#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/define.h"
#include "../include/playerInput.h"
#include "../include/gestionEnregistrement.h"

int main()
{
    // SI fichier est vide
    char str[100];
    srand(time(NULL));
    joueur *nouveauJoueur = malloc(sizeof(joueur));
    printf("Bonjour, quel est votre nom ?\n");
    scanf("%s",nouveauJoueur->nom);
    createGameFile(*nouveauJoueur, str);
    nouveauJoueur->score = 0;
    essaisNumberChoice();
    numberColorChoice();
    nouveauJoueur->proposition = (ligne*)malloc(sizeof(ligne)*nombreEssais);
    if (nouveauJoueur->proposition == NULL)
    {
        printf("erreur d'allocation memoire");
        exit(1);
    }

    for(int i = 0; i<nombreEssais; i++)
    {
        nouveauJoueur->proposition[i].pion = (Couleur*)malloc(sizeof(Couleur)*nombreColonne);
        if(nouveauJoueur->proposition[i].pion == NULL)
        {
            printf("erreur d'allocation memoire\n");
            exit(1);
        }
    }

    Couleur *combinaisonSecret = (Couleur*)malloc(nombreColonne * sizeof(Couleur));
    combinaisonInput(combinaisonSecret);

    for(int numeroEssai = 0; numeroEssai<nombreEssais; numeroEssai++)
    {
        playerInput(nouveauJoueur, combinaisonSecret, numeroEssai);
    }
    printf("Dommage %s, vous avez perdu, n'hesitez pas a reessayer.\n",nouveauJoueur->nom);

    return 0;
}
