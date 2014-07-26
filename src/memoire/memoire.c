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
 * @file memoire.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "memoire.h"
#include "questions.h"

Univers *allouerUnivers(int vgame_mode,int vnb_joueurs, int vnb_cellules,char *vquestions,char *vmasque){
   /* Allocation en memoire de l'Univers */
   Univers *u=(Univers *)malloc(sizeof(Univers));

   /* Initialisation des champs de l'Univers */
   u->game_mode=vgame_mode;
   u->nb_joueurs=vnb_joueurs;
   u->nb_cellules=vnb_cellules;
   u->plateau=allouerPlateau(vnb_cellules,vmasque);;
   u->joueur=allouerJoueurs(vnb_joueurs);
   u->monstre=allouerMonstres(vnb_cellules);
   u->BOSS=allouerPersonnage(-1,BOSSFINAL,1,EXP_BOSS,EXP_BOSS,CASE_FINALE,"Boss");
   u->nb_questions=(int *)malloc(sizeof(int));
   *(u->nb_questions)=0;
   chargerQuestions(u,vquestions);
   
   return u;
}

void libererUnivers(Univers *u){
   libererPlateau(u->plateau);
   libererJoueurs(u->joueur);
   libererMonstres(u->monstre);
   libererQuestions(u->questions);
   free(u->nb_questions);
   libererPersonnage(u->BOSS);
   free(u);
}

Cellule **allouerPlateau(int n,char *masque){
   int i;

   /* Allocation en memoire du plateau */
   Cellule **p=(Cellule **)calloc(n,sizeof(Cellule));


   for(i=0;i<n;i++){
      /* Allocation en memoire de la cellule i du plateau */
      p[i]=(Cellule *)malloc(sizeof(Cellule));

      /* Initialisation des champs */
      p[i]->type=(int)masque[i]-48;
      p[i]->last=NULL;
   }
   return p;
}

void libererPlateau(Cellule **p){
   int i;
   for(i=0;p[i];i++) free(p[i]);
   free(p);
}

Personnage *allouerPersonnage(int id,int type,int pouvoir,int exp,int energie,int pos,char *label){
   /* Allocation memoire du Personnage */
   Personnage *p=(Personnage *)malloc(sizeof(Personnage));

   /* Initialisation des champs */
   p->id=id;
   p->type=type;
   p->pouvoir=pouvoir;
   p->exp=exp;
   p->energie=energie;
   p->pos=pos;

   /* Allocation memoire du label */
   p->label=(char *)calloc(strlen(label)+1,sizeof(char));
   
   strcpy(p->label,label);
   return p;
}

void libererPersonnage(Personnage *p){
   free(p->label);
   free(p);
}

Joueur **allouerJoueurs(int n){
   int i;
   Joueur **j;
   /* Alloue */
   j=(Joueur **)calloc(n+1,sizeof(Joueur *));
   for(i=0;i<n;i++){
      /* Allocation en memoire du joueur i*/
      j[i]=(Joueur *)malloc(sizeof(Joueur));

      /* Allocaion memoire des heros */
      j[i]->troll=allouerPersonnage(i,TROLL,1,EXP_TROLL,EXP_TROLL,0,"Troll");
      j[i]->magicien=allouerPersonnage(i,MAGICIEN,1,EXP_MAGICIEN,EXP_MAGICIEN,0,"Magicien");
   }

   return j;
}

void libererJoueurs(Joueur **j){
   int i;
   for(i=0;j[i];i++){
      libererPersonnage(j[i]->troll);
      libererPersonnage(j[i]->magicien);
      free(j[i]);
   }
   free(j);
}

Personnage **allouerMonstres(int n){
   int i,e;
   Personnage **m;
   /* Alloue */
   m=(Personnage **)calloc(n,sizeof(Personnage));
   for(i=0;i<n;i++){
      e=rand()%50;
      m[i]=allouerPersonnage(-1,MONSTRE,0,e,e,i,"Monstre");
   }
   return m;
}

void libererMonstres(Personnage **m){
   int i;
   for(i=0;m[i];i++){
      libererPersonnage(m[i]);
   }
   free(m);
}

void chargerQuestions(Univers *u,char *fichier){
   int i=0;
   FILE *f;
   char buffer[256];

   /* Alloue la structure */
   u->questions=(Question **)calloc(5,sizeof(Question *));

   /* Ouverture du fichier de questions */
   f=fopen(fichier,"r");

   if(f){
      /* Parcours du fichier de questions */
      while(fgets(buffer,256,f)!=NULL){
	 u->questions[i]=interpreterLigne(buffer);
	 (*(u->nb_questions))++;
	 i++;
      }
   }else{
      perror("Erreur lors de l'ouverture du fichier de questions.");
   }
}

void libererQuestion(Question *q){
   int i;
   free(q->texte);
   for(i=0;i<3;i++){
      free(q->choix[i]);
   }
   free(q->choix);
   free(q);
}

void libererQuestions(Question **q){
   int i;
   for(i=0;q[i];i++){
      libererQuestion(q[i]);
   }
   free(q);
}
