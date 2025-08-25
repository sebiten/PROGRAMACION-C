#include <stdio.h>

int main(int argc, char const *argv[])
{
    float promedioEstatura, estatura1, estatura2, estatura3;
    printf("Ingrese la estatura del primer estudiante (en metros): ");
    scanf("%f", &estatura1);
    printf("Ingrese la estatura del segundo estudiante (en metros): ");
    scanf("%f", &estatura2);
    printf("Ingrese la estatura del tercer estudiante (en metros): ");
    scanf("%f", &estatura3);

    promedioEstatura = (estatura1 + estatura2 + estatura3) / 3;
    printf("El promedio de estatura es: %.2f metros\n", promedioEstatura);
    return 0;
}
// Ejercicio 7:  Dados tres números reales correspondientes a las estaturas de tres estudiantes, calcular e informar la estatura promedio.