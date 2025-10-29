#include <stdio.h>
#include <string.h>

#include "TAD_Articulo.h"

int main() {
  TVecArticulos A;
  int N = 0, opcion;
  TArticulo art;
  int cod, minStock;
  char prov[30];

  do {
    mostrarMenu();
    printf("\nOpción: ");
    scanf("%d", &opcion);
    getchar();

    switch (opcion) {
      case 1:
        cargarLista(A, &N);
        break;
      case 2:
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
        insertarOrdenado(A, &N, art);
        break;
      case 3:
        printf("\nIngrese código a eliminar: ");
        scanf("%d", &cod);
        eliminarPorCodigo(A, &N, cod);
        break;
      case 4:
        mostrarLista(A, N);
        break;
      case 5:
        printf("\nProveedor: ");
        getchar();
        gets(prov);
        mostrarPorProveedor(A, N, prov);
        break;
      case 6:
        printf("\nIngrese stock mínimo: ");
        scanf("%d", &minStock);
        mostrarMenorStock(A, N, minStock);
        break;
      case 0:
        printf("\nFin del programa.\n");
        break;
      default:
        printf("Opción inválida.\n");
    }
  } while (opcion != 0);

  return 0;
}
