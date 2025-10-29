#include <stdio.h>
#include <string.h>
#define tam 20
#define tamV 50

typedef char tCad[tam];
typedef tCad tVector[tamV];

void leeCad(tCad, int);
void carga_lista(tVector, int);
void muestra_lista(tVector, int);
void ordenar(tVector, int);

int main() {
  int N;
  tVector CIUDADES;

  printf("Ingrese cantidad de ciudades: ");
  scanf("%d", &N);
  getchar();  // limpia el salto de línea

  carga_lista(CIUDADES, N);
  muestra_lista(CIUDADES, N);
  ordenar(CIUDADES, N);

  printf("\n\n--- Lista ordenada ---\n");
  muestra_lista(CIUDADES, N);
  return 0;
}

void leeCad(tCad cad, int t) {
  int j = 0;
  char c = getchar();
  while (c != EOF && c != '\n' && j < t - 1) {
    cad[j] = c;
    j++;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}

void carga_lista(tVector V, int t) {
  int i;
  for (i = 1; i <= t; i++) {
    printf("Ingrese ciudad %d: ", i);
    fflush(stdin);  // aceptado en UNSa
    leeCad(V[i], tam);
  }
}

void muestra_lista(tVector V, int t) {
  int i;
  for (i = 1; i <= t; i++) printf("%s\n", V[i]);
}

void ordenar(tVector V, int t) {
  int i, j;
  tCad aux;
  for (i = 1; i < t; i++)
    for (j = i + 1; j <= t; j++)
      if (strcmp(V[i], V[j]) > 0) {  // corrección
        strcpy(aux, V[i]);
        strcpy(V[i], V[j]);
        strcpy(V[j], aux);
      }
}
