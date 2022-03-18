#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * Exercice 7 : Autour du cercle
 *
 * Ce programme effectue des calculs concernant les cercles
 * et affiche les valeurs obtenue (périmètre et surface)
 **/

#define PI 3.14159

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Veuillez mettre un rayon de cercle");
        return 1;
    }

    double rayon = strtod(argv[1], NULL);

    if (rayon < 0)
    {
        printf("Veuillez mettre un rayon positif");
        return 1;
    }

    if (rayon > DBL_MAX || sqrt(DBL_MAX / PI) < rayon)
    {
        printf("Le rayon est trop grand");
        return 1;
    }
    double perimetre = PI * pow(rayon, 2);
    printf("%lf\n", perimetre);

    return 0;
}