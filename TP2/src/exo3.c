#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 30

/**
 * Exercice 3 : Algorithme de tri
 *
 * Ce programme effectue 3 types de tris différents : bulles,
 * minima successifs, insertion
 **/

void printArray(int arr[])
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/**
 * Echange deux valeurs en utilisant les pointeurs
 */
void swap(int *first, int *second)
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[])
{
    int loop_min;
    for (int i = 0; i < N - 1; i++)
    {
        loop_min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[loop_min])
            {
                loop_min = j;
            }
        }
        swap(&arr[i], &arr[loop_min]);
    }
}

void insertionSort(int arr[])
{
    int value;
    for (int i = 1; i < N; i++)
    {
        value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = value;
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    printf("Bubble Sort : \n");
    int arr1[N];

    for (int i = 0; i < N; i++)
    {
        arr1[i] = rand() % 51;
    }
    printArray(arr1);
    bubbleSort(arr1);
    printArray(arr1);

    printf("Selection Sort : \n");
    int arr2[N];
    for (int i = 0; i < N; i++)
    {
        arr2[i] = rand() % 51;
    }
    printArray(arr2);
    selectionSort(arr2);
    printArray(arr2);

    printf("Insertion Sort : \n");
    int arr3[N];
    for (int i = 0; i < N; i++)
    {
        arr3[i] = rand() % 51;
    }
    printArray(arr3);
    insertionSort(arr3);
    printArray(arr3);

    return 1;
}