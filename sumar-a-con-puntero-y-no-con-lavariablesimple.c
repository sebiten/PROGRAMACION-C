#include <stdio.h>

typedef int tVector[100];

// prototipos
void eliminarDigito(tVector v, int* n, int pos);
void cargarVector(tVector v, int* n);
void mostrarVector(tVector v, int n);
void ordenarVector(tVector v, int n);

int main() {
  tVector A;
  int n, d, pos;
  pos = 3;
  cargarVector(A, &n);
  mostrarVector(A, n);
  ordenarVector(A, n);
  printf("---vector ya ordenado---\n");
  mostrarVector(A, n);

  return 0;
}

void cargarVector(tVector v, int* n) {
  int i;
  printf("ingrese la cantidad de elementos del vector: ");
  scanf("%d", n);
  for (i = 1; i <= *n; i++) {
    printf("ingrese v[%d]\n", i);
    scanf("%d", &v[i]);
  }
}
void mostrarVector(tVector v, int n) {
  for (int i = 1; i <= n; i++) {
    printf("v[%d]=%d\n", i, v[i]);
  }
}
void ordenarVector(tVector v, int n) {
  int aux;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (v[i] > v[j]) {
        aux = v[j];
        v[j] = v[i];
        v[i] = aux;
      }
    }
  }
}