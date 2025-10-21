#include <stdio.h>

typedef int vec[100];
typedef int vecp[100];

// prototipos
void cargarV(vec, int*, vecp);
void mostrarV(vec, int);
void mostrarP(vecp, int);
void ordenarP(vecp, int, vec);
int comparar(vecp, int);

int main(void) {
  int n;
  vec A;
  vec P;

  printf("=== CARGA DEL VECTOR A ===\n");
  cargarV(A, &n, P);

  printf("\n=== VECTOR A ORIGINAL ===\n");
  mostrarV(A, n);

  printf("\n\n=== VECTOR P (POSICIONES INICIALES) ===\n");
  mostrarP(P, n);

  ordenarP(P, n, A);

  printf("\n\n=== VECTOR P ORDENADO SEGUN A ===\n");
  mostrarP(P, n);

  printf("\n\n=== RESULTADO ===\n");
  printf("Cantidad de elementos en la posición correcta: %d\n", comparar(P, n));

  return 0;
}

// ---------------------------------------------------------

void cargarV(vec v, int* n, vecp P) {
  int i;
  printf("Ingrese la cantidad de elementos (n): ");
  scanf("%d", n);
  for (i = 1; i <= *n; i++) {
    printf("A[%d] = ", i);
    scanf("%d", &v[i]);
    P[i] = i;
  }
}

// ---------------------------------------------------------

void mostrarV(vec v, int n) {
  int i;
  printf("Índice\tValor\n");
  printf("------\t------\n");
  for (i = 1; i <= n; i++) {
    printf("%3d\t%3d\n", i, v[i]);
  }
}

// ---------------------------------------------------------

void mostrarP(vecp P, int n) {
  int i;
  printf("Índice\tP[i]\n");
  printf("------\t----\n");
  for (i = 1; i <= n; i++) {
    printf("%3d\t%3d\n", i, P[i]);
  }
}

// ---------------------------------------------------------

void ordenarP(vecp P, int n, vec A) {
  int i, j, aux;
  for (i = 1; i < n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (A[P[j]] < A[P[i]]) {
        aux = P[i];
        P[i] = P[j];
        P[j] = aux;
      }
    }
  }
}

// ---------------------------------------------------------

int comparar(vecp P, int n) {
  int i, cont = 0;
  for (i = 1; i <= n; i++) {
    if (P[i] == i) cont++;
  }
  return cont;
}
