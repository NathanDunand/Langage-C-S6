#include <stdio.h>

/**
 * Exercice 7 : Opérateurs logiques et Booléens
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/
int main(int argc, char **argv)
{
    int x = 5 & 6;
    printf("%i\n", x);

    x = 5 && 6;
    printf("%i\n", x);

    return 0;
}