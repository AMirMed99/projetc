#include <stdio.h>
#include <string.h>
#include "treeview.h"
#include <gtk/gtk.h>

enum
{
CIN,
NOM,
PRENOM,
DATE_NAISSANCE,
ADRESSE,
COLUMNS,
};

//ajouter une personne
void ajouter_personne(personne p)
{

FILE *f;
f=fopen("utilisateur.txt","a");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",p.cin, p.nom, p.prenom, p.date_naissance, p.adresse);
fclose(f);
}}
//afficher une personne
void afficher_personne(GtkWidget *liste)
{

GtkCellRenderer *renderer; 
GtkTreeViewColumn *column;
GtkTreeIter iter; 
GtkTreeStore *store;
char nom[30];
char prenom[30];
char date[30];
char adresse[30];
char cin[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_naissance",renderer,"text",DATE_NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("utilisateur.txt","r");
if (f==NULL)
{return;}
else {
f=fopen("utilisateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",cin,nom,prenom,date, adresse)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE_NAISSANCE,date,ADRESSE,adresse,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}}
void supprimer_personne(personne p)
{
char nom[30];
char prenom[30];
char date[30];
char adresse[30];
char cin[30];

FILE *f,*g;
f=fopen("utilisateur.txt","r");
g=fopen("dump.txt","w");
if(f==NULL || g==NULL)
{
return;}
else{
while(fscanf(f,"%s %s %s %s %s",p.cin, p.nom, p.prenom, p.date_naissance, p.adresse)!=EOF)
{
if (strcmp(p.cin,cin)!=0||strcmp(p.nom,nom)!=0||strcmp(p.prenom,prenom)!=0||strcmp(p.date_naissance,date)!=0||strcmp(p.adresse,adresse)!=0)
fprintf(f,"%s %s %s %s %s",cin,nom,prenom,date,adresse);
}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("dump.txt","utilisateur.txt");
}
}












