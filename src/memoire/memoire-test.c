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
 * @author Auteur1 <mail@ecole.ensicaen.fr> 
 * @author Auteur2 <mail@ecole.ensicaen.fr> 
 * @version     0.0.1 - Sep 20, 2010
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file header.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "memoire.h"

int main(int argc, char* argv[]) {
   /* Allouer Univers OK */
   Univers *u=allouerUnivers(0,10,21,argv[1],"000000000000000000000");
   /* Allouer plateau OK */
   //u->plateau=allouerPlateau(10);
   /* Liberer plateau OK */
   //libererPlateau(u->plateau);
   /* Allouer Joueurs OK */
   //u->joueur=allouerJoueurs(100);
   //libererJoueurs(u->joueur);
   /* Allouer Monstres OK */
   //u->monstre=allouerMonstres(21);
   //libererMonstres(u->monstre);
   /* Charger les questions en memoire OK */
   chargerQuestions(u,argv[1]);
   int i;
   printf("questions : %d",*(u->nb_questions));

   for(i=0;i<*u->nb_questions;i++){
      printf("%s ? %s %s %s",
	     u->questions[i]->texte,
	     u->questions[i]->choix[0],
	     u->questions[i]->choix[1],
	     u->questions[1]->choix[2]);
   }
   
   libererQuestions(u->questions);
   return 0;
}
