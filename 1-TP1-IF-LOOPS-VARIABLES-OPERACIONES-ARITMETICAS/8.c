#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N1, N2, N3, suma;
    printf("Ingrese el primer número natural: ");
    scanf("%d", &N1);
    printf("Ingrese el primer número natural: ");
    scanf("%d", &N2);
    printf("Ingrese el primer número natural: ");
    scanf("%d", &N3);

    suma = N1 + N2 + N3;
    if (suma < 180)
    {
        printf("la suma tiene que dar 180 grados.\n");
    }
    if (N1 == 90 || N2 == 90 || N3 == 90)
    {
        printf("es un triangulo rectangulo\n");
    }
    if (N1 > 90 || N2 > 90 || N3 > 90)
    {
        printf("es un triangulo obtusanguloi\n");
    }
    else
        (
            printf("es un triangulo acutangulo"));

    return 0;
}
