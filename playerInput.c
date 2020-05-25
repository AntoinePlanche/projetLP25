#include "playerInput.h"

int nombreEssais = 0;
int nombreColonne = 0;

/**
 * @brief Cette fonction permet de remplir la ligne du joueur 
 * 
 * @param joueur 
 */
void playerInput(joueur *joueur)
{
    ligne choix;

    choix.pion = malloc(nombreColonne * sizeof(Couleur));

    if (choix.pion != NULL)
    {
        initalizePion(&choix);

        while (!isFull(&choix))
        {
            system("clear");
            printf("                ***** Au tour de %s *****\n\n", joueur->nom);
            printf("Choix de couleur : ROUGE, JAUNE, BLEU, ORANGE, VERT, BLANC, VIOLET, ROSE\n");

            int position = 0;
            char *color;
            displayChoice(&choix);

            printf("A quelle position souhaitez modifier la couleur ? Position : ");
            scanf("%d", &position);

            if (position <= nombreColonne)
            {
                printf("Quelle couleur souhaitez vous donner à cette case ? Couleur : ");
                scanf("%s", color);

                fillChoixWithColor(&choix, position, color);
            }
            else
            {
                printf("Cette position n'existe pas\n");
            }
        }

        char playerAnswer;
        printf("Validez vous cette proposition (o/n) ");
        scanf(" %c", &playerAnswer);
        while (playerAnswer != 'o' && playerAnswer != 'O' && playerAnswer != 'n' && playerAnswer != 'N')
        {
            printf("Votre reponse doit etre (o/n)\n");
            scanf(" %c", &playerAnswer);
        }

        while (playerAnswer == 'N' || playerAnswer == 'n')
        {
            printf("\nhello\n");
            int position = 0;
            char *color;

            printf("A quelle position souhaitez modifier la couleur ? Position : ");
            scanf(" %d", &position);

            if (position <= nombreColonne)
            {
                printf("Quelle couleur souhaitez vous donner à cette case ? Couleur : ");
                scanf(" %s", color);

                fillChoixWithColor(&choix, position, color);
            }
            else
            {
                printf("Cette position n'existe pas\n");
            }

            displayChoice(&choix);

            printf("Validez vous cette proposition (o/n) ");
            scanf(" %c", &playerAnswer);
        }

        joueur->proposition->pion = choix.pion;
    }
    else
    {
        printf("Erreur d'allocation mémoire\n");
    }
}

void combinaisonInput(Couleur *combinaison)
{
    ligne choix;
    numberColorChoice();

    choix.pion = malloc(nombreColonne * sizeof(Couleur));

    if (choix.pion != NULL)
    {
        if (modeChoice())
        {
            initalizePion(&choix);

            while (!isFull(&choix))
            {
                system("clear");
                printf("                ***** CHOIX DE LA COMBINAISON SECRETE *****\n\n");
                printf("Choix de couleur : ROUGE, JAUNE, BLEU, ORANGE, VERT, BLANC, VIOLET, ROSE\n");

                int position = 0;
                char *color;
                displayChoice(&choix);

                printf("A quelle position souhaitez modifier la couleur ? Position : ");
                scanf("%d", &position);

                if (position <= nombreColonne)
                {
                    printf("Quelle couleur souhaitez vous donner à cette case ? Couleur : ");
                    scanf("%s", color);

                    fillChoixWithColor(&choix, position, color);
                }
                else
                {
                    printf("Cette position n'existe pas\n");
                }
            }

            char playerAnswer;
            printf("Validez vous cette proposition (o/n) ");
            scanf(" %c", &playerAnswer);
            while (playerAnswer != 'o' && playerAnswer != 'O' && playerAnswer != 'n' && playerAnswer != 'N')
            {
                printf("Votre reponse doit etre (o/n)\n");
                scanf(" %c", &playerAnswer);
            }

            while (playerAnswer == 'N' || playerAnswer == 'n')
            {
                printf("\nhello\n");
                int position = 0;
                char *color;

                printf("A quelle position souhaitez modifier la couleur ? Position : ");
                scanf(" %d", &position);

                if (position <= nombreColonne)
                {
                    printf("Quelle couleur souhaitez vous donner à cette case ? Couleur : ");
                    scanf(" %s", color);

                    fillChoixWithColor(&choix, position, color);
                }
                else
                {
                    printf("Cette position n'existe pas\n");
                }

                displayChoice(&choix);

                printf("Validez vous cette proposition (o/n) ");
                scanf(" %c", &playerAnswer);
            }

            combinaison = choix.pion;

            //TODO save the combinaison in the log file
        }

        else
        {
            for (int i = 0; i < nombreColonne; i++)
            {
                Couleur randomColor = (Couleur)rand() % 8;

                while (randomColor == NONE)
                {
                    randomColor = (Couleur)rand() % 8;
                }

                choix.pion[i] = randomColor;
            }

            //TODO remove after testing
            displayChoice(&choix);

            combinaison = choix.pion;

            //TODO save the combinaison in the log file
        }
    }
    else
    {
        printf("Erreur d'allocation mémoire\n");
    }
}

