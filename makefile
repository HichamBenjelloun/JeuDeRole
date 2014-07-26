# Makefile pour le projet ODL
# Benjelloun Hicham 30 Nov 2012
# v4.0

# Identification
AUTHOR=benjelloun

# Commandes
CC=gcc
CFLAG=-pg
SDLFLAG=`sdl-config --cflags --libs` -lSDL_image -lSDL_ttf
CPFLAG=
RM=rm -rf

# Repertoires
REF=./
REFM=../../
HEADERS=$(REF)include/
SRC=$(REF)src/
OBJ=$(REF)obj/
BIN=$(REF)bin/
DOC=$(REF)doc/

# Liste de fichiers
OBJECTS=$(wildcard $(OBJ)*.o)
TESTS=$(filter %-test.o,$(OBJECTS))
TESTO=$(OBJ)$(TEST)-test.o

# Construction de l'executable
all :	module
	$(RM) $(OBJ)*test*
	$(CC) $(CFLAG) $(OBJ)*.o -o $(BIN)game

# Construction des Modules
module :
	make -C $(SRC)

# Edition des liens d'un module
link_module :	$(OBJECTS)
	echo $(TESTS)
	$(foreach o,$(TESTS), if test $(o) != $(TESTO); then $(RM) $(o); fi;)
	$(CC) $(CFLAG) $(OBJ)* -o $(BIN)$(TEST)

# Edition des liens
intfct: modules
	$(CC) $(CFLAG) $(OBJ)*.o -o $(BIN)game

# Documentation
documentation :
	doxygen config

# Nettoyer les fichiers temporaires
clean:
	$(RM) gmon.out *.tar *~ $(SRC)*~ $(HEADERS)*~ $(OBJ)* $(BIN)* $(DOC)*
	make -C $(SRC) clean

# Archive
archive :
	tar -cvf $(AUTHOR)_projet.tar *

# Tarball
tarball : clean archive
