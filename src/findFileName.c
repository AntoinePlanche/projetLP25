#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <dirent.h>
#include "../include/gestionEnregistrement.h"

void *findFileName(){

    DIR *d;
    struct dirent *dir;
    d = opendir("./Previous-Game");
    char choixFile [100];
    char *testCSVFile;
    int nbFileCSV = 0;


        printf("Voici la liste des fichiers de sauvegarde :\n");
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {
                    testCSVFile = strstr(dir->d_name, ".csv");

                    if(testCSVFile != NULL) {
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

                    if(testCSVFile != NULL && strcmp(choixFile, dir->d_name) == 0) {
                        //printf("%i", strcmp(choixFile, dir->d_name));
                        //printf("%s\n", dir->d_name);

                        printf("Vous avez choisi de reprendre la partie %s !\n\n", dir->d_name);
                        strcpy(filename, dir->d_name);
                        closedir(d);
                        return 0;

                    } else {
                    testFind = true;
                    }

                }
                closedir(d);
            }


            while(testFind)
            {
                printf("\nQuelle partie voulez-vous reprendre ? (par exemple fichier.csv)\n");
                scanf("%s", choixFile);
                d = opendir("./Previous-Game");
                if(d)
                {

                    while ((dir = readdir(d)) != NULL)
                    {
                        testCSVFile = strstr(dir->d_name, ".csv");

                        if(testCSVFile != NULL && strcmp(choixFile, dir->d_name) == 0) {
                            //printf("%i", strcmp(choixFile, dir->d_name));
                            //printf("%s\n", dir->d_name);

                            printf("Vous avez choisi de reprendre la partie %s !\n\n", dir->d_name);
                            strcpy(filename, dir->d_name);
                            closedir(d);
                            return 0;


                        } else {
                            testFind = true;
                        }

                    }
                    closedir(d);
                }

        }




    return 0;

}
