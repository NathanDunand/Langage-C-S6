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

void delete_people()
{
    int index = intFromSTDIN("Selectionnez l'index de la personne à supprimer : ");
    if (index < 0 || index >= CURRENT_INDEX)
    {
        printf("Il n'y a rien à supprimer\n");
    }
    for (int i = index; i < CURRENT_INDEX - 1; i++)
    {
        DATABASE[i] = DATABASE[i + 1];
    }
    CURRENT_INDEX--;
}

void modify_people()
{
    int index = intFromSTDIN("Selectionnez l'index de la personne à modifier : ");
    if (index < 0 || index >= CURRENT_INDEX)
    {
        printf("Index incorrect\n");
        return;
    }

    char *name = charFromSTDIN("Entrer le nouveau nom : ");
    char *surname = charFromSTDIN("Entrez le nouveau prénom : ");

    int day = intFromSTDIN("Entrer le nouveau jour de naissance : ");
    if (day < 1 || day > 31)
    {
        printf("Nombre incorrect.\n");
        return;
    }

    int month = intFromSTDIN("Entrer le nouveau numéro de mois de naissance : ");
    if (month < 1 || month > 12)
    {
        printf("Nombre incorrect.\n");
        return;
    }

    int year = intFromSTDIN("Entrer la nouvelle année de naissance : ");
    if (year < 0 || year > 2022)
    {
        printf("Nombre incorrect.\n");
        return;
    }

    DATABASE[index].name = name;
    DATABASE[index].surname = surname;
    DATABASE[index].date_of_birth.day = day;
    DATABASE[index].date_of_birth.month = month;
    DATABASE[index].date_of_birth.year = year;
}

void display_people()
{
    for (int i = 0; i < CURRENT_INDEX; i++)
    {
        printf("###\n** INDEX ** : %d\n", i);
        printf("Nom : %s\nPrénom : %s\nDate Naissance : %d/%d/%d\n", DATABASE[i].name, DATABASE[i].surname, DATABASE[i].date_of_birth.day, DATABASE[i].date_of_birth.month, DATABASE[i].date_of_birth.year);
        printf("###\n\n");
    }
}

void sort_by_date()
{
    for (int i = 0; i < CURRENT_INDEX - 1; i++)
    {
        for (int j = i + 1; j < CURRENT_INDEX; j++)
        {

            unsigned int i_cmp = (DATABASE[i].date_of_birth.year * 1000) + (DATABASE[i].date_of_birth.month * 10) + DATABASE[i].date_of_birth.day;
            unsigned int j_cmp = (DATABASE[j].date_of_birth.year * 1000) + (DATABASE[j].date_of_birth.month * 10) + DATABASE[j].date_of_birth.day;

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
    int quit = 0;
    while (quit != 1)
    {
        int choice = intFromSTDIN("\nChoix :\n0. Quitter\n1. Créer une fiche personne\n2. Afficher toutes les fiches personnes\n3. Trier les fiches en fonction de la date de naissance\n4. Selection d'une fiche pour modification\n5. Supprimer une fiche personne\n");
        switch (choice)
        {
        case 0:
            quit = 1;
            break;
        case 1:
            create_personne();
            break;
        case 2:
            display_people();
            break;
        case 3:
            sort_by_date();
            break;
        case 4:
            modify_people();
            break;
        case 5:
            delete_people();
            break;
        default:
            exit(1);
        }
    }
    return 0;
}