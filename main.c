#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contacts.h"

Contacts *conatcts = NULL;
int Taille = 0;

int main(){

    int choix = 0 , choixValid = 1; 

    conatcts = calloc(Taille , sizeof(Contacts));

    while(choix != 5){

        choixValid = Choix(&choix);

        if (choixValid == 0 || choix < 1 || choix > 8){
            printf("\n\t ---- Choix Invalid ----\n");
        }else{
            
            switch (choix){
            case 1:
                    int valid_Ajoute = Ajouter_un_contact(conatcts , &Taille);
                    if(valid_Ajoute){
                        printf("\n\t --- Le Contact a ete Ajoute avec Succes ----\n");
                        Taille++;
                    }else{
                        printf("\n\t --- Erreur d'ajoutr ----\n");
                    }
                break;
            case 2:
                    Afficher_tout_les_contact(conatcts , &Taille);
                    break;
            default:
                break;
            }

        }

    }



}