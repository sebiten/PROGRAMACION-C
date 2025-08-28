#include <stdio.h>

int main(void)
{
    int nro, n;
    printf("ingrese la cantidad de numeros a evaluar:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("ingrese un numero:");
        scanf("%d", &nro);
        if (nro % 2 == 0)
        {
            printf("%d es un numero par \n", nro);
        }
        else
        {
            printf("%d es un numero impar \n", nro);
        }
    }

    return 0;
}