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

   /* Allocation memoire de base */
   Univers *u=allouerUnivers(0,3,21,argv[1],"000000000000000000000");
   // u->plateau=allouerPlateau(u->nb_cellules);
   u->joueur=allouerJoueurs(u->nb_joueurs);
   u->monstre=allouerMonstres(u->nb_cellules);
   chargerQuestions(u,argv[1]);

   printf("\n\033[1;4m Affichage de l'état initial :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Deplacement d'un joueur de  */

   deplacer(u,u->joueur[0]->troll,0,15);
   deplacer(u,u->joueur[1]->troll,0,16);

   printf("\n\033[1;4m Affichage de l'état (1) :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Blessure d'un Joueur */
   blesser(u->joueur[0]->troll,20);

   printf("\n\033[1;4m Affichage de l'état (2) :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Soigner un joueur */
   soigner(u->joueur[0]->troll);

   printf("\n\033[1;4m Affichage de l'état (3) :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Gain d'experience d'un Joueur */
   gainExp(u->joueur[0]->troll,50);

   printf("\n\033[1;4m Affichage de l'état (4) :\033[0m\n");
   INTFC_afficherEtats(u);

   /* Test de la fonction estAllie() */
   printf("Test de la fonction estAllie()...\n");

   printf("1 = %d\n",estAllie(u->joueur[0]->troll,u->joueur[0]->magicien));   
   printf("0 = %d\n",estAllie(u->joueur[0]->troll,u->joueur[1]->magicien));

   /* Test de la fonction reunion */
   printf("Test de la fonction reunion()...\n");

   printf("0 = %d\n",reunion(u,u->joueur[0]->troll,15));
   deplacer(u,u->joueur[0]->magicien,0,15);
   printf("1 = %d\n",reunion(u,u->joueur[0]->troll,15));   
   
   return 0;
}

	  
