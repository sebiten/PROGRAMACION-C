#include <stdio.h>
#include <string.h>
#define tam 20
#define tamV 50
typedef char tCad[tam]; /*declara una cadena*/

typedef tCad tVector[tam]; /*declara un vector de cadenas*/

void leeCad(tCad, int);
void carga_lista(tVector,int);
void muestra_lista(tVector,int);
void ordenar (tVector,int);

int main(){
	int N;
	tVector CIUDADES;
	printf("ingrese cantidad de ciudades: ");
	scanf("%d",&N);
	carga_lista(CIUDADES,N);
	muestra_lista(CIUDADES,N);
	ordenar(CIUDADES,N);
	muestra_lista(CIUDADES,N);
	return 0;
}
	void leeCad(tCad cad, int t){
		int j;
		char c;
		j=0;
		c=getchar();
		while(c!=EOF&&c!='\n'&&j<t-1){
			cad[j]=c;
			j++;
			c=getchar();
		}
		cad[j]='\0';
		while(c!=EOF&&c!='\n')
			c=getchar();
		
	}

void carga_lista(tVector V,int t){
	int i;
	for (i=1;i<=t;i++){
		printf("\ningrese ciudad:");
		fflush(stdin);
		leeCad(V[i],10);
	}
}
void muestra_lista(tVector V,int t){
	int i;
	for (i=1;i<=t;i++)
		printf("%s ",V[i]);
}

void ordenar (tVector V,int t){
	int i,j;
	tCad aux;
	for (i=1;i<t;i++)
		for(j=i+1;j<=t;j++)
			if (strcmp(V[i],V[j])==1){
				strcpy(aux,V[i]); /*aux=V[i];*/
				strcpy(V[i],V[j]); /*V[i]=V[j];*/
				strcpy(V[j],aux); /*V[j]=aux;*/
			}
				
}
