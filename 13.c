// Dada una lista con las edades de N deportistas, se necesita informar la edad promedio de los deportistas de la lista; cuál es la menor y mayor edad ingresada.
#include <stdio.h>
int main(void)
{
    int edades, n,
        suma = 0,
        menor = 0,
        mayor = 0;
    float promedio;
    printf("Ingrese la cantidad de deportistas: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("ingrese la %d edad:", i + 1);
        scanf("%d", &edades);
        suma += edades;
        if (i == 0)
        {
            mayor = edades;
            menor = edades;
        }
        else
        {
            if (edades < menor)
                menor = edades;
            if (edades > mayor)
                mayor = edades;
        }
    }
    promedio = (double)suma / n;
    printf("Edad promedio: %.2f\n", promedio);
    printf("Menor edad: %d\n", menor);
    printf("Mayor edad: %d\n", mayor);
    return 0;
}