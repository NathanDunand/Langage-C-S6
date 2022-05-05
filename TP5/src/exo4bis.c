#include <stdlib.h>
#include <stdio.h>

#define N 3

typedef struct maillon
{
    int x;
    struct maillon *suiv;
} maillon;

void main(void)
{
    maillon *lc;   // (1)
    maillon *tete; // (2)
    int cpt;       // (3)

    /*init des maillons*/
    lc = (maillon *)malloc(sizeof(maillon)); // (4)
    tete = lc;                               // (5)

    // Creation des maillons en fin de liste
    for (cpt = 1; cpt < N; cpt++) // pour tous les maillons à créer
    {
        lc->suiv = (maillon *)malloc(sizeof(maillon)); // (6)
        lc = lc->suiv;                                 // (7)
    }
    lc->suiv = NULL; // (8)

    cpt = 0;   // (9)
    lc = tete; // (10)

    // remplissage des valeurs de chacun des maillons
    while (lc != NULL) // tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        lc->x = cpt;   // (11) affectation
        cpt++;         // (12) increment du compteur
        lc = lc->suiv; // (13) passe au suivant
    }

    lc = tete; // (14)

    while (lc != NULL) // tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        printf("Valeur du champs courant = %d \n", lc->x);
        printf("Adresse maillon courant= %X et du suivant %X\n", lc, lc->suiv);
        lc = lc->suiv; // (15) passe au suivant
    }
}