#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../include/gestionEnregistrement.h"

char filename[100];
int nombreColonne;

void combinaisonSecret(Couleur *combinaison) {
    FILE *fp;
    fp = fopen(filename, "w+");


    for (int i = 0; i < nombreColonne; i++)
    {
        fprintf(fp, "%d", combinaison[i]);
        fprintf(fp, ";");
    }

    fclose(fp);

}
