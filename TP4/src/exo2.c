#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        if (c == 10)
        {
            break;
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
    new_date.day = -1;
    new_date.month = -1;
    new_date.year = -1;

    new_personne.name = "";
    new_personne.surname = "";

    char *name = charFromSTDIN("Entrer le nom : ");
    char *surname = charFromSTDIN("Entrez le prénom : ");

    new_personne.name = name;
    new_personne.surname = surname;

    int day = intFromSTDIN("Entrer le jour de naissance : ");
    if (day < 1 || day > 31)
    {
        printf("Nombre incorrect.\n");
        exit(1);
    }
    new_date.day = day;

    int month = intFromSTDIN("Entrer le numéro de mois de naissance : ");
    if (month < 1 || month > 12)
    {
        printf("Nombre incorrect.\n");
        exit(1);
    }
    new_date.month = month;

    int year = intFromSTDIN("Entrer l'année de naissance : ");
    if (year < 0 || year > 2022)
    {
        printf("Nombre incorrect.\n");
        exit(1);
    }
    new_date.year = year;

    new_personne.date_of_birth = new_date;
    DATABASE[CURRENT_INDEX] = new_personne;
    CURRENT_INDEX++;
}

void display_people()
{
    for (int i = 0; i < CURRENT_INDEX; i++)
    {
        printf("Nom : %s\nPrénom : %s\nDate Naissance : %d/%d/%d\n", DATABASE[i].name, DATABASE[i].surname, DATABASE[i].date_of_birth.day, DATABASE[i].date_of_birth.month, DATABASE[i].date_of_birth.year);
        printf("###\n");
    }
}

void sort_by_date() // error de bufferoverflow
{
    for (int i = 0; i < CURRENT_INDEX - 1; i++)
    {
        for (int j = i + 1; j < CURRENT_INDEX; j++)
        {
            char i_day[3];
            char i_month[3];
            char i_year[5];
            char i_concat[3 + 3 + 5];
            int i_cmp;

            sprintf(i_day, "%d", DATABASE[i].date_of_birth.day);
            sprintf(i_month, "%d", DATABASE[i].date_of_birth.month);
            sprintf(i_year, "%d", DATABASE[i].date_of_birth.year);

            strcat(i_concat, i_day);
            strcat(i_concat, i_month);
            strcat(i_concat, i_year);

            i_cmp = atoi(i_concat);

            char j_day[3];
            char j_month[3];
            char j_year[5];
            char j_concat[3 + 3 + 5];
            int j_cmp;

            sprintf(j_day, "%d", DATABASE[j].date_of_birth.day);
            sprintf(j_month, "%d", DATABASE[j].date_of_birth.month);
            sprintf(j_year, "%d", DATABASE[j].date_of_birth.year);

            strcat(j_concat, j_day);
            strcat(j_concat, j_month);
            strcat(j_concat, j_year);

            j_cmp = atoi(j_concat);

            if (i_cmp > j_cmp)
            {
                personne tmp = DATABASE[i];
                DATABASE[i] = DATABASE[j];
                DATABASE[j] = tmp;
            }
        }
    }
}

int main()
{
    create_personne();
    create_personne();
    create_personne();
    sort_by_date();
    display_people();

    return 0;
}