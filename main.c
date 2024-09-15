#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contacts.h"

Contacts *conatcts = NULL;
int Taille = 0;

int main(){

    int choix = 0 , choixValid = 1; 

    conatcts = calloc(Taille , sizeof(Contacts));

    while(choix != 7){

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
            case 3:
                    int valid_modifie = Modifier_un_contact(conatcts , &Taille);
                    if(valid_modifie){
                        printf("\n\t --- Le Contact a ete Modifier avec Succes ----\n");
                    }else{
                        printf("\n\t --- Erreur de Modification ----\n");
                    }
                    break;
            case 4:
                    int valid_suppression = Supprimer_un_contact(conatcts , &Taille);
                    if(valid_suppression){
                        printf("\n\t --- Le Contact a ete Supprimer avec Succes ----\n");
                        if(Taille > 0 ) Taille--;
                    }else{
                        printf("\n\t --- Erreur de Suppression ----\n");
                    }
                    break;
            default:
                break;
            }

        }

    }



}