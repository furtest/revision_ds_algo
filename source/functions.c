#include <stdio.h>
#include <string.h>

#include "../headers/structs.h"
#include "../headers/functions.h"
#include "../headers/donne.h"

/// @brief Affiche une note
/// @param note la note a afficher 
void afficheNote(const Note note){
   // ... 
}

/// @brief Affiche un eleve
/// @param eleve Affiche les informations à propos de l'élève
/// @param notes Si True affiche les notes de l'élève si False ne les affiche pas
void afficheEleve(const Eleve eleve, bool notes){
    // ... 
}

/// @brief Calcul la moyenne d'un eleve
/// @param eleve
/// @return L'eleve car on le passe par valeur
Eleve calculMoyenne(Eleve eleve){ 
    // ...
    return (Eleve) {0}; // cette ligne est à changer
}

/// @brief ajoute une note à un élève
/// @param eleve l'élève auquel ajouter la note
/// @param note la note à ajouter
/// @return l'élève avec la note
Eleve ajouteNote(Eleve eleve, const Note note){
    // ...
    return (Eleve) {0}; // cette ligne est à changer
}

/// @brief Permet à l'utilisateur de saisir une note
/// @return Renvoie une struct _Note, en cas d'erreur de saisie la note prend la valeur -1;
Note saisieNote(void){
    // ...
    return (Note) {0}; // cette ligne est à changer
}

/// @brief Permet à l'utilisateur de saisir une date de naissance
/// @return la date de naissance
DateDeNaissance saisieDateDeNaissance(void){
    // ...
    return (DateDeNaissance) {0}; // cette ligne est à changer
}

/// @brief Permet à l'utilisateur de saisir un élève
/// @return l'elève
Eleve saisieEleve(void){
    // ...
    return (Eleve) {0}; // cette ligne est à changer
}

/// @brief Recherche un élève dans un tableau d'élève par son nom et prénom
/// @param eleves le tableau d'eleves
/// @param nb_eleves le nb d'eleves dans le tableau
/// @param nom le nom que l'on cherche
/// @param prenom le prenom que l'on cherche
/// @return L'eleve recherché si il existe un élève vide sinon
int chercheEleve(Eleve eleves[], size_t nb_eleves, char nom[], char prenom[]){
    // ...
    return 0; // cette ligne est à changer
}

/// @brief Copier une appréciation sur toute les notes d'un tableau de notes
/// @param notes le tableau de note
/// @param nb_note le nombre de note dans le tableau
/// @param appreciation l'appréciation à écrire
void ecrireAppreciation(Note notes[], size_t nb_note, char appreciation[]){
   // ... 
}