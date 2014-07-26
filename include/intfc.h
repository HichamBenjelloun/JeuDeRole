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
 * @todo
 * @bug Pas de bug detecte.
 */

/**
 * @file intfc.h
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#ifndef __INTFC_H
#define __INTFC_H

#include "header.h"

/**
 * @fn MODE_JEU INTFC_ChoixModeDeJeu()
 * @brief Demande a l'utilisateur le mode de jeu
 * (automatique ou manuel) et retourne sa reponse
 * @return Mode de Jeu
 */

MODE_JEU INTFC_ChoixModeDeJeu();

/**
 * @fn INTFC_ChoixNbJoueurs()
 * @brief Demande a l'utilisateur le nombre de joueurs
 * et retourne sa reponse
 * @return Nombre de joueurs
 */

int INTFC_ChoixNbJoueurs();

/**
 * @fn INTFC_afficherPlateau(Univers *)
 * @brief Affiche le plateau en precisant les
 * differents types de cases et leur numero
 * @param Univers
 * @return
 */
void afficherPlateau(Univers *);

/**
 * @fn INTFC_afficherEtats(Univers *)
 * @brief Affiche les états des differents joueurs,
 * energie et position.
 * @param Univers
 * @return void
 */
void INTFC_afficherEtats(Univers *);

/**
 * @fn INTFC_deplacer(Personnage *)
 * @brief Affiche le deplacement d'un personnage.
 * @param Personnage
 * @param Nouvelle position
 * @return void
 */
void INTFC_deplacer(Personnage *,int);

/**
 * @fn INTFC_blesser(Personnage *)
 * @brief Affiche la blessure d'un personnage.
 * @param Personnage
 * @param Degats causes par une blessure.
 * @return void
 */
void INTFC_blesser(Personnage *,int);

/**
 * @fn INTFC_gainExp(Personnage *)
 * @brief Affiche le gain d'experience d'un personnage
 * @param Personnage
 * @param Gain d'experience.
 * @return void
 */
void INTFC_gainExp(Personnage *,int);

/**
 * @fn INTFC_poserQuestion(Univers *,int,Personnage *)
 * @brief Pose une questions designee par son numero au personnage.
 * @param Univers
 * @param Numero de la question
 * @param Personnage
 * @return void
 */
int INTFC_poserQuestion(Univers *,int,Personnage *);

/**
 * @fn INTFC_resultatQuestion(int,Personnage *)
 * @brief Affiche le resultat d'une question
 * Bonne reponse (i=1) ou mauvaise reponse (i=0)
 * @param Booleen i
 * @param Personnage
 * @return void
 */
void INTFC_resultatQuestion(int,Personnage *);

/**
 * @fn INTFC_attaque(Univers *,Personnage *,Personnage *)
 * @brief Affiche l'attaque d'u npersonnage sur un autre.
 * @param Univers
 * @param Personnage
 * @param Personnage
 * @return void
 */
void INTFC_attaque(Univers *,Personnage *, Personnage *);

/**
 * @fn INTFC_demanderMassue(Univers *,int,Personnage *)
 * @brief Demande au personnage s'il veut realiser une attaque massue
 * et retourne la reponse.
 * @param Univers
 * @param Personnage
 * @return int
 */
int INTFC_demanderMassue(Univers *,Personnage *);

/**
 * @fn INTFC_massue(Personnage *)
 * @brief Pose une questions designee par son numero au personnage.
 * @param Personnage
 * @return void
 */
void INTFC_massue(Personnage *);

/**
 * @fn INTFC_demanderInvocation(Univers *,int,Personnage *)
 * @brief Demande au personnage s'il veut realiser une invocation a la case courante
 * et retourne sa reponse.
 * @param Univers
 * @param Personnage
 * @return int
 */
int INTFC_demanderInvocation(Univers *,Personnage *);

/**
 * @fn INTFC_invocation(Personnage *)
 * @brief Affiche l'invocation du magicien.
 * @param Personnage
 * @return void
 */
void INTFC_invocation(Personnage *);

/**
 * @fn INTFC_poserQuestion(Univers *,Personnage *,int)
 * @brief Affiche l'attaque deconcentration du Boss.
 * @param Univers
 * @param Personnage
 * @param Identifiant du personnage
 * @return void
 */
int INTFC_deconcentration(Univers *,Personnage *,int);

/**
 * @fn INTFC_combat(Personnage *,Personnage *)
 * @brief Affiche l'annonce du combat entre deux personnages.
 * @param Personnage
 * @param Personnage
 * @return void
 */
void INTFC_combat(Personnage *,Personnage *);

/**
 * @fn INTFC_victoire(Personnage *,Personnage *)
 * @brief Affiche la victoire d'un personnage sur un autre.
 * @param Personnage
 * @param Personnage
 * @return void
 */
void INTFC_victoire(Personnage *,Personnage *);

/**
 * @fn INTFC_combatFinal(int)
 * @brief Affiche l'annonce du combat final d'un joueur.
 * @param Identifiant du joueur.
 * @return void
 */
void INTFC_combatFinal(int);

/**
 * @fn INTFC_issueCombatFinal(int,int)
 * @brief Affiche l'issue du combat final
 * @param Identifiant du joueur.
 * @param Booleen indiquant si le joueur a gagne ou non.
 * @return void
 */
void INTFC_issueCombatFinal(int,int);

/**
 * @fn INTFC_tourDeJeu(int)
 * @brief Affiche l'issue du combat final
 * @param Identifiant du joueur.
 * @param Booleen indiquant si le joueur a gagne ou non.
 * @return void
 */
void INTFC_tourDeJeu(int);

#endif
