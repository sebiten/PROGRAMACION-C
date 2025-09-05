#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int X, Y, opcion;
    float A, B;

    printf("Ingrese natural X: ");
    scanf("%d", &X);
    printf("Ingrese natural Y: ");
    scanf("%d", &Y);

    srand(time(NULL));
    A = rand() % (Y - X + 1) + X;
    B = rand() % (Y - X + 1) + X;

    printf("\nA = %f   B = %f\n", A, B);

    // menu de opciones
    printf("\nMenu de opciones:");
    printf("\n1. Raiz cuadrada de A");
    printf("\n2. Potencia A^B");
    printf("\n3. Logaritmo decimal de B");
    printf("\nSeleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("Raiz cuadrada de A = %f\n", sqrt(A));
        break;
    case 2:
        printf("Potencia A^B = %f\n", pow(A, B));
        break;
    case 3:
        printf("Logaritmo decimal de B = %f\n", log10(B));
        break;
    default:
        printf("Opcion invlida\n");
    }

    return 0;
}
