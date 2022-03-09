#include <stdio.h>

/**
 * Exercice 5 : La division
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/

/**
 * Les différences entre les résultats vient des types utilisés.
 * En effet, selon le type, l'interprétation du binaire n'est pas la même
 * c'est pour cela que pour un même calcul on obtient des résultats différents.
 **/

int main(int argc, char **argv[])
{
    float x = 10 / 3;
    printf("%f\n", x);
    printf("%i\n", (int)x);

    x = 10.0 / 3;
    printf("%f\n", x);

    x = 10.0 / 3.0;
    printf("%f\n", x);

    x = (float)10 / 3;
    printf("%f\n", x);

    x = ((float)10) / 3;
    printf("%f\n", x);

    x = ((float)10) / 3;
    printf("%.0f\n", x);
    printf("%.5f\n", x);

    return 0;
}