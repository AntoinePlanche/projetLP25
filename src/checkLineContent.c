#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/define.h"

bool checkLineContent(Couleur *targetLigne, ligne *input, int lengthLine)
{

    input->nbrBonneCouleurBonEndroit = 0;
    input->nbrBonneCouleurMauvaisEndroit = 0;

    for (int i = 0; i < lengthLine; i++)
    {
        printf("target = %d", targetLigne[i]);
        printf("player = %d", input->pion[i]);
        if (targetLigne[i] == input->pion[i])
        {
            input->nbrBonneCouleurBonEndroit++;
        }

        for (int j = 0; j < lengthLine; j++)
        {
            if (input->pion[j] == targetLigne[i] && i != j)
            {
                input->nbrBonneCouleurMauvaisEndroit++;
            }
        }
    }

    if (input->nbrBonneCouleurBonEndroit == lengthLine)
    {

        return true;
    }

    return false;
}
