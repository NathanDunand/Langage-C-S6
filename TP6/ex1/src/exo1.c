#include <stdio.h>
#include <stdlib.h>

/**
 * Exercice 6 : tp de la mort
 **/

struct Personne{
    struct Personne* precedente;

    char nom[50];
    char prenom[50];
    int num_badge; /*4 num*/
    int code_secret;
    char last_date_access[11];/*DD/MM/YYYY*/
    int last_hour_access;

    struct Personne* suivante;
} Personne;

/* Liste doublement chaînée */
/*struct Node_Personne{
    struct Node_Personne* personne_precedente;
    struct Personne personne;
    struct Node_Personne* personne_suivante;
} Node_Personne;*/

void print_personne(struct Personne * p){
    printf("\tnom : %s\n\tprénom : %s\n\tnuméro badge : %i\n\tcode secret : %i\n\tdernier passage le : %s à %ih\n", p->nom, p->prenom, p->num_badge, p->code_secret, p->last_date_access, p->last_hour_access);
}

/*affiche toutes les personnes à partir de celle qu'on lui donne en paramètre*/
void print_personnes(struct Personne * head){
    printf("Liste des personnes : \n");
    /*Personne p;
    int i;
    for(i = 0; i < nb_p; i++){
        print_personne(l.personne);
        printf("\n\n");
        p = &l.personne_suivante;
    }*/
    struct Personne * pers_courante = head;
    while(pers_courante != NULL){
        print_personne(pers_courante);
        printf("\n\n");
        pers_courante = pers_courante->suivante;
    }
}

/*ajoute à la liste head la personne p, qu'importe la personne qu'on lui fournit*/
void ajouter_personne(struct Personne * head, struct Personne * p){
    struct Personne * pers_courante = head;
    /*on va à la fin de la liste*/
     while(pers_courante->suivante != NULL){
         printf("cc");
        pers_courante = pers_courante->suivante;
    }
    /*on ajoute*/
    pers_courante->suivante = p;
    pers_courante->suivante->suivante = NULL;
    /*TODO : manque le double linking, actuellement c'est juste une liste simplement chaînée*/
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
    struct Personne p1 = {NULL, "Dunand", "Nathan", 1234, 2345, "14/09/2000", 2, NULL};
    struct Personne p2 = {NULL, "AAA", "Nathan", 1234, 2345, "14/09/2000", 2, NULL};
    struct Personne p3 = {NULL, "BBB", "Nathan", 1234, 2345, "14/09/2000", 2, NULL};
    ajouter_personne(&p1, &p2);
    print_personnes(&p1);
    ajouter_personne(&p1, &p3);
    print_personnes(&p1);
    int menu;
    printf("Menu : veuillez choisir votre action :\n- 1 : afficher la liste des personnes enregistrées\n- 2 : ajouter une personne à la liste\n- 3 : supprimer une personne suivant le numéro de badge\n- 4 : modifier le code secret d'une personne\n- 5 : simuler le contrôle d'accès via le clavier\n- 6 : sauvegarder les personnes dans un fichier\n- 7 : lire un fichier contenant des personnes\n\n");
    
    menu = intFromSTDIN("action : ");
    switch (menu)
    {
    case 1:
        printf("Liste des personnes enregistrées :\n");
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;    
    default:
        break;
    }
    return 0;
}
