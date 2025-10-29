#include <stdio.h>
#include <string.h>
#define TAM 100
typedef char tCad[TAM];
typedef tCad tVecCad[TAM];

void leeCad(tCad cad, int t) {
  int j;
  char c;
  j = 0;
  c = getchar();
  while (c != EOF && c != '\n' && j < t - 1) {
    cad[j] = c;
    j++;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}
// Prototipos
void ingreso_Ordenado(tVecCad V, int n);

int main(void) {
  tVecCad saludos;
  int n, i;
  // Ahora un vector de saludos
  printf("¿Cuántos saludos desea ingresar? ");
  scanf("%d", &n);
  fflush(stdin);
  for (i = 0; i < n; i++) {
    printf("Ingrese saludo %d: ", i + 1);
    leeCad(saludos[i], TAM);
  }
  printf("\nLos saludos ingresados son:\n");
  for (i = 0; i < n; i++) {
    printf("%s\n", saludos[i]);
  }

  return 0;
}
void ingreso_Ordenado(tVecCad V, int n) {
  int i, j;
  tCad aux;
  for (i = 1; i < n; i++) {
    strcpy(aux, V[i]);
    j = i - 1;
    while (j >= 0 && strcmp(V[j], aux) > 0) {
      strcpy(V[j + 1], V[j]);
      j--;
    }
    strcpy(V[j + 1], aux);
  }
}