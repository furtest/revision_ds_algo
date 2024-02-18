# Intro et téléchargement

Ceci est un exercice pour vous permettre de réviser pour le prochain DS d'algo (le repo ne sera plus accessible après le DS sauf sur demande).  
- Pour copier le code vous aurez besoin de git, pour vérifiez si vous l'avez exécutez `git --version`.   
- Si vous avez comme sortie quelque chose comme `git version 2.34.1` alors tout vas bien sinon exécutez `sudo apt install git`.   
- Une fois git installé exécutez `git clone https://github.com/furtest/revision_ds_algo.git`

# Structure du projet
Plusieurs fichier et dossier sont présent dans le dossier (j'utilise la modularité qui je crois n'est pas au programme du DS) :
- Correction : la correction n'allez pas la voir avant d'avoir fini demandez de l'aide si vous n'y arrivez pas
- headers : Les fichier header pour le projet
    - donne.h : pas besoin d'y toucher c'est pour la fonction getInput
    - functions.h : les prototypes des fonctions que vous devez écrire
    - structs.h : les structure, vous devez les compléter
    - test.h : les prototypes des fonction pour tester vos fonctions pas besoin d'y toucher
- source : les fichier source pour le projet
    - donne.c : la fonction getInput, pas besoin d'y toucher
    - functions.c : le principal fichier que vous avez besoin de modifier, il contient toute les fonctions à compléter
    - test.o : les fonctions de test dans un fichier objet pour que vous ne regardiez pas comment j'ai fait et que ça vous aide (quand vous aurez fini le fichier test.c est dans correction)
- main.c : le fichier main, libre à vous de commenter les lignes pour les test, de les supprimer, de rajouter des choses
- Makefile : le makefile pour le projet
- README.md : ce fichier
- Sujet.md : le sujet en format markdown (si vous n'avez pas de quoi lire du markdown regardez pour le convertir en pdf)

# Compilation
Pour compiler vous pouvez soit exécuter gcc vous même soit utiliser le makefile qui vous fournit 3 commandes :
1. make : compile simplement le projet 
2. make run : compile et exécute
3. make clean : supprime le fichier de sortie (compile)

# Autre

Si vous voulez exécuter votre code avec vscode regardez sur google comment modifier task.json et si vous ne trouvez pas vous pouvez me demander.
Si vous avez des question mon discord : furtest