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
 * @version     2.0 - Nov 25, 2012
 * 
 * @todo
 * @bug Pas de bug detecte.
 */

#ifndef __JEU_H
#define __JEU_H


/**
 * @file jeu.h
 *  
 * Header des fonctions de jeu
 *
 */

#include "header.h"
#include "primitives.h"
#include "intfc.h"

void defaiteJoueur(Univers *u,Joueur *j);

void chargerQuestions(Univers *u,char *fichier);

/**
 * @fn void poserQuestion(Personnage *p)
 * @brief Questionne un personnage
 * Augmente l'experience du personnage si il a bien repondu.
 * @param p
 *
 * @return void
 */

void poserQuestion(Univers *u,Personnage *p);

/**
 * @fn  void attaque(Personnage *a,Personnage *b)
 * @brief Attaque simple (d10)
 *
 * @param a
 * @param b
 * @return Lance l'attaque du personnage a sur le personnage b
 */

void attaque(Univers *u,Personnage *a,Personnage *b);

/**
 * @fn void massue(Personnage *a,Personnage *b);
 * @brief Attaque speciale : Attaque Massue
 * 40 jet de d10
 *
 * @param a
 * @param b
 * @return void
 */

void massue(Personnage *a,Personnage *b);

/**
 * @fn void invocation(Personnage *p)
 * @brief Invocation d'un monstre sur la case courante.
 * Creer un monstre allie a la position du personnage p
 * @param p
 * @return void
 */

void invocation(Univers *u,Personnage *p);

/**
 * @fn void combat(Personnage *a, Personnage *b)
 * @brief Combat entre deux personnages.
 * Les deux personnages s'attaquent successivement jusqu'a ce que
 * le niveau d'energue de l'un deux soit nul.
 *
 * @param a
 * @param b
 * @return Combat entre les personnages a et b.
 */

void combat(Univers *u,Personnage *a, Personnage *b);

/**
 * @fn void combatFinal(int i)
 * @brief Combat final du joueur i
 *
 * @param i
 * @return void
 */

void combatFinal(Univers *u,int i);

/**
 * @fn void victoire(Personnage *a,Personnage *b)
 * @brief Victoire du personnage a sur le personnage b
 * Effectue les modifications correspondantes :
 *  - Deplace b en 0
 *  - Gain d'experience de a
 *
 * @param a
 * @param b
 * @return void
 */

void victoire(Univers *u,Personnage *a,Personnage *b);

/**
 * @fn void action(Personnage *p)
 * @brief Lance l'action associee a un personnage a
 *
 * @param p
 * @return void
 */

void action(Univers *u,Personnage *p);

/**
 * @fn void tourDeJeu(int k);
 * @brief Realise un tour de jeu.
 * 
 * @param k
 * @return void
 *
 */

void tourDeJeu(Univers *u,int k);

#endif
