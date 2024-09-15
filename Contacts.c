#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contacts.h"
#include <stdbool.h>

int Choix(int *choix){
    int ch; 
    printf("\n"
               "\t==============================================\n\t"
               "|          \033[36mMenu d\'application\033[0m                |\n"
               "\t==============================================\n\t"
               "|\t[1] Ajouter une contact              |\n\t"
               "|\t[2] Afficher tout les contact        |\n\t"
               "|\t[3] Modifier un contact              |\n\t"
               "|\t[4] Supprimer un contact             |\n\t"
               "|\t[5] Rechercher contact               |\n\t"
               "|\t[6] Tri les contact                  |\n\t"
               "|\t[\033[33m7\033[0m] \033[33mQuitter\033[0m                          |\n"
               "\t==============================================\n\t"
               "\n\tTapez votre choix [1-8] : ");
               ch = scanf("%d", choix);
               while(getchar() != '\n');
               if(ch) return ch;
               else return 0;
}

void Afficher_tout_les_contact(Contacts *contacts, int *Taille){

    if(contacts == NULL || *Taille  == 0){
        printf("\n\t ---- La Liste est vide ----\n");
        return; 
    }

    int i;

    for(i=0 ; i < *Taille ; i++){
        printf("\n\t ------ Contacts %d ------\n\n" , contacts[i].id);
        printf("\t -- Nom       : %s\n" , contacts[i].Nom);
        printf("\t -- Telephone : +212 %d\n" , contacts[i].Tele);
        printf("\t -- Email     : %s\n" , contacts[i].Email);
    }
}