/**
 * @brief Cette fonction permet de completer la ligne en fonction de la chaine de caractere representant la couleur donnée par le joueur 
 * 
 * @param choix ligne actuellement en jeu
 * @param index index de la position de la couleur choisie
 * @param colorName chaine de caractere representant la couleur 
 */
void fillChoixWithColor(ligne *choix, int index, char *colorName)
{
    colorName = charPointerToUpperCase(colorName);

    printf("color = %s\n", colorName);

    if (strcmp(colorName, "ROUGE") == 0)
    {
        choix->pion[index] = ROUGE;
    }
    else if (strcmp(colorName, "JAUNE") == 0)
    {
        choix->pion[index] = JAUNE;
    }
    else if (strcmp(colorName, "BLEU") == 0)
    {
        choix->pion[index] = BLEU;
    }
    else if (strcmp(colorName, "ORANGE") == 0)
    {
        choix->pion[index] = ORANGE;
    }
    else if (strcmp(colorName, "VERT") == 0)
    {
        choix->pion[index] = VERT;
    }
    else if (strcmp(colorName, "BLANC") == 0)
    {
        choix->pion[index] = BLANC;
    }
    else if (strcmp(colorName, "VIOLET") == 0)
    {
        choix->pion[index] = VIOLET;
    }
    else if (strcmp(colorName, "ROSE") == 0)
    {
        choix->pion[index] = ROSE;
    }
    else
    {
        printf("Cette couleur %s n'existe pas dans le jeu\n", colorName);
    }
}

/**
 * @brief Cette fonction permet de convertir la couleur donnée par l'utilisateur en majuscule afin d'eviter les malentendus 
 * 
 * @param name 
 * @return char* 
 */
char *charPointerToUpperCase(char *name)
{
    name = strdup(name); // make a copy of name
    for (char *p = name; *p; p++)
    {
        *p = toupper(*p);
    }

    return name;
}

/**
 * @brief Cette fonction permet de savoir si la ligne est remplie ou non 
 * 
 * @param choix 
 * @return true si la ligne est remplie
 * @return false si il y a des cases vides dans la ligne
 */
bool isFull(ligne *choix)
{
    bool indiceFull = true;
    for (int i = 0; i < nombreColonne; i++)
    {
        if (choix->pion[i] == NONE)
            indiceFull = false;
    }

    return indiceFull;
}

/**
 * @brief Cette fonction permet d'initialiser la couleur de chaque pion de la ligne 
 * 
 * @param choix nouvelle ligne du jeu
 */
void initalizePion(ligne *choix)
{
    for (int i = 0; i < nombreColonne; i++)
    {
        choix->pion[i] = NONE;
    }
}

/**
 * @brief Cette fonction permet d'afficher le choix du joueur au fur et à mesure que celui-ci rempli la ligne 
 * 
 * @param proposition 
 */
void displayChoice(ligne *proposition)
{
    printf("|");
    for (int i = 0; i < nombreColonne; i++)
    {
        switch (proposition->pion[i])
        {
        case ROUGE:
            printf("    ROUGE   |");
            break;
        case JAUNE:
            printf("    JAUNE   |");
            break;
        case BLEU:
            printf("    BLEU    |");
            break;
        case ORANGE:
            printf("    ORANGE  |");
            break;
        case VERT:
            printf("    VERT    |");
            break;
        case BLANC:
            printf("    BLANC   |");
            break;
        case VIOLET:
            printf("    VIOLET  |");
            break;
        case ROSE:
            printf("    ROSE    |");
            break;

        default:
            printf(" %d  ****   |", i);
            break;
        }
    }
    printf("\n");
}

/**
 * @brief Cette fonction permet d'afficher ce que vient de jouer le joueur 
 * Cette fonction peut etre utiliser pour faire du debug ou de l'affichage
 * 
 * @param joueur 
 */
void displayPlayerChoice(joueur *joueur)
{
    printf("|");
    for (int i = 0; i < nombreColonne; i++)
    {
        switch (joueur->proposition->pion[i])
        {
        case ROUGE:
            printf("    ROUGE   |");
            break;
        case JAUNE:
            printf("    JAUNE   |");
            break;
        case BLEU:
            printf("    BLEU    |");
            break;
        case ORANGE:
            printf("    ORANGE  |");
            break;
        case VERT:
            printf("    VERT    |");
            break;
        case BLANC:
            printf("    BLANC   |");
            break;
        case VIOLET:
            printf("    VIOLET  |");
            break;
        case ROSE:
            printf("    ROSE    |");
            break;

        default:
            printf(" %d  ****   |", i);
            break;
        }
    }
    printf("\n");
}

/**
 * @brief Cette fonction permet de connaitre le mode de jeu choisi par le joueur 
 * 
 * @return true si le JoueurVSJoueur 
 * @return false si JoueurVSOrdinateur
 */
bool modeChoice()
{
    printf("Mode de jeu :\n");
    printf("    1 - Mode Joueur Vs Joueur\n");
    printf("    2 - Mode Joueur Vs Ordinateur\n");

    int playerAnswer;

    do
    {
        printf("Choix = ");
        scanf(" %d", &playerAnswer);
    } while (playerAnswer != 1 && playerAnswer != 2);

    if (playerAnswer == 1)
    {
        printf("Vous avez choisi le mode Joueur Vs Joueur\n");
        return true;
    }
    else
    {
        printf("Vous avez choisi le mode Joueur Vs Ordinateur\n");
        return false;
    }
}

/**
 * @brief Cette fonction permet d'initaliser le nombre de colonne dans le jeu
 * 
 */
void numberColorChoice()
{
    printf("Combien de colonne de couleur souhaitez-vous utiliser (version officiel -> 4 colonnes\n");

    do
    {
        printf("Choix = ");
        scanf(" %d", &nombreColonne);
    } while (nombreColonne < 0);

    printf("Est ce que %d colonnes vous convient ? (o/n)\n", nombreColonne);
    char playerAnswer;

    do
    {
        scanf(" %c", &playerAnswer);
    } while (playerAnswer != 'o' && playerAnswer != 'O' && playerAnswer != 'n' && playerAnswer != 'N');

    while (playerAnswer == 'n' || playerAnswer == 'N')
    {
        do
        {
            printf("Choix = ");
            scanf(" %d", &nombreColonne);
        } while (nombreColonne < 0);

        printf("Est ce que %d colonnes vous convient ? (o/n)\n", nombreColonne);

        do
        {
            scanf(" %c", &playerAnswer);
        } while (playerAnswer != 'o' && playerAnswer != 'O' && playerAnswer != 'n' && playerAnswer != 'N');
    }
}

int main(void)
{
    joueur thomas;

    thomas.nom = "Test";
    thomas.score = 0;

    Couleur combinaison;

    combinaisonInput(&combinaison);

    //playerInput(&thomas);
}