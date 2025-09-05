#include <stdio.h>

int main(int argc, char *argv[]) {
	int segundos, horas, minutos, segundos_restantes;
	
	// Entrada
	printf("Ingrese la cantidad de segundos: ");
	scanf("%d", &segundos);
	
	// Proceso
	horas = segundos / 3600;               // cantidad de horas
	minutos = (segundos % 3600) / 60;      // minutos restantes
	segundos_restantes = segundos % 60;    // segundos restantes
	
	// Salida
	printf("%d segundos equivalen a: %d horas, %d minutos y %d segundos\n",
		   segundos, horas, minutos, segundos_restantes);
	
	return 0;
}
