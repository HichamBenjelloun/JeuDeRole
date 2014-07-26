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
 * @version     1.0 - Sep 11, 2012
 * 
 * @todo
 * @bug Pas de bug detecte.
 */

#ifndef __PRIMITIVES_H
#define __PRIMITIVES_H

/**
 * @file primitives.h
 *  
 * Description des fonctions primitives.
 * 
 */

#include "header.h"
#include "memoire.h"

/**
 * @fn int lancerDeAttaque(Personnage *p)
 * @brief Lancer De d'attaque
 *
 * @param p Personnage

 * @return Valeur du lancer de De d'attaque du personnage p
 */

int lancerDeAttaque(Personnage *p);

/**
 * @fn int lancerDeDeplacement(Personnage *p)
 * @brief Lancer De de deplacement
 *
 * @param p

 * @return Valeur du lancer du De de deplacement du personnage p
 */

int lancerDeDeplacement(Personnage *p);

/**
 * @fn void deplacer(Personnage *p,int a,int b)
 *
 * @brief Deplacement d'un personnage
 * Deplace le personnage p de a vers b
 * 
 * @param p Personnage
 * @param a Depart
 * @param b Arrivee
 *
 * @return 
 */

void deplacer(Univers *u,Personnage *p,int a,int b);

/**
 * @fn void blesser(Personnage *p,int b)
 * @brief Blessure d'un personnage.
 * Retranche b points d'energie au personnage p
 *
 * @param p
 * @param b
 *
 * @return
 */

void blesser(Personnage *p,int b);

/**
 * @fn void soigner(Personnage *p)
 * @brief Soin d'un personnage.
 * Recharge le nombre de points d'energie du personnage p
 *
 * @param p
 */

void soigner(Personnage *p);

/**
 * @fn void gainExp(Personnage *a,int ajout)
 * @brief Gain d'experience d'un personnage.
 * Ajoute ajout points d'experience du personnage p
 *
 * @param a
 * @param ajout
 */

void gainExp(Personnage *a,int ajout);

/**
 * @fn int estAllie(Personnage *a,Personnage *b);
 * @brief Verifie si deux personnages sont bien allies
 *
 * @param a
 * @param b
 * @return int 1 si a et b sont allies, 0 sinon.
 */

int estAllie(Personnage *a,Personnage *b);

/**
 * @fn int reunion(Personnage *p,int c)
 * @brief Verifie si les deux heros d'un meme joueurs
 * sont reunis sur une meme case.
 *
 * @param p
 * @param c
 * @return int 1 si p est sur la meme case que son collegue, 0 sinon.
 */

int reunion(Univers *u,Personnage *p,int c);


#endif
