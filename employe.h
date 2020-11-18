#ifndef EMPLOYE_H_INCLUDED
#define EMPLOYE_H_INCLUDED

typedef struct employe
{
char LastName[20];
char FirstName[20];
int  ID;
int Age;
char gender[10];
int ph_num;
char email[50];
}emp;
int dimension();
int menu();
void ajouter_emp(employe *E,int *N);
void modifier_emp(employe *E,int *N);
void supprimer_emp(employe *E,int *N);
int chercher_emp();
void afficher_emp(employe *E,int *N);



#endif // EMPLOYE_H_INCLUDED
