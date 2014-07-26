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
 * @bug Pas de bug detecte.
 */

#ifndef __MEMOIRE_H
#define __MEMOIRE_H

#include "header.h"
#include "questions.h"

/**
 * @file memoire.h
 *  
 * Fonctions d'allocation et de liberation de la memoire.
 *
 */

Univers *allouerUnivers(int game_mode,int nb_joueurs, int nb_cellules,char *questions,char *vmasque);
void libererUnivers(Univers *u);

Cellule **allouerPlateau(int n,char *masque);
void libererPlateau(Cellule **p);

Personnage *allouerPersonnage(int id,int type,int pouvoir,int exp,int energie,int pos,char *label);
void libererPersonnage(Personnage *p);

Joueur **allouerJoueurs(int n);
void libererJoueurs(Joueur **j);

Personnage **allouerMonstres(int n);
void libererMonstres(Personnage **m);

void chargerQuestions(Univers *u, char *fichier);
void libererQuestion(Question *q);
void libererQuestions(Question **);

#endif
