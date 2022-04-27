#include <stdio.h>
#include <stdlib.h>

/**
 * Exo 4 : Programme qui convertie un temps donnée en heures minutes secondes
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

float floatFromSTDIN(char *to_display)
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

        if ((c < 48 || c > 57) && c != 10 && c != 46)
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

    float given = atof(linep);
    return given;
}

char *compare_int(int a, int b)
{
    char *ret[2];
    if (a == b)
    {
        ret[0] = "1";
        ret[1] = "V";
        return *ret;
    }
    else
    {
        ret[0] = "0";
        ret[1] = "F";
        return *ret;
    }
}

char *compare_float(float a, float b)
{
    char *ret[2];
    if (a == b)
    {
        ret[0] = "1";
        ret[1] = "V";
        return *ret;
    }
    else
    {
        ret[0] = "0";
        ret[1] = "F";
        return *ret;
    }
}

int main(int argc, char **argv)
{
    int a = intFromSTDIN("Premier nombre entier : ");
    int b = intFromSTDIN("Deuxième nombre entier: ");

    char *res = compare_int(a, b);
    printf("Le résultat est %c\n", res[0]);

    float af = floatFromSTDIN("Premier nombre flottant : ");
    float bf = floatFromSTDIN("Deuxième nombre flottant: ");

    char *resf = compare_float(af, bf);
    printf("Le résultat est %c\n", resf[0]);

    exit(0);
}