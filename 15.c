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

        if (nro == 0)
        {
            // Caso especial: 0 cuenta como todos pares
            b = 0;
        }
        else
        {
            aux = nro;
            b = 0; // arranca suponiendo válido
            while (aux > 0)
            {
                dig = aux % 10;
                if (dig % 2 != 0)
                {
                    b = 1; // bandera de "hay impar"
                    break; // no sigo revisando
                }
                aux = aux / 10;
            }
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
