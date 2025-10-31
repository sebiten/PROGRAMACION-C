/*Ejercicio 8: Se tienen la siguiente estructura para un inmueble: N° Catastro, Nombre del Propietario, 
Calle y N°, Tipo (Terreno, Construcción, Edificado), Metros cuadrados de construcción, Cantidad de baños, 
Cantidad de habitaciones.
	Se solicita cargar 3 inmuebles y a través de un menú realizar las siguientes operaciones:
	a) Mostrar los datos del inmueble con el mayor valor de metros cuadrados de construcción.
	b) Ingresar un N° de Catastro y permitir modificar la información del registro.
	c) Dado el Nombre del Propietario mostrar todos los inmuebles declarados.*/
#include<stdio.h>
#define MAX 40
typedef char tCad[MAX];
typedef struct{
	int nro_cat,tipo,cb,ch;
	tCad nombre,calle;
	float metros;
}tInmueble; /*defino nuevo tipo de dato*/

void leeCad(tCad,int);
tInmueble carga_Inmueble();
int compara_metros(tInmueble,tInmueble);
void muestra_inmueble(tInmueble);
int main(){
	tInmueble Inm1,Inm2,Inm3;
	Inm1=carga_Inmueble();
	Inm2=carga_Inmueble();
	Inm3=carga_Inmueble();
	if (compara_metros(Inm1,Inm2)==1 && compara_metros(Inm1,Inm3)==1)
		muestra_inmueble(Inm1);
	else if (compara_metros(Inm2,Inm1)==1 && compara_metros(Inm2,Inm3)==1)
		muestra_inmueble(Inm2);
	else if (compara_metros(Inm3,Inm1)==1 && compara_metros(Inm3,Inm2)==1)
		muestra_inmueble(Inm3);
	else
		printf("\nindistinto");
	
	
	return 0;
}
void leeCad(tCad cad,int tam){
	int j;
	char c;
	
	j=0; /*Se comienza la lectura de caracteres del Buffer*/
	c=getchar();
	while(c!=EOF && c!='\n' && j<tam-1){
		cad[j]=c;
		j++;
		c=getchar();
	}
	cad[j]='\0';
	while(c!=EOF && c!='\n') /*Se vacía de caracteres el Buffer*/
		c=getchar();	
}
tInmueble carga_Inmueble(){
	tInmueble reg;
	fflush(stdin);
	printf("\ningrese nombre propietario: ");
	leeCad(reg.nombre,MAX);
	printf("\ningrese nro catastro: ");
	scanf("%d",&reg.nro_cat);
	printf("\ningrese cant baños: ");
	scanf("%d",&reg.cb);
	printf("\ningrese cant metros cuadrado construidos: ");
	scanf("%f",&reg.metros);
	/*hay que cargar todos los campos*/
	return reg;
}
int compara_metros(tInmueble A,tInmueble B){
	int resp;
	if (A.metros>B.metros)
		resp=1;
	else if (A.metros<B.metros)
		resp=-1;
	else
		resp=0;
	return resp;
}
void muestra_inmueble(tInmueble reg){
	printf("\nDATOOOOOS");
	printf("\n%s",reg.nombre);
}
