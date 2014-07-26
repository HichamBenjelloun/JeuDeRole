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
 * @author Hicham Benjelloun <benjelloun@ecole.ensicaen.fr> 
 * @version    2.0 - Nov 25 2012
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file main.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "header.h"
#include "memoire.h"
#include "jeu.h"


int main(int argc, char* argv[]) {
   int i,k,n,g;
   k=1;
   /* */

   srand(1);

   /* Mode de jeu */
   g=INTFC_ChoixModeDeJeu();
   
   /* Nombre de Joueurs */
   do{
      n=INTFC_ChoixNbJoueurs();
   } while(n<2);

  /* Allocation memoire de base */
   Univers *u=allouerUnivers(g,n,22,argv[1],"0121321231213212312210");

   /* Deroulement du Jeu */
   while(u->BOSS->energie){
      tourDeJeu(u,k);
      k++;
   }
   
   return 0;
}
