#include <stdio.h>

int main(void)
{
    int numero = 377, 
    nro = numero;
    int dig = numero % 10;
    for (int n = 2; n < nro; n++) // n= 2,3,4,5,6,7,etc..
    {
        int esPrimo = 1;
        for (int i = 2; i * i <= n; i++) // i=2,3,4,5,6,7,8,etc...
        {
            if (n % i == 0)
            {
                esPrimo = 0;
                break;
            }
        }
        if (esPrimo == 1)
        {
            printf("%d ", n);
        }
    }

    numero /= 10;
    return 0;
}
