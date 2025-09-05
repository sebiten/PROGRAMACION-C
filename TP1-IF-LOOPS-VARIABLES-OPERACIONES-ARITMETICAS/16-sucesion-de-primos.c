#include <stdio.h>

int main()
{
    int K;
    printf("Ingrese un número: ");

    scanf("%d", &K);

    for (int n = 2; n <= K; n++) // n= 2,3,4,5,6,7,etc..
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

    return 0;
}
