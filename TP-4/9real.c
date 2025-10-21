#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int tVecA[MAX];
typedef int tVecPosA[MAX];
// prototipos
void cargarVectorA(tVecA vA, int* n, tVecPosA vPosA);
void mostrarVectorA(tVecA vA, int n, tVecPosA vPosA);
int main() {
  int n;
  tVecA A;
  tVecPosA posA;

  cargarVectorA(A, &n, posA);
  printf("\nVECTOR A:\n");
  mostrarVectorA(A, n, posA);

  return 0;
}

void cargarVectorA(tVecA vA, int* n, tVecPosA vPosA) {
  int i;
  printf("Ingrese la cantidad de elementos N: ");
  scanf("%d", n);
  for (i = 1; i < *n; i++) {
    printf("A[%d]: ", i);
    scanf("%d", &vA[i]);
    vPosA[i] = i;
  }
}

void mostrarVectorA(tVecA vA, int n, tVecPosA vPosA) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("A[%d] = %d  (P[%d] = %d)\n", i, vA[i], i, vPosA[i]);
  }
  printf("\n");
}