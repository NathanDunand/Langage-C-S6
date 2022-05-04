/*
 * TP 5 : Pointeurs
 *
 * insuffisance des appels de fonction
 * avec passage par valeur
 */

#include <stdio.h>
void echanger(int *pa, int *pb)
{
    int tmp; // (4.1)

    tmp = *pa; // (4.2)
    *pa = *pb; // (4.3)
    *pb = tmp; // (4.4)
}

void main()
{
    int x, y; // (1)

    x = 12; // (2)
    y = 34; // (3)

    printf("Avant échange : x = %d ; y = %d\n", x, y);

    echanger(&x, &y); // (4)

    printf("Après échange : x = %d ; y = %d\n", x, y);
}