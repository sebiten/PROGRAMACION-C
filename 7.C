#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char tVector[MAX];

// ---- Prototipos ----
void cargarVector(tVector v, int *n);
void mostrarVector(tVector v, int n);
void insertarCaracter(tVector v, int *n, int p, char c);
void eliminarAnteriorVocal(tVector v, int *n);
void cambiarVocalesMayusculas(tVector v, int n);
int esVocal(char c);

// ---- Programa Principal ----
int main()
{
    tVector A;
    int N = 0, op, P;
    char C;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Cargar vector\n");
        printf("2. Mostrar vector\n");
        printf("3. Insertar caracter en posicion P\n");
        printf("4. Eliminar elemento anterior a la primera vocal\n");
        printf("5. Cambiar vocales a mayusculas\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cargarVector(A, &N);
            break;
        case 2:
            mostrarVector(A, N);
            break;
        case 3:
            if (N == 0)
                printf("Debe cargar el vector primero.\n");
            else
            {
                printf("Ingrese la posicion P (1 a %d): ", N + 1);
                scanf("%d", &P);
                printf("Ingrese el caracter: ");
                scanf(" %c", &C);
                insertarCaracter(A, &N, P, C);
            }
            break;
        case 4:
            eliminarAnteriorVocal(A, &N);
            break;
        case 5:
            cambiarVocalesMayusculas(A, N);
            break;
        }
    } while (op != 0);

    return 0;
}

// ---- Cargar vector ----
void cargarVector(tVector v, int *n)
{
    int i;
    printf("Ingrese la cantidad de caracteres: ");
    scanf("%d", n);
    printf("Ingrese los caracteres (sin espacios):\n");
    for (i = 1; i <= *n; i++)
    {
        scanf(" %c", &v[i]);
    }
}

// ---- Mostrar vector ----
void mostrarVector(tVector v, int n)
{
    int i;
    printf("Vector: ");
    for (i = 1; i <= n; i++)
        printf("%c", v[i]);
    printf("\n");
}

// ---- Insertar caracter ----
void insertarCaracter(tVector v, int *n, int p, char c)
{
    int i;
    if (p < 1 || p > *n + 1)
    {
        printf("Posicion invalida.\n");
        return;
    }
    for (i = *n; i >= p; i--)
    {
        v[i + 1] = v[i];
    }
    v[p] = c;
    (*n)++;
}

// ---- Eliminar anterior a primera vocal ----
void eliminarAnteriorVocal(tVector v, int *n)
{
    int i, posVocal = 0;
    for (i = 1; i <= *n; i++)
    {
        if (esVocal(v[i]))
        {
            posVocal = i;
            break;
        }
    }
    if (posVocal > 1)
    {
        for (i = posVocal - 1; i < *n; i++)
            v[i] = v[i + 1];
        (*n)--;
        printf("Elemento anterior a la primera vocal eliminado.\n");
    }
    else
    {
        printf("No hay vocales o no existe elemento anterior.\n");
    }
}

// ---- Cambiar vocales a mayúsculas ----
void cambiarVocalesMayusculas(tVector v, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        switch (v[i])
        {
        case 'a':
            v[i] = 'A';
            break;
        case 'e':
            v[i] = 'E';
            break;
        case 'i':
            v[i] = 'I';
            break;
        case 'o':
            v[i] = 'O';
            break;
        case 'u':
            v[i] = 'U';
            break;
        }
    }
    printf("Vocales cambiadas a mayúsculas.\n");
}

// ---- Función auxiliar ----
int esVocal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
