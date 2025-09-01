#include <stdio.h>

int main(void)
{
    int numero = 232, aux = 232, last, first;
    last = aux % 10;

    while (aux > 9)
    {
        aux = aux / 10;
    }
    if (last == aux)
    {
        printf("el numero %d es capicua \n", numero);
    }
    else
    {
        printf("%d no es capicua", numero);
    }

    return 0;
}