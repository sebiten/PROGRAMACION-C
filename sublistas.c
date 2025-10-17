#include <stdio.h>
#define MAX 100

typedef int tVector[MAX];

void cargarVector(tVector v, int *n);
void mostrarVector(tVector v, int n);
void sublistasCrecientes(tVector v, int n);
void sublistasDecrecientes(tVector v, int n);

int main()
{
    tVector v;
    int n, op;

    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &n);
    cargarVector(v, &n);

    do
    {
        printf("\n---- MENU ----\n");
        printf("1. Mostrar vector\n");
        printf("2. Sublistas crecientes\n");
        printf("3. Sublistas decrecientes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            mostrarVector(v, n);
            break;
        case 2:
            sublistasCrecientes(v, n);
            break;
        case 3:
            sublistasDecrecientes(v, n);
            break;
        }
    } while (op != 0);

    return 0;
}

void cargarVector(tVector v, int *n)
{
    int i;
    for (i = 1; i <= *n; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}

void mostrarVector(tVector v, int n)
{
    int i;
    printf("\nVector: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void sublistasCrecientes(tVector v, int n)
{
    int i, j, inicio;
    i = 1;

    printf("\nSublistas crecientes:\n");
    while (i < n)
    {
        if (v[i] < v[i + 1])
        {
            inicio = i;
            while (i < n && v[i] < v[i + 1])
            {
                i++;
            }

            printf("[");
            for (j = inicio; j <= i; j++)
            {
                printf("%d ", v[j]);
            }
            printf("]\n");
        }
        i++;
    }
}

void sublistasDecrecientes(tVector v, int n)
{
    int i, j, inicio;
    i = 1;

    printf("\nSublistas decrecientes:\n");
    while (i < n)
    {
        if (v[i] > v[i + 1])
        {
            inicio = i;
            while (i < n && v[i] > v[i + 1])
            {
                i++;
            }

            printf("[");
            for (j = inicio; j <= i; j++)
            {
                printf("%d ", v[j]);
            }
            printf("]\n");
        }
        i++;
    }
}
