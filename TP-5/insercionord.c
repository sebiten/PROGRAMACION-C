#include <stdio.h>
#include <string.h>

#define TAM 100
typedef char tCad[30];
typedef tCad tVecCad[TAM];

void leeCad(tCad cad, int t);

int main(void) {
  tVecCad Nombres;
  tCad nuevo;
  int n = 0;  // cantidad actual de nombres
  int j;
  int seguir = 1;

  while (seguir) {
    printf("Ingrese un nombre: ");
    leeCad(nuevo, 30);

    // Inserción ordenada (mantener orden alfabético)
    j = n - 1;  // último nombre ya cargado
    while (j >= 0 && strcmp(nuevo, Nombres[j]) < 0) {
      strcpy(Nombres[j + 1], Nombres[j]);  // correr hacia abajo
      j--;
    }

    // insertar el nuevo en su lugar correcto
    strcpy(Nombres[j + 1], nuevo);
    n++;

    printf("\nLista actual:\n");
    for (int i = 0; i < n; i++) {
      printf("%d. %s\n", i + 1, Nombres[i]);
    }

    printf("\n¿Desea ingresar otro nombre? (1 = Sí, 0 = No): ");
    scanf("%d", &seguir);
    getchar();  // limpiar salto de línea
  }

  printf("\n=== LISTA FINAL ORDENADA ===\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %s\n", i + 1, Nombres[i]);
  }

  return 0;
}

// Leer cadena con espacios
void leeCad(tCad cad, int t) {
  int j = 0;
  char c = getchar();
  while (c != EOF && c != '\n' && j < t - 1) {
    cad[j++] = c;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}
