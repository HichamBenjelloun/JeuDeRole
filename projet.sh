#!/bin/sh
# BENJELLOUN Hicham - 28 Nov 2012
# 4.0

titre="\n\033[1;4;33mMenu du Projet ODL - Jeu de Rôles (version du 30 Novembre 2012)\033[0m\n\n"

menu="q - Arrêter le script.\nm - Rafraichir la page\n0 - Afficher l'arborescence du repertoire de travail.\n1 - Compiler\n2 - Lancer le Jeu\n3 - Generer la documentation doxygen et l'ouvrir\n4 - Ouvrir le rapport de projet\n6 - Nettoyer le repertoire des fichiers crees\n"

echo $titre$menu

while echo "\033[1m(Script Shell)\033[0m Entrer une commande" ;  read commande
do

    case $commande in
	q) 
	    echo "\n\033[1;33mFermeture du Script Shell\033[0m\n"
	    break;;
	m) 
	    clear
	    echo $titre$menu;;
	0) 
	    echo "\n\033[1;33mInterdependances entre les fichiers\033[0m\n"
	    more tree.txt;;
	1) 
	    make all &&
	    echo "\n\033[1;32mCompilation realisee avec succès !\033[0m\n";;
	2)
	    ./bin/game ./questions/questions_001.txt;;	
	3) 
	    doxygen config
	    firefox ./doc/html/index.html -bg &
	    clear
	    echo $titre$menu;;
	4) 
	    evince ./rapport.pdf &
	    clear
	    echo $titre$menu;;
	5) 
	    make clean &&
	    echo "\n\033[1;32mFichiers effaces avec succes !\033[0m\n";;
    esac

done
