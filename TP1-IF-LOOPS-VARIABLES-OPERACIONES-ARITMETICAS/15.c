#include <stdio.h>

int main(void)
{
    int dig, nro, n, aux, b;
    int countpares = 0, sumapar = 0;
    float promedio;

    printf("Ingrese la cantidad de N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el %d nro: ", i + 1);
        scanf("%d", &nro);
        aux = nro;
        b = 0;
        while (aux > 0)
        {
            dig = aux % 10;
            if (dig % 2 != 0)
            {
                b = 1; // bandera de "hay impar"
                break;
            }
            aux = aux / 10;
        }
        if (b == 0)
        {
            printf("El nro %d tiene todos sus dig pares \n", nro);
            countpares++;
            sumapar += nro;
        }
        else
        {
            printf("El nro %d NO tiene todos sus dig pares \n", nro);
        }
    }

    if (countpares > 0)
    {
        promedio = (float)sumapar / countpares;
        printf("\nEl promedio es %.2f\n", promedio);
    }
    else
    {
        printf("\nNo hubo numeros con todos sus digitos pares\n");
    }

    return 0;
}
