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
    maillon lc; // (1)
    lc.x = 1;   // (2)

    printf("Valeur du champs x = %d\n\n", lc.x);

    lc.suiv = (maillon *)malloc(sizeof(maillon)); // (3)
    lc.suiv->x = 2;                               // (4)

    printf("Valeur du champs x du deuxieme maillon = %d\n\n", lc.suiv->x);
}