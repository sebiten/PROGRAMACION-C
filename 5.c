#include <ctype.h>  // para tolower
#include <stdio.h>
#include <string.h>
#define tam 30
#define tamV 50

typedef char tCad[tam];
typedef tCad tVector[tamV];

// Prototipos
void leeCad(tCad cad, int t);
void carga_lista(tVector V, int n);
void muestra_lista(tVector V, int n);
void ordenar(tVector V, int n);
int unaVocal(tCad cad);
int contarUnaVocal(tVector V, int n);
int buscarCiudad(tVector V, int n, tCad buscada);

int main(void) {
  tVector ciudades;
  tCad buscada;
  int n, op, pos;

  printf("Ingrese cantidad de ciudades: ");
  scanf("%d", &n);
  getchar();  // limpiar el '\n' pendiente

  carga_lista(ciudades, n);
  ordenar(ciudades, n);

  do {
    printf("\n=== MENU ===\n");
    printf("1) Mostrar cuantas ciudades tienen una sola vocal\n");
    printf("2) Buscar posicion de una ciudad\n");
    printf("3) Mostrar toda la lista\n");
    printf("0) Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    getchar();

    switch (op) {
      case 1:
        printf("Cantidad: %d\n", contarUnaVocal(ciudades, n));
        break;
      case 2:
        printf("Ingrese ciudad a buscar: ");
        leeCad(buscada, tam);
        pos = buscarCiudad(ciudades, n, buscada);
        if (pos != -1)
          printf("%s esta en la posicion %d\n", buscada, pos);
        else
          printf("No se encontro %s\n", buscada);
        break;
      case 3:
        muestra_lista(ciudades, n);
        break;
      case 0:
        printf("Fin del programa.\n");
        break;
      default:
        printf("Opcion invalida.\n");
    }
  } while (op != 0);

  return 0;
}

// ====== Implementaciones ======

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

void carga_lista(tVector V, int n) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("Ciudad %d: ", i);
    fflush(stdin);
    leeCad(V[i], tam);
  }
}

void muestra_lista(tVector V, int n) {
  int i;
  printf("\n--- Lista de ciudades ---\n");
  for (i = 1; i <= n; i++) printf("%s\n", V[i]);
}

void ordenar(tVector V, int n) {
  int i, j;
  tCad aux;
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (strcmp(V[i], V[j]) > 0) {
        strcpy(aux, V[i]);
        strcpy(V[i], V[j]);
        strcpy(V[j], aux);
      }
}

// --- Función auxiliar: determina si una ciudad tiene una sola vocal ---
int unaVocal(tCad cad) {
  int i;
  int vocales[5] = {0};  // a e i o u
  char c;
  for (i = 0; cad[i] != '\0'; i++) {
    c = tolower(cad[i]);
    if (c == 'a')
      vocales[0] = 1;
    else if (c == 'e')
      vocales[1] = 1;
    else if (c == 'i')
      vocales[2] = 1;
    else if (c == 'o')
      vocales[3] = 1;
    else if (c == 'u')
      vocales[4] = 1;
  }
  int suma = vocales[0] + vocales[1] + vocales[2] + vocales[3] + vocales[4];
  return (suma == 1);  // 1 si solo tiene una vocal distinta
}

// --- Cuenta cuantas ciudades cumplen ---
int contarUnaVocal(tVector V, int n) {
  int i, cont = 0;
  for (i = 1; i <= n; i++)
    if (unaVocal(V[i])) cont++;
  return cont;
}

// --- Buscar posicion de una ciudad ---
int buscarCiudad(tVector V, int n, tCad buscada) {
  int i;
  for (i = 1; i <= n; i++)
    if (strcmp(V[i], buscada) == 0) return i;
  return -1;
}
