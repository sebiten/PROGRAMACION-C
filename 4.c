/*Ejercicio 4: Dados dos naturales, X e Y, donde X<Y, se necesita generar
aleatoriamente dos números reales A y B, pertenecientes a rango [X, Y] y a
continuación mostrar un menú que permita calcular y mostrar:
    a) La raíz cuadrada de A.
    b) La potencia de AB.
    c) El logaritmo decimal de B.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    int X, Y;
    float A, B, raiz;
    printf("ingrese natural X: ");
    scanf("%d", &X);
    printf("ingrese natural Y: ");
    scanf("%d", &Y);
    srand(time(NULL));
    A = rand() % (Y - X + 1) + X;
    B = rand() % (Y - X + 1) + X;
    printf("\n\nA=%f     B=%f", A, B);

    printf("\n\nraiz=%f", sqrt(A)); /*INVOCACION*/
    raiz = sqrt(A);                 /*INVOCACION*/
    printf("\n\nraiz=%f", raiz);
    if (sqrt(A) > 20) /*INVOCACION*/
        printf("%f era grande", A);
    else
        printf("maso");
    printf("\n\npotencia=%f", pow(A, B));
    printf("\n\nlog=%f", log(B));
    return 0;
}
