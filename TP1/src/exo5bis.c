#include <stdio.h>

/**
 * Exercice 5bis : Le modulo
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/

/**
 * On est obligé de cast le nombre réel en int car l'opération modulo
 * ne peut être effectuée sur un nombre réel.
 **/
int main(int argc, char **argv)
{
    int x = 5 % 2;
    printf("%i\n", x);

    float x2 = (int)5.0 % 2;
    printf("%f\n", x2);

    return 0;
}