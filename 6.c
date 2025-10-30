#include <stdio.h>
#include <string.h>

#define TAM 100  // tamaño máximo de vectores

// ==== Tipos definidos ====
typedef char tCad[30];
typedef tCad tVecCad[TAM];
typedef int tVecInt[TAM];

// ==== Prototipos de funciones ====
void leerCad(tCad cad, int t);
void ingresoOrdenado(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                     tVecInt Edades, int* n);
void mostrarLista(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                  tVecInt Edades, int n);
void mostrarPorEdad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                    tVecInt Edades, int n, int edadBuscada);
void eliminarPorCiudad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                       tVecInt Edades, int* n, tCad ciudadBuscada);
void agregarCliente(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                    tVecInt Edades, int* n);
void buscarPorNombre(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                     tVecInt Edades, int n, tCad apellidoBuscado,
                     tCad nombreBuscado);

// ==== Función principal ====
int main() {
  tVecCad Apellidos, Nombres, Ciudades;
  tVecInt Edades;
  int n = 0, op;
  int edadBuscada;
  tCad ciudadBuscada, apellidoBuscado, nombreBuscado;

  do {
    printf("\n=== MENU AGENDA ===\n");
    printf("1. Ingresar clientes ordenados por Apellido y Nombre\n");
    printf("2. Mostrar lista completa\n");
    printf("3. Mostrar clientes con una edad dada\n");
    printf("4. Eliminar clientes por ciudad\n");
    printf("5. Agregar nuevo cliente (manteniendo orden)\n");
    printf("6. Buscar cliente por Apellido y Nombre\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    getchar();  // limpia salto de línea

    switch (op) {
      case 1:
        ingresoOrdenado(Apellidos, Nombres, Ciudades, Edades, &n);
        break;
      case 2:
        mostrarLista(Apellidos, Nombres, Ciudades, Edades, n);
        break;
      case 3:
        printf("Ingrese la edad a buscar: ");
        scanf("%d", &edadBuscada);
        getchar();
        mostrarPorEdad(Apellidos, Nombres, Ciudades, Edades, n, edadBuscada);
        break;
      case 4:
        printf("Ingrese la ciudad a eliminar: ");
        leerCad(ciudadBuscada, 30);
        eliminarPorCiudad(Apellidos, Nombres, Ciudades, Edades, &n,
                          ciudadBuscada);
        break;
      case 5:
        agregarCliente(Apellidos, Nombres, Ciudades, Edades, &n);
        break;
      case 6:
        printf("Apellido: ");
        leerCad(apellidoBuscado, 30);
        printf("Nombre: ");
        leerCad(nombreBuscado, 30);
        buscarPorNombre(Apellidos, Nombres, Ciudades, Edades, n,
                        apellidoBuscado, nombreBuscado);
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

// ==== Funciones auxiliares ====

void leerCad(tCad cad, int t) {
  int i = 0;
  char c = getchar();
  while (c != '\n' && c != EOF && i < t - 1) {
    cad[i] = c;
    i++;
    c = getchar();
  }
  cad[i] = '\0';
}

// Inserta clientes ordenados por Apellido y Nombre a medida que se ingresan
void ingresoOrdenado(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                     tVecInt Edades, int* n) {
  int cant, i, j;
  tCad apeAux, nomAux, ciuAux;
  int edadAux;

  printf("Cuantos clientes desea ingresar? ");
  scanf("%d", &cant);
  getchar();

  for (i = 0; i < cant; i++) {
    printf("\nCliente %d\n", i + 1);
    printf("Apellido: ");
    leerCad(apeAux, 30);
    printf("Nombre: ");
    leerCad(nomAux, 30);
    printf("Ciudad de nacimiento: ");
    leerCad(ciuAux, 30);
    printf("Edad: ");
    scanf("%d", &edadAux);
    getchar();

    // Insertar ordenado por apellido y nombre
    j = *n - 1;
    while (j >= 0 && (strcmp(Apellidos[j], apeAux) > 0 ||
                      (strcmp(Apellidos[j], apeAux) == 0 &&
                       strcmp(Nombres[j], nomAux) > 0))) {
      strcpy(Apellidos[j + 1], Apellidos[j]);
      strcpy(Nombres[j + 1], Nombres[j]);
      strcpy(Ciudades[j + 1], Ciudades[j]);
      Edades[j + 1] = Edades[j];
      j--;
    }

    strcpy(Apellidos[j + 1], apeAux);
    strcpy(Nombres[j + 1], nomAux);
    strcpy(Ciudades[j + 1], ciuAux);
    Edades[j + 1] = edadAux;
    (*n)++;
  }
}

void mostrarLista(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                  tVecInt Edades, int n) {
  int i;
  printf("\n=== LISTA DE CLIENTES ===\n");
  for (i = 0; i < n; i++) {
    printf("%s, %s - %s - %d anios\n", Apellidos[i], Nombres[i], Ciudades[i],
           Edades[i]);
  }
}

void mostrarPorEdad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                    tVecInt Edades, int n, int edadBuscada) {
  int i, encontrado = 0;
  printf("\nClientes con edad %d:\n", edadBuscada);
  for (i = 0; i < n; i++) {
    if (Edades[i] == edadBuscada) {
      printf("%s, %s - %s\n", Apellidos[i], Nombres[i], Ciudades[i]);
      encontrado = 1;
    }
  }
  if (!encontrado) printf("No hay clientes con esa edad.\n");
}

void eliminarPorCiudad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                       tVecInt Edades, int* n, tCad ciudadBuscada) {
  int i, j;
  for (i = 0; i < *n; i++) {
    if (strcmp(Ciudades[i], ciudadBuscada) == 0) {
      // correr todos una posición hacia atrás
      for (j = i; j < *n - 1; j++) {
        strcpy(Apellidos[j], Apellidos[j + 1]);
        strcpy(Nombres[j], Nombres[j + 1]);
        strcpy(Ciudades[j], Ciudades[j + 1]);
        Edades[j] = Edades[j + 1];
      }
      (*n)--;
      i--;  // volver a verificar esta posición (porque corrió)
    }
  }
  printf("Clientes de %s eliminados.\n", ciudadBuscada);
}

void agregarCliente(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                    tVecInt Edades, int* n) {
  tCad apeAux, nomAux, ciuAux;
  int edadAux, j;

  printf("Apellido: ");
  leerCad(apeAux, 30);
  printf("Nombre: ");
  leerCad(nomAux, 30);
  printf("Ciudad de nacimiento: ");
  leerCad(ciuAux, 30);
  printf("Edad: ");
  scanf("%d", &edadAux);
  getchar();

  j = *n - 1;
  while (j >= 0 && (strcmp(Apellidos[j], apeAux) > 0 ||
                    (strcmp(Apellidos[j], apeAux) == 0 &&
                     strcmp(Nombres[j], nomAux) > 0))) {
    strcpy(Apellidos[j + 1], Apellidos[j]);
    strcpy(Nombres[j + 1], Nombres[j]);
    strcpy(Ciudades[j + 1], Ciudades[j]);
    Edades[j + 1] = Edades[j];
    j--;
  }
  strcpy(Apellidos[j + 1], apeAux);
  strcpy(Nombres[j + 1], nomAux);
  strcpy(Ciudades[j + 1], ciuAux);
  Edades[j + 1] = edadAux;
  (*n)++;

  printf("Cliente agregado correctamente.\n");
}

void buscarPorNombre(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                     tVecInt Edades, int n, tCad apellidoBuscado,
                     tCad nombreBuscado) {
  int i, encontrado = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(Apellidos[i], apellidoBuscado) == 0 &&
        strcmp(Nombres[i], nombreBuscado) == 0) {
      printf("Datos del cliente:\n");
      printf("Ciudad: %s\nEdad: %d\n", Ciudades[i], Edades[i]);
      encontrado = 1;
    }
  }
  if (!encontrado) printf("No se encontro el cliente.\n");
}
