#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARACTER1 50
#define MAX_CHARACTER2 100

typedef struct{

    char id[MAX_CHARACTER2];
    char Nom[MAX_CHARACTER1];
    int Tele;
    char Email[MAX_CHARACTER2];

}Contacts;

void Afficher_tout_les_contact(Contacts *contacts, int *Taille);
int Ajouter_un_contact(Contacts *contacts, int *Taille);
int Modifier_un_contact(Contacts *contacts, int *Taille);
int Supprimer_un_contact(Contacts *contacts, int *Taille);
int Rechechr_un_contact(Contacts *contacts, int *Taille);
int Tri_des_contact(Contacts *contacts, int *Taille);
int Choix(int *choix);

