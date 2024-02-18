#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER

#include <stdbool.h>
#include "structs.h"

void afficheNote(const Note note);
void afficheEleve(const Eleve eleve, bool notes);
Eleve calculMoyenne(Eleve eleve);
Eleve ajouteNote(Eleve eleve, const Note note);
Note saisieNote(void);
Eleve saisieEleve(void);
DateDeNaissance saisieDateDeNaissance(void);
int chercheEleve(Eleve eleves[], size_t nb_eleves, char nom[], char prenom[]);
void ecrireAppreciation(Note notes[], size_t nb_note, char appreciation[]);

#endif