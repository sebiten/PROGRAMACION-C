#include <stdio.h>
#include <string.h>
#define tam 100

typedef char tCad[tam];
void leeCad(tCad, int);

int main() {
  tCad texto, palabra, larga;
  int N, i, may, j;
  printf("ingrese texto: ");
  leeCad(texto, tam);
  printf("%s", texto);
  N = strlen(texto);
  printf("\nlongitud %d", N);
  may = 0;
  j = -1;
  for (i = 0; i <= N; i++) {
    if (texto[i] != ' ') {
      j++;
      palabra[j] = texto[i];
    } else {
      palabra[j + 1] = '\0';
      j = -1;
      if (strlen(palabra) > may) {
        may = strlen(palabra);
        /*NO SE �PUEDE HACER larga=palabra*/
        strcpy(larga, palabra);
      }
    }
  }
  if (strlen(palabra) > may) {
    may = strlen(palabra);
    strcpy(larga, palabra);
  }
  printf("\nla palabra mas larga es %s", larga);
  printf("\nde longitud %d", may);
  return 0;
}
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
