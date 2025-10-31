#include<stdio.h>
#define MAX 40
typedef char tCad[MAX];
typedef struct{
	int nro_cuenta;
	float saldo;
	tCad nombre;
}tCliente; /*defino nuevo tipo de dato*/
void leeCad(tCad,int);
tCliente carga_cliente();
void muestra_cliente(tCliente);
void modificar_saldo1(tCliente*);
void modificar_saldo2(tCliente*);
int main(){
	tCliente cliente1;
	cliente1=carga_cliente();
	muestra_cliente(cliente1);
	modificar_saldo1(&cliente1);
	muestra_cliente(cliente1);
	modificar_saldo2(&cliente1);
	muestra_cliente(cliente1);
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
tCliente carga_cliente(){
	tCliente reg;
	fflush(stdin);
	printf("\ningrese nombre: ");
	leeCad(reg.nombre,MAX);
	printf("\ningrese nro cuenta: ");
	scanf("%d",&reg.nro_cuenta);
	printf("\ningrese saldo: ");
	scanf("%f",&reg.saldo);
	return reg;
}
void muestra_cliente(tCliente reg){
	printf("\nDATOS ");
	printf("\n%s",reg.nombre);
	printf("\n%f",reg.saldo);

}
void modificar_saldo1(tCliente* reg){
	printf("\ningrese nuevo");
	scanf("%f",&reg->saldo);
}
void modificar_saldo2(tCliente* reg){
	reg->saldo=reg->saldo - 1000;
}
