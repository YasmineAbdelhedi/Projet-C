#include<stdio.h>
#include "function.h"
int ajouter_utilisateur(char*filename ,utilisateur u)
{
FILE *f;
f=fopen(filename,"a");
if (f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %s %d %s %d \n",u.ID_uti,u.prenom,u.nom,u.d.j,u.d.m,u.d.a,u.genre,u.vote,u.role,u.nbv);
fclose(f);
return 1;   }
else
    return 0;
} int modifier_utilisateur(char* filename,utilisateur nouv,int ID)
{
FILE *f;
FILE *t;
int test=0;
utilisateur u;
f=fopen(filename,"r");
t=fopen("utilisateurtemp.txt","w");
if (f!=NULL && t!=NULL)
{
    while (fscanf(f,"%d %s %s %d %d %d %s %d %s %d \n",&u.ID_uti,u.prenom,u.nom,&u.d.j,&u.d.m,&u.d.a,u.genre,&u.vote,u.role,&u.nbv)!=EOF)
   {
if(u.ID_uti==ID)
       {
fprintf(t,"%d %s %s %d %d %d %s %d %s %d \n",nouv.ID_uti,nouv.prenom,nouv.nom,nouv.d.j,nouv.d.m,nouv.d.a,nouv.genre,nouv.vote,nouv.role,nouv.nbv);
test=1;}

else
fprintf(t,"%d %s %s %d %d %d %s %d %s %d \n",u.ID_uti,u.prenom,u.nom,u.d.j,u.d.m,u.d.a,u.genre,u.vote,u.role,u.nbv);
   }
}
fclose(t);
fclose(f);
remove(filename);
rename("utilisateurtemp.txt",filename);
return test;
}
int supprimer_utilisateur(char* filename,int ID)
{
FILE *f;
FILE *t;
utilisateur u;
int test=0;
f=fopen(filename,"r");
t=fopen("utilisateurtemp.text","w");
if (f!=NULL && t!=NULL)
    {
    while (fscanf(f,"%d %s %s %d %d %d %s %d %s %d \n",&u.ID_uti,u.prenom,u.nom,&u.d.j,&u.d.m,&u.d.a,u.genre,&u.vote,u.role,&u.nbv)!=EOF)
    {
if(u.ID_uti==ID)
       test=1;

else
fprintf(t,"%d %s %s %d %d %d %s %d %s %d \n",u.ID_uti,u.prenom,u.nom,u.d.j,u.d.m,u.d.a,u.genre,u.vote,u.role,u.nbv);
    }
    }
fclose(t);
fclose(f);
remove(filename);
rename("utilisateurtemp.text",filename);
return test;
}
utilisateur chercher(char*filename,int ID)
{
    utilisateur u;
int test;
FILE* f;
f=fopen(filename,"r");
 if(f!=NULL)
    {
        while(test==0 && fscanf(f,"%d %s %s %d %d %d %s %d %s %d \n",&u.ID_uti,u.prenom,u.nom,&u.d.j,&u.d.m,&u.d.a,u.genre,&u.vote,u.role,&u.nbv)!=EOF)
        {
            if(u.ID_uti==ID)
                test=1;
        }
    }
    fclose(f);
    if(test==0)
        u.ID_uti=-1;
        return u;
}

