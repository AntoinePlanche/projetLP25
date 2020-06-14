#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../include/gestionEnregistrement.h"

/**
 * @brief This method is used to delete a file
 * 
 * @return void permet de rappeller la fonction autant de fois que le joueur le souhaite ?
 */
void deleteFile()
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./Previous-Game");
    char playerAnswer, choixFile[100], *testCSVFile, folder[100] = FOLDER_NAME;

    printf("Voulez vous supprimer un fichier ? (o/n)\n");
    scanf(" %c", &playerAnswer);
    while (playerAnswer != 'o' && playerAnswer != 'O' && playerAnswer != 'n' && playerAnswer != 'N')
    {
        printf("Votre reponse doit etre (o/n)\n");
        scanf(" %c", &playerAnswer);
    }
    if (playerAnswer == 'O' || playerAnswer == 'o')
    {
        d = opendir("./Previous-Game");
        printf("Voici la liste des fichiers de sauvegarde :\n");
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                testCSVFile = strstr(dir->d_name, ".csv");

                if (testCSVFile != NULL)
                {
                    printf("- %s\n", dir->d_name);
                }
            }
            closedir(d);
        }

        bool testFind = false;
        printf("Quel fichier voulez-vous supprimer ?\n");
        scanf("%s", choixFile);

        int ret = remove(strcat(folder, choixFile));

        if (ret == 0)
        {
            printf("Fichier supprimé \n");
            return deleteFile();
        }

        else
        {
            testFind = true;
        }

        while (testFind)
        {
            printf("Erreur ! Merci de saisir un nom de fichier correct !\n");
            printf("Quel fichier voulez-vous supprimer ?\n");
            scanf("%s", choixFile);

            int ret = remove(strcat(folder, choixFile));

            if (ret == 0)
            {
                printf("Fichier supprimé \n");
                return deleteFile();
            }

            else
            {
                testFind = true;
            }
        }
    }
}

/**
 * @brief This method is used to find File Name
 * 
 * @return void* 
 */
void *findFileName()
{

    DIR *d;
    struct dirent *dir;
    d = opendir("./Previous-Game");
    char choixFile[100];
    char *testCSVFile;

    printf("Voici la liste des fichiers de sauvegarde :\n");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            testCSVFile = strstr(dir->d_name, ".csv");

            if (testCSVFile != NULL)
            {
                printf("- %s\n", dir->d_name);
            }
        }
        closedir(d);
    }
    d = opendir("./Previous-Game");
    bool testFind = false;
    printf("\nQuelle partie voulez-vous reprendre ? (par exemple fichier.csv)\n");
    scanf("%s", choixFile);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            testCSVFile = strstr(dir->d_name, ".csv");

            if (testCSVFile != NULL && strcmp(choixFile, dir->d_name) == 0)
            {
                strcpy(filename, dir->d_name);
                printf("Vous avez choisi de reprendre la partie %s !\n\n", dir->d_name);
                closedir(d);
                return 0;
            }
            else
            {
                testFind = true;
            }
        }
        closedir(d);
    }

    while (testFind)
    {
        printf("\nQuelle partie voulez-vous reprendre ? (par exemple fichier.csv)\n");
        scanf("%s", choixFile);
        d = opendir("./Previous-Game");
        if (d)
        {

            while ((dir = readdir(d)) != NULL)
            {
                testCSVFile = strstr(dir->d_name, ".csv");

                if (testCSVFile != NULL && strcmp(choixFile, dir->d_name) == 0)
                {
                    strcpy(filename, dir->d_name);
                    printf("Vous avez choisi de reprendre la partie %s !\n\n", dir->d_name);

                    closedir(d);
                    return 0;
                }
                else
                {
                    testFind = true;
                }
            }
            closedir(d);
        }
    }

    return 0;
}
