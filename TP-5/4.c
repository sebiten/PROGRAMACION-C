#include <stdio.h>
#include <string.h>
#define TAM 100
typedef char tCad[TAM];
void leeCad(tCad cad, int t);
void mostrarCad(tCad frase, int n);
// ====== Programa principal ======
int main(void) {
  tCad frase;
  printf("Ingrese una frase: ");
  leeCad(frase, TAM);
  printf("La frase ingresada es: ");
  int n = strlen(frase);
  printf("la cantidad de caracteres es: %d\n", n);
  mostrarCad(frase, n);
  return 0;
}
// ====== Implementaciones ======
void mostrarCad(tCad frase, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s", frase[i]);
  }
  putchar('\n');
}
void leeCad(tCad cad, int t) {
  int j = 0;
  char c;
  c = getchar();
  while (c != EOF && c != '\n' && j < t - 1) {
    cad[j++] = c;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}