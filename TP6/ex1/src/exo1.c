#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Exercice 6 : tp de la mort
 **/

struct Personne{
    struct Personne* precedente;

    char* nom;
    char* prenom;
    int num_badge; /*4 num*/
    int code_secret;
    char* last_date_access;/*DD/MM/YYYY*/
    int last_hour_access;

    struct Personne* suivante;
} Personne;

/* Liste doublement chaînée */
/*struct Node_Personne{
    struct Node_Personne* personne_precedente;
    struct Personne personne;
    struct Node_Personne* personne_suivante;
} Node_Personne;*/

/*affiche une seule personne*/
void print_personne(struct Personne * p){
    printf("\tnom : %s\n\tprénom : %s\n\tnuméro badge : %i\n\tcode secret : %i\n\tdernier passage le : %s à %ih\n", p->nom, p->prenom, p->num_badge, p->code_secret, p->last_date_access, p->last_hour_access);
}

/*parcours de la liste en sens inverse : pour revenir au début*/
void revenir_debut_liste(struct Personne * queue){
    struct Personne * pers_courante = queue;
    while(pers_courante != NULL){
        /*debug*/
        /*print_personne(pers_courante);
        printf("\n\n");*/
        pers_courante = pers_courante->precedente;
    }
}

/*affiche toutes les personnes à partir du début de la liste qu'importe le noeud qu'on lui donne*/
void print_personnes(struct Personne * head){
    revenir_debut_liste(head);
    printf("Liste des personnes : \n");
    struct Personne * pers_courante = head;
    while(pers_courante != NULL){
        print_personne(pers_courante);
        printf("\n\n");
        pers_courante = pers_courante->suivante;
    }
}

/*DEBUG : affiche la personne précédente dans la liste si elle existe*/
void print_pers_prec(struct Personne * node){
    if(node->precedente != NULL){
        print_personne(node->precedente);
    }
}

int get_current_hour(){
    /*heure actuelle, code honteusement pompé depuis ce fil stackoverflow : https://stackoverflow.com/questions/701524/getting-the-current-hour-in-c-using-time-h*/
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    return tm_struct->tm_hour;
}

/*ajoute à la liste head la personne p à la fin de la liste*/
void ajouter_personne(struct Personne * head, struct Personne * p){
    struct Personne * pers_courante = head;
    struct Personne * ptr_personne_prec = head;
    /*on va à la fin de la liste*/
     while(pers_courante->suivante != NULL){
        /*on avance*/
        pers_courante = pers_courante->suivante;
        /*on se souvient de la personne précédente pour le linkage*/
        if(pers_courante != NULL){
            ptr_personne_prec = pers_courante;
        }
    }
    /*on ajoute*/
    pers_courante->suivante = p;
    pers_courante->suivante->suivante = NULL;
    /*double chaîne*/
    /*on va à la nouvelle dernière personne (on l'a ajouté juste avant)*/
    pers_courante = pers_courante->suivante;
    pers_courante->precedente = ptr_personne_prec;
}

/*Retourne le nombre de personne de la liste*/
int get_size_liste(struct Personne * p){
    revenir_debut_liste(p);
    struct Personne * pers_courante = p;
    int compteur = 0;
    while(pers_courante->suivante != NULL){
        compteur++;
    }
    return compteur;
}

char* stringFromSTDIN(char *to_display)
{
    printf("%s", to_display);
    char *line = malloc(50), *linep = line;
    size_t lenmax = 50, len = lenmax;
    int c;

    if (line == NULL)
    {
        /*error*/
        return '\0';
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

    return line;
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
    /*ajouter_personne(&p1, &p3);
    ajouter_personne(&p1, &p4);
    print_pers_prec(&p1);
    print_personnes(&p1);
    revenir_debut_liste(&p4);*/
    int menu;
    do{
        printf("Menu : veuillez choisir votre action :\n- 1 : afficher la liste des personnes enregistrées\n- 2 : ajouter une personne à la liste\n- 3 : supprimer une personne suivant le numéro de badge\n- 4 : modifier le code secret d'une personne\n- 5 : simuler le contrôle d'accès via le clavier\n- 6 : sauvegarder les personnes dans un fichier\n- 7 : lire un fichier contenant des personnes\n- autre touche : quitter\n\n");
        menu = intFromSTDIN("action : ");
        switch (menu)
        {
        case 1:
            printf("Liste des personnes enregistrées :\n");
            /*TODO : à voir comment faire pour l'initialisation de la liste*/
            if(get_size_liste > 0){
                print_personnes(&p1);
            } else { printf("Aucune personne.\n"); }
            break;
        case 2:
            printf("Ajouter une personne à la liste :\n");
            char* nom = stringFromSTDIN("Nom : ");
            char* prenom = stringFromSTDIN("Prénom : ");
            int num_badge = intFromSTDIN("Numéro du badge : ");
            int code_secret = intFromSTDIN("Code secret : ");
            /*valeurs par défaut*/
            char last_date_access[11] = "00/00/0000";
            int last_hour_access = 0;
            struct Personne p1 = {NULL, nom, prenom, num_badge, code_secret, last_date_access, last_hour_access, NULL};

            break;
        case 3:
            printf("Supprimer une personne suivant le numéro de badge\n");
            int num_badge3 = intFromSTDIN("Entrez le numéro du badge à supprimer : ");
            /*suppression à faire ici*/
            break;
        case 4:
            printf("Modifier le code secret d'une personne\n");
            int num_badge4 = intFromSTDIN("Entrez le numéro du badge dont le code secret doit être modifié : ");
            /*fonction*/
            break;
        case 5:
            printf("Simuler le contrôle d'accès via le clavier\n");
            int num_badge5 = intFromSTDIN("Entrez le numéro de votre badge : ");
            int code_secret5 = intFromSTDIN("Entrez votre code secret : ");
            /*fonction*/
            break;
        case 6:
            break;
        case 7:
            break;    
        default:
            menu = 0;
            break;
        }
    }while(menu >= 1 && menu <= 7);
    return 0;
}
