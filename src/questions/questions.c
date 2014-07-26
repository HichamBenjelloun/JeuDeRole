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
 * @author Benjelloun Hicham <benjelloun@ecole.ensicaen.fr> 
 * @version     1.0 - Nov 30, 2012
 * 
 * @todo
 * @bug
 */

/**
 * @file questions.c
 *  
 * 
 * 
 */

#include "header.h"

Question *interpreterLigne(char *buffer){
   int i;
   char *token=(char *)malloc(sizeof(char));
   char *to_delete=token;
   Question *q=(Question *)malloc(sizeof(Question));

   /* Allocation en memoire + init du texte de la question */
   token=strtok(buffer,"|");
   q->texte=(char *)calloc(strlen(token)+1,sizeof(char));
   strcpy(q->texte,token); 

   /* Allocation en memoire du tableau de choix */
   q->choix=(char **)calloc(3,sizeof(char *));

   /* Allocation en memoire + init des choix */
   for(i=0;i<3;i++){
      token=strtok(NULL,"|");
      q->choix[i]=(char *)calloc(strlen(token)+1,sizeof(char));
      strcpy(q->choix[i],token);
   }

   /* Solution */
   token=strtok(NULL,"|");
   q->solution=atoi(token);

   /* Liberation du token */
   free(to_delete);
   return q;
}

