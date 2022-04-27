#include <stdio.h>
#include <stdlib.h>

/**
 * Exo 3 : Programme qui convertie un temps donnée en heures minutes secondes
 * en secondes.
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

        if ((c < 48 || c > 57) && c != 10)
        {
            printf("Veuillez rentrer des chiffres\n");
            exit(1);
        }

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
    int h = intFromSTDIN("Heure : ");
    int m = intFromSTDIN("Minute : ");
    int s = intFromSTDIN("Secondes : ");

    int res = h * 60 * 60 + m * 60 + s;
    printf("Le résultat est %d\n", res);
}