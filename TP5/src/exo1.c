#include <stdio.h>

void main(void)
{
  int *px;
  px = (int *)malloc(sizeof(int));

  *px = 1;
  printf("Adresse de px : %X\n", &px);
  printf("Adresse pointee par le pointeur px = %X\n", px);
  printf("Valeur memorisee a l'adresse pointee par le pointeur px = %d\n\n", *px);
}