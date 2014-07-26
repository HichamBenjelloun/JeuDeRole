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
 * @version    2.0 - Nov 25, 2012
 * 
 * @todo
 * @bug Pas de bug detecte.
 */

/**
 * @file primitives.c
 *  
 * Definition des fonctions elementaires.
 *
 */

#include "primitives.h"

char *getType(Personnage *a){
   char *type=(char *)calloc(10,sizeof(char));
   switch(a->type){
   case TROLL:
      sprintf(type,"Troll");
      break;
   case MAGICIEN:
      sprintf(type,"Magicien");
      break;
   case MONSTRE:
      sprintf(type,"Monstre");
      break;
   case BOSSFINAL:
      sprintf(type,"BOSS");
      break;
   }
   return type;
}

int lancerDeAttaque(Personnage *p){
   switch(p->type){
   case TROLL:
   case MAGICIEN:
   case MONSTRE:
      return 1+rand()%DE_ATTAQUE;
   case BOSSFINAL:
      return 1+rand()%DE_ATTAQUEBOSS;
   default:
      return 0;
   }
}

int lancerDeDeplacement(Personnage *p){
   switch(p->type){
   case TROLL:
   case MAGICIEN:
      return 1+rand()%DE_DEPLACEMENT;
   default:
      return 0;
   }
}

void deplacer(Univers *u,Personnage *p,int a,int b){
   /* Maj du plateau */
   u->plateau[a]->last=NULL;

   /* Maj position < a 21 */
   p->pos=(b<21)?b:21;
}

void blesser(Personnage *p, int b){
   /* Perte de points d'energie */
   p->energie-=b;

   /* On ramene l'energie a zero si elle est negative */
   if(p->energie<0) p->energie=0; 

   /* Interface */
   INTFC_blesser(p,b);
}

void soigner(Personnage *p){
   p->energie=p->exp;
}

void gainExp(Personnage *a,int ajout){
   /* Gain d'experience et mise a jour de l'energie */
   a->exp+=ajout;
   a->energie=a->exp;

   /* Interface */
   INTFC_gainExp(a,ajout);
}

int estAllie(Personnage *a,Personnage *b){
   return (a->id == b->id);
}

int reunion(Univers *u,Personnage *p, int c){
   int j=p->id;
   return ((u->joueur[j]->troll)->pos==c && (u->joueur[j]->magicien)->pos==c);
}
