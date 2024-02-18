# L'ENT++

Je vais vous proposer ici un exercice regroupant beaucoup de notions qui seront au DS (pas forcément tout on a pas encore le planning) pour vous permettre de réviser. Une correction est jointe ainsi que des indices vous permettant de vous débloquer sans regarder directement la correction. Si vous avez des questions ou des soucis n'hésitez pas à me demander ou m'envoyer un message.

L'objectif vas être de recréer le système de notation de l'ENT en C, pour cela il va nous falloir utiliser plusieurs notions importantes : les structures, les tableaux et les chaînes de charactère.

# Explication de notation et informations

## Notation
Je vais noter les endroits à compléter par :
```c
// ...
ou
/* ... */
```
## Informations

### Fonction getinput
Je vous fournit une fonction getinput qui permet à l'utilisateur d'entrer une chaîne de caractère libre à vous de l'utiliser ou non.
Voici le prototype :
```c
void getinput(char buffer[], size_t size);
```
Elle prend en argument une chaîne de caractère buffer et la taille de cette chaîne et la rempli avec la saisie de l'utilisateur.

### Erreur et contact
Si vous remarquez une erreur vous pouvez la corriger (fork le repo et faire une pull request) ou pour les simples mortel m'envoyer un message sur discord : furtest


# Structures de base

On va créer trois structures qui vont nous permettre de contenir les données.

## Note
Note qui vas contenir :
- Un identifiant de matiere
- Un flottant note
- Un coefficient entier non signé
- Une chaîne de caractère appreciation

```c
typedef struct _note{
    enum matieres matiere;
    // ... 
} Note;
```

## Eleve
Eleve qui vas contenir :
- Une chaine de caractère nom
- Une chaine de caractère prenom
- Un entier nom signé date_de_naissance
- Un tableau de struct _note appelé notes
- Le nombre de note nombre_notes de type size_t (dans stdlib.h)
- Un entier non signé classement

```c
typedef struct _eleve{
    // ... 
} /*...*/;
```

## DateDeNaissance
Cette structure permet de stocker une date de naissance (ce n'est certainement pas le meilleur moyen de le faire), elle contient trois entier non signé _jour_, _mois_ et _annee_
```c
typedef struct _dateDeNaissance{
    // ...
} DateDeNaissance;
```

# Fonctions de base

Tant que vous n'avez pas écrit les structures le code risque de ne pas compiler

## Affichage des structures

1. Ecrire une fonction permettant d'afficher une note ayant le prototype suivant
    ```c
    void afficheNote(const Note note);
    ```

2. Ecrire une fonction permettant d'afficher un eleve ayant le prototype suivant
    ```c
    void afficheEleve(const Eleve eleve, bool notes)
    ```
    Si le booléen notes est true la fonction doit afficher toutes les notes de l'élève en plus de ses informations si il est false alors elle ne doit afficher que les informations à son propos pas ses notes.

## Ajout de données

1. Ecrire une fonction permettant d'ajouter une note a un élève ayant le prototype suivant
    ```c
    Eleve ajouteNote(Eleve eleve, const Note note)
    ```
    Si le tableau de note de l'élève est plein la fonction renverra l'élève sans le changer

2. Ecrire une fonction permettant a l'utilisateur de saisir une note elle doit s'appeler _saisieNote_ ne prendre aucun argument et renvoyer une _Note_.   
    La fonction doit remplir tout les champs d'une structure Note, lors de la saisie de la matière on pourra utiliser le code suivant. On traite ici _matiere_ comme un _int_, si l'utilisateur ne rentre pas une matière valide il faudra mettre la note à -1 et la renvoyer.
    ```c
    enum matieres matiere;
    printf("Choisissez la matiere :\n"
            "1 - Maths\n"
            "2 - Physique\n"
            "3 - Algo\n"
            "4 - Webdev\n"
            "5 - Reseau\n"
            "6 - SHES\n"
            "7 - Autre\n"
            ">>> ");
    scanf("%d", &matiere);
    ```
    Pour la saisie de l'appréciation vous pouvez utiliser la fonction [getinput](#fonction-getinput) fournie.

3. Ecrire une fonction permettant à l'utilisateur de saisir une date de naissance
    ```c
    DateDeNaissance saisieDateDeNaissance(void);
    ```

4. Ecrire une fonction permettant à l'utilisateur de saisir les informations d'un nouvel élève
    ```c
    Eleve saisieEleve(void);
    ```

## Autre fonctions

1. Calcul de moyenne   
    Ecrire une fonction permettant de calculer la moyenne d'un élève a partir de ses notes en prenant en compte les coefficients, la fonction doit ensuite stocker la note dans la variable moyenne de l'eleve.
    Le prototype :
    ```c
    Eleve calculMoyenne(Eleve eleve);
    ```

2. Recherche d'élève dans un tableau   
    Ecrire une fonction permettant de rechercher un élève dans un tableau par son nom et son prénom
    ```c
    int chercheEleve(Eleve eleves[], size_t nb_eleves, char nom[], char prenom[]);
    ```
    Pour faire cela utilisez des fonctions adaptées.

3. Copie d'appreciation    
    Le prof a la flemme il veux mettre la même appréciation a tout le monde, écrire une fonction prenant en argument un tableau de note et une appréciation et écrivant cette apréciation partout.
    ```c
    void ecrireAppreciation(Note notes[], size_t nb_note, char appreciation[]);
    ```

# Main

Dans le main vous avez des fonctions qui permette de tester vos fonctions vous pouvez les commenter si vous n'avez pas encore implémenter la fonction en question.

Ce que vous pouvez faire :
Ecrire du code pour vérifier que la fonction ecrireAppreciation fonctionne correctement.

# Que faire en plus
Vous pouvez essayer d'écrire une fonction qui prend en argument un tableau d'élèves, qui calcule la moyenne des élèves et renseigne correctement le classement de chaque élève, je mettrai une implémentation de cette fonction regardez le github