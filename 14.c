// Dada una lista de N números enteros y dos valores enteros, A y B. Se pide informar cuántos números naturales de la lista son sólo múltiplo de A y cuántos son múltiplos sólo de B.
#include <stdio.h>

int main(void)
{
    int n, a = 2, b = 5, nro, counta = 0, countb = 0;
    printf("ingrese la cantidad de numeros:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("ingrese el %d número :", i + 1);
        scanf("%d", &nro);

        if (nro % a == 0 && nro % b != 0)
        {
            printf("%d es solo multiplo de A\n", nro);
            counta++;
        }
        else if (nro % b == 0 && nro % a != 0)
        {
            printf("%d es solo multiplo de B\n", nro);
            countb++;
        }
    }
    printf("B posee %d multiplos", countb);
    printf("A posee %d multiplos", counta);

    return 0;
}