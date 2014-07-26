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
 * @file intfct-test.c
 *  
 * Fichier de Test (Validé 24 Nov 2012)
 * Toutes les fonctions de ce module fonctionnent.
 */

#include "header.h"
#include "memoire.h"
#include "intfc.h"

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

   /* Affichage des Etats */
   Univers *u=allouerUnivers(g,n,21,argv[1],"0121321231213212312210");   
   
   printf("\n\033[1m Affichage de l'etat :\033[0m\n\n");
   INTFC_afficherEtats(u);

   /* Deplacement */
   printf("\n\033[1m Affichage d'un deplacement :\033[0m\n\n");
   INTFC_deplacer(u->joueur[rand()%n]->magicien,10);

   /* Blessure */
   printf("\n\033[1m Affichage d'une blessure d'un joueur :\033[0m\n\n");
   INTFC_blesser(u->joueur[rand()%n]->troll,50);

   /* Gain d'experience d'un joueur */
   printf("\n\033[1m Affichage du gain d'experience d'un joueur :\033[0m\n\n");
   INTFC_gainExp(u->joueur[rand()%n]->troll,5);

   /* Poser une questions a un joueur */
   printf("\n\033[1m Poser une question a un joueur :\033[0m\n\n");
   printf("Choix de la question 0/2\n",u->nb_questions);
   INTFC_poserQuestion(u,rand()%*u->nb_questions,u->joueur[rand()%n]->troll);

   /* Donner le resultat a une question */
   printf("\n\033[1m Affichage du resultat a une question :\033[0m\n\n");
   INTFC_resultatQuestion(1,u->joueur[rand()%n]->troll);
   printf("\n");
   INTFC_resultatQuestion(0,u->joueur[rand()%n]->troll);

   /* Attaque d'un personnage */
   printf("\n\033[1m Affichage d'une attaque :\033[0m\n\n");
   INTFC_attaque(u,u->joueur[rand()%n]->troll,u->joueur[rand()%n]->magicien);

   /* Proposer attaque Massue */
   printf("\n\033[1m Propose d'utiliser l'attaque massue :\033[0m\n\n");
   INTFC_demanderMassue(u,u->joueur[rand()%n]->troll);

   /* Attaque massue */
   printf("\n\033[1m Utiliser l'attaque massue :\033[0m\n\n");
   INTFC_massue(u->joueur[rand()%n]->troll);

   /* Proposer Invocation */
   printf("\n\033[1m Propose d'utiliser l'invocation :\033[0m\n\n");
   INTFC_demanderInvocation(u,u->joueur[rand()%n]->magicien);

   /* Invocation */
   printf("\n\033[1m Utiliser l'invocation :\033[0m\n\n");
   INTFC_invocation(u->joueur[rand()%n]->magicien);

   /* Attaque Deconcentration du BOSS */
   printf("\n\033[1m Deconcentration du Boss :\033[0m\n\n");
   INTFC_deconcentration(u,u->BOSS,rand()%n);

   /* Annonce d'un combat */
   printf("\n\033[1m Annonce d'un combat :\033[0m\n\n");
   INTFC_combat(u->joueur[rand()%n]->troll,u->joueur[rand()%n]->magicien);

   /* Annonce d'une victoire */
   printf("\n\033[1m Annonce d'une victoire :\033[0m\n\n");
   INTFC_victoire(u->joueur[rand()%n]->troll,u->joueur[rand()%n]->magicien);

   /* Annonce du combat Final */
   printf("\n\033[1m Annonce du combat final :\033[0m\n\n");
   INTFC_combatFinal(rand()%n);

   /* Issue combat final */
   printf("\n\033[1m Issue du combat final:\033[0m\n\n");
   INTFC_issueCombatFinal(rand()%n,1);

   /* Tour de jeu - Affichage du Titre */
   printf("\n\033[1m Affichage du numero de tour de jeu :\033[0m\n\n");
   INTFC_tourDeJeu(1);


   return 0;
}

	  
