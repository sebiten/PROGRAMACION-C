#include <stdio.h>

typedef float vel[100];
typedef int tiempo[100];
typedef int dia[100];
typedef int mes[100];
typedef int anio[100];
typedef int id[100];

// PROTOTIPOS
void cargarV(vel, tiempo, dia, mes, anio, id, int*);
void mayorVel(vel, float, int, int*);
void promedioVel(vel, int, float*);
void tiempoIntervalo(tiempo, int, int);
int main() {
  int n;
  vel Vel;
  tiempo Tiempo;
  dia Dia;
  mes Mes;
  anio Anio;
  id ID;
  float v;
  int t;
  int cont = 0;
  float prom;
  printf("=== INGRESO DE ENTRENAMIENTOS ===\n");
  cargarV(Vel, Tiempo, Dia, Mes, Anio, ID, &n);
  printf("\nIngrese la velocidad umbral (km/h): ");
  scanf("%f", &v);
  mayorVel(Vel, v, n, &cont);
  printf("\nCantidad de entrenamientos con velocidad mayor a %.2f km/h: %d\n",
         v, cont);
  promedioVel(Vel, n, &prom);
  printf("\nVelocidad promedio de los entrenamientos: %.2f km/h\n", prom);
  printf("\nIngrese el tiempo umbral (segundos) T: ");
  scanf("%d", &t);
  tiempoIntervalo(Tiempo, n, t);
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
void mayorVel(vel Vel, float v, int n, int* cont) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("\nEntrenamiento %d:\n", i);
    if (Vel[i] > v) {
      printf("Velocidad: %.2f km/h\n", Vel[i]);
      (*cont)++;
    }
  }
}
void promedioVel(vel Vel, int n, float* prom) {
  int i;
  float suma = 0;
  for (i = 1; i <= n; i++) {
    suma += Vel[i];
  }
  *prom = suma / n;
}
void tiempoIntervalo(tiempo T, int n, int t) {
  int ini = t - 30;
  int fin = t + 30;
  for (int i = 1; i <= n; i++) {
    if (T[i] >= ini && T[i] <= fin) {
      printf("El entrenamiento %d pertenece al intervalo.\n", i);
    }
  }
}