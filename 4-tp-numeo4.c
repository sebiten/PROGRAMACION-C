#include <stdio.h>
#define MAX 100

typedef int tVector[MAX];

void cargarVector(tVector v, int *n);
void mostrarVector(tVector v, int n);
int edadMasRepetida(tVector v, int n);
void primeraSublistaCrecientePares(tVector v, int n);

int main() {
    tVector v;
    int n, op, mayor;

    printf("Ingrese cantidad de alumnos: ");
    scanf("%d", &n);
    cargarVector(v, &n);

    do {
        printf("\n---- MENU ----\n");
        printf("1. Mostrar vector\n");
        printf("2. Edad con mayor cantidad de repeticiones\n");
        printf("3. Primera sublista creciente de pares\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                mostrarVector(v, n);
                break;
            case 2:
                mayor = edadMasRepetida(v, n);
                printf("\nLa edad con mayor cantidad de repeticiones es: %d\n", mayor);
                break;
            case 3:
                primeraSublistaCrecientePares(v, n);
                break;
        }
    } while(op != 0);

    return 0;
}

void cargarVector(tVector v, int *n) {
    int i;
    for(i=1; i<=*n; i++) {
        printf("Edad %d: ", i);
        scanf("%d", &v[i]);
    }
}

void mostrarVector(tVector v, int n) {
    int i;
    printf("\nLista de edades:\n");
    for(i=1; i<=n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int edadMasRepetida(tVector v, int n) {
    int i, j, cont, maxCont, mayor;
    maxCont = 0;
    mayor = v[1];

    for(i=1; i<=n; i++) {
        cont = 0;
        for(j=1; j<=n; j++) {
            if(v[i] == v[j])
                cont++;
        }

        if(cont > maxCont || (cont == maxCont && v[i] > mayor)) {
            maxCont = cont;
            mayor = v[i];
        }
    }

    return mayor;
}

void primeraSublistaCrecientePares(tVector v, int n) {
    int i, j, inicio, largo;
    int encontrada = 0;
    i = 1;

    while(i < n && encontrada == 0) {
        if(v[i] % 2 == 0 && v[i+1] % 2 == 0 && v[i] < v[i+1]) {
            inicio = i;
            while(i < n && v[i] % 2 == 0 && v[i+1] % 2 == 0 && v[i] < v[i+1]) {
                i++;
            }
            largo = i - inicio + 1;
            if(largo >= 2) {
                printf("\nPrimera sublista creciente de pares:\n[");
                for(j=inicio; j<=i; j++) {
                    printf("%d ", v[j]);
                }
                printf("]\n");
                encontrada = 1;
            }
        }
        i++;
    }

    if(encontrada == 0) {
        printf("\nNo se encontro una sublista creciente de pares.\n");
    }
}
