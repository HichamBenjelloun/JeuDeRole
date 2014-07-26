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
 * @version    1.0 - Nov 07, 2012
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file intfc_t.c
 *  
 * Interface de Jeu
 * Terminal
 */

#include "intfc.h"

MODE_JEU INTFC_ChoixModeDeJeu(){
   int mode;
   printf("Veuiller entrer le mode de jeu : (0) Automatique (1) Manuel\t");
   scanf("%d",&mode);
   return mode;
}

int INTFC_ChoixNbJoueurs(){
   int n;
   printf("Veuiller entrer le nombre de joueurs\t");
   scanf("%d",&n);
   return n;
}

void INTFC_afficherPlateau(Univers *u){
   int i;
   printf("\n");
   for(i=0;i<u->nb_cellules;i++){
      switch(u->plateau[i]->type){
      case CASE_SANCTUAIRE:
	 printf("(%s,%d)","CS",i);
	 break;
      case CASE_QUESTION:
	 printf("(%s,%d)","CQ",i);
	 break;
      case CASE_PAUSE:
	 printf("(%s,%d)","CP",i);
	 break;
      case CASE_MONSTRE:
	 printf("(%s,%d)","CM",i);
	 break;
      }
   }
}

void INTFC_afficherEtats(Univers *u){
   int i;
   printf("\n");
   for(i=0;i<u->nb_joueurs;i++){
      printf("J%d - T(%d)(%d/%d) M(%d)(%d/%d)\n",
	     i+1,
	     u->joueur[i]->troll->pos,u->joueur[i]->troll->energie,u->joueur[i]->troll->exp,
	     u->joueur[i]->magicien->pos,u->joueur[i]->magicien->energie,u->joueur[i]->magicien->exp
	     );
   }
}

void INTFC_deplacer(Personnage *p,int pos){
   printf("\033[36m%s %d va en position %d\n\033[0m",p->label,1+p->id,pos);
}

void INTFC_blesser(Personnage *p,int b){
   printf("\033[33m(%c%d,-%d)\033[0m",p->label[0],1+p->id,b); 
   /*printf("\033[33m%s %d perd %d points d'energie (reste %d/%d),\033[0m",p->label,1+p->id,b,p->energie,p->exp);*/
}

void INTFC_gainExp(Personnage *a,int ajout){
   printf("\033[32m(+%d EXP)\033[0m\n",ajout);
}

int INTFC_poserQuestion(Univers *u,int i,Personnage *p){
   int reponse;
   printf("\n\033[1m(Question)\033[0m Joueur %d : %s - (1) %s (2) %s (3) %s\t",1+p->id,
	  u->questions[i]->texte,
	  u->questions[i]->choix[0],
	  u->questions[i]->choix[1],
	  u->questions[i]->choix[2]);
   
   if(!u->game_mode){
      printf("\n");
      return (1+rand()%3);
   }
   
   scanf("%d",&reponse);
   return (reponse);
}

void INTFC_resultatQuestion(int i,Personnage *p){ /* Affiche le resultat de la question */
   if(i){
      printf("\033[32mJoueur %d, Bonne reponse !\033[0m",1+p->id);
   }else{
      printf("\033[31mJoueur %d, Mauvaise reponse !\n\033[0m",1+p->id);
   }
}

void INTFC_attaque(Univers *u,Personnage *a, Personnage *b){
   printf("\033[33m(%c%d,a)\033[0m",a->label[0],1+a->id);
   /* printf("\033[33m%s %d attaque ! \033[0m",a->label,1+a->id); */
}

int INTFC_demanderMassue(Univers *u,Personnage *p){
   int reponse=0;
   printf("Troll %d - (0) Attaque simple (1) Attaque massue ",1+p->id);

   if(!u->game_mode){
      printf("\n");
      return (rand()%2);
   }

   scanf("%d",&reponse);
   
   return reponse;
}

void INTFC_massue(Personnage *a){
   printf("%s %d Attaque Massue !\n",a->label,1+a->id);
}

int INTFC_demanderInvocation(Univers *u,Personnage *p){
   int reponse=0;
   printf("Magicien %d - (0) Deplacement (1) Invocation ",1+p->id);

   if(!u->game_mode){
      printf("\n");
      return (rand()%2);
   }

   scanf("%d",&reponse);
   return reponse;
}

void INTFC_invocation(Personnage *a){
   printf("\033[35mMagie en %d : %s %d invoque un monstre !\n\033[0m",a->pos,a->label,1+a->id);
}

int INTFC_deconcentration(Univers *u,Personnage *a,int i){
   int reponse;
   if(a->pouvoir){
      reponse=rand()%2;
      if(reponse){
	 u->BOSS->pouvoir=0;
	 printf("\n\033[32mAttaque Deconcentration du BOSS ! Le Joueur %d passe son tour !\033[0m\n",1+i);
	 return 1;
      }
   }
   return 0;
}

void INTFC_combat(Personnage *a,Personnage *b){
   printf("\n\033[32mCombat : %s %d VS %s %d !\n\033[0m",a->label,1+a->id,b->label,1+b->id);
}

void INTFC_victoire(Personnage *a, Personnage *b){
   printf("\n\033[32mCombat : %s %d gagne le combat!\033[0m",a->label,1+a->id);
}

void INTFC_combatFinal(int i){
   printf("Combat Final : Joueur %d VS Boss\n",i+1);
}

void INTFC_issueCombatFinal(int i, int bossalive){
   if(bossalive){
      printf("\nCombat Final : Joueur %d perd le combat final !\n",i+1);
   }else{
      printf("\n\033[32mCF : Joueur %d remporte la partie !\n\033[0m",i+1);
   }
}

void INTFC_tourDeJeu(int k){
   printf("\n\n\033[1;4m[ Tour De Jeu Numero %d ]\033[0m \n\n",k);
}
