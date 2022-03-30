#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * Affiche un carré de line * line
 *
 * ex : pour line = 4
 * ****
 * ****
 * ****
 * ****
 */
void square(int line)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < line; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void right_arrow(int line)
{
    for (int i = 0; i < line; i++)
    {
        int x = 0;
        if (line % 2 == 1)
        {
            x = 1;
        }

        if (i < (int)(line / 2 + x))
        {
            for (int pt = 0; pt < i + 1; pt++)
            {
                printf("*");
            }
        }
        else
        {
            for (int pt = line - i; pt > 0; pt--)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void left_arrow(int line)
{
    for (int i = 0; i < line; i++)
    {
        int x = 0;
        if (line % 2 == 1)
        {
            x = 1;
        }

        if (i < (int)(line / 2 + x))
        {
            for (int k = 0; k < (int)(line / 2 + x) - (i + 1); k++)
            {
                printf(" ");
            }
            for (int pt = 0; pt < i + 1; pt++)
            {
                printf("*");
            }
        }
        else
        {
            for (int k = 0; k < (int)(line / 2 + x) - (line - i); k++)
            {
                printf(" ");
            }
            for (int pt = line - i; pt > 0; pt--)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void pyramid(int line, int newline)
{
    for (int i = 0; i < line; i++)
    {
        int x = 0;
        if (line % 2 == 1)
        {
            x = 1;
        }

        for (int j = 0; j < line - (i + x); j++)
        {
            printf(" ");
        }
        for (int pt = 0; pt < 2 * i + 1; pt++)
        {
            printf("*");
        }

        printf("\n");
    }
    if (newline == 1)
    {
        printf("\n");
    }
}

void diamond(int line)
{
    int x = 0;
    if (line % 2 == 1)
    {
        x = 1;
    }

    pyramid((int)(line / 2 + x), 0);
    int new_length = line - (int)(line / 2 + x);

    for (int i = 0; i < new_length; i++)
    {
        for (int j = 0; j < new_length + i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * (new_length - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Exercice 2 : Etoile
 *
 * Ce programme affiche des etoiles en fonction de l'entrée
 **/

int intFromSTDIN(to_display)
{
    printf(to_display);
}

int main(int argc, char **argv)
{
    int line = intFromSTDIN("Entrez le nombre de lignes");
    int menu = intFromSTDIN("Que voulez vous afficher (1-5)");

    if (line < 0)
    {
        printf("ERREUR : Nombre de lignes : Nombre incorrect");
        return 1;
    }

    if (menu <= 0 && menu > 5)
    {
        printf("ERREUR : Option d'affichage : Nombre incorrect");
        return 1;
    }

    switch (menu)
    {
    case 1:
        square(line);
        break;
    case 2:
        right_arrow(line);
        break;
    case 3:
        left_arrow(line);
        break;
    case 4:
        pyramid(line, 1);
        break;
    case 5:
        diamond(line);
        break;
    default:
        return 1;
    }

    return 0;
}