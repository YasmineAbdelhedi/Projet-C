#include<stdio.h>
#include "obs.h"
int ajouter_observateur(char *filename,observateur o)
{
FILE *f;
f=fopen(filename,"a");
if (f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %s %s %s \n",o.ID_obs,o.prenom,o.nom,o.d.j,o.d.m,o.d.a,o.genre,o.CINPassword,o.app);
fclose(f);
return 1;   }
else
    return 0;
}
int modifier_observateur(char *filename,observateur nouvO,int ID)
{
FILE *f;
FILE *t;
int test=0;
observateur o;
f=fopen(filename,"r");
t=fopen("observateurtemp.txt","w");
if (f!=NULL && t!=NULL)
{
    while (fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&o.ID_obs,o.prenom,o.nom,&o.d.j,&o.d.m,&o.d.a,o.genre,o.CINPassword,o.app)!=EOF)
   {
if(o.ID_obs==ID)
       {
fprintf(t,"%d %s %s %d %d %d %s %s %s \n",nouvO.ID_obs,nouvO.prenom,nouvO.nom,nouvO.d.j,nouvO.d.m,nouvO.d.a,nouvO.genre,nouvO.CINPassword,nouvO.app);
test=1;}

else
fprintf(t,"%d %s %s %d %d %d %s %s %s \n",o.ID_obs,o.prenom,o.nom,o.d.j,o.d.m,o.d.a,o.genre,o.CINPassword,o.app);
   }
}
fclose(t);
fclose(f);
remove(filename);
rename("observateurtemp.txt",filename);
return test;
}
int supprimer_observateur(char* filename,int ID)
{
FILE *f;
FILE *t;
observateur o;
int test=0;
f=fopen(filename,"r");
t=fopen("observateurtemp.text","w");
if (f!=NULL && t!=NULL)
    {
    while (fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&o.ID_obs,o.prenom,o.nom,&o.d.j,&o.d.m,&o.d.a,o.genre,o.CINPassword,o.app)!=EOF)
    {
if(o.ID_obs==ID)
       test=1;

else
fprintf(t,"%d %s %s %d %d %d %s %s %s \n",o.ID_obs,o.prenom,o.nom,o.d.j,o.d.m,o.d.a,o.genre,o.CINPassword,o.app);
    }
    }
fclose(t);
fclose(f);
remove(filename);
rename("observateurtemp.text",filename);
return test;
}
observateur chercher(char* filename,int ID)
{
    observateur o;
int test;
FILE* f;
f=fopen(filename,"r");
 if(f!=NULL)
    {
        while(test==0 && fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&o.ID_obs,o.prenom,o.nom,&o.d.j,&o.d.m,&o.d.a,o.genre,o.CINPassword,o.app)!=EOF)
        {
            if(o.ID_obs==ID)
                test=1;
        }
    }
    fclose(f);
    if(test==0)
        o.ID_obs=-1;
        return o;
}

