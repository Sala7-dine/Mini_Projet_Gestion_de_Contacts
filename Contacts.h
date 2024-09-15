#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"


#define MAX_CHARACTER1 50
#define MAX_CHARACTER2 100

typedef struct{

    int id;
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

