#include <stdio.h>
#include <string.h>
#include "internaute.dynamique.fich.h"
#include <time.h>

INTERNAUTE Lire_Internaute()
{

    INTERNAUTE inter ;

    int tmp,hr=0,min=0,sec=0,r=0;
    inter.prix=1.5;
    printf("saisir le cin : ");
    scanf("%d",&inter.Cin);
    do
    {
       printf("\nsaisir la date avec le format suivant: jour mois annee ");
       scanf("%d %d %d",&inter.date.jour,&inter.date.mois,&inter.date.annee);
    }while (inter.date.jour<0 || inter.date.jour>31 || inter.date.mois<0 || inter.date.mois>12 || inter.date.annee<2022 || inter.date.annee>2024);
    do
    {
       printf("\nsaisir l heure d entree  avec le format suivant: heure minute seconde ");
       scanf("%d  %d  %d",&inter.heure_de_entree.heure,&inter.heure_de_entree.minute,&inter.heure_de_entree.seconde);
    }while (inter.heure_de_entree.heure<0 || inter.heure_de_entree.heure>23 || inter.heure_de_entree.minute<0 || inter.heure_de_entree.minute>59 || inter.heure_de_entree.seconde<0 || inter.heure_de_entree.seconde>59);
    do
    {
       printf("\nsaisir l heure de sortie  avec le format suivant: heure minute seconde ");
       scanf("%d  %d  %d",&inter.heure_de_sortie.heure,&inter.heure_de_sortie.minute,&inter.heure_de_sortie.seconde);
    }while (inter.heure_de_sortie.heure<0 || inter.heure_de_sortie.heure>23 || inter.heure_de_sortie.minute<0 || inter.heure_de_sortie.minute>59 || inter.heure_de_sortie.seconde<0 || inter.heure_de_sortie.seconde>59);

    do
    {
       printf("\nsaisir le numero du pc : ");
       scanf("%d",&inter.num);
    }while((inter.num<0) || (inter.num>30));
    tmp=(inter.heure_de_sortie.heure*3600+inter.heure_de_sortie.minute*60+inter.heure_de_sortie.seconde)-(inter.heure_de_entree.heure*3600+inter.heure_de_entree.minute*60+inter.heure_de_entree.seconde);
    if(tmp<=0)
       {
        tmp=tmp+24*3600;
        hr=tmp/3600;
        r=tmp%3600;
        min=r/60;
        sec=r%60;
        inter.temps_passee.heure=hr;
        inter.temps_passee.minute=min;
        inter.temps_passee.seconde=sec;

       }
    else
    {
        hr=tmp/3600;
        r=tmp%3600;
        min=r/60;
        sec=r%60;
        inter.temps_passee.heure=hr;
        inter.temps_passee.minute=min;
        inter.temps_passee.seconde=sec;


    }


    inter.montant=(inter.prix/3600)*tmp;


    return inter;
}

void Afficher_Internaute(INTERNAUTE I)
{



    printf("\n Cin: %d",I.Cin);
    printf("\n date: %d/%d/%d",I.date.jour,I.date.mois,I.date.annee);
    printf("\n heure d entree est  : %d:%d:%d",I.heure_de_entree.heure,I.heure_de_entree.minute,I.heure_de_entree.seconde);
    printf("\n heure de sortie est : %d:%d:%d",I.heure_de_sortie.heure,I.heure_de_sortie.minute,I.heure_de_sortie.seconde);
    printf("\n numero de pc : %d \n",I.num);
    printf("le temps passee est : %d hrs : %d min : %d sec\n",I.temps_passee.heure,I.temps_passee.minute,I.temps_passee.seconde);
    printf("le prix d une heure est : %f dt \n",I.prix);
    printf("le montant a payer  est : %f dt\n",I.montant);

}

Liste Lire_Liste_internaute(INTERNAUTE I,Liste lst)
{
    struct cellule *courant;
    courant=(struct cellule *)malloc(sizeof(struct cellule));
    courant->suivant=lst;
    courant->valeur=I;
    return(courant);
}

void affiche_Liste_internaute(Liste Lst)
{
    struct cellule* courrant;
    courrant =Lst;
    while (courrant!=NULL)
    {

         Afficher_Internaute(courrant->valeur);
         courrant=courrant->suivant;
    }
}

struct cellule* rechercher_internaute(Liste lst)
{
    struct cellule* courrant=NULL;
    int cin;
    printf("donner le cin de l internaute ");
    scanf("%d",&cin);
    courrant=lst;
    while(courrant!=NULL)
    {
        if(courrant->valeur.Cin==cin)
               return courrant;
        courrant=courrant->suivant;
    }
    return NULL;

}




