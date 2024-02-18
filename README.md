# Intro et téléchargement

Ceci est un exercice pour vous permettre de réviser pour le prochain DS d'algo (le repo ne sera plus accessible après le DS sauf sur demande).  
- Pour copier le code vous aurez besoin de git. Pour vérifier si vous l'avez, exécutez `git --version`.   
- Si vous avez comme sortie quelque chose qui ressemble à `git version 2.34.1`, alors tout va bien ; sinon, exécutez `sudo apt install git`.   
- Une fois git installé, exécutez `git clone https://github.com/furtest/revision_ds_algo.git`. Vous pourrez ensuite entrer dans le répertoire et commencer à travailler (`cd revision_ds_algo`).

# Structure du projet
Plusieurs fichiers et dossiers sont présents dans le dossier (j'utilise la modularité qui je crois n'est pas au programme du DS) :
- Correction : N'allez pas voir la correction avant d'avoir fini ! Demandez de l'aide si vous n'y arrivez pas.
- headers : Les fichiers header pour le projet
    - donne.h : Pas besoin d'y toucher, c'est pour la fonction getInput.
    - functions.h : Les prototypes des fonctions que vous devez écrire
    - structs.h : Les structures, vous devez les compléter.
    - test.h : Les prototypes des fonctions pour tester vos fonctions, pas besoin d'y toucher.
- source : Les fichiers source du projet
    - donne.c : La fonction getInput, pas besoin d'y toucher.
    - functions.c : Le principal fichier que vous devrez modifier, il contient toutes les fonctions à compléter.
    - test.o : Les fonctions de test, dans un fichier objet pour que vous ne regardiez pas comment j'ai fait et que ça vous aide (quand vous aurez fini le fichier test.c est dans correction)
- main.c : Le fichier main, libre à vous de commenter les lignes pour les tests, de les supprimer, de rajouter des choses...
- Makefile : Le makefile du projet (permettant d'automatiser la compilation)
- README.md : Ce fichier
- sujet.md : Le sujet en format markdown (si vous n'avez pas de quoi lire du markdown, regardez pour le convertir en pdf, ou regardez le fichier depuis Github, comme ici.)

# Compilation
Pour compiler vous pouvez soit exécuter gcc vous même soit utiliser le makefile qui vous fournit 3 commandes :
1. make : compile simplement le projet 
2. make run : compile et exécute
3. make clean : supprime le fichier de sortie (compile)

# Autre

Si vous voulez exécuter votre code avec vscode regardez sur google comment modifier task.json et si vous ne trouvez pas vous pouvez me demander.   
Si vous avez des questions, voici mon discord : furtest
