#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contacts.h"

int Choix(int *choix){
    int ch; 
    printf("\n"
               "\t==============================================\n\t"
               "|          \033[36mMenu d\'application\033[0m                |\n"
               "\t==============================================\n\t"
               "|\t[1] Ajouter une contact              |\n\t"
               "|\t[2] Afficher tout les contact        |\n\t"
               "|\t[4] Modifier un contact              |\n\t"
               "|\t[5] Supprimer un contact             |\n\t"
               "|\t[6] Rechercher contact               |\n\t"
               "|\t[7] Tri les contact                  |\n\t"
               "|\t[\033[33m8\033[0m] \033[33mQuitter\033[0m                          |\n"
               "\t==============================================\n\t"
               "\n\tTapez votre choix [1-8] : ");
               ch = scanf("%d", choix);
               while(getchar() != '\n');
               if(ch) return ch;
               else return 0;
}

void Afficher_tout_les_contact(Contacts *contacts, int *Taille){

    if(contacts == NULL){
        printf("\n\t ---- La Liste est vide ----\n");
    }

    int i;

    for(i=0 ; i < *Taille ; i++){
        printf("\n\t ------ Contacts %d ------\n\n" , contacts[i].id);
        printf("\t -- Nom       : %s\n" , contacts[i].Nom);
        printf("\t -- Telephone : %d\n" , contacts[i].Tele);
        printf("\t -- Email     : %s\n" , contacts[i].Email);
    }
}

int Ajouter_un_contact(Contacts *contacts, int *Taille){

    int i;
    contacts = realloc(contacts , (*Taille + 1)*sizeof(Contacts));

    if(contacts == NULL){
        printf("\n\t --- Erreur D'allocation ----\n");
        return 0;
    }

    Contacts contact;

    printf("\n\t ---- Ajouter un contatc ----\n");

    while(1){
        
        printf("\n\t -- iD   : ");
        int valide_input = scanf("%d" , &contact.id);
        while(getchar() != '\n');

        if(valide_input){
            break;
        }else{
            printf("\n\t -- Invalid Choix -- \n");
        }

    }
    


    printf("\n\t -- Nom   : ");
    scanf(" %[^\n]s" , contact.Nom);

    printf("\n\t -- Telephone   : ");
    scanf("%d" , &contact.Tele);

    printf("\n\t -- Email   : ");
    scanf(" %[^\n]s" , contact.Email);

    contacts[*Taille] = contact; 

    return 1;
}