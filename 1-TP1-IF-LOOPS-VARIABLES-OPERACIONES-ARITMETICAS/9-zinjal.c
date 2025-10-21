
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int tipo, horaE, minE, horaS, minS, min_entrada, min_salida, dur_min, hrs_a_cobrar;
	float tarifa;
	printf("ingrese el tipo de vehiculo (1-moto, 2-auto, 3-camion): ");
	scanf("%d", &tipo);
	printf("ingrese la hora de entrada (hh mm): ");
	scanf("%d %d", &horaE, &minE);
	printf("ingrese la hora de salida (hh mm): ");
	scanf("%d %d", &horaS, &minS);
	if (tipo == 1)
		tarifa = 1000;
	else if (tipo == 2)
		tarifa = 1500;
	else
		tarifa = 2000;
	min_entrada = horaE * 60 + minE;
	min_salida = horaS * 60 + minS;
	dur_min = min_salida - min_entrada;
	hrs_a_cobrar = (dur_min + 59) / 60;
	printf("la tarifa a cobrar es: %.2f\n", tarifa * hrs_a_cobrar);
	
	return 0;
}
