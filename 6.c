#include <stdio.h>
#include <string.h>

typedef char tCad[30];
typedef tCad tVecCad[100];
typedef int tVecInt[100];

// Prototipos
void leeCad(tCad, int);
void cargarClientesOrdenado(tVecCad, tVecCad, tVecCad, tVecInt, int);
void mismaEdad(tVecCad, tVecCad, tVecCad, tVecInt, int, int);
void eliminarPorCiudad(tVecCad, tVecCad, tVecCad, tVecInt, int*, tCad);
int main(void) {
  tVecCad Apellidos, Nombres, Ciudades;
  tVecInt Edades;
  int n;  // cantidad de clientes
  int op;

  printf("Ingrese N (cantidad de clientes): ");
  scanf("%d", &n);
  getchar();  // limpiar salto de línea

  cargarClientesOrdenado(Apellidos, Nombres, Ciudades, Edades, n);
  do {
    printf("\n=== MENU DE OPCIONES ===\n");
    printf("1. Mostrar todos los clientes con la misma edad\n");
    printf("2. Eliminar todos los clientes de una ciudad\n");
    printf("3. Agregar un nuevo cliente manteniendo el orden\n");
    printf("4. Buscar cliente por apellido y nombre\n");
    printf("5. Mostrar todos los clientes\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    scanf("%d", &op);
    getchar();

    switch (op) {
      case 1:
        printf("ingrese la edad a buscar: ");
        int edadBuscada;
        scanf("%d", &edadBuscada);
        getchar();
        mismaEdad(Apellidos, Nombres, Ciudades, Edades, n, edadBuscada);
        break;
      case 2:
        printf("ingrese la ciudad a eliminar: ");
        int ciudadAeliminar;
        leeCad(ciudadAeliminar, 30);
        getchar();
        eliminarPorCiudad(Apellidos, Nombres, Ciudades, Edades, n,
                          ciudadAeliminar);
      case 0:
        printf("Fin del programa.\n");
        break;
      default:
        printf("Opcion aun no implementada.\n");
    }
  } while (op != 0);

  return 0;
}

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
void cargarClientesOrdenado(tVecCad Apellidos, tVecCad Nombres,
                            tVecCad Ciudades, tVecInt Edades, int n) {
  int i, j;
  tCad ap, nom, ciu;
  int edad;

  for (i = 1; i <= n; i++) {
    printf("\n=== CLIENTE %d ===\n", i + 1);
    printf("Apellido: ");
    leeCad(ap, 30);
    printf("Nombre: ");
    leeCad(nom, 30);
    printf("Ciudad: ");
    leeCad(ciu, 30);
    printf("Edad: ");
    scanf("%d", &edad);
    getchar();
    // Buscamos posición para insertar (manteniendo orden)
    j = i - 1;
    while (j >= 0 && strcmp(ap, Apellidos[j]) < 0) {
      strcpy(Apellidos[j + 1], Apellidos[j]);
      strcpy(Nombres[j + 1], Nombres[j]);
      strcpy(Ciudades[j + 1], Ciudades[j]);
      Edades[j + 1] = Edades[j];
      j--;
    }

    // Si apellidos iguales, comparar nombres
    while (j >= 0 && strcmp(ap, Apellidos[j]) == 0 &&
           strcmp(nom, Nombres[j]) < 0) {
      strcpy(Apellidos[j + 1], Apellidos[j]);
      strcpy(Nombres[j + 1], Nombres[j]);
      strcpy(Ciudades[j + 1], Ciudades[j]);
      Edades[j + 1] = Edades[j];
      j--;
    }

    // Insertar cliente en posición correcta
    strcpy(Apellidos[j + 1], ap);
    strcpy(Nombres[j + 1], nom);
    strcpy(Ciudades[j + 1], ciu);
    Edades[j + 1] = edad;
  }
}

void mismaEdad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
               tVecInt Edades, int n, int edadBuscada) {
  int i;
  for (i = 1; i <= n; i++) {
    if (Edades[i] == edadBuscada) {
      printf("\nCliente %d:\n", i + 1);
      printf("  Apellido: %s\n", Apellidos[i]);
      printf("  Nombre:   %s\n", Nombres[i]);
      printf("  Ciudad:   %s\n", Ciudades[i]);
      printf("  Edad:     %d años\n", Edades[i]);
    }
  }
}

void eliminarPorCiudad(tVecCad Apellidos, tVecCad Nombres, tVecCad Ciudades,
                       tVecInt Edades, int* n, tCad ciudadAeliminar) {
  int i, j;

  for (i = 0; i < *n; i++) {
    if (strcmp(Ciudades[i], ciudadAeliminar) == 0) {
      // Desplazar hacia arriba todos los elementos siguientes
      for (j = i; j < *n - 1; j++) {
        strcpy(Apellidos[j], Apellidos[j + 1]);
        strcpy(Nombres[j], Nombres[j + 1]);
        strcpy(Ciudades[j], Ciudades[j + 1]);
        Edades[j] = Edades[j + 1];
      }
      (*n)--;  // hay un elemento menos
      i--;     // 👈 volver una posición atrás para revisar el nuevo elemento
               // movido
    }
  }
}
