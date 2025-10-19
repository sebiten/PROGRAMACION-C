#include <stdio.h>
#define MAX 100

// ───── PROTOTIPOS ─────
void cargarVector(int v[], int* n);
void mostrarVector(int v[], int n);
void mostrarEnIntervalo(int v[], int n, int T);

// ───── PROGRAMA PRINCIPAL ─────
int main(void) {
  int tiempos[MAX];
  int n, T;

  printf("=== INGRESO DE DATOS ===\n");
  cargarVector(tiempos, &n);

  printf("\n=== VECTOR DE TIEMPOS ===\n");
  mostrarVector(tiempos, n);

  printf("\nIngrese el tiempo de referencia T: ");
  scanf("%d", &T);

  printf("\n=== RESULTADOS ===\n");
  mostrarEnIntervalo(tiempos, n, T);

  return 0;
}

// ───── FUNCIONES ─────

// Cargar los N tiempos
void cargarVector(int v[], int* n) {
  int i;
  printf("Ingrese la cantidad de tiempos (N): ");
  scanf("%d", n);
  for (i = 1; i <= *n; i++) {
    printf("Tiempo[%d]: ", i);
    scanf("%d", &v[i]);
  }
}

// Mostrar todos los tiempos cargados
void mostrarVector(int v[], int n) {
  int i;
  printf("Indice\tValor\n");
  printf("------\t------\n");
  for (i = 1; i <= n; i++) {
    printf("%3d\t%4d\n", i, v[i]);
  }
}

// Mostrar los tiempos dentro del intervalo [T-30, T+30]
void mostrarEnIntervalo(int v[], int n, int T) {
  int i, limInf, limSup, cont = 0;

  limInf = T - 30;
  limSup = T + 30;

  printf("Intervalo considerado: [%d, %d]\n", limInf, limSup);
  printf("\nTiempos dentro del intervalo:\n");
  printf("-------------------------------\n");

  for (i = 1; i <= n; i++) {
    if (v[i] >= limInf && v[i] <= limSup) {
      printf("v[%d] = %d ✅\n", i, v[i]);
      cont++;
    }
  }

  if (cont == 0)
    printf("No hay tiempos dentro del intervalo.\n");
  else
    printf("\nTotal de tiempos dentro del intervalo: %d\n", cont);
}
