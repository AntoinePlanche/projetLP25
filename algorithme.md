``` ALGORITHME FONCTION MAIN

        si( FICHIERSAUVEGARDE est vide)

            match contre ordinateur ou contre utilisateur

            si(ordinateur)

                Cb de pion fait un ligne ? (stock�e dans variable n)
                on enregistre n dans FICHIERSAUVEGARDE.
                On alloue dynamiquement un tableau de couleur de taille n
                pour i allant de 1 � n

                    On initialise Couleur[i] de facon al�atoire avec la fonction rand (on lui fait prendre une couleur au hasard)

                Cb d'essai voulez vous ? ( stock�e dans varable x)
                On alloue dynamiquement un tableau de stucture ligne (mastermind cf define.h) de taille x avec le membre Couleur[] de taille n
                on enregistre x dans FICHIERSAUVEGARDE.
                pour i allant de 1 � x avec pas de 1

                    appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] remplie selon les souhaits de l'utilisateur
                    on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                    si( ligne[i].nbrBonneCouleurBonEndroit == n)

                       { VICTOIRE -> on sort du programme }

                    enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                {DEFAITE}

            sinon -> on joue contre un autre utilisateur

                Cb de pion fait un ligne ? (stock�e dans variable n)
                on enregistre n dans FICHIERSAUVEGARDE.
                On alloue dynamiquement un tableau de couleur de taille n

                pour i allant de 1 � n avec pas de 1

                    On remplie Couleur[i] avec le choix de l'utilisateur

                Cb d'essai voulez-vous ? ( stock�e dans varable x)
                On alloue dynamiquement un tableau de stucture ligne (mastermind cf define.h) de taille x avec le membre Couleur[] de taille n
                on enregistre x dans FICHIERSAUVEGARDE.
                pour i allant de 1 � x avec pas de 1

                    appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] remplie selon les souhaits de l'utilisateur
                    on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                    si( ligne[i].nbrBonneCouleurBonEndroit == n)

                        VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                    enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                DEFAITE -> on sort du programme et on efface le FICHIERSAUVEGARDE



        Sinon (FICHIERSAUVEGARDE pas vide) -> la principale difficult� est qu'on ne sait pas quelles informations poss�dent le fichier peut etre juste x ou juste x et n ou x et n et pleins de lignes


            on recup�re n (il existe forc�ment si le FICHIERSAUVEGARDE n'est pas vide (premi�re information))

            si (x existe dans le fichier)

                on recup�re x
                On alloue dynamiquement un tableau de couleur de taille n de facon al�atoire avec la fonction rand()
                On alloue dynamiquement un tableau de stucture ligne (mastermind cf define.h) de taille x avec le membre Couleur[] de taille n

                si ("ligneObjectif" est definie dans le fichier )

                    on recupere ligneObjectif dans le tableau de Couleur
                    i = 0

                    tant que (ligne[i] est definie dans le FICHIERSAUVEGARDE)

                        on remplie le tableau de structure ligne � l'index i
                        i++

                    pour j allant de i � x avec pas de 1

                        appelle de la fonction de remplissage qui prend en param�tre ligne[j]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] rempli selon les souhait de l'utilisateur
                        on envoi ligne[j] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                        si( ligne[i].nbrBonneCouleurBonEndroit == n)

                            VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                        enregistrement dans le FICHIERSAUVEGARDE de ligne[j] � travers une fonction d'enregistrement qui recoit ligne[j]

                    DEFAITE et on efface le FICHIERSAUVEGARDE

                sinon -> "ligneObjectif" n'est pas definie dans le fichier

                    On demande si l'utilisateur veut jouer contre l'ordinateur ou contre un autre joueur
                    si(ordinateur)

                        pour i allant de 1 � n

                            On initialise Couleur[i] de facon al�atoire avec la fonction rand (on lui fait prendre une couleur au hasard)

                        pour i allant de 1 � x avec pas de 1

                            appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] rempli selon les souhaits de l'utilisateur
                            on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                            si( ligne[i].nbrBonneCouleurBonEndroit == n)

                                VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                            enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                        {DEFAITE}

                    Sinon -> on joue contre un autre utilisateur

                         pour i allant de 1 � n avec pas de 1

                            On remplie Couleur[i] avec le choix de l'utilisateur

                         pour i allant de 1 � x avec pas de 1

                                appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] rempli selon les souhaits de l'utilisateur
                                on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                                si( ligne[i].nbrBonneCouleurBonEndroit == n)

                                    VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                                enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                         DEFAITE -> on sort du programme ET on efface le FICHIERSAUVEGARDE


            sinon -> x n'existe pas dans le FICHIERSAUVEGARDE

                On demande x
                On alloue dynamiquement un tableau de couleur de taille n de facon al�atoire avec la fonction rand()
                On alloue dynamiquement un tableau de stucture ligne (mastermind cf define.h) de taille x avec le membre Couleur[] de taille n
                On demande si l'utilisateur veut jouer contre l'odrinateur ou contre un autre jouer
                    si(ordinateur)

                        pour i allant de 1 � n

                            On initialise Couleur[i] de facon al�atoire avec la fonction rand (on lui fait prendre une couleur au hasard)

                        pour i allant de 1 � x avec pas de 1

                            appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] remplie selon les souhaits de l'utilisateur
                            on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                            si( ligne[i].nbrBonneCouleurBonEndroit == n)

                                VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                            enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                        {DEFAITE}

                    Sinon -> on joue contre un autre utilisateur

                        pour i allant de 1 � n avec pas de 1

                            On remplie Couleur[i] avec le choix de l'utilisateur

                         pour i allant de 1 � x avec pas de 1

                                appel de la fonction de remplissage qui prend en param�tre ligne[i]( permet � l'utilisateur de choisir comment remplir sa ligne)-> renvoi ligne[i] remplie selon les souhaits de l'utilisateur
                                on envoie ligne[i] dans la fonction de v�rification qui va se charger de remplir les membres nbrBonneCouleurBonEndroit et nbrBonneCouleurMauvaisEndroit de la structure ligne[i]

                                si( ligne[i].nbrBonneCouleurBonEndroit == n)

                                    VICTOIRE -> on sort du programme et on efface le FICHIERSAUVEGARDE

                                enregistrement dans le FICHIERSAUVEGARDE de ligne[i] � travers une fonction d'enregistrement qui recoit ligne[i]

                         DEFAITE -> on sort du programme ET on efface le FICHIERSAUVEGARDE

        FIN

```