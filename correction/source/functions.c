#include <stdio.h>
#include <string.h>

#include "../headers/structs.h"
#include "../headers/functions.h"
#include "../headers/donne.h"

/// @brief Affiche une note
/// @param note la note a afficher 
void afficheNote(const Note note){
    printf("%.2f coefficient %d\nAppreciation : %s\n", note.note, note.coefficient, note.appreciation); 
}

/// @brief Affiche un eleve
/// @param eleve Affiche les informations à propos de l'élève
/// @param notes Si True affiche les notes de l'élève si False ne les affiche pas
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
}

/// @brief Calcul la moyenne d'un eleve
/// @param eleve
/// @return L'eleve car on le passe par valeur
Eleve calculMoyenne(Eleve eleve){
    float moyenne = 0;
    unsigned int coeff = 0;
    for(int i = 0; i < eleve.nombre_notes; ++i){
        moyenne += eleve.notes[i].note * eleve.notes[i].coefficient;
        coeff += eleve.notes[i].coefficient;
    }
    eleve.moyenne = (moyenne/coeff);
    return eleve;
}

/// @brief ajoute une note à un élève
/// @param eleve l'élève auquel ajouter la note
/// @param note la note à ajouter
/// @return l'élève avec la note
Eleve ajouteNote(Eleve eleve, const Note note){
    if(eleve.nombre_notes >= NOMBRE_NOTE){
        return eleve;
    }
    eleve.notes[eleve.nombre_notes] = note;
    eleve.nombre_notes++;
    return eleve;
}

/// @brief Permet à l'utilisateur de saisir une note
/// @return Renvoie une struct _Note, en cas d'erreur de saisie la note prend la valeur -1;
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
    getinput(note.appreciation, APPRECIATION_SIZE);

    return note;
}

/// @brief Permet à l'utilisateur de saisir une date de naissance
/// @return la date de naissance
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

/// @brief Permet à l'utilisateur de saisir un élève
/// @return l'elève
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

/// @brief Recherche un élève dans un tableau d'élève par son nom et prénom
/// @param eleves le tableau d'eleves
/// @param nb_eleves le nb d'eleves dans le tableau
/// @param nom le nom que l'on cherche
/// @param prenom le prenom que l'on cherche
/// @return l'index de l'élève dans le tableau ou -1
int chercheEleve(Eleve eleves[], size_t nb_eleves, char nom[], char prenom[]){
    for(int i=0; i < nb_eleves; ++i){
        if(strcmp(eleves[i].nom, nom) == 0 && strcmp(eleves[i].prenom, prenom) == 0){
            return i;
        }
    }
    return -1;
}

/// @brief Copier une appréciation sur toute les notes d'un tableau de notes
/// @param notes le tableau de note
/// @param nb_note le nombre de note dans le tableau
/// @param appreciation l'appréciation à écrire
void ecrireAppreciation(Note notes[], size_t nb_note, char appreciation[]){
    for(int i = 0; i < nb_note; ++i){
        strcpy(notes[i].appreciation, appreciation);
    }
}