#ifndef STRUCTS_HEADER
#define STRUCTS_HEADER

#include <stdlib.h>

#define APPRECIATION_SIZE ((size_t) 500)
#define NOM_SIZE ((size_t) 50)
#define PRENOM_SIZE ((size_t) 30)
#define NOMBRE_NOTE ((size_t) 20)

enum matieres {MATHS, PHYSIQUE, ALGO, WEBDEV, RESEAU, SHES, AUTRE};

typedef struct _dateDeNaissance{
    // ... 
} DateDeNaissance;

typedef struct _note{
    enum matieres matiere;
    // ... 
} Note;


typedef struct _eleve{
   // ... 
} /* ... */;


#endif