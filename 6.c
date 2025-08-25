// Ejercicio 6:  Dados tres números naturales correspondientes a día, mes y año de una fecha, indicar si dicha fecha es válida.
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int dia, mes, año;
    printf("Ingrese el día: ");
    scanf("%d", &dia);
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    printf("Ingrese el año: ");
    scanf("%d", &año);

    if (año < 0)
    {
        printf("Fecha inválida: el año no puede ser negativo.\n");
        return 0;
    }
    if (mes < 1 || mes > 12)
    {
        printf("Fecha inválida: el mes debe estar entre 1 y 12.\n");
        return 0;
    }
    if (dia < 1 || dia > 31)
    {
        printf("Fecha inválida: el día debe estar entre 1 y 31.\n");
        return 0;
    }
    {
        if (dia > 30)
        {
            printf("Fecha inválida: el mes %d tiene máximo 30 días.\n", mes);
            return 0;
        }
    }
    printf("Fecha válida: %02d/%02d/%d\n", dia, mes, año);

    return 0;
}
