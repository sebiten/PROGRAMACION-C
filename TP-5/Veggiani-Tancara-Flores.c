/*Ejercicio 10: Se tiene los datos de dos círculos. Estos datos son: el nombre, el punto central y el radio.
Se solicita ingresar N puntos del plano e indicar, para cada punto, el círculo al cual el punto es interior, o
si es exterior a ambos círculos.
Nota: utilizar TD registro para representar cada círculo y cada punto. 

INTEGRANTES :
Dino Fabrizio Veggiani
Joaquin Alejandro Flores
Rodrigo Humberto Tancara Cruz*/
#include <stdio.h>
#include <math.h>
#define MAX 20

typedef char tCad[MAX];
typedef struct {
	float x,y;
}TRPunto;
typedef struct {
	tCad nombre;
	TRPunto centro;
	float radio;
}TRCirculo;

void leeCad(tCad,int);
TRCirculo ingresoCirculo();
TRPunto ingresoPunto();
float distanciaPuntos(TRPunto,TRPunto);
void pertenencia(TRCirculo,TRCirculo,TRPunto);

int main() {
	
	int i,N;
	TRCirculo C1, C2;
	TRPunto P;
	
	printf("\nIngresar circulo C1: ");
	C1=ingresoCirculo();
	printf("\nIngresar circulo C2: ");
	C2=ingresoCirculo();
	
	printf("\nIngresar cantidad de puntos a analizar: ");
	scanf("%d",&N);
	
	for (i=1 ; i<=N ; i++){
		printf("\nIngresar punto[%d]: ", i);
		P=ingresoPunto();
		pertenencia(C1,C2,P);
	}
	
	return 0;
}

void leeCad(tCad cad,int tam){
	int j;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<tam-1){
		cad[j]=c;
		j++;
		c=getchar();
	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}
TRCirculo ingresoCirculo(){
	TRCirculo c;
	fflush(stdin);
	printf("\nIngresar Nombre: ");
	leeCad(c.nombre,MAX);
	printf("\nIngresar Centro del circulo: ");
	c.centro=ingresoPunto();
	printf("\nIngresar radio del circulo: ");
	scanf("%f",&c.radio);
	return c;
	
}
TRPunto ingresoPunto(){
	TRPunto p;
	printf("\nIngresar Coordenada en X: ");
	scanf("%f",&p.x);
	printf("\nIngresar Coordenada en Y: ");
	scanf("%f",&p.y);
	return p;
}
float distanciaPuntos(TRPunto a,TRPunto b){
	float d;
	d=sqrt((b.x - a.x)*(b.x - a.x)+(b.y - a.y)*(b.y - a.y));
	return d;
	}
void pertenencia(TRCirculo c1,TRCirculo c2,TRPunto p){
	if (distanciaPuntos(c1.centro,p)<=c1.radio)
		if(distanciaPuntos(c2.centro,p)<=c2.radio)
		printf("\nEl punto se encuentra dentro de ambos circulos");
		else 
		printf("\nEl punto se encuentra dentro del circulo %s",c1.nombre);
	else 
		if(distanciaPuntos(c2.centro,p)<=c2.radio)
		printf("\nEl punto se encuentra dentro del circulo %s",c2.nombre);
		else printf("\nEl punto es externo a ambos circulos");
}
/* 5 de 5 */
