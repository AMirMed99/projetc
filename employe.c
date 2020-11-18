#include <stdio.h>
#include <stdlib.h>
#include "employe.h"

int menu()
{
int x;
    do{
    printf("---------------------------------------------\n");
    printf("Menu\n");
    printf("---------------------------------------------\n");
    printf("1: Ajouter un employé \n");
    printf("2: modifier un employé \n");
    printf("3: supprimer un employé \n");
    printf("---------------------------------------------\n");
    printf("Introduire votre choix: ");
    scanf("%d",&x);
    }while(x<0 || x>3);
    return x;
}
void ajouter_emp(employe *E,int *N)
{
printf("Donner le nom : ");
scanf(&E[*N].LastName);
printf("Donner le Prénom  : ");
scanf(E[*N].FirstName);
printf("Donner l'identifiant : ");
scanf("%ld",&E[*N].ID);
printf("Donner  l'age : ");
scanf("%ld",&E[*N].Age);
printf("Donner le email  : ");
scanf(E[*N].email);

}
void modifier_emp(employe *E,int *N)
{

}
void supprimer_emp(employe *E,int *N)
{
{ int i,j,identity;

printf("Donner un identifiant : ");
scanf("%d",&identity);

for(i=0;i<*N;i++)
{
    if((*(E+i)).ID==identity)
    {
        for (j=i;j<*N-1;j++)
            *(E+j)=*(E+j+1);
        (*N)--;

    }

}

}

}
int chercher_emp()
{

}
void afficher_emp(employe *E,int N)
{
int i;
printf("Employés : \n");
for (i=0;i<N;i++)
{
    printf("NOM : %s  ,  Prenom : %s, ID : %ld , Age : %d \n" ,(*(E+i)).LastName ,(*(E+i)).FirstName , (*(E+i)).ID,(*(E+i)).age);

}
int Dimension()
{
int N;
do
{
    printf("Donner la dimension:\n");
    scanf("%d",&N);
}
while(N<=0 || N>50);
return(N);
}
