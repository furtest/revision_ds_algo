# Structure de base

## Note
```c
typedef struct _note{
    enum matieres matiere;
    float note;
    unsigned int coefficient;
    char appreciation[APPRECIATION_SIZE]; 
} Note;
```

## Eleve
Pour mettre une structure dans une structure je préfère utiliser la partie avec le mot clé struct plutôt que le typedef pour être absolument sur de ce qui est dans ma structure et éviter les erreurs
```c
typedef struct _eleve{
    char nom[NOM_SIZE];
    char prenom[PRENOM_SIZE];
    struct _dateDeNaissance date_de_naissance;
    struct _note notes[NOMBRE_NOTE];
    size_t nombre_notes;
    float moyenne;
    unsigned int classement;
} Eleve;
```

## Date de naissance
```c
typedef struct _dateDeNaissance{
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
} DateDeNaissance;
```

# Fonctions d'affichage

## Affiche note
Le _%.2f_ permet d'afficher la note avec deux chiffres après la virgule
```c
void afficheNote(const Note note){
    printf("%.2f coefficient %d\nAppreciation : %s\n", note.note, note.coefficient, note.appreciation); 
}
```

## Affiche eleve
```c
void afficheEleve(const Eleve eleve, bool notes){
    printf("%s %s né le %d/%d/%d est %deme avec une moyenne de %.2f\n",
    eleve.prenom, eleve.nom,
    eleve.date_de_naissance.jour, eleve.date_de_naissance.mois, eleve.date_de_naissance.annee,
    eleve.classement, eleve.moyenne);
    if(notes){
        for(int i = 0; i < eleve.nombre_notes; ++i){
            afficheNote(eleve.notes[i]);
        }
    }
```

# Ajout de donnée

## Ajoute note
On vérifie si le tableau n'est pas plein, si il est plein on renvoie l'élève inchangé sinon on ajoute la note et on incrémente le nombre de note.
```c
Eleve ajouteNote(Eleve eleve, const Note note){
    if(eleve.nombre_notes >= NOMBRE_NOTE){
        return eleve;
    }
    eleve.notes[eleve.nombre_notes] = note;
    eleve.nombre_notes++;
    return eleve;
}
```

## Saisie note
```c
Note saisieNote(void){
    Note note = {0};

    int matiere;
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
    if(matiere < 1 || matiere > 7){
        note.note = -1;
        return note;        
    }
    note.matiere = matiere;

    printf("Entrez la note : ");
    scanf("%f", &(note.note));

    printf("Entrez le coefficient : ");
    scanf("%d", &(note.coefficient));

    note.matiere = matiere;
    printf("Entrez l'appreciation\n>>> ");
    getinput(note.appreciation, APPRECIATION_SIZE); // On utilise notre fonction getinput

    return note;
}
```
## Saisie date de naissance
```c
DateDeNaissance saisieDateDeNaissance(void){
    DateDeNaissance date = {0};
    printf("Entrez le jour de naissance : ");
    scanf("%d", &(date.jour));
    printf("Entrez le mois de naissance : ");
    scanf("%d", &(date.mois));
    printf("Entrez l'année naissance : ");
    scanf("%d", &(date.annee));
    return date;
}
```

## Saisie élève
```c
Eleve saisieEleve(void){
    Eleve eleve = {0};
    printf("Entrez le nom : ");
    getinput(eleve.nom, NOM_SIZE);
    printf("Entrez le prenom : ");
    getinput(eleve.prenom, PRENOM_SIZE);
    eleve.date_de_naissance = saisieDateDeNaissance();
    eleve.nombre_notes = 0;
    eleve.moyenne = 0;
    eleve.classement = 0;
    return eleve;
}
```

# Autre fonction

## Calcul moyenne
```c
Eleve calculMoyenne(Eleve eleve){
    float moyenne = 0;
    unsigned int coeff = 0;
    for(int i = 0; i < eleve.nombre_notes; ++i){
        moyenne += eleve.notes[i].note * eleve.notes[i].coefficient; // On prend en compte le coefficient
        coeff += eleve.notes[i].coefficient;
    }
    eleve.moyenne = (moyenne/coeff);
    return eleve;
}
```

## Cherche élève
On parcourt le tableau en comparant le nom et le prenom, si on trouve on renvoie l'index de l'élève dans le tableau sinon on renvoie -1
```c
int chercheEleve(Eleve eleves[], size_t nb_eleves, char nom[], char prenom[]){
    for(int i=0; i < nb_eleves; ++i){
        if(strcmp(eleves[i].nom, nom) == 0 && strcmp(eleves[i].prenom, prenom) == 0){
            return i;
        }
    }
    return -1;
}
```

## Ecrire appréciation
On parcours le tableau et on copie l'appreciation à chaque fois
```c
void ecrireAppreciation(Note notes[], size_t nb_note, char appreciation[]){
    for(int i = 0; i < nb_note; ++i){
        strcpy(notes[i].appreciation, appreciation);
    }
}
```