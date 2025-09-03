#include <stdio.h>

int main()
{
    int numero;
    int contadorCapicuas = 0;
    printf("Ingrese números naturales (corte con 0 o -1):\n");
    do
    {
        scanf("%d", &numero);
        if (numero <= 0)
            break;
        int original = numero,
            num = numero,
            inverso = 0;
        while (num > 0)
        {
            inverso = inverso * 10 + num % 10;
            num /= 10;
        }
        if (inverso == original)
        {
            contadorCapicuas++;

            int soloImpares = 1,
                temp = original;
            while (temp > 0)
            {
                int digito = temp % 10;
                if (digito % 2 == 0)
                {
                    soloImpares = 0;
                    break;
                }
                temp /= 10;
            }

            if (soloImpares)
            {
                printf("Capicúa solo con dígitos impares: %d\n", original);
            }
        }
    } while (numero > 0);

    printf("Cantidad de capicúas: %d\n", contadorCapicuas);

    return 0;
}
