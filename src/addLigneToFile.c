#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/gestionEnregistrement.h"

// Name of the file
char filename[100];
// Number of columns
int nombreColonne;

/**
 * @brief This method is used to add a line to the file 
 * 
 * @param proposition line which has to be stored in the file
 */
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
