#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef int tVector[MAX];

void cargarVector(tVector v, int* n);
void mostrarVector(tVector v, int n);
void notasRepetidas(tVector v, int n);

int main() {
  int n;
  tVector A;

  srand(time(NULL));

  cargarVector(A, &n);
  mostrarVector(A, n);
  notasRepetidas(A, n);

  return 0;
}

void cargarVector(tVector v, int* n) {
  printf("Ingrese la cantidad de notas: ");
  scanf("%d", n);

  for (int i = 1; i <= *n; i++) v[i] = rand() % 101;
}

void mostrarVector(tVector v, int n) {
  printf("\nNotas generadas: ");
  for (int i = 1; i <= n; i++) {
    printf("%d", v[i]);
    if (i < n) printf(", ");
  }
  printf("\n");
}

void notasRepetidas(tVector v, int n) {
  int i, j, frec, maxFrec = 0;

  // calcular frecuencia máxima
  for (i = 1; i <= n; i++) {
    frec = 0;
    for (j = 1; j <= n; j++)
      if (v[i] == v[j]) frec++;

    if (frec > maxFrec) maxFrec = frec;
  }

  // mostrar notas modales
  printf("\nNota/s modal/es (repetidas %d veces): ", maxFrec);
  for (i = 1; i <= n; i++) {
    frec = 0;
    for (j = 1; j < i; j++)
      if (v[i] == v[j]) frec = -1;  // ya mostrada

    if (frec == 0) {
      int cont = 0;
      for (j = 1; j <= n; j++)
        if (v[i] == v[j]) cont++;

      if (cont == maxFrec) printf("%d ", v[i]);
    }
  }
  printf("\n");
}
