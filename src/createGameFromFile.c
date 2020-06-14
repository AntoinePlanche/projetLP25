#include <stdio.h>
#include <stdlib.h>
#include "../include/define.h"
#include <string.h>
#define LINE_LEN 200

char filename[100];
int nombreEssais;
int playerLinesCount;

Couleur getColorByIndex(int index);

/**
 * @brief Get the Color By Index
 * 
 * @param index 
 * @return Couleur 
 */
Couleur getColorByIndex(int index)
{
    switch (index)
    {
    case 0:
        return ROUGE;
        break;
    case 1:
        return JAUNE;
        break;
    case 2:
        return BLEU;
        break;
    case 3:
        return ORANGE;
        break;
    case 4:
        return VERT;
        break;
    case 5:
        return BLANC;
        break;
    case 6:
        return VIOLET;
        break;
    case 7:
        return ROSE;
        break;

    default:
        return NONE;
        break;
    }
}

/**
 * @brief Set the Game Parameters
 * 
 * @param line 
 * @param joueur 
 */
void setGameParameters(char *line, joueur *joueur)
{
    const char delimiter[2] = ";";
    char *token = strtok(line, delimiter);
    int i = 0;

    while (token != NULL)
    {
        if (i == 0)
        {
            strcpy(joueur->nom, token);
            ASSERT_DATA("joueur.nom", joueur->nom);
        }
        if (i == 1)
        {
            nombreColonne = atoi(token);
            ASSERT_INT("nombreColonne", nombreColonne);
        }
        if (i == 2)
        {
            nombreEssais = atoi(token);
            ASSERT_INT("nombreEssais", nombreEssais);

            joueur->proposition = (ligne *)malloc(sizeof(ligne) * nombreEssais);

            if (joueur->proposition == NULL)
            {
                ASSERT("ERREUR ALLOCATION MEMOIRE");
                exit(1);
            }
        }

        token = strtok(NULL, delimiter);
        i++;
    }
}

/**
 * @brief Fill the secret combinaison from the line in the file
 * 
 * @param line 
 * @param combinaison 
 */
void fillCombinaisonFromFile(char *line, Couleur *combinaison)
{
    const char delimiter[2] = ";";
    char *token = strtok(line, delimiter);
    int i = 0;

    while (token != NULL)
    {
        if (i <= nombreColonne - 1)
        {
            combinaison[i] = getColorByIndex(atoi(token));
            ASSERT("COMBINAISON");
        }
        token = strtok(NULL, delimiter);
        i++;
    }
}

/**
 * @brief Fill the line from the line in the file (Colors, wrond and good answer)
 * 
 * @param line 
 * @param inputLine 
 */
void fillInputLine(char *line, ligne *inputLine)
{
    const char delimiter[2] = ";";
    char *token = strtok(line, delimiter);
    int i = 0;

    while (token != NULL)
    {
        if (i == nombreColonne)
        {
            inputLine->nbrBonneCouleurBonEndroit = TO_INT(token);
            ASSERT_INT("proposition->nbrBonneCouleurBonEndroit", inputLine->nbrBonneCouleurBonEndroit);
        }
        else if (i == nombreColonne + 1)
        {
            inputLine->nbrBonneCouleurMauvaisEndroit = TO_INT(token);
            ASSERT_INT("proposition->nbrBonneCouleurMauvaisEndroit", inputLine->nbrBonneCouleurBonEndroit);
        }

        if (i < nombreColonne)
        {
            ASSERT("COULEUR");
            inputLine->pion[i] = getColorByIndex(TO_INT(token));
            ASSERT_INT("proposition->pion", (Couleur)inputLine->pion[i]);
        }
        token = strtok(NULL, delimiter);
        i++;
    }
}

/**
 * @brief Create a Game From File object
 * 
 * @param combinaison 
 * @param player 
 */
void createGameFromFile(Couleur *combinaison, joueur *player)
{
    char tampon[20];
    char tampon2[40] = FOLDER_NAME;
    char line[LINE_LEN + 1];
    int count = 0;

    playerLinesCount = 0;

    strcpy(tampon, filename);
    strcat(tampon2, tampon);

    strcpy(filename, tampon2);

    ASSERT_DATA("NOM FICHIER", tampon2);

    FILE *fp = fopen(tampon2, "r");

    if (fp != NULL)
    {
        ASSERT("CONTENT");
        while (fgets(line, LINE_LEN, fp) != NULL)
        {
            RETURN;
            ASSERT_DATA("LINE", line);
            ASSERT_INT("LINE n°", count);

            if (count == 0)
            {
                setGameParameters(line, player);
                player->proposition = (ligne *)malloc(sizeof(ligne) * nombreEssais);

                // Allocation de l'espace memoire pour stocker les lignes possedant nombreColonne x Couleur
                for (int i = 0; i < nombreEssais; i++)
                {
                    player->proposition[i].pion = (Couleur *)malloc(sizeof(Couleur) * nombreColonne);

                    if (player->proposition[i].pion == NULL)
                    {
                        printf("erreur d'allocation memoire\n");
                        exit(1);
                    }
                }
            }
            else if (count == 1)
                fillCombinaisonFromFile(line, combinaison);
            else
            {
                ligne inputLine;
                inputLine.pion = (Couleur *)malloc(sizeof(Couleur) * nombreColonne);

                fillInputLine(line, &inputLine);

                player->proposition[playerLinesCount] = inputLine;

                playerLinesCount++;
            }

            count++;
        }
    }
}
