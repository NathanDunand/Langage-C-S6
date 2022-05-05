#include <stdlib.h>
#include <stdio.h>

#define N 10

typedef struct maillon
{
    int x;
    struct maillon *suiv;
} maillon;

int intFromSTDIN(char *to_display, int max)
{
    printf(to_display, max - 1);
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

void delete (int index, maillon *act)
{
    maillon *prev;
    maillon *next;
    maillon *tmp;

    for (int i = 1; i < index; i++)
    {
        if (i == index - 1)
        {
            tmp = act->suiv;
            prev = act;
            next = act->suiv->suiv;
            prev->suiv = next;
            free(tmp);
        }
        act = act->suiv;
    }
}

void main(void)
{
    maillon *lc;
    maillon *tete;
    int cpt;

    /*init des maillons*/
    lc = (maillon *)malloc(sizeof(maillon));
    tete = lc;

    // Creation des maillons en fin de liste
    for (cpt = 1; cpt < N; cpt++) // pour tous les maillons à créer
    {
        lc->suiv = (maillon *)malloc(sizeof(maillon));
        lc = lc->suiv;
    }
    lc->suiv = NULL;

    cpt = 0;
    lc = tete;

    // remplissage des valeurs de chacun des maillons
    while (lc != NULL) // tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        lc->x = cpt;   // affectation
        cpt++;         // increment du compteur
        lc = lc->suiv; // passe au suivant
    }

    lc = tete;

    int index = intFromSTDIN("Entrer l'index du maillon à supprimer (entre 0 et %d inclus) : ", N);
    if (index < 0 || index >= N)
    {
        printf("ERREUR : index invalide");
        exit(1);
    }

    delete (index, lc);
    lc = tete;

    while (lc != NULL) // tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        printf("Valeur du champs courant = %d \n", lc->x);
        printf("Adresse maillon courant= %X et du suivant %X\n", lc, lc->suiv);
        lc = lc->suiv; // (15) passe au suivant
    }
}