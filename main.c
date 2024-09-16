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
            printf("\n\t \x1b[31m---- Choix Invalid ----\x1b[0m \n");
        }else{
            
            switch (choix){
            case 1:
                    int valid_Ajoute = Ajouter_un_contact(conatcts , &Taille);
                    if(valid_Ajoute){
                        printf("\n\t \x1b[32m--- Le Contact a ete Ajoute avec Succes ----\x1b[0m \n");
                        Taille++;
                    }else{
                        printf("\n\t \x1b[31m--- Erreur d'ajoutr ----\x1b[0m \n");
                    }
                break;
            case 2:
                    Afficher_tout_les_contact(conatcts , &Taille);
                    break;
            case 3:
                    int valid_modifie = Modifier_un_contact(conatcts , &Taille);
                    if(valid_modifie){
                        printf("\n\t \x1b[32m--- Le Contact a ete Modifier avec Succes ----\x1b[0m\n");
                    }else{
                        printf("\n\t \x1b[31m--- Erreur de Modification ----\x1b[0m\n");
                    }
                    break;
            case 4:
                    int valid_suppression = Supprimer_un_contact(conatcts , &Taille);
                    if(valid_suppression){
                        printf("\n\t \x1b[32m--- Le Contact a ete Supprimer avec Succes ----\x1b[0m\n");
                        if(Taille > 0 ) Taille--;
                    }else{
                        printf("\n\t \x1b[31m--- Erreur de Suppression ----\x1b[0m\n");
                    }
                    break;
            case 5:
                    int valid_cherche = Rechechr_un_contact(conatcts , &Taille);
                    if(valid_cherche != 1){
                        printf("\n\t \x1b[31m--- Erreur de Recherche ----\x1b[0m\n");
                    }
                    break;
            case 6:
                    int valid_tri = Tri_des_contact(conatcts , &Taille);
                    if(valid_tri){
                        printf("\n\t \x1b[32m--- Les Contact a ete Tri avec succes ----\x1b[0m\n");
                    }
                    break;
            case 7:
                    printf("\n\t \x1b[32m----- A bientot -----\x1b[0m \n");
                    break;
            default:
                break;
            }
        }
    }
}