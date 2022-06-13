# Projet-LP25

This project is a school project, it is based on the MasterMind game. 

### Who to compile ?

If you already have make installed on you computer, you can simply do :

```
Projet-LP25$ make
```

If you want to compile using gcc you can do :

```
Projet-LP25$ gcc -g playerInput.c createGameFile.c addLigneToFile.c combinaisonSecret.c main.c -o Mastermind
```

If none of them are installed you must have a look at http://www.mingw.org

### Launch 

Then to launch the program it is quit simple you only have to do :

```
ProjetLP25$ ./Mastermind
```

### How does it work ?

The first step when you launch the program is to give your name, it will be used to create a game file in which all the information of the game will be stored. 
If you already played to the game a file already exists, thus you will have to give a custom filename. 

The goal of doing that is to allow the player to stop the game and play again later.

* Rules

Concerning the rules, the player has to give a number of trials. This number corresponds to the number of row in the game. After that, the player has to give the number of columns he wants. The higher the number of columns is, the harder the game will be. Indeed, the chance to win decrease when increasing the number of columns or decreasing the number of trials. 

After giving the parameter of the game, the player has two possibilities.

- One player game

Then the computer randomly chose the secret combination. Then, the player has to find it within the number of trials given earlier.

- Two players game

Concerning this mode of the game, one player gives the secret combination and the other has to find it within the number of trials given earlier.

To give of proposition the player has to specify the column he wants to modify its colour. When the row is full of colour, the player can modify the colour of one column or continue to play. If he finds the secret combination, he wins the game.

### Structure

- Previous-Game folder are stored all the game files 
- include -> header
- src -> source code 
