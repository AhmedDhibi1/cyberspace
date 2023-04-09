#ifndef INTERNAUTE_DYN_H_INCLUDED
#define INTERNAUTE_DYN_H_INCLUDED
#include "structure.fich.h"
typedef struct inter
{
    int Cin;
    DATE date;
    TEMPS heure_de_entree;
    TEMPS heure_de_sortie;
    int num;
    float prix ,montant;
    TEMPS temps_passee;

}INTERNAUTE;

struct cellule
{
INTERNAUTE valeur;
struct cellule *suivant;
};
typedef struct cellule *Liste;


INTERNAUTE Lire_Internaute();
void Afficher_Internaute(INTERNAUTE I);
void modifier_internaute(INTERNAUTE *I);
Liste Lire_Liste_internaute(INTERNAUTE I,Liste lst);
void affiche_Liste_internaute(Liste Lst);
struct cellule* rechercher_internaute(Liste lst);
struct cellule* supprimer_internaute(Liste lst);
void liste_internaute_par_pc_date(Liste lst);
TEMPS temps_moyenne_internaute_par_jour(Liste lst,int r,DATE d);
TEMPS taux_occupation_journee(Liste lst,DATE d);
TEMPS taux_occupation_mois(Liste lst);

#endif // INTERNAUTE_DYN_H_INCLUDED
