#include <stdio.h>

int divisores(int x);
int primo(int x);
float comparar(float a, float b);
int invertir(int x);

int main(void) {
	int opcion;
	
	do {
		printf("\n===== MENU =====\n");
		printf("1) Cantidad de divisores de X\n");
		printf("2) Determinar si X es primo\n");
		printf("3) Comparar A y B (1 si A>B, 0 si A=B, -1 si A<B)\n");
		printf("4) Invertir un numero X\n");
		printf("5) Ejecutar TODO junto (tu flujo original)\n");
		printf("0) Salir\n");
		printf("Elige una opcion: ");
		scanf("%d", &opcion);
			
		
		if (opcion == 1) {
			int x;
			printf("Ingrese X: ");
			scanf("%d", &x);
			int contdiv = divisores(x);
			printf("El numero %d tiene %d divisores naturales.\n", x, contdiv);
			
		} else if (opcion == 2) {
			int x;
			printf("Ingrese X: ");
			scanf("%d", &x);
			if (primo(x)) printf("El numero %d es primo.\n", x);
			else          printf("El numero %d NO es primo.\n", x);
			
		} else if (opcion == 3) {
			float a, b;
			printf("Ingrese A: ");
			scanf("%f", &a);
			printf("Ingrese B: ");
			scanf("%f", &b);
			int cmp = (int)comparar(a, b);
			if (cmp == 1)      printf("A es MAYOR que B.\n");
			else if (cmp == 0) printf("A es IGUAL que B.\n");
			else               printf("A es MENOR que B.\n");
			
		} else if (opcion == 4) {
			int x;
			printf("Ingrese X: ");
			scanf("%d", &x);
			int inv = invertir(x);
			printf("El numero invertido de %d es: %d\n", x, inv);
			
		} else if (opcion == 5) {
			// === TU FLUJO ORIGINAL, TODO JUNTO ===
			int x;
			float a, b;
			
			printf("ingrese el nro: ");
			scanf("%d", &x);
			
			printf("ingrese a: ");
			scanf("%f", &a);
			
			printf("ingrese b: ");
			scanf("%f", &b);
			
			int contdiv = divisores(x);
			printf("El número %d tiene %d divisores naturales.\n", x, contdiv);
			
			if (primo(x)) printf("el numero %d es primo.\n", x);
			else          printf("el numero %d NO es primo.\n", x);
			
			int comparacion = (int)comparar(a, b);
			if (comparacion == 1)      printf("a es MAYOR que b.\n");
			else if (comparacion == -1)printf("a es MENOR que b.\n");
			else                       printf("a es IGUAL que b.\n");
			
			int numinvertido = invertir(x);
			printf("el numero invertido de x:%d es:%d\n", x, numinvertido);
			
		} else if (opcion == 0) {
			printf("Saliendo...\n");
		} else {
			printf("Opcion invalida.\n");
		}
		
	} while (opcion != 0);
	
	return 0;
}

/* ======  módulos ====== */
int divisores(int x){
	int contdiv=0;
	for (int i = 1; i <= x; i++){
		if(x % i == 0){
			contdiv = contdiv +1;
		}
	}
	return contdiv;
}
	
	int primo(int x) {
		if (x < 2) return 0; // los menores a 2 no son primos
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return 0; // si encuentro un divisor ? no es primo
			}
		}
		return 1; // si no encontré divisores ? es primo
	}
	
	float comparar(float a, float b) {
		if(a > b) return 1;
		else if (a == b) return 0;
		else return -1;
	}
	
	int invertir(int x){
		int invertido = 0;
		int aux = x;
		while(aux > 0){
			int dig = aux % 10;
			invertido = invertido * 10 + dig;
			aux = aux/10;
		}
		return invertido;
	}
		
