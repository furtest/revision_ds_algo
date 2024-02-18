#ifndef STRUCTS_HEADER
#define STRUCTS_HEADER

#include <stdlib.h>

#define APPRECIATION_SIZE ((size_t) 500)
#define NOM_SIZE ((size_t) 50)
#define PRENOM_SIZE ((size_t) 30)
#define NOMBRE_NOTE ((size_t) 20)

enum matieres {MATHS, PHYSIQUE, ALGO, WEBDEV, RESEAU, SHES, AUTRE};

typedef struct _dateDeNaissance{
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
} DateDeNaissance;

typedef struct _note{
    enum matieres matiere;
    float note;
    unsigned int coefficient;
    char appreciation[APPRECIATION_SIZE]; 
} Note;


typedef struct _eleve{
    char nom[NOM_SIZE];
    char prenom[PRENOM_SIZE];
    struct _dateDeNaissance date_de_naissance;
    struct _note notes[NOMBRE_NOTE];
    size_t nombre_notes;
    float moyenne;
    unsigned int classement;
} Eleve;


#endif