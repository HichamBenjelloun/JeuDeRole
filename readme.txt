# Projet ODL Jeu de Rôles - Nov 30 2012
# Benjelloun Hicham

# Pour compiler le projet, utiliser la commande

make all

# Pour tester un module en particulier, utiliser les commandes :

make module MODULES='module1 module2 ...'
make link_module TEST='module_test'

# Pour lancer le jeu, utiliser un fichier de questions en argument

./bin/game ./questions/questions_001.txt

# Un script automatisant toutes les tâches est disponible. Pour le lancer :

sh ./projet.sh

# Pour plus d'information, lire le rapport de projet.
