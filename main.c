#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main()
{
    utilisateur u1={11636833,"Yassine","messaoudi",23,12,2000,"f",1,"agent",2},u2={11636835,"Mr","3asfour",1,2,2010,"f",2,"agent",3},u3;
int x ;

     x=ajouter_utilisateur("utilisateur.txt",u1);
     //ajout
    if (x==1)
        printf("\n ajout d'utilisateur avec succes");
    else printf("\n echec ajout");

    //modification
     x=modifier_utilisateur("utilisateur.txt",u2,11636833);
    if(x==1)
        printf("\n Modification d'utilisateur avec succes");
    else printf("\n echec Modification");
    x=supprimer_utilisateur("utilisateur.txt",11636838) ;
    if(x==1)
        printf("\n Suppression d'utilisateur avec succes");
    else printf("\n echec Suppression");
    u3=chercher("utilisateur.txt",11636835);
    if(u3.ID_uti==-1)
        printf("introuvable");
return 0 ;
}

