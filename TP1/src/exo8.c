#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * Exercice 8 : Calculatrice
 *
 * Ce programme simule une calculatrice. Prend une opérande et deux valeurs
 * pour effectuer les calculs
 **/

int main(int argc, char **argv)
{   
    /*char op;*/
    char* op = malloc(sizeof(char));
    printf("Entrez l'opération (/,*,-,+): ");
    scanf("%c", &op);

    double op1, op2;
    printf("Entrez la première opérande: ");
    scanf("%lf", &op1);

    printf("Entrez la deuxième opérande: ");
    scanf("%lf", &op2);

    double result;
    if (op == '/')
    {
        if (op2 == 0)
        {
            printf("Division par 0 impossible\n");
            return 1;
        }
        result = op1 / op2;
        printf("%lf\n", result);
    }
    else if (op == '*')
    {
        result = op1 * op2;
        printf("%lf\n", result);
    }
    else if (op == '-')
    {
        result = op1 - op2;
        printf("%lf\n", result);
    }
    else if (op == '+')
    {
        result = op1 + op2;
        printf("%lf\n", result);
    }
    else
    {
        printf("L'opération demandée n'est pas connue\n");
        return 1;
    }

    return 0;
}