#include "main.h"

int main()
{
    Couleur combinaison;
    joueur joueur1;

    joueur1.nom = "Test";
    joueur1.score = 0;

    numberColorChoice();
    combinaisonInput(&combinaison);

    playerInput(&joueur1, &combinaison);

    return 0;
}
