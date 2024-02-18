#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../headers/structs.h"
#include "../headers/functions.h"
#include "../headers/donne.h"

Note createTestNote(void){
    Note note = {0};
    note.matiere = 1;
    note.note = 13.25;
    note.coefficient = 2;
    char appreciation[APPRECIATION_SIZE] = "Pas mal.";
    strcpy(note.appreciation, appreciation);
    return note;
}

DateDeNaissance createTestDateDeNaissance(void){
    return (DateDeNaissance) { 12, 1, 2005};
}

Eleve createTestEleve(void){
    Eleve eleve = {0};

    char nom[NOM_SIZE] = "Dupont";
    strcpy(eleve.nom, nom);
    char prenom[PRENOM_SIZE] = "Andre";
    strcpy(eleve.prenom, prenom);
    eleve.date_de_naissance = createTestDateDeNaissance();
    eleve.notes[0] = createTestNote();
    eleve.notes[1] = createTestNote();
    eleve.notes[1].note = 15;
    eleve.notes[1].coefficient = 1;
    eleve.nombre_notes = 2;
    eleve.classement = 1;

    return eleve;
}

void testAfficheNote(void){
    Note note = createTestNote();
    afficheNote(note);
}

void testAfficheEleve(void){
    Eleve eleve = createTestEleve();
    afficheEleve(eleve, false);
    afficheEleve(eleve, true);
}

void testCalculMoyenne(void){
    Eleve eleve = createTestEleve();
    eleve = calculMoyenne(eleve);
    if(eleve.moyenne > 13.83 && eleve.moyenne < 13.84){
        printf("Calcul moyenne semble fonctionner.\n");
    }else{
        printf("Calcul moyenne ne fonctionne pas.\n");
    }    
}

void testAjouteNote(void){
    Eleve eleve = createTestEleve();
    Note note = createTestNote();
    note.matiere = 3;
    note.coefficient = 10;
    eleve = ajouteNote(eleve, note);
    if(eleve.nombre_notes == 3 && eleve.notes[2].matiere == 3 && eleve.notes[2].coefficient == 10){
        printf("L'ajout d'une note semble fonctionner\n");
    }else{
        printf("ajouteNote ne fonctionne pas.\n");
    }
    eleve.nombre_notes = NOMBRE_NOTE;
    note.coefficient = 42;
    eleve.notes[NOMBRE_NOTE - 1] = note;
    if(eleve.nombre_notes != NOMBRE_NOTE || eleve.notes[NOMBRE_NOTE - 1].coefficient != 42){
        printf("ajouteNote semble ajouter ou modifier des notes lorsque le tableau de note est plein\n");
    }else{
        printf("ajouteNote semble fonctionner correctement\n");
    }
}

void testChercheEleve(void){
    Eleve eleves[3] = {0};
    eleves[0] = createTestEleve();
    eleves[1] = createTestEleve();
    eleves[2] = createTestEleve();
    char nom[NOM_SIZE] = "zorglub";
    strcpy(eleves[2].nom, nom);
    char prenom[PRENOM_SIZE] = "jack";
    strcpy(eleves[2].prenom, prenom);
    int eleve = chercheEleve(eleves, 3, "zorglub", "jack");
    if(eleve == 2){
        printf("Chercher eleve fonctionne correctement\n");
    }else{
        printf("Chercher eleve ne fonctionne pas\n");
    }
}