#include <stdio.h>

/**
 * Exercice 6 : Opérateurs logiques et Booléens
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/
int main(int argc, char **argv)
{
    /**
     * vaut 4 car 5 = 101 en base 2 et 6 = 110 en base 2 donc
     * 101 & 110 = 100 qui vaut 4 en base 10
     **/
    int x = 5 & 6;
    printf("%i\n", x);

    /**
     * vaut 1 car les nombres (sauf 0) valent tous 1 en booléen
     * donc 1 & 1 = 1.
     **/
    x = 5 && 6;
    printf("%i\n", x);

    /**
     * vaut 7 car 5 = 101 en base 2 et 6 = 110 en base 2 donc
     * 101 | 110 = 111 qui vaut 7 en base 10
     **/
    x = 5 | 6;
    printf("%i\n", x);

    /**
     * vaut 1 car les nombres (sauf 0) valent tous 1 en booléen
     * donc 1 || 1 = 1.
     **/
    x = 5 || 6;
    printf("%i\n", x);

    /**
     * vaut 3 car 5 = 101 en base 2 et 6 = 110 en base 2 donc
     * 101 ^ 110 = 011 qui vaut 3 en base 10
     **/
    x = 5 ^ 6;
    printf("%i\n", x);

    /**
     * inverse les bits 0 à 1 et 1 à 0. et on obtient donc le complémentaire de 5 qui est -6
     **/
    x = ~5;
    printf("%i\n", x);

    /**
     * vaut 0 car 5 vaut 1 en booléen donc !1 = 0
     **/
    x = !5;
    printf("%i\n", x);

    return 0;
}