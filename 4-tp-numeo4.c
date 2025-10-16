#include <stdio.h>
#define TAM 100

// Prototipos
typedef int tVector[TAM];
int cargarVector(tVector v, int n);
void mostrarVector(tVector v, int n);
int mayorConMasRepeticiones(tVector v, int n);

int main()
{
    int n, opcion;
    tVector edades;
    printf("Ingrese N edades: \n");
    scanf("%d", &n);
    n = cargarVector(edades, n);
    printf("Las edades ingresadas son: \n");
    mostrarVector(edades, n);
    do
    {
        printf("----MENU----\n");
        printf("1. Determinar mayor edad con mayor cantidad de repeticiones sabiendo que existe y es unica\n");
        printf("2. Mostrar la primera sublista creciente, de al menos dos numeros, conformada solo por elementos pares\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Mostrando opcion 1 \n");
            mostrarVector(edades, n);
            break;
        case 2:
            printf("Mostrando opcion 2 \n");
            mostrarVector(edades, n);
            break;
        case 0:
            printf("Saliendo...\n");
        }
    } while (opcion != 0);

    return 0;
}

int cargarVector(tVector v, int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("Ingrese la edad %d: ", i);
        scanf("%d", &v[i]);
    }
    return n;
}

void mostrarVector(tVector v, int n)
{
    for (int i = 1; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int mayorConMasRepeticiones(tVector v, int n)
{
    int i, j, cont, maxCont = 0, mayor = v[1];
    for (i = 1; i <= n; i++)
    {
        cont = 0;
        for (j = 1; j <= n; j++)
        {
            if (v[i] == v[j])
                cont++;
        }

        // si tiene más repeticiones o igual cantidad pero es mayor
        if (cont > maxCont || (cont == maxCont && v[i] > mayor))
        {
            maxCont = cont;
            mayor = v[i];
        }
    }

    return mayor;
}
void mostrarPrimeraSublistaCreciente(tVector v, int n)
{
    int i = 1, j, inicio, fin, largo;

    while (i < n)
    {
        // Paso 1: buscar el inicio de una posible sublista creciente
        if (v[i] < v[i + 1])
        {
            inicio = i;

            // Paso 2: seguir avanzando mientras siga creciendo
            j = i + 1;
            while (j < n && v[j] < v[j + 1])
                j++;

            fin = j; // fin de la sublista creciente
            largo = fin - inicio + 1;

            // Paso 3: verificar si tiene al menos 2 elementos
            if (largo >= 2)
            {
                printf("Primera sublista creciente:\n");
                for (int k = inicio; k <= fin; k++)
                    printf("%d ", v[k]);
                printf("\n");
                return; // cortamos, solo queremos la primera
            }

            i = j; // continuar buscando después del tramo
        }
        else
        {
            i++; // no crece, seguimos buscando
        }
    }

    printf("No hay sublista creciente de al menos dos elementos.\n");
}
