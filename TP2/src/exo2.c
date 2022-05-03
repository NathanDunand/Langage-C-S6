#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * Exercice 2 : Etoile
 *
 * Ce programme affiche des etoiles en fonction de l'entrée
 **/

/**
 * Affiche un carré de line * line
 */
void square(int line)
{
    int i = 0;
    while (i < line)
    {
        for (int j = 0; j < line; j++)
        {
            printf("*");
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

/**
 * Affiche une flèche pointant vers la droite d'une hauteur
 * de line et largeur de line/2 (+1 si impair)
 */
void right_arrow(int line)
{
    /*for (int i = 0; i < line; i++)
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
    printf("\n");*/
    /*line*2-1 -> nombre de ligne*/
    for(int i = 0; i < line*2-1; i++){
        if(i+1 < line){
            for(int j = 0; j <= i; j++){
                printf("*");
            }
        } else if(i+1 > line){
            for(int j = (line*2)-(i+1); j > 0; j--){
                printf("*");
            }
        } else {
            /*hauteur de la pyramide*/
            for(int j = 0; j <= i; j++){
                printf("*");
            }
        }
        printf("\n");
    }
}

/**
 * Affiche une flèche pointant vers la gauche d'une hauteur
 * de line et largeur de line/2 (+1 si impair)
 */
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

/**
 * Affiche une pyramide d'une hauteur
 * de line et largeur de line/2 (+1 si impair)
 */
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

/**
 * Affiche un losange d'une hauteur de line
 */
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
 * Permet de récupérer un nombre de manière sécurisé
 */
int intFromSTDIN(char *to_display)
{
    printf("%s", to_display);
    char *line = malloc(100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if (line == NULL)
    {
        return 0;
    }

    for (;;)
    {
        c = fgetc(stdin);
        if (c == EOF)
            break;

        if (--len == 0)
        {
            len = lenmax;
            char *linen = realloc(linep, lenmax *= 2);

            if (linen == NULL)
            {
                free(linep);
                return 0;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if ((*line++ = c) == '\n')
            break;
    }
    *line = '\0';

    int given = atoi(linep);
    return given;
}

int main(int argc, char **argv)
{
    int line = intFromSTDIN("Entrez le nombre de lignes : ");

    if (line < 1 || line > 20)
    {
        printf("ERREUR : Nombre de lignes : Nombre incorrect (0<N<20)\n");
        return 1;
    }

    int menu = intFromSTDIN("Que voulez vous afficher (1-5) ? ");

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