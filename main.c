#include <stdio.h>
#include <stdlib.h>
#include "employe.h"
typedef struct employe
{
char LastName[20];
char FistName[20];
int ID;
int Age;
char gender;
int ph_num;
char email;
};
int dimension();
int menu();
void ajouter_emp(employe *E)
void modifier_emp(employe *E)
void supprimer_emp(employe *E)
int chercher_emp()
void afficher_emp(employe *E)

int main()
{
int choix;
int N;
employe E[50];
N=dimension()
do{
        choix=menu();
        switch(choix)
        {
        case 1:
            ajouter_emp(E,&N);
            break;

        case 2:
            modifier_emp(E,&N);
            break;

        case 3:
            supprimer_emp(E,&N);
            break;
        case 4:
            chercher_emp();
            break;
        case 5:
            Afficher_emp(E,N);
            break;
        }
    }
    while(choix!=0);
}
