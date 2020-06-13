#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/gestionEnregistrement.h"

char filename[100];
int nombreColonne;

/**
 * @brief Cette methode permet d'ajouter au fichier tous les infos necessaires à la construction d'une partie 
 * 
 * @param combinaison Combinaison secrete
 * @param joueur 
 */
void addFirstInfo(Couleur *combinaison, joueur *joueur)
{
    FILE *fp;
    fp = fopen(filename, "w+");

    fprintf(fp, "%s", joueur->nom);
    fprintf(fp, ";");
    fprintf(fp, "%i", nombreColonne);
    fprintf(fp, ";");
    fprintf(fp, "%i", nombreEssais);
    fprintf(fp, ";");
    fprintf(fp, "\n");
    for (int i = 0; i < nombreColonne; i++)
    {
        fprintf(fp, "%d", combinaison[i]);
        fprintf(fp, ";");
    }

    fclose(fp);
}
