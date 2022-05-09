#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER 50

/**
 * Exercice 6 : tp de la mort
 **/

struct Personne{
    struct Personne* precedente;

    char nom[BUFFER];
    char prenom[BUFFER];
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

/*0 si le noeud est le noeud originel, 1 sinon*/
int is_head(struct Personne * node){
    int is_head;
    /*noeud originel*/
    if(node == NULL){
        return 0;
    }
    /*si tout est NULL sauf le suivant (pas obligatoirement NULL)*/
    if(node->precedente == NULL && node->num_badge == 0 && node->code_secret == 0 && node->last_hour_access == 0){
        is_head = 0;
    } else {
        is_head = 1;
    }
    return is_head;
}

void supprimer_personne(struct Personne * head, int num_badge){
    struct Personne * pers_courante = head;
    revenir_debut_liste(head);
    while(pers_courante != NULL){
        /*printf("boucle : %i\n", pers_courante->num_badge);*/
        if(pers_courante->num_badge == num_badge){
            /*delink & relink*/
            /*TODO : gérer la chiée de cas limite*/
            if(pers_courante->precedente == NULL){
                /*TODO : peut-être un bug ici, sinon tout semble bon*/
                /*l'élément qu'on supprime est le premier de la liste*/
                pers_courante->suivante->precedente = pers_courante->precedente;
            } else if(pers_courante->suivante == NULL) {
                /*l'élément qu'on supprime est le dernier de la liste*/
                pers_courante->precedente->suivante = NULL;
            } else {
                /*l'élément n'est ni premier ni dernier*/
                pers_courante->precedente->suivante = pers_courante->suivante;
                pers_courante->suivante->precedente = pers_courante->precedente;
            }
            /*libération de l'espace mémoire puisque alloué avec malloc()*/
            free(pers_courante);
            return;
        }
        /*on avance*/
        pers_courante = pers_courante->suivante;
    }
    printf("Le numéro de badge spécifié n'existe pas.\n");
    return;
}

/*affiche toutes les personnes à partir du début de la liste qu'importe le noeud qu'on lui donne*/
void print_personnes(struct Personne * head){
    /*revenir_debut_liste(head);*/
    /*printf("Liste des personnes : \n");*/
    struct Personne * pers_courante = head;
    while(pers_courante != NULL){
        if(is_head(pers_courante)){
            print_personne(pers_courante);
            printf("\n\n");
        }
        pers_courante = pers_courante->suivante;
    }
}

/*DEBUG ONLY : affiche la personne précédente dans la liste si elle existe*/
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

/*Retourne le nombre de personne de la liste*/
int get_size_liste(struct Personne * p){
    revenir_debut_liste(p);
    struct Personne * pers_courante = p;
    int compteur = 0;
    /*aucun noeud sauf l'originel*/
    if(pers_courante == NULL){
        return 0;
    }
    while(pers_courante->suivante != NULL){
        pers_courante = pers_courante->suivante;
        compteur++;
    }
    /*on ne compte pas le noeud originel*/
    return compteur--;
}

/*retourne 1 si le numéro du badge est déjà dans la liste, 0 sinon*/
int numero_badge_exist(struct Personne * head, int num_badge){
    struct Personne * pers_courante = head;
    /*noeud originel et vide*/
    if(is_head(pers_courante) == 0 && get_size_liste(pers_courante) == 0){
        return 0;
    }
    /*si on est sur le noeud originel et que la liste contient d'autres noeuds*/
    if(is_head(pers_courante) == 0 && get_size_liste(pers_courante) != 0){
        pers_courante = pers_courante->suivante;
    }
    int badges[get_size_liste(head)], i = 0;
    while(pers_courante != NULL){
        badges[i] = pers_courante->num_badge;
        /*on avance*/
        pers_courante = pers_courante->suivante;
        i++;
    }
    /*on a remplit notre tableau de badge*/
    for(i = 0; i < get_size_liste(head); i++){
        if(num_badge == badges[i]){
            return 1;
        }
    }
    return 0;
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
    printf("Personne ajoutée !\n");
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
    /*init de la structure, ce noeud ne peut pas être supprimé*/
    struct Personne * head = malloc(sizeof(Personne));
    /*DEBUG ZONE*/
    /*struct Personne * p2;
    p2->nom = "DUNAND";
    p2->prenom = "Nathan";
    p2->code_secret = 1234;
    p2->num_badge = 1;
    ajouter_personne(head, p2);
    print_personnes(head);*/

    /*END*/

    do{
        printf("\n----------------------------------\nMenu : veuillez choisir votre action :\n- 1 : afficher la liste des personnes enregistrées\n- 2 : ajouter une personne à la liste\n- 3 : supprimer une personne suivant le numéro de badge\n- 4 : modifier le code secret d'une personne\n- 5 : simuler le contrôle d'accès via le clavier\n- 6 : sauvegarder les personnes dans un fichier\n- 7 : lire un fichier contenant des personnes\n- autre touche : quitter\n\n----------------------------------\n");
        menu = intFromSTDIN("action : ");
        /*noeud originel, ne peut pas être supprimé*/
        switch (menu)
        {
        case 1:
            printf("Liste des personnes enregistrées :\n");
            if(get_size_liste(head) > 0){
                print_personnes(head);
            } else { printf("Aucune personne.\n"); }
            break;
        case 2:
            printf("Ajouter une personne à la liste :\n");
            char nom[BUFFER];
            printf("Nom : ");
            fgets(nom, BUFFER, stdin);
            nom[strcspn(nom, "\n")] = 0;
            
            char prenom[BUFFER];
            printf("Prénom : ");
            fgets(prenom, BUFFER, stdin);
            prenom[strcspn(prenom, "\n")] = 0;
            int num_badge = intFromSTDIN("Numéro du badge : ");
            /*on vérifie que le numéro du badge n'existe pas déjà*/
            if(numero_badge_exist(head, num_badge) == 1){
                printf("Ce numéro de badge existe déjà !\n");
                break;
            }
            int code_secret = intFromSTDIN("Code secret : ");
            /*valeurs par défaut*/
            char last_date_access[11] = "00/00/0000";
            int last_hour_access = 0;
            /*peut être faire un malloc ici */
            struct Personne * p = malloc(sizeof(Personne));
            p->precedente = NULL;
            memcpy(p->nom, nom, strlen(nom)+1);
            memcpy(p->prenom, prenom, strlen(prenom)+1);
            p->num_badge = num_badge;
            p->code_secret = code_secret;
            memcpy(p->last_date_access, last_date_access, strlen(last_date_access)+1);
            p->last_hour_access = last_hour_access;
            p->suivante = NULL;
            ajouter_personne(head, p);
            break;
        case 3:
            printf("Supprimer une personne suivant le numéro de badge\n");
            int num_badge3 = intFromSTDIN("Entrez le numéro du badge à supprimer : ");
            supprimer_personne(head, num_badge3);
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

    /*TODO: penser au free ici*/
    return 0;
}
