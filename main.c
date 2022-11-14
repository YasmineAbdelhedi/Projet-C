#include <stdio.h>
#include <stdlib.h>
#include "obs.h"
int main()
{
    observateur o1={11636833,"Yassine","messaoudi",23,12,2000,"f","156161","sfg"},o2={11636835,"Mr","3asfour",1,2,2010,"f","122","agent"},o3;
int x ;

     x=ajouter_observateur("observateur.txt",o1);
     //ajout
    if (x==1)
        printf("\n ajout d'observateur avec succes");
    else printf("\n echec ajout");

    //modification
     x=modifier_observateur("observateur.txt",o2,11636833);
    if(x==1)
        printf("\n Modification d'observateur avec succes");
    else printf("\n echec Modification");
    x=supprimer_observateur("observateur.txt",11636838) ;
    if(x==1)
        printf("\n Suppression d'observateur avec succes");
    else printf("\n echec Suppression");
    o3=chercher("observateur.txt",11636835);
    if(o3.ID_obs==-1)
        printf("introuvable");
return 0 ;
}

