# Makefile pour le projet ODL
# Benjelloun Hicham 30 Nov 2012
# v4.0

# Identification
AUTHOR=benjelloun

# Repertoires
REF=../
REFM=../../
HEADERS=$(REFM)include/
OBJ=$(REFM)obj/
BIN=$(REFM)bin/
DOC=$(REFM)doc/
MOD=$(MODULES)/
# Ensemble de Fichiers
SRC=$(wildcard *.c)

# Commandes
CC=gcc
CFLAG=-pg -I$(HEADERS)
SDLFLAG=`sdl-config --cflags --libs` -lSDL_image -lSDL_ttf
CPFLAG=
RM=rm -f 

# Modules
MODULES=primitives jeu intfct memoire questions main

# Construction des Modules
all :
	$(foreach m,$(MODULES), make -C $(m) -f $(REF)makefile module;)

# Construction d'un Module

module :	$(SRC)
	$(foreach fichier,$(SRC),$(CC) $(CFLAG) $(fichier) -c -o $(OBJ)$(subst .c,,$(fichier).o);)	

# Nettoyer les fichiers temporaires
clean :
	$(foreach m,$(MODULES),$(RM) ./$(m)/*~)
