#include <stdio.h>

int main(void)
{
    int digito, nombre;
    printf("inserte el primer digito:");
    scanf("%d", &digito);
    switch (digito)
    {
    case 0:
        printf("cero");
        break;
    case 1:
        printf("uno");
        break;
    case 2:
        printf("dos");
        break;
    case 3:
        printf("tres");
        break;
    case 4:
        printf("cuatro");
        break;
    case 5:
        printf("cinco");
        break;
    case 6:
        printf("seis");
        break;
    case 7:
        printf("siete");
        break;
    case 8:
        printf("ocho");
        break;
    case 9:
        printf("nueve");
        break;
    default:
        printf("error, no es un digito");
        break;
    }
    return 0;
}