#include <stdio.h>
#include <string.h>

#define MAX 100
typedef char tCad[30];

typedef struct {
  int codigo;       // Código del país
  tCad nombre;      // Nombre del país
  tCad capital;     // Capital del país
  tCad continente;  // Continente
} tPais;

typedef tPais tVec[MAX];

/* ===================== PROTOTIPOS ===================== */

void leeCad(tCad, int);
tPais cargarPais();
void cargarLista(tVec, int*);
void mostrarPais(tPais);
void mostrarLista(tVec, int);

void ordenarPorCodigo(tVec, int);

int buscarCodigo(tVec, int, int);
void agregarOrdenado(tVec, int*, tPais);
void modificarCapital(tVec, int);
void eliminarPais(tVec, int*);
void buscarPorCapital(tVec, int);

/* ===================== FUNCION PRINCIPAL ===================== */

int main() {
  int n, opcion;
  tVec lista;

  printf("Ingrese cantidad de paises: ");
  scanf("%d", &n);
  getchar();  // limpiar el \n

  cargarLista(lista, &n);
  ordenarPorCodigo(lista, n);

  do {
    printf("\n===== MENU =====\n");
    printf("1) Agregar un nuevo pais (ordenado)\n");
    printf("2) Modificar capital por codigo\n");
    printf("3) Eliminar pais por codigo\n");
    printf("4) Buscar pais por capital\n");
    printf("5) Mostrar lista\n");
    printf("0) Salir\n");
    printf("Seleccione opcion: ");
    scanf("%d", &opcion);
    getchar();

    switch (opcion) {
      case 1:
        agregarOrdenado(lista, &n, cargarPais());
        break;
      case 2:
        modificarCapital(lista, n);
        break;
      case 3:
        eliminarPais(lista, &n);
        break;
      case 4:
        buscarPorCapital(lista, n);
        break;
      case 5:
        mostrarLista(lista, n);
        break;
    }

  } while (opcion != 0);

  return 0;
}

/* ===================== MANEJO DE CADENAS ===================== */

void leeCad(tCad cad, int tam) {
  int i = 0;
  char c = getchar();
  while (c != '\n' && c != EOF && i < tam - 1) {
    cad[i++] = c;
    c = getchar();
  }
  cad[i] = '\0';
}

/* ===================== CARGA ===================== */

tPais cargarPais() {
  tPais p;

  printf("\nCodigo del pais: ");
  scanf("%d", &p.codigo);
  getchar();

  printf("Nombre del pais: ");
  leeCad(p.nombre, 30);

  printf("Capital del pais: ");
  leeCad(p.capital, 30);

  printf("Continente: ");
  leeCad(p.continente, 30);

  return p;
}

void cargarLista(tVec lista, int* n) {
  int i;
  for (i = 1; i <= *n; i++) {
    printf("\n--- Pais %d ---\n", i);
    lista[i] = cargarPais();
  }
}

/* ===================== MOSTRAR ===================== */

void mostrarPais(tPais p) {
  printf("\nCodigo: %d", p.codigo);
  printf("\nNombre: %s", p.nombre);
  printf("\nCapital: %s", p.capital);
  printf("\nContinente: %s\n", p.continente);
}

void mostrarLista(tVec lista, int n) {
  int i;
  printf("\n===== LISTA DE PAISES =====\n");
  for (i = 1; i <= n; i++) {
    mostrarPais(lista[i]);
  }
}

/* ===================== ORDENAMIENTO ===================== */

void ordenarPorCodigo(tVec lista, int n) {
  int i, j;
  tPais aux;

  for (i = 2; i <= n; i++) {
    aux = lista[i];
    j = i - 1;

    while (j >= 1 && lista[j].codigo > aux.codigo) {
      lista[j + 1] = lista[j];
      j--;
    }
    lista[j + 1] = aux;
  }
}

/* ===================== BUSQUEDA ===================== */

int buscarCodigo(tVec lista, int n, int codigo) {
  int i = 1;
  while (i <= n && lista[i].codigo != codigo) i++;

  if (i <= n)
    return i;
  else
    return 0;
}

/* ===================== AGREGAR ORDENADO ===================== */

void agregarOrdenado(tVec lista, int* n, tPais nuevo) {
  int i = *n;

  if (*n >= MAX - 1) {
    printf("Lista llena.\n");
    return;
  }

  while (i >= 1 && lista[i].codigo > nuevo.codigo) {
    lista[i + 1] = lista[i];
    i--;
  }

  lista[i + 1] = nuevo;
  (*n)++;

  printf("Pais agregado correctamente.\n");
}

/* ===================== MODIFICAR CAPITAL ===================== */

void modificarCapital(tVec lista, int n) {
  int codigo, pos;
  tCad nuevaCapital;

  printf("Ingrese codigo a modificar: ");
  scanf("%d", &codigo);
  getchar();

  pos = buscarCodigo(lista, n, codigo);

  if (pos == 0) {
    printf("No existe un pais con ese codigo.\n");
    return;
  }

  printf("Nueva capital: ");
  leeCad(nuevaCapital, 30);

  strcpy(lista[pos].capital, nuevaCapital);

  printf("Capital modificada correctamente.\n");
}

/* ===================== ELIMINAR ===================== */

void eliminarPais(tVec lista, int* n) {
  int codigo, pos, i;

  printf("Ingrese codigo a eliminar: ");
  scanf("%d", &codigo);
  getchar();

  pos = buscarCodigo(lista, *n);

  if (pos == 0) {
    printf("Codigo inexistente.\n");
    return;
  }

  for (i = pos; i < *n; i++) {
    lista[i] = lista[i + 1];
  }
  (*n)--;

  printf("Pais eliminado.\n");
}

/* ===================== BUSCAR POR CAPITAL ===================== */

void buscarPorCapital(tVec lista, int n) {
  tCad cap;
  int i;

  printf("Ingrese capital a buscar: ");
  leeCad(cap, 30);

  for (i = 1; i <= n; i++) {
    if (strcmp(lista[i].capital, cap) == 0) {
      printf("\nEl pais correspondiente es: %s\n", lista[i].nombre);
      return;
    }
  }

  printf("No existe un pais con esa capital.\n");
}
