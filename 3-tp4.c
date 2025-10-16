#include <stdio.h>
#include <ctype.h>
#define TAM 100

typedef char tVector[TAM];

// Prototipos
void cargar(tVector, int*);
void mostrar(tVector, int);
int buscar(tVector, int, char);
void borrar_digitos(tVector, int*);
void ordenar(tVector, int);

// Programa principal
int main() {
    tVector frase;
    int n, pos;
    char car;

    cargar(frase, &n);
    printf("\nLa frase ingresada es:\n");
    mostrar(frase, n);

    printf("\n\nIngrese un caracter a buscar: ");
    scanf(" %c", &car);

    pos = buscar(frase, n, car);
    if (pos != -1)
        printf("\nEl caracter '%c' se encuentra en la posicion %d.\n", car, pos);
    else
        printf("\nEl caracter '%c' no se encuentra en la frase.\n", car);

    borrar_digitos(frase, &n);
    ordenar(frase, n);

    printf("\nFrase resultante sin digitos y ordenada ascendentemente:\n");
    mostrar(frase, n);

    return 0;
}

//--------------------------------------------
void cargar(tVector v, int *n) {
    char c;
    *n = 0;
    printf("Ingrese la frase caracter por caracter (finaliza con '/'): \n");
    scanf(" %c", &c);
    while (c != '/' && *n < TAM) {
        v[*n] = c;
        (*n)++;
        scanf(" %c", &c);
    }
}

//--------------------------------------------
void mostrar(tVector v, int n) {
    for (int i = 0; i < n; i++)
        printf("%c ", v[i]);
    printf("\n");
}

//--------------------------------------------
int buscar(tVector v, int n, char c) {
    for (int i = 0; i < n; i++)
        if (v[i] == c)
            return i; // devuelve la primera posición
    return -1; // no encontrado
}

//--------------------------------------------
void borrar_digitos(tVector v, int *n) {
    int i = 0, j = 0;
    while (i < *n) {
        if (!isdigit(v[i])) { // si NO es dígito, lo mantenemos
            v[j] = v[i];
            j++;
        }
        i++;
    }
    *n = j;
}

//--------------------------------------------
void ordenar(tVector v, int n) {
    int i, j;
    char aux;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}