int Ajouter_un_contact(Contacts *contacts, int *Taille){

    int i;
    printf("\n --- Taille = %d ----\n" , *Taille);
    contacts = realloc(contacts , (*Taille + 1)*sizeof(Contacts));

    if(contacts == NULL){
        printf("\n\t --- Erreur D'allocation ----\n");
        return 0;
    }

    Contacts contact;

    printf("\n\t ---- Ajouter un contatc ----\n");

    // Validation de id -------
    int id_count = 0; 
    while(1){
        printf("\n\t -- iD   : ");
        int valide_input = scanf("%d" , &contact.id);
        while(getchar() != '\n');

        if(valide_input){
            break;
        }else if(id_count > 2){
            return 0;
        }else{
            id_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }

    // Validation de nom -------
    int nom_count = 0 ;
    while(1){
        printf("\n\t -- Nom   : ");
        int valide_input = scanf(" %[^\n]s" , contact.Nom);
        while(getchar() != '\n');
        int i = 0 , valid_nom = 1;
        while(contact.Nom[i] != '\0'){
            if( (contact.Nom[i] >= 65 && contact.Nom[i] <= 90) || (contact.Nom[i] >= 97 && contact.Nom[i] <= 122)){
                valid_nom = 1;
            }else{
                valid_nom = 0;
            }
            i++;
        }


        if(valide_input && strlen(contact.Nom) > 3 && valid_nom){
            break;
        }else if(nom_count > 2){
            return 0;
        }else{
            nom_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }


    // Validation de Telephone -------
    int tel_count = 0; 
    while(1){
        
        printf("\n\t -- Telephone : ");
        int valide_input =  scanf("%d" , &contact.Tele);
        while(getchar() != '\n');

        int chiffre = contact.Tele , numbre_chiffre = 0;

        while(chiffre != 0) {
            chiffre = chiffre / 10;
            numbre_chiffre++;
        } 

        if(valide_input && numbre_chiffre >= 9){
            break;
        }else{
            tel_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }

    // Validation d'email -------
    int email_count = 0; 
    while(1){
        printf("\n\t -- Email   : ");
        int valide_input = scanf(" %[^\n]s" , contact.Email);
        while(getchar() != '\n');

        int valid_email = 1;
        
        char *arb = strchr(contact.Email , '@'); 
        if(arb != NULL){
            char *point = strchr( arb,'.');
            if(point != NULL){
                valid_email = 1;
            } else {
                valid_email = 0;
            }

        }else{
            valid_email = 0;
        }

        if(valide_input && strlen(contact.Email) > 3 && valid_email){
            break;
        }else if(email_count > 2){
            return 0;
        }else{
            email_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }
    
    contacts[*Taille] = contact; 

    return 1;
}

int Modifier_un_contact(Contacts *contacts, int *Taille){

    char nom[MAX_CHARACTER1];

    // virifier le nom existe ou non
    int choix_count = 0 , pos;
   
    while(1){
        bool exist = false;
        printf("\n\t -- Veuillez Saisir Le Nom de Contact : ");
        int valide_input = scanf(" %[^\n]s" , nom);
        while(getchar() != '\n');

        for(int i=0;i<*Taille;i++){
            int value = strcmp(contacts[i].Nom , nom);
            if(value == 0){
                exist = true;
                pos = i;
                break;
            }  
        }


        if(valide_input && exist){
            break;
        }else if (exist == false) {
            printf("\n\t --- Contact avec ce nom n'est pas exist ---- \n");
            choix_count++;
        }else if( choix_count > 2 ) {
            return 0;
        }else{
            printf("\n\t -- Invalid Choix -- \n");
            choix_count++;
        }
    }

    Contacts contact;

    printf("\n\t ---- Modifier un contatc ----\n");

    // Validation de id -------
    contact.id = contacts[pos].id;

    // Validation de nom -------
    int nom_count = 0 ;
    while(1){
        printf("\n\t -- Nom   : ");
        int valide_input = scanf(" %[^\n]s" , contact.Nom);
        while(getchar() != '\n');
        int i = 0 , valid_nom = 1;
        while(contact.Nom[i] != '\0'){
            if( (contact.Nom[i] >= 65 && contact.Nom[i] <= 90) || (contact.Nom[i] >= 97 && contact.Nom[i] <= 122)){
                valid_nom = 1;
            }else{
                valid_nom = 0;
            }
            i++;
        }


        if(valide_input && strlen(contact.Nom) > 3 && valid_nom){
            break;
        }else if(nom_count > 2){
            return 0;
        }else{
            nom_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }


    // Validation de Telephone -------
    int tel_count = 0; 
    while(1){
        
        printf("\n\t -- Telephone : ");
        int valide_input =  scanf("%d" , &contact.Tele);
        while(getchar() != '\n');

        int chiffre = contact.Tele , numbre_chiffre = 0;

        while(chiffre != 0) {
            chiffre = chiffre / 10;
            numbre_chiffre++;
        } 

        if(valide_input && numbre_chiffre >= 9){
            break;
        }else{
            tel_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }

    // Validation d'email -------
    int email_count = 0; 
    while(1){
        printf("\n\t -- Email   : ");
        int valide_input = scanf(" %[^\n]s" , contact.Email);
        while(getchar() != '\n');

        int valid_email = 1;
    
        char *arb = strchr(contact.Email , '@'); 
        if(arb != NULL){
            char *point = strchr( arb,'.');
            if(point != NULL){
                valid_email = 1;
            } else {
                valid_email = 0;
            }

        }else{
            valid_email = 0;
        }

        if(valide_input && strlen(contact.Email) > 3 && valid_email){
            break;
        }else if(email_count > 2){
            return 0;
        }else{
            email_count++;
            printf("\n\t -- Invalid Choix -- \n");
        }
    }
    
    contacts[pos] = contact ; 

    return 1;


}

int Supprimer_un_contact(Contacts *contacts, int *Taille){

    char nom[MAX_CHARACTER1];
    int choix_count = 0 , pos , i;

    // verifier le nom existe ou non
    while(1){
        bool exist = false;
        printf("\n\t -- Veuillez Saisir Le Nom de Contact : ");
        int valide_input = scanf(" %[^\n]s" , nom);
        while(getchar() != '\n');

        for(int i=0;i<*Taille;i++){
            int value = strcmp(contacts[i].Nom , nom);
            if(value == 0){
                exist = true;
                pos = i;
                break;
            }  
        }

        if(valide_input && exist){
            break;
        }else if (exist == false) {
            printf("\n\t --- Contact avec ce nom n'est pas exist ---- \n");
            choix_count++;
        }else if( choix_count > 2 ) {
            return 0;
        }else{
            printf("\n\t -- Invalid Choix -- \n");
            choix_count++;
        }
    }

    if(*Taille > 0){
        for(i=pos;i<*Taille - 1;i++){
            contacts[i] = contacts[i+1];
        }
        return 1;
    }else{
        contacts = NULL;
    }

    return 1;

}
