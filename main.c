#include <stdio.h>
#include <stdlib.h>
#include "internaute.dynamique.fich.h"

#include <time.h>
#include <string.h>

int main()
{
    int choix=0;
    INTERNAUTE I;
    Liste lst=NULL;
    struct cellule* rech=NULL;
    char rep[3];
    time_t seconds;
    struct tm instant;
    time(&seconds);
    instant=*localtime(&seconds);
    struct cellule *courrant=NULL;
    FILE *fichier;

    while(1)
    {
      printf("**************************************\n");
      printf("                MENU                 \n");
      printf("********** %d/%d/%d **** %d:%d:%d\n",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min,instant.tm_sec);
      printf("**************************************\n");
      printf("1.  saisir un internaute\n");
      printf("2.  saisir un ensemble d internautes\n");
      printf("3.  afficher l ensemble des internautes\n");
      printf("4.  rechercher un  internaute\n");
      printf("5.  mofifier un  internaute\n");
      printf("6.  supprimer un  internaute\n");
      printf("7.  les internautes qui ont occupé un PC donnee pour une date donnée \n");
      printf("8.  statistiques \n");
      printf("0.  quitter \n");
      printf("\n");
      printf("**************************************\n");
      printf("introduire votre choix: ");
      scanf("%d",&choix);

      switch(choix)
      {
          case 1:
              {
                  fichier=fopen("internautes.txt","rt");
                  if(fichier==NULL)
                  {
                      printf("fichier non ouvert\n");
                  }
                  else
                  {
                      while(!feof(fichier))
                      {
                         fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d %d %f\n",
                         &I.Cin,
                         &I.date.jour,
                         &I.date.mois,
                         &I.date.annee,
                         &I.heure_de_entree.heure,
                         &I.heure_de_entree.minute,
                         &I.heure_de_entree.seconde,
                         &I.heure_de_sortie.heure,
                         &I.heure_de_sortie.minute,
                         &I.heure_de_sortie.seconde,
                         &I.num,
                         &I.montant);
                         lst=Lire_Liste_internaute(I,lst);

                     }

                    }


              break;
              }

          case 2:
              {
              do{
                  I=Lire_Internaute();
                  lst=Lire_Liste_internaute(I,lst);
                  printf("\nvoulez vous ajouter un nouveau internaute? oui/non ");
                  scanf("%s",rep);
              }while (strcmp(rep,"oui")==0);

              break;
              }
          case 3:
              {
                  affiche_Liste_internaute(lst);
                  break;
              }
          case 4:
              {
              rech=rechercher_internaute(lst);
              if(rech!=NULL)
                   Afficher_Internaute(rech->valeur);
              else
                   printf("etudiant introuvable\n");

              break;
              }
          case 5:
              {
              rech=rechercher_internaute(lst);
              if(rech!=NULL)
                   Afficher_Internaute(rech->valeur);
                   printf("voulez vous modifier cet etudiant? oui/non  ");
                   scanf("%s",rep);
                   if(strcmp(rep,"oui")==0)
                   {
                      modifier_internaute(&(rech->valeur));
                   }
              else
                   printf("internaute introuvable\n");


              break;
              }
          case 6:
          {
              lst=supprimer_internaute(lst);
              break;
          }
          case 7:
            {
                liste_internaute_par_pc_date( lst);
                break;
            }
          case 8:
              {


                TEMPS t ,T ,T_1;
                int r;
                DATE d ,D;
                int ch;
                printf("1. temps moyen par internaute par jour \n");
                printf("2. taux d occupation de la journee \n");
                printf("3. taux d occupation du dernier mois \n");
                printf("introduire votre choix \n");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    {
                         printf("donner le cin ");
                         scanf("%d",&r);
                         printf("donner la date sous le format suivant : jour mois annee ");
                         scanf("%d %d %d",&d.jour,&d.mois,&d.annee);
                         t=temps_moyenne_internaute_par_jour(lst,r,d);
                         printf("le temps moyen de l internaute %d est:%d hrs : %d min : %d sec \n",r,t.heure,t.minute,t.seconde);
                         break;
                    }
                case 2:
                    {
                        printf("donner la date sous le format suivant pour calculer le taux d occupation de la journee : jour mois annee");
                        scanf("%d %d %d",&D.jour,&D.mois,&D.annee);
                        T=taux_occupation_journee(lst,D);
                        printf("le taux d occupation de la journee est:%d hrs : %d min : %d sec \n",T.heure,T.minute,T.seconde);
                        break;
                    }
                case 3:
                    {
                        T_1= taux_occupation_mois (lst);
                        printf("le taux d occupation du dernier mois est : %d : %d : %d \n",T_1.heure,T_1.minute,T_1.seconde);
                        break;
                    }
                default:
                    printf("choix invalide");

                }
                break;



            }


          case 0:
              {
              {
                 fichier=fopen("internautes.txt","w");
                 if(fichier==NULL)
                 {
                     printf("\nerreur d'ouverture du fichier");
                 }
                 else
                 {
                     courrant=lst;
                     while(courrant!=NULL)
                     {
                         fprintf(fichier," la cin :%d \n la date %d : %d : %d \n l heur d entree : %d : %d : %d\n l heure de sortie : %d : %d : %d\n numero de pc : %d \n le montant est : %f \n le temps passee est : %d : %d : %d",
                                 courrant->valeur.Cin,
                                 courrant->valeur.date.jour,
                                 courrant->valeur.date.mois,
                                 courrant->valeur.date.annee,
                                 courrant->valeur.heure_de_entree.heure,
                                 courrant->valeur.heure_de_entree.minute,
                                 courrant->valeur.heure_de_entree.seconde,
                                 courrant->valeur.heure_de_sortie.heure,
                                 courrant->valeur.heure_de_sortie.minute,
                                 courrant->valeur.heure_de_sortie.seconde,
                                 courrant->valeur.num,
                                 courrant->valeur.montant,
                                 courrant->valeur.temps_passee.heure,
                                 courrant->valeur.temps_passee.minute,
                                 courrant->valeur.temps_passee.seconde);
                         courrant=courrant->suivant;

                     }
                 }
                 fclose(fichier);
                 exit(0);
              }
          default:
              printf("saisir un choix entre 0 et 6");


      }

    }
    }
    return 0;
}

