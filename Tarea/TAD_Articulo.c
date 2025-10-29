#include "TAD_Articulo.h"

void mostrarMenu() {
  printf("1. Cargar lista inicial (ordenada)\n");
  printf("2. Agregar un nuevo artículo\n");
  printf("3. Eliminar un artículo por código\n");
  printf("4. Mostrar todos los artículos\n");
  printf("5. Mostrar artículos por proveedor\n");
  printf("6. Mostrar artículos con stock menor al mínimo\n");
  printf("0. Salir\n");
}

void insertarOrdenado(TVecArticulos V, int* n, TArticulo nuevo) {
  int i = *n - 1;
  while (i >= 0 && V[i].codigo > nuevo.codigo) {
    V[i + 1] = V[i];
    i--;
  }
  V[i + 1] = nuevo;
  (*n)++;
}

void cargarLista(TVecArticulos V, int* n) {
  int i, cant;
  TArticulo art;
  printf("\nCantidad de artículos: ");
  scanf("%d", &cant);
  getchar();

  for (i = 0; i < cant; i++) {
    printf("\nArtículo %d:\n", i + 1);
    printf("Código: ");
    scanf("%d", &art.codigo);
    getchar();
    printf("Nombre: ");
    gets(art.nombre);
    printf("Proveedor: ");
    gets(art.proveedor);
    printf("Stock: ");
    scanf("%d", &art.stock);
    printf("Precio: ");
    scanf("%f", &art.precio);
    insertarOrdenado(V, n, art);
  }
}

void mostrarLista(TVecArticulos V, int n) {
  int i;
  printf("\n=== LISTA DE ARTÍCULOS ===\n");
  for (i = 0; i < n; i++) {
    printf("\nCódigo: %d", V[i].codigo);
    printf("\nNombre: %s", V[i].nombre);
    printf("\nProveedor: %s", V[i].proveedor);
    printf("\nStock: %d", V[i].stock);
    printf("\nPrecio: %.2f\n", V[i].precio);
  }
}

void mostrarPorProveedor(TVecArticulos V, int n, char prov[]) {
  int i, existe = 0;
  printf("\n=== ARTÍCULOS DEL PROVEEDOR %s ===\n", prov);
  for (i = 0; i < n; i++) {
    if (strcmp(V[i].proveedor, prov) == 0) {
      printf("\nCódigo: %d - %s ($%.2f, stock %d)", V[i].codigo, V[i].nombre,
             V[i].precio, V[i].stock);
      existe = 1;
    }
  }
  if (!existe) printf("\nNo se encontraron artículos de ese proveedor.\n");
}

void eliminarPorCodigo(TVecArticulos V, int* n, int cod) {
  int i, j, encontrado = 0;
  for (i = 0; i < *n && !encontrado; i++) {
    if (V[i].codigo == cod) {
      encontrado = 1;
      for (j = i; j < *n - 1; j++) V[j] = V[j + 1];
      (*n)--;
      printf("\nArtículo eliminado correctamente.\n");
    }
  }
  if (!encontrado) printf("\nCódigo no encontrado.\n");
}

void mostrarMenorStock(TVecArticulos V, int n, int min) {
  int i, hay = 0;
  printf("\n=== ARTÍCULOS CON STOCK MENOR A %d ===\n", min);
  for (i = 0; i < n; i++) {
    if (V[i].stock < min) {
      printf("\nCódigo: %d - %s (Stock: %d)", V[i].codigo, V[i].nombre,
             V[i].stock);
      hay = 1;
    }
  }
  if (!hay) printf("\nNo hay artículos con stock menor al mínimo.\n");
}
