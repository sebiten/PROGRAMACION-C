#include <stdio.h>
#include <ctype.h>

int clasificar(char c) {
	if (isdigit((unsigned char)c)) return 1;
	
	c = tolower((unsigned char)c); 
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return -1;
	
	if (isalpha((unsigned char)c)) return 0;

	return 0; 
}

int main(void) {
	int N;
	int cantDigitos = 0, cantConsonantes = 0, cantVocales = 0;
	
	printf("Ingrese N (cantidad de caracteres a leer): ");
	if (scanf("%d", &N) != 1 || N < 0) {
		printf("N invalido.\n");
		return 1;
	}
	for (int i = 1; i <= N; i++) {
		char c;
		printf("Ingrese el caracter %d: ", i);
		scanf(" %c", &c);  // el espacio ANTES de %c hace que se ignoren \n, espacios, etc.
		
		int tipo = clasificar(c);
		if (tipo == 1)       cantDigitos++;
		else if (tipo == -1) cantVocales++;
		else                 cantConsonantes++;
	}
	printf("\nResultados:\n");
	printf("Digitos: %d\n", cantDigitos);
	printf("Consonantes: %d\n", cantConsonantes);
	printf("Vocales: %d\n", cantVocales);
	
	return 0;
}
