#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    float rayon = (float)strtod(argv[1], NULL);
    float perimetre = PI * pow(rayon, 2);
    printf("%f\n", perimetre);

    return 0;
}