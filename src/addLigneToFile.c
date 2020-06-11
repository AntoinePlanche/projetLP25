#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/gestionEnregistrement.h"

char filename[100];
int nombreColonne;

void addLigneToFile(ligne *proposition)
{

    FILE *fp;
    fp = fopen(filename, "a");
    fprintf(fp, "\n");
    for (int i = 0; i < nombreColonne; i++)
    {
        fprintf(fp, "%d", proposition->pion[i]);
        fprintf(fp, ";");
    }
    fprintf(fp, "%d", proposition->nbrBonneCouleurBonEndroit);
    fprintf(fp, ";");
    fprintf(fp, "%d", proposition->nbrBonneCouleurMauvaisEndroit);
    fprintf(fp, ";");
    fclose(fp);
}
