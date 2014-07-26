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

#ifndef __HEADER_H
#define __HEADER_H


/**
 * @file header.h
 *  
 * Definitions des differents types utilises dans le programme.
 *
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* Enumerations */

typedef enum{
   MODE_AUTO=0,
   MODE_NORMAL=1
} MODE_JEU;


/**
 * @struct TYPE_PERSONNAGE
 * @brief Definit un type de personnage parmi les suivants :
 * TROLL, MAGICIEN, MONSTRE, BOSSFINAL
 */

typedef enum{
   TROLL=0,
   MAGICIEN=1,
   MONSTRE=2,
   BOSSFINAL=3
} TYPE_PERSONNAGE;

/**
 * @struct TYPE_CASE
 * @brief Definit un type de case parmi les suivants :
 * CASE_SANCTUAIRE, CASE_QUESTION, CASE_MONSTRE, CASE_PAUSE
 */

typedef enum{
   CASE_SANCTUAIRE=0,
   CASE_QUESTION=1,
   CASE_MONSTRE=2,
   CASE_PAUSE=3
} TYPE_CASE;

/**
 * @struct TYPE_DE
 * @brief Definit un type de DE (valeur) parmi les suivants :
 * DE_DEPLACEMENT (6), DE_ATTAQUE (10), DE_ATTAQUEBOSS (20)
 */

typedef enum{
   DE_DEPLACEMENT=6,
   DE_ATTAQUE=10,
   DE_ATTAQUEBOSS=20
} TYPE_DE;

/**
 * @struct VAL_EXPERIENCE
 * @brief Definit les valeurs des experiences des personnages :
 * EXP_TROLL (100), EXP_MAGICIEN (100), EXP_BOSS (1000)
 */

typedef enum{
   EXP_TROLL=100,
   EXP_MAGICIEN=100,
   EXP_BOSS=1000
} VAL_EXPERIENCE;

/* Cases */

#define NB_CASES 22 /*!< Nombre total de cases */
#define CASE_FINALE 21 /*!< Position de la case Finale */

/* Questions */

#define TMAX 256 /*!< Nombre maximal de questions */
#define TQMAX 100 /*!< Taille maximale d'une question */
#define VAL_QUESTION 50 /*!< Valeur d'une question en points d'experience gagnes */

/* Structures */

/**
 * @struct Personnage
 * @brief Represente un personnage en fonction de ses attributs.
 */

typedef struct{
   int id; /*!< Identifiant, numero du joueur qui le possede */
   int type; /*!< Type du personnage  */
   int pouvoir; /*!< 1 si le personnage a un pouvoir en reserve, 0 sinon */
   int exp; /*!< Points d'experience */
   int energie; /*!< Energie du personnage, reinitialisee a chaque fin de combat */
   int pos; /*!< Position du personnage */
   char *label;
} Personnage;

/**
 * @struct Joueur
 * @brief Un joueur est represente par la donnee de deux pointeurs
 * pointant chacun vers un de ses heros.
 */

typedef struct{
   Personnage *troll; /*!< Pointeur sur le Troll du joueur */
   Personnage *magicien; /*!< Pointeur sur le Magicien du joueur */
} Joueur;

/**
 * @struct Cellule 
 * @brief Contient le type de la case et un pointeur sur le dernier personnage arrive
 * ayant execute son action.
 */

typedef struct{
   int type; /*!< Type de la cellule */
   Personnage *last; /*!< Pointeur sur le dernier personnage arrive */ 
} Cellule;

/**
 * @struct Question
 * @brief Represente par un texte, 3 choix et une solution
 *
 */

typedef struct{
   char *texte; /*!<Texte de la question */
   char **choix; /*!< Choix possibles */
   int solution; /*!< Solution */
} Question;

typedef struct{
   MODE_JEU game_mode;
   int nb_joueurs; /* !<Nombre de Joueurs */
   int nb_cellules; /* !< Nombre de cellules */
   Cellule **plateau; /* !<Tableau de cases */
   Joueur **joueur;/* !<Tableau de joueurs */
   Personnage **monstre;/* !<Tableau de monstres */
   Personnage *BOSS; /* !< Pointeur sur le personnage BOSS */
   Question **questions; /*!<Tableau de questions */
   int *nb_questions; /* !< Nombre de questions */
} Univers;





#endif
