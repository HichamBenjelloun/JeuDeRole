/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Benjelloun <benjelloun@ecole.ensicaen.fr> 
 *
 * @version     1.0 - Nov 30, 2012
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file header.c
 *  
 * 
 * 
 */

#include "header.h"
#include "primitives.h"
#include "memoire.h"

int main(int argc,char **argv){
   int n,g;
   srand(time(NULL));

   /* Choix du mode de jeu */
   printf("\n\033[1m Choix du mode de jeu :\033[0m\n\n");
 
   g=INTFC_ChoixModeDeJeu();
   printf("Le mode de Jeu entré est %d\n",g);

   /* Choix du nombre de Joueurs */
   printf("\n\033[1m Choix du nombre de joueurs :\033[0m\n\n");

   n=INTFC_ChoixNbJoueurs();
   printf("Le nombre de joueurs entré est %d\n",n);

   /* Univers */
   Univers *u=allouerUnivers(g,n,21,argv[1],"0121321231213212312210");   

   /* Affichage des Etats */
   INTFC_afficherEtats(u);

   /* Poser une question a un joueur */
   poserQuestion(u,u->joueur[0]->troll);

   printf("\n\033[1;4m Affichage de l'état (1) :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Deplacement d'un Joueur */
   deplacement(u,u->joueur[0]->troll);
    
   printf("\n\033[1;4m Affichage de l'état (2) :\033[0m\n");
   INTFC_afficherEtats(u);
    
   /* Attaque */
   attaque(u,u->joueur[rand()%u->nb_joueurs]->troll,u->joueur[rand()%u->nb_joueurs]->magicien);
   INTFC_afficherEtats(u);


   return 0;
}

	  
