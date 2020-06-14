#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>

#define LENGTH_NAME 20
#define CLEAR "cls||clear"
#define FOLDER_NAME "Previous-Game/"

/** DEFINE MACROS **/
#define TO_INT(x) atoi(x)

#define RETURN printf("\n")

#define ASSERT(message) fprintf(stderr, __FILE__ ":%d: " message "\n", __LINE__)

#define ASSERT_INT(message, data) fprintf(stderr, __FILE__ ":%d: " message " = %d\n", __LINE__, data)

#define ASSERT_DATA(message, data) fprintf(stderr, __FILE__ ":%d: " message " = %s\n", __LINE__, data)

/**
 * @brief All the color a cell can have 
 * 
 */
typedef enum couleur
{
    ROUGE,
    JAUNE,
    BLEU,
    ORANGE,
    VERT,
    BLANC,
    VIOLET,
    ROSE,
    NONE
} Couleur;

/**
 * @brief This struct represents a line 
 * 
 */
typedef struct ligne
{
    Couleur *pion;
    int nbrBonneCouleurBonEndroit;
    int nbrBonneCouleurMauvaisEndroit;
} ligne;

/// Pointer of line
typedef ligne *mastermind;

/**
 * @brief This struct represents a player 
 * 
 * This player has :
 * - name
 * - Pointer of line, then all the game is stored in the player proposition pointer 
 * - score  
 */
typedef struct joueur
{
    char nom[LENGTH_NAME];
    mastermind proposition;
    int score;
} joueur;

/// Number of column
extern int nombreColonne;
/// Number of trials
extern int nombreEssais;
/// Number of lines filled by the player
extern int playerLinesCount;

void process_field(int field_count, char *value);

#endif // DEFINE_H_INCLUDED
