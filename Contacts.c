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
               "\n\tTapez votre choix [1-7] : ");
               ch = scanf("%d", choix);
               while(getchar() != '\n');
               if(ch) return ch;
               else return 0;
}

void Afficher_un_contact(Contacts *contacts, int i){

    printf("\n\t ------ Contacts %d ------\n\n" , i+1);
    printf("\t -- iD        : %d\n" , contacts[i].id);
    printf("\t -- Nom       : %s\n" , contacts[i].Nom);
    printf("\t -- Telephone : +212 %d\n" , contacts[i].Tele);
    printf("\t -- Email     : %s\n" , contacts[i].Email);
    
}

void Afficher_tout_les_contact(Contacts *contacts, int *Taille){

    if(contacts == NULL || *Taille  == 0){
        printf("\n\t \x1b[31m---- La Liste est vide ----\x1b[0m\n");
        return; 
    }

    int i;

    for(i=0 ; i < *Taille ; i++){
        printf("\n\t \x1b[32m------ Contacts %d ------\x1b[0m\n\n" , i+1);
        printf("\t -- iD        : %d\n" , contacts[i].id);
        printf("\t -- Nom       : %s\n" , contacts[i].Nom);
        printf("\t -- Telephone : +212 %d\n" , contacts[i].Tele);
        printf("\t -- Email     : %s\n" , contacts[i].Email);
    }
}

int Ajouter_un_contact(Contacts *contacts, int *Taille){

    int i;
    contacts = realloc(contacts , (*Taille + 1)*sizeof(Contacts));

    if(contacts == NULL){
        printf("\n\t \x1b[31m--- Erreur D'allocation ----\x1b[0m\n");
        return 0;
    }

    Contacts contact;

    printf("\n\t \x1b[32m---- Ajouter un contatc ----\x1b[0m \n");

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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
        }else if( choix_count > 2 ) {
            return 0;
        }else if (exist == false) {
            printf("\n\t \x1b[33m--- Contact avec ce nom n'est pas exist ----\x1b[0m \n");
            choix_count++;
        }else{
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
            choix_count++;
        }
    }

    Contacts contact;

    printf("\n\t \x1b[32m---- Modifier un contatc ----\x1b[0m\n");

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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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
        }else if( choix_count > 2 ) {
            return 0;
        }else if (exist == false) {
            printf("\n\t \x1b[33m--- Contact avec ce nom n'est pas exist ----\x1b[0m \n");
            choix_count++;
        }else{
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
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

int Rechechr_un_contact(Contacts *contacts, int *Taille){

    char nom[MAX_CHARACTER1];
    int choix_count = 0 , pos , i;

    // verifier le nom existe ou non
    while(1){
        bool exist = false;
        printf("\n\t -- Saisir Le Nom de Contact qui voules-vous chercher : ");
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
        }else if( choix_count > 2 ) {
            return 0;
        }else if (exist == false) {
            choix_count++;
            printf("\n\t \x1b[33m--- Contact avec ce nom n'est pas exist ----\x1b[0m \n");
        }else{
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
            choix_count++;
        }
    }   

    Afficher_un_contact(contacts , pos);

    return 1;
}

int Tri_des_contact(Contacts *contacts, int *Taille){

    int choix_count = 0 , choix;
   
    while(1){
        printf("\n\t \x1b[32m----- Trier Les Contacts --------\x1b[0m \n");
        printf("\t 1 - par Nom.\n"); 
        printf("\t 2 - par Telephone.\n"); 
        printf("\t 3 - par Addresse Email.\n"); 
        printf("\t 0 - Menu Priincipale.\n"); 
        printf("\t\t => ");
        int valide_input = scanf("%d" , &choix);
        while(getchar() != '\n');

        if(valide_input){
            break;
        }else if( choix_count > 2 ) {
            return 0;
        }else{
            printf("\n\t \x1b[31m-- Invalid Choix --\x1b[0m \n");
            choix_count++;
        }
    }

    
   
    if (choix == 1){
        Contacts e; 
        for (int i = 0; i < *Taille; i++) {
            for (int j = i + 1; j < *Taille; j++){ 
                if (strcmp(contacts[i].Nom, contacts[j].Nom) > 0) {
                    e = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = e;
                }
            }
        }
        return 1;
    } else if (choix == 2) {
        Contacts e; 
        for (int i = 0; i < *Taille; i++) {
            for (int j = i + 1; j < *Taille; j++){ 
                if (contacts[i].Tele > contacts[j].Tele) {
                    e = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = e;
                }
            }
        }
        return 1;
    } else if (choix == 3) {
         Contacts e; 
        for (int i = 0; i < *Taille; i++) {
            for (int j = i + 1; j < *Taille; j++){ 
                if (strcmp(contacts[i].Email, contacts[j].Email) > 0) {
                    e = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = e;
                }
            }
        }
        return 1;
    } else{
        return 0;
    }
}