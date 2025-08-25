#include <stdio.h>
// entrada jobhrs, hrsvalue POR DIA
#define MES 30

int main(int argc, char *argv[])
{
	int jobhrs, hrsvalue, sueldo;

	printf("Ingrese las horas trabajadas por dia: ");
	scanf("%i", &jobhrs);

	printf("Ingrese el valor de la hora: ");
	scanf("%i", &hrsvalue);

	sueldo = jobhrs * hrsvalue * MES;

	printf("El sueldo total del mes es: %i\n", sueldo);

	return 0;
}
