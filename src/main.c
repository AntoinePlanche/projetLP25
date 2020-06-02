#include "../include/main.h"

int main()
{
    Couleur combinaison;
    joueur joueur1;

    joueur1.nom = "Test";
    joueur1.score = 0;

    essaisNumberChoice();
    numberColorChoice();

    combinaisonInput(&combinaison);

    playerInput(&joueur1, &combinaison);

    return 0;
}
