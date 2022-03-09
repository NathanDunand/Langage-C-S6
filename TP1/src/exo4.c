#include <stdio.h>

/**
 * Exercice 4 : Priorité des opérateurs
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/
int main(int argc, char **argv)
{
    int x;

    x = -3 + 4 * 5 - 6;
    printf("%i\n", x);
    x = (-3 + 4) * 5 - 6;
    printf("%i\n", x);
    x = -3 + (4 * 5) - 6;
    printf("%i\n", x);
    x = -3 + 4 * (5 - 6);
    printf("%i\n", x);

    return 0;
}