#ifndef OBS_H_INCLUDED
#define OBS_H_INCLUDED
typedef struct
{
    int j;
    int m;
    int a;
}DATE;
typedef struct
{   int ID_obs;
    char prenom[30];
    char nom[30];
    DATE d;
    char genre[1];
    char CINPassword[30];
    char app[30];

}observateur;
//function;
int ajouter_observateur(char *filename,observateur o);
int modifier_observateur(char *filename,observateur o1,int ID);
int supprimer_observateur(char* filename,int ID);
observateur chercher(char* filename,int ID_obs);
#endif // OBS_H_INCLUDED

