#include <stdio.h>
#include <stdlib.h>
#include "../include/define.h"
#include <string.h>
#define LINE_LEN 200

char filename[100];
int essaisRestants;



void addPropToGame(ligne *proposition, int i, int token)
{
    printf("Test %i : ", i);
    printf("%i  =  ", token);
    if(i == nombreEssais)
    {
        proposition->nbrBonneCouleurBonEndroit = token;
        printf("proposition->nbrBonneCouleurBonEndroit : %i\n", proposition->nbrBonneCouleurBonEndroit);
    } else if(i == nombreEssais + 1) {

        proposition->nbrBonneCouleurMauvaisEndroit = token;
        printf("proposition->nbrBonneCouleurMauvaisEndroit : %i\n", proposition->nbrBonneCouleurMauvaisEndroit);

    } else {
        proposition->pion[i] = token;
        printf("proposition->pion : %i\n", proposition->pion[i]);
    }

    return 0;

}



void parsePlayer(char* line, joueur *joueur, int count, Couleur *combinaison, int countProp)
{
    const char delimiter[2] = ";";
    char* token = strtok(line, delimiter);
    int i = 0;

    printf("count %i\n", count);


    if(count != 0 && count != 1)
       {
            countProp++;
       }


    while(token != NULL){
        if(count == 0){
            if(i == 0){
                strcpy(joueur->nom, token);
                printf("joueur.nom = %s\n", joueur->nom);

            }
            if(i == 1){
                nombreColonne = atoi(token);
                printf("nombreColonne = %i\n", nombreColonne);

            }
            if(i == 2){
                nombreEssais = atoi(token);
                printf("nombreEssais = %i\n", nombreEssais);

            }
        }
        if(count == 1 && i <= nombreColonne-1){

            combinaison[i] = atoi(token);
            printf("combinaison[%i] = %i\n", i,combinaison[i]);

            }


        if(countProp>=0 && i <= nombreColonne+1){
                addPropToGame(&(joueur->proposition[countProp]), i, atoi(token));
            }




        token = strtok(NULL, delimiter);
        i++;

    }
    return 0;
}



void createGameFromFile(Couleur *combinaison, joueur *joueur)
{
    char tampon[20];
    char tampon2[40] = "Previous-Game/";
    char line[LINE_LEN+1];
    int count = 0;
    int countProp=-1;

    strcpy(tampon, filename);
    strcat(tampon2,tampon);

    printf("%s\n", tampon2);

    FILE *fp = fopen(tampon2, "r");

    if(fp != NULL)
    {

        printf("\nContents\n");
        while(fgets(line, LINE_LEN, fp) != NULL)
        {
            printf("\n%s", line);
            parsePlayer(line, joueur, count, combinaison, countProp);
            count++;
        }

    }

    essaisRestants = nombreEssais - count + 2;



    return 0;
}
