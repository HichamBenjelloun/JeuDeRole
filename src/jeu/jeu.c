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
 * @file jeu.c
 *  
 * Definit les fonctions de jeu
 *
 */


#include "jeu.h"
#include "primitives.h"
#include "intfc.h"

void poserQuestion(Univers *u,Personnage *p){
   int i,correct;

   /* Choix aleatoire de la questions */
   i=rand()%*(u->nb_questions);

   /* Interface */
   correct=(INTFC_poserQuestion(u,i,p)==u->questions[i]->solution);
   INTFC_resultatQuestion(correct,p);

   /* Gain d'experience du joueur */
   if(correct) gainExp(p,10);
}

void deplacement(Univers *u,Personnage *p){
   int reponse=0;

   /* Interface */
   if(p->type==MAGICIEN && p->pouvoir) reponse=INTFC_demanderInvocation(u,p);
   
   /* Cas d'invocation */
   if(reponse) invocation(u,p);

   /* Maj de la position */
   deplacer(u,p,p->pos,p->pos+lancerDeDeplacement(p));

   /* Interface */
   INTFC_deplacer(p,p->pos);
}

void attaque(Univers *u,Personnage *a,Personnage *b){
   int puiss=0;
   int reponse=0;

   /* Interface */

   if(a->type==TROLL && a->pouvoir==1) reponse=INTFC_demanderMassue(u,a);

   /* Cas d'attaque massue */
   if(reponse) massue(a,b);

   /* Calcul de la puissance de l'attaque */
   puiss=lancerDeAttaque(a);

   /* Interface */
   INTFC_attaque(u,a,b);

   /* Degats de l'attaque */
   blesser(b,puiss);
}

void massue(Personnage *a,Personnage *b){
   if(a->type==TROLL && a->pouvoir){
      int n=40;
      int somme=0;
      /* Interface */
      INTFC_massue(a);

      /* Attaque massue */
      while(n--) somme+=lancerDeAttaque(a);
      blesser(b,somme);

      /* Maj du pouvoir */
      a->pouvoir=0;
   }
}

void invocation(Univers *u,Personnage *p){
   int e;

   if(p->type==MAGICIEN && p->pouvoir && p->pos){   
      /* Interface */
      INTFC_invocation(p);

      /* Maj du plateau */
      u->plateau[p->pos]->type=CASE_MONSTRE;

      /* Creation d'un nouveau monstre allie a p */
      e=rand()%50;

      /* Initisalisation du Monstre */
      u->monstre[p->pos]->id=p->id;
      u->monstre[p->pos]->exp=e;
      u->monstre[p->pos]->energie=e;

      /* Maj du pouvoir */
      p->pouvoir=0;
   }
}

void combat(Univers *u,Personnage *a,Personnage *b){
   /* Interface */
   INTFC_combat(a,b);

   /* Deroulement du combat */
   while(a->energie>0 && b->energie>0){
      attaque(u,a,b);
      if(b->energie>0) attaque(u,b,a);
   }

   /* Issue du combat */
   (a->energie)?victoire(u,a,b):victoire(u,b,a);
}

void combatFinal(Univers *u,int i){
   int puiss;

   /* Annonce du combat final */
   INTFC_combatFinal(i);

   /* Deroulement du combat */
   while(u->BOSS->energie>0 && 
	 ((u->joueur[i]->troll)->energie>0 || (u->joueur[i]->magicien)->energie>0)){
      /* Attaque du boss */
      if(u->BOSS->energie){
	 attaque(u,u->BOSS,u->joueur[i]->troll);
	 attaque(u,u->BOSS,u->joueur[i]->magicien);
	 /* Deconcentration du boss */
	 if(INTFC_deconcentration(u,u->BOSS,i)){
	    u->BOSS->pouvoir=0;
	    continue;
	 }else{
	    /* Attaque des heros */
	    if((u->joueur[i]->troll)->energie) attaque(u,u->joueur[i]->troll,u->BOSS);
	    if((u->joueur[i]->magicien)->energie) attaque(u,u->joueur[i]->magicien,u->BOSS);
	 }
      }
   }
 
   /* Issue du combat */
   INTFC_issueCombatFinal(i,u->BOSS->energie);   

   if(u->BOSS->energie){
      defaiteJoueur(u,u->joueur[i]);
      u->BOSS->pouvoir=1;
   }else{
      libererUnivers(u);
      exit(0);
   }
}

void victoire(Univers *u,Personnage *a,Personnage *b){
   /* Interface */
   INTFC_victoire(a,b);

   /* Gain d'experience de a */
   if(a->type<=1) gainExp(a,(b->exp)/2);

   /* Maj des positions */
   if(b->type<=1) deplacer(u,b,b->pos,0);

   /* Reinitialisation des energies */
   soigner(a);
   soigner(b);

   /* Maj du plateau */
   deplacer(u,a,a->pos,a->pos);

   if(b->type==MONSTRE){
      u->plateau[a->pos]->type=CASE_PAUSE;
   }
}
void defaiteJoueur(Univers *u,Joueur *j){
   /* Replacement du Joueur */
   j->troll->pos=0;
   j->magicien->pos=0;
   /* Reinitialisation des energies */
   soigner(j->troll);
   soigner(j->magicien);
}

void action(Univers *u,Personnage *p){
   int j,type;
   Personnage *perso;
   switch(u->plateau[p->pos]->type){
   case CASE_SANCTUAIRE:
      /* On verifie la presence des deux heros sur la CS de fin */
      if(reunion(u,p,CASE_FINALE)) combatFinal(u,p->id);     
      break;
   case CASE_QUESTION:
      poserQuestion(u,p);
      perso=u->plateau[p->pos]->last;
      if(perso && !estAllie(p,perso)) combat(u,p,perso);
      break;
   case CASE_MONSTRE:
      if(!estAllie(p,u->monstre[p->pos])) combat(u,p,u->monstre[p->pos]);
      break;
   case CASE_PAUSE:
      perso=u->plateau[p->pos]->last;
      if(perso && !estAllie(p,perso)) combat(u,p,perso);
      break;
   }
   /* Maj du plateau */
   u->plateau[p->pos]->last=p;
}

void tourDeJeu(Univers *u,int k){
   int i;
   INTFC_tourDeJeu(k);
   INTFC_afficherPlateau(u);
   INTFC_afficherEtats(u);
   
   for(i=0;i<u->nb_joueurs;i++){ 
      /* Troll */
      deplacement(u,u->joueur[i]->troll); 
      action(u,u->joueur[i]->troll); 
      /* Magicien */
      deplacement(u,u->joueur[i]->magicien);  
      action(u,u->joueur[i]->magicien); 
   }

}


