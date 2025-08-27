// ACTIVIDAD OBLIGATORIA - NIVEL 1
// Se desea realizar el sorteo de un millón de dólares entre un grupo de personas usando la terminación del DNI de cada una. Se elige al azar un número natural de 3 cifras llamado K para encontrar al ganador o ganadores.El resultado debe ser uno de los siguientes:
// Sólo una terminación de DNI es igual a K. Entonces una sola persona ganó el millón.
// Más de una terminación de DNI es igual a K. Entonces el premio se divide entre todos los ganadores.
// Nadie gana el premio
// Se posee como información una lista de DNI de una cierta cantidad de personas y un número natural K de 3 cifras. Muestre el dni del ganador, si es único, o muestre la cantidad de ganadores en caso de que sea más de uno.
#include <stdio.h>

int main(void)
{
    int n, k, dni;
    int count = 0;
    int ganador = 0;

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &n);
    printf("Ingrese el numero K (3 cifras 000..999): ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el DNI de la persona %d: ", i + 1);
        scanf("%d", &dni);
        if (dni % 1000 == k)
        {
            count++;
            ganador = dni;
        }
    }

    if (count == 0)
    {
        printf("Nadie gana el premio.\n");
    }
    else if (count == 1)
    {
        printf("El ganador es el DNI: %d (terminacion %03d)\n", ganador, k);
    }
    else
    {
        printf("Hay %d ganadores. El premio se divide entre ellos (terminacion %03d).\n", count, k);
    }

    return 0;
}
