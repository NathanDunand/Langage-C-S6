#include <stdio.h>
#include <stdlib.h>

#define LENGTH_ARRAY 20

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    char *name;
    char *surname;
    date date_of_birth;
} personne;

personne DATABASE[LENGTH_ARRAY];
int CURRENT_INDEX = 0;

char *charFromSTDIN(char *to_display)
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

    return linep;
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

void create_personne()
{
    personne new_personne;
    date new_date;

    new_personne.name = "";
    new_personne.surname = "";

    int day = intFromSTDIN("Entrer le jour de naissance : ");
    if (day < 1 || day > 31)
    {
        printf("Nombre incorrect.");
        exit(1);
    }
    new_personne.date_of_birth.day = day;

    int month = intFromSTDIN("Entrer le numéro de mois de naissance : ");
    if (day < 1 || day > 12)
    {
        printf("Nombre incorrect.");
        exit(1);
    }
    new_personne.date_of_birth.month = month;

    int year = intFromSTDIN("Entrer l'année de naissance : ");
    if (year < 0 || year > 2022)
    {
        printf("Nombre incorrect.");
        exit(1);
    }
    new_personne.date_of_birth.year = year;

    new_personne.date_of_birth = new_date;
    DATABASE[CURRENT_INDEX] = new_personne;
}

int main()
{

    return 0;
}