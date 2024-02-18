#include <stdlib.h>
#include <stdio.h>

#include "../headers/donne.h"

/// @brief Permet à l'utilisateur de saisir une chaine de caractère
/// @param buffer l'endroit où stocker la chaine
/// @param size la taille de la chaine
void getinput(char buffer[], size_t size){
    if(buffer == NULL){
        return;
    }
    char bin;
    while ((bin = getchar()) != '\n' && bin != EOF) { } 
    fgets(buffer, size - 1, stdin);
    size_t i = 0;
    while(buffer[i] != '\0' && i < size){
        i++;
    }
   buffer[i - 1] = '\0';  
}