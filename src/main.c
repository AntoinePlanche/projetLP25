#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "../include/define.h"
#include "../include/playerInput.h"
#include "../include/gestionEnregistrement.h"

int main()
{
    // SI fichier est vide
    char choixReprendrePartie, str[100];
    int numeroEssai = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir("./Previous-Game");
    char *isCSVFile;
    int nbFileCSV = 0;
    srand(time(NULL));
    joueur *nouveauJoueur = malloc(sizeof(joueur));
    printf("Bonjour, quel est votre nom ?\n");
    scanf("%s", nouveauJoueur->nom);
    Couleur *combinaisonSecret = (Couleur *)malloc(nombreColonne * sizeof(Couleur));

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            isCSVFile = strstr(dir->d_name, ".csv");

            if (isCSVFile != NULL)
            {
                nbFileCSV = nbFileCSV + 1;
            }
        }
        closedir(d);
        if (nbFileCSV != 0)
        {

            printf("Voulez-vous reprendre une partie en cours ? (o/n)\n");
            scanf(" %c", &choixReprendrePartie);
            while (choixReprendrePartie != 'o' && choixReprendrePartie != 'O' && choixReprendrePartie != 'n' && choixReprendrePartie != 'N')
            {
                printf("Voulez-vous reprendre une partie en cours ? (o/n)\n");
                scanf(" %c", &choixReprendrePartie);
            }

            if (choixReprendrePartie == 'o' || choixReprendrePartie == 'O')
            {

                findFileName();

                createGameFromFile(combinaisonSecret, nouveauJoueur);

                numeroEssai = nombreEssais - essaisRestants;

                printf("COMBINAISON : \n");
                displayChoice(combinaisonSecret);

                printf("ANCIENS CHOIX : \n");
                for (int i = 0; i < playerLinesCount; i++)
                {
                    RETURN;
                    ASSERT_INT("LIGNE N°", i);
                    displayChoice(nouveauJoueur->proposition[i].pion);

                    ASSERT_INT("MAUVAISE REPONSE", nouveauJoueur->proposition[i].nbrBonneCouleurMauvaisEndroit);

                    ASSERT_INT("BON REPONSE", nouveauJoueur->proposition[i].nbrBonneCouleurBonEndroit);
                }
            }
            else
            {
                createGameFile(*nouveauJoueur, str);

                nouveauJoueur->score = 0;
                essaisNumberChoice();
                numberColorChoice();
                nouveauJoueur->proposition = (ligne *)malloc(sizeof(ligne) * nombreEssais);
                if (nouveauJoueur->proposition == NULL)
                {
                    printf("erreur d'allocation memoire");
                    exit(1);
                }

                for (int i = 0; i < nombreEssais; i++)
                {
                    nouveauJoueur->proposition[i].pion = (Couleur *)malloc(sizeof(Couleur) * nombreColonne);

                    if (nouveauJoueur->proposition[i].pion == NULL)
                    {
                        printf("erreur d'allocation memoire\n");
                        exit(1);
                    }
                }

                combinaisonInput(combinaisonSecret, nouveauJoueur);
            }
        }
        else
        {

            createGameFile(*nouveauJoueur, str);

            nouveauJoueur->score = 0;
            essaisNumberChoice();
            numberColorChoice();
            nouveauJoueur->proposition = (ligne *)malloc(sizeof(ligne) * nombreEssais);
            if (nouveauJoueur->proposition == NULL)
            {
                printf("erreur d'allocation memoire");
                exit(1);
            }

            for (int i = 0; i < nombreEssais; i++)
            {
                nouveauJoueur->proposition[i].pion = (Couleur *)malloc(sizeof(Couleur) * nombreColonne);
                if (nouveauJoueur->proposition[i].pion == NULL)
                {
                    printf("erreur d'allocation memoire\n");
                    exit(1);
                }
            }

            combinaisonInput(combinaisonSecret, nouveauJoueur);
        }
    }

    for (int i = 0; i < nombreEssais; i++)
    {
        playerInput(nouveauJoueur, combinaisonSecret, i);
    }
    //remove(strcat("Previous-Game/",filename));
    printf("Dommage %s, vous avez perdu, n'hesitez pas a reessayer.\n", nouveauJoueur->nom);

    return 0;
}
