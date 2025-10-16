#include <stdio.h>

void sumar(int *a);   
// recibe un puntero a 'a' protipo en caso de declarar la funcion o metodo;

int main() {
	int a;
	printf("Ingrese a: ");
	scanf("%d", &a);
	
	sumar(&a); // paso la dirección de 'a'
	printf("\nEn main, a ahora vale: %d\n", a);
	
	return 0;
}

void sumar(int *a) {
	int b = 10;
	*a = *a + b; // modifico el valor original de 'a'
	printf("La suma en total es: %d", *a);
}
