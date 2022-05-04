#include <stdio.h>

void echangerPointeurs(int **ppa, int **ppb)
{
    int *tmp;

    tmp = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}

void main()
{
    int x, y;

    x = 12;
    y = 34;

    int *px, *py;
    px = &x;
    py = &y;

    printf("Avant échange : x = %d ; y = %d\n", *px, *py);

    echangerPointeurs(&px, &py);

    printf("Après échange : x = %d ; y = %d\n", *px, *py);
}