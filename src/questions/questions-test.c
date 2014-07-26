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

#include "questions.h"

int main(int argc, char* argv[]) {
   FILE *f=fopen(argv[1],"r");
   Question *q;   

   if(f){
      //q=interpreterLigne(f);
   }else{
      perror("Erreur lors de l'ouverture du fichier.");
   }

   //printf("%s %s %s %s\n",q->texte,q->choix[0],q->choix[1],q->choix[2]);
   
   return 0;
}
