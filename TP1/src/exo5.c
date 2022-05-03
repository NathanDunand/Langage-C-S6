#include <stdio.h>

/**
 * Exercice 5 : La division
 *
 * Ce programme effectue des calculs et affiche les valeurs
 **/

/**
 * Les différences entre les résultats vient des types utilisés.
 * En effet, selon le type, l'interprétation du binaire n'est pas la même
 * c'est pour cela que pour un même calcul on obtient des résultats différents.
 **/

int main(int argc, char **argv)
{

    /* Division */
    printf("Division : \n");
    float x = 10 / 3;
    printf("%f\n", x);
    printf("ici : %i\n", (int)x);

    x = 10.0 / 3;
    printf("%f\n", x);

    x = 10.0 / 3.0;
    printf("%f\n", x);

    x = (float)10 / 3;
    printf("%f\n", x);

    x = ((float)10) / 3;
    printf("%f\n", x);

    x = ((float)10) / 3;
    printf("%.0f\n", x);
    printf("%.5f\n", x);

    /*
    * La différence réside dans le fait que les variables ne sont pas codées de la même manières en mémoire, 
    * on réalise un cast (conversion) des variables à afficher. Cela explique les deux premiers affichages de x ;
    * puisqu'un flottant n'est pas codé de la même manière en mémoire, alors si on l'interprète comme un entier,
    * la valeur paraît aberrante.
    * Le cast permet de ne pas lever warning en affichant un type comme étant un autre.
    */
    return 0;
}