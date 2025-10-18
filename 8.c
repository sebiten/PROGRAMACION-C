#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// ------------------------------------------------------------
// TIPO DE DATO
typedef char tVec[MAX];

// ------------------------------------------------------------
// PROTOTIPOS
void cargarVector(tVec v, int* m);
void mostrarVector(tVec v, int m);
int busquedaSecuencial(tVec v, int m, char x);
void ordenar(tVec v, int m);
int busquedaBinaria(tVec v, int m, char x);

// ------------------------------------------------------------
// PROGRAMA PRINCIPAL
int main() {
  tVec A;
  int m, posx;
  char x;

  // 1️⃣ Cargar y mostrar la lista original
  cargarVector(A, &m);
  printf("\nVECTOR ORIGINAL:\n");
  mostrarVector(A, m);

  // 2️⃣ Ingreso del carácter a buscar
  printf("\nIngrese el caracter a buscar: ");
  scanf(" %c", &x);

  // ------------------------------------------------------------
  // a) BÚSQUEDA EN LISTA NO ORDENADA
  posx = busquedaSecuencial(A, m, x);

  if (posx != 0)
    printf(
        "\n(a) El caracter '%c' se encuentra en la posicion %d (sin "
        "ordenar).\n",
        x, posx);
  else
    printf("\n(a) El caracter '%c' no se encontro en la lista (sin ordenar).\n",
           x);

  // ------------------------------------------------------------
  // b) ORDENAR Y BUSCAR CON BÚSQUEDA BINARIA
  ordenar(A, m);
  printf("\nVECTOR ORDENADO:\n");
  mostrarVector(A, m);

  posx = busquedaBinaria(A, m, x);

  if (posx != 0)
    printf(
        "\n(b) El caracter '%c' se encuentra en la posicion %d (ordenada).\n",
        x, posx);
  else
    printf("\n(b) El caracter '%c' no se encontro en la lista ordenada.\n", x);

  return 0;
}

// ------------------------------------------------------------
// FUNCIÓN: CARGAR VECTOR
void cargarVector(tVec v, int* m) {
  int i;
  printf("Ingrese la cantidad de elementos (M): ");
  scanf("%d", m);

  printf("Ingrese los caracteres alfanumericos (sin repetir):\n");
  for (i = 1; i <= *m; i++) {
    printf("A[%d]: ", i);
    scanf(" %c", &v[i]);
  }
}

// ------------------------------------------------------------
// FUNCIÓN: MOSTRAR VECTOR
void mostrarVector(tVec v, int m) {
  int i;
  for (i = 1; i <= m; i++) {
    printf("%c ", v[i]);
  }
  printf("\n");
}

// ------------------------------------------------------------
// FUNCIÓN: BÚSQUEDA SECUENCIAL (para el caso a)
int busquedaSecuencial(tVec v, int m, char x) {
  int i = 1;
  while (i <= m && v[i] != x) {
    i++;
  }

  if (i <= m)
    return i;  // encontrado
  else
    return 0;  // no encontrado
}

// ------------------------------------------------------------
// FUNCIÓN: ORDENAR VECTOR (método simple)
void ordenar(tVec v, int m) {
  int i, j;
  char aux;

  for (i = 1; i <= m - 1; i++) {
    for (j = i + 1; j <= m; j++) {
      if (v[i] > v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
}

// ------------------------------------------------------------
// FUNCIÓN: BÚSQUEDA BINARIA (para el caso b)
int busquedaBinaria(tVec v, int m, char x) {
  int ini, fin, med;
  ini = 1;
  fin = m;
  med = (ini + fin) / 2;  // se calcula antes del while (estilo UNSa)

  while (ini <= fin && v[med] != x) {
    if (x < v[med])
      fin = med - 1;
    else
      ini = med + 1;

    med = (ini + fin) / 2;  // se recalcula
  }

  if (ini <= fin)
    return med;  // encontrado
  else
    return 0;  // no encontrado
}
