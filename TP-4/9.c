#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int tVecA[MAX];
typedef int tVecB[MAX];

// PROTOTIPOS
void cargarListaA(tVecA vA, int* n);
void mostrarListaA(tVecA vA, int n);
void mostrarListaB(tVecB vB, int j);
float promedioPosImpares(tVecA vA, int n);
int crearListaB(tVecA vA, tVecB vB, float prom, int n);

// ----------------------------------------------------
int main() {
  int n, j;
  float prom;
  tVecA A;
  tVecB B;

  cargarListaA(A, &n);
  printf("\nLISTA A:\n");
  mostrarListaA(A, n);

  prom = promedioPosImpares(A, n);
  printf("\nPromedio de posiciones impares: %.2f\n", prom);

  j = crearListaB(A, B, prom, n);
  printf("\nLISTA B (mayores al promedio):\n");
  mostrarListaB(B, j);

  return 0;
}

// ----------------------------------------------------
void cargarListaA(tVecA vA, int* n) {
  int i;
  printf("Ingrese la cantidad de elementos N: ");
  scanf("%d", n);
  for (i = 1; i <= *n; i++) {
    printf("A[%d]: ", i);
    scanf("%d", &vA[i]);
  }
}

// ----------------------------------------------------
void mostrarListaA(tVecA vA, int n) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("%d ", vA[i]);
  }
  printf("\n");
}

// ----------------------------------------------------
void mostrarListaB(tVecB vB, int j) {
  int i;
  if (j == 0)
    printf("(no hay elementos mayores al promedio)\n");
  else {
    for (i = 1; i <= j; i++) {
      printf("%d ", vB[i]);
    }
    printf("\n");
  }
}

// ----------------------------------------------------
float promedioPosImpares(tVecA vA, int n) {
  int i, cont = 0, suma = 0;
  float prom;

  for (i = 1; i <= n; i += 2) {
    suma += vA[i];
    cont++;
  }

  prom = (float)suma / cont;
  return prom;
}

// ----------------------------------------------------
int crearListaB(tVecA vA, tVecB vB, float prom, int n) {
  int i, j = 0;

  for (i = 1; i <= n; i++) {
    if (vA[i] > prom) {
      j++;
      vB[j] = vA[i];
    }
  }

  return j;  // devuelve cantidad de elementos en B
}