void modifier_internaute(INTERNAUTE *I)
{
    INTERNAUTE inter;
    int i,choix;
    inter = *I;
    int n;
    printf("\n que voulez vous modifier ");
    printf("\n 1.  Cin ");
    printf("\n 2.  date ");
    printf("\n 3.  heure d entree ");
    printf("\n 4.  heure de sortie ");
    printf("\n 5.  numero de pc ");
    printf("\n introduire votre choix ");
    scanf("%d",&choix);
    switch(choix)
    {
          case 1:
          {
                  printf("saisir le Cin:  ");
                  scanf("%d",&inter.Cin);

                  break;
          }
          case 2:
          {
                  do
                  {
                     printf("\n introduire la date: jour mois annee:  ");
                     scanf("\n %d %d %d",&inter.date.jour,&inter.date.mois,&inter.date.annee);
                  }while (inter.date.jour<0 || inter.date.jour>31 || inter.date.mois<0 || inter.date.mois>12 || inter.date.annee<2022 || inter.date.annee>2024);
                  break;
          }
          case 3:
          {
                  do
                  {
                     printf("\n introduire l heure d entree: heure minute seconde  ");
                     scanf("\n %d %d %d",&inter.heure_de_entree.heure,&inter.heure_de_entree.minute,&inter.heure_de_entree.seconde);
                  }while (inter.heure_de_entree.heure<0 || inter.heure_de_entree.heure>23 || inter.heure_de_entree.minute<0 || inter.heure_de_entree.minute>59 || inter.heure_de_entree.seconde<0 || inter.heure_de_entree.seconde>59);
                  break;
          }
          case 4:
          {
                  do
                  {
                     printf("\n introduire l heure d entree de la forme suivante: heure minute seconde  ");
                     scanf("\n %d %d %d",&inter.heure_de_entree.heure,&inter.heure_de_entree.minute,&inter.heure_de_entree.seconde);
                  }while (inter.heure_de_sortie.heure<0 || inter.heure_de_sortie.heure>23 || inter.heure_de_sortie.minute<0 || inter.heure_de_sortie.minute>59 || inter.heure_de_sortie.seconde<0 || inter.heure_de_sortie.seconde>59);
                  break;
          }
          case 5:
          {
                  do
                  {
                     printf("saisir le numero du pc:  ");
                     scanf("%d",&inter.num);
                  }while ((inter.num<0) || (inter.num>30));
                  break;
          }
          default:
              printf("choix errone\n");
    }
    *I=inter;
}
struct cellule* supprimer_internaute(Liste lst){
    int c;
    struct cellule *courrant=lst;
    struct cellule *precedent=NULL;
    printf("\n  donner le cin de l'internaute a supprimer");
    scanf("%d",&c);
    while(courrant!=NULL)
        {
            if(courrant->valeur.Cin==c)
                break;
            precedent=courrant;
            courrant=courrant->suivant;
        }
        if(courrant!=NULL)
        {
            if(precedent!=NULL)
                precedent->suivant=courrant->suivant;
            else
                lst=courrant->suivant;
            free(courrant);
        }
    return (lst);
}
void liste_internaute_par_pc_date(Liste lst)
{
    struct cellule* courrant=NULL;
    DATE d;
    int numpc;
    printf("donner le numero de pc  de l internaute ");
    scanf("%d",&numpc);
    printf("donner la date sous le format suivant : jour mois annee");
    scanf("%d %d %d",&d.jour,&d.mois,&d.annee);

    courrant=lst;
    while(courrant!=NULL)
    {
        if((courrant->valeur.date.jour==d.jour)&&(courrant->valeur.date.mois==d.mois)&&(courrant->valeur.date.annee==d.annee)&&(courrant->valeur.num==numpc))
               Afficher_Internaute(courrant->valeur);
        courrant=courrant->suivant;
    }
}
TEMPS temps_moyenne_internaute_par_jour(Liste lst,int r,DATE d)
{
    struct cellule* courrant=NULL;

    TEMPS t;
    int i=0;
    int somme_tmps=0;
    int moy;

    courrant=lst;
    while(courrant!=NULL)
    {
        if((courrant->valeur.date.jour==d.jour)&&(courrant->valeur.date.mois==d.mois)&&(courrant->valeur.date.annee==d.annee)&&(courrant->valeur.Cin==r)){
             somme_tmps= somme_tmps+(courrant->valeur.temps_passee.heure*3600)+(courrant->valeur.temps_passee.minute*60)+(courrant->valeur.temps_passee.seconde);
             i++;
        }
        courrant=courrant->suivant;


    }
    if (i!=0){
      moy=somme_tmps/i;
      t.heure=moy/3600;
      r=moy%3600;
      t.minute=r/60;
      t.seconde=r%60;
    }
    else
        {
            t.heure=0;
            t.minute=0;
            t.seconde=0;
        }



    return t;
}
TEMPS taux_occupation_journee(Liste lst,DATE d)
{
    struct cellule* courrant=NULL;

    TEMPS t;
    int i=0,r;
    int somme_tmps=0;
    int moy;

    courrant=lst;
    while(courrant!=NULL)
    {
        if((courrant->valeur.date.jour==d.jour)&&(courrant->valeur.date.mois==d.mois)&&(courrant->valeur.date.annee==d.annee)){
             somme_tmps= somme_tmps+(courrant->valeur.temps_passee.heure*3600)+(courrant->valeur.temps_passee.minute*60)+(courrant->valeur.temps_passee.seconde);
             i++;
        }
        courrant=courrant->suivant;


    }
    if (i!=0){
      moy=somme_tmps/i;
      t.heure=moy/3600;
      r=moy%3600;
      t.minute=r/60;
      t.seconde=r%60;
    }
    else
        {
            t.heure=0;
            t.minute=0;
            t.seconde=0;
        }



    return t;
}

TEMPS taux_occupation_mois(Liste lst)
{
    time_t seconds;
    struct tm instant;
    time(&seconds);
    instant=*localtime(&seconds);
    struct cellule* courrant=NULL;



    TEMPS t;
    int k=0,r,i;
    int somme_tmps=0;
    int moy;
    courrant=lst;
    while(instant.tm_mon==courrant->valeur.date.mois)
    {

             somme_tmps= somme_tmps+(courrant->valeur.temps_passee.heure*3600)+(courrant->valeur.temps_passee.minute*60)+(courrant->valeur.temps_passee.seconde);
             k++;
    }
    if (k!=0){
      moy=somme_tmps/k;
      t.heure=moy/3600;
      r=moy%3600;
      t.minute=r/60;
      t.seconde=r%60;
    }
    else
        {
            t.heure=0;
            t.minute=0;
            t.seconde=0;
        }
        return t;
}
