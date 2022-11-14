#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct
{
    int j;
    int m;
    int a;
}DATE;
typedef struct
{   int ID_uti;
    char prenom[30];
    char nom[30];
    DATE d;
    char genre[1];
    int vote;
    char role[30];
    int nbv;

}utilisateur;
//function;
int ajouter_utilisateur(char* filename,utilisateur u);
int modifier_utilisateur(char* filename,utilisateur nouv,int ID);
int supprimer_utilisateur(char* filename,int ID);
utilisateur chercher(char*filename,int ID);
#endif // FUNCTION_H_INCLUDED

