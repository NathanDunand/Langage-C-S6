#include "degre.h"

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

void executerChoix(int choice)
{
    float res;
    int good = 1;
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        res = cel2fah(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    case 2:
        res = cel2kel(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    case 3:
        res = fah2cel(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    case 4:
        res = fah2kel(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    case 5:
        res = kel2cel(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    case 6:
        res = kel2fah(floatFromSTDIN("Entrez un nombre flottant"));
        break;
    default:
        good = 0;
        break;
    }
    if (good == 0)
        print("Veuillez choisir un nombre entre 0 et 6 inclus");
    else
        printf("Le résultat est %f", res);
}

int lireChoix()
{
    int choice = intFromSTDIN("Faites votre choix entre \n0 quitter\n1 : Celsius -> Fahrenheit\n2 : Celsius -> Kelvin\n3 : Farenheit -> Celsius\n4 : Farenheit -> Kelvin\n5 : Kelvin -> Celsius\n6 : Kelvin -> Fahrenheit");
    return choice;
}

int main(int argc, char **argv)
{
    while (1)
    {
        executerChoix(lireChoix());
    }
}