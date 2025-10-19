#include <stdio.h>

typedef float vel[100];
typedef int tiempo[100];
typedef int dia[100];
typedef int mes[100];
typedef int anio[100];
typedef int id[100];

// PROTOTIPOS
void cargarV(vel, tiempo, dia, mes, anio, id, int*);
void mostrarV(vec, int);
int main() {
  int n;
  vel Vel;
  tiempo Tiempo;
  dia Dia;
  mes Mes;
  anio Anio;
  id ID;

  printf("=== INGRESO DE ENTRENAMIENTOS ===\n");
  cargarV(Vel, Tiempo, Dia, Mes, Anio, ID, &n);
  mostrarV(A, N);
  return 0;
}

// ----------------------------------------------

void cargarV(vel Vel, tiempo Tiempo, dia Dia, mes Mes, anio Anio, id ID,
             int* n) {
  int i;
  printf("Ingrese la cantidad de entrenamientos: ");
  scanf("%d", n);

  for (i = 1; i <= *n; i++) {
    printf("\nEntrenamiento %d:\n", i);
    printf("Velocidad (km/h): ");
    scanf("%f", &Vel[i]);
    printf("Tiempo (segundos): ");
    scanf("%d", &Tiempo[i]);
    printf("Fecha (D M A): ");
    scanf("%d %d %d", &Dia[i], &Mes[i], &Anio[i]);
    printf("ID: ");
    scanf("%d", &ID[i]);
  }
}
