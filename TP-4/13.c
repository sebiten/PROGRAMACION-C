#include <stdio.h>

typedef int CodProducto[200];
typedef int CodProveedor[200];
typedef int Cantidad[200];
typedef float Precio[200];

// PROTOTIPOS
void cargarProductos(CodProducto, CodProveedor, Cantidad, Precio, int*);
void actualizarPrecios(CodProducto, CodProveedor, Cantidad, Precio, int*);
int buscarProducto(CodProducto, int, int);

int main(void) {
  int m;  // cantidad de productos del mini mercado
  CodProducto CodProd;
  CodProveedor CodProv;
  Cantidad Cant;
  Precio Pre;

  printf("=== CARGA DE PRODUCTOS DEL MINI MERCADO ===\n");
  cargarProductos(CodProd, CodProv, Cant, Pre, &m);

  printf("\n=== LISTA ORDENADA POR CODIGO DE PRODUCTO ===\n");
  for (int i = 1; i <= m; i++) {
    printf("CodProd: %d | CodProv: %d | Cant: %d | Precio: %.2f\n", CodProd[i],
           CodProv[i], Cant[i], Pre[i]);
  }

  printf("\n=== ACTUALIZACIÓN DE PRECIOS ===\n");
  actualizarPrecios(CodProd, CodProv, Cant, Pre, &m);

  printf("\n=== LISTA FINAL ACTUALIZADA ===\n");
  for (int i = 1; i <= m; i++) {
    printf("CodProd: %d | CodProv: %d | Cant: %d | Precio: %.2f\n", CodProd[i],
           CodProv[i], Cant[i], Pre[i]);
  }

  return 0;
}

// ----------------------------------------------------
// Carga ordenada de productos por Código de Producto
void cargarProductos(CodProducto CodProd, CodProveedor CodProv, Cantidad Cant,
                     Precio Pre, int* m) {
  int i, j;
  int nuevoCodProd, nuevoCodProv, nuevaCant;
  float nuevoPre;

  printf("Ingrese la cantidad de productos: ");
  scanf("%d", m);

  for (i = 1; i <= *m; i++) {
    printf("\nProducto %d:\n", i);
    printf("Codigo de producto: ");
    scanf("%d", &nuevoCodProd);
    printf("Codigo de proveedor: ");
    scanf("%d", &nuevoCodProv);
    printf("Cantidad: ");
    scanf("%d", &nuevaCant);
    printf("Precio de venta: ");
    scanf("%f", &nuevoPre);

    // Inserción ordenada por código
    j = i - 1;
    while (j >= 1 && nuevoCodProd < CodProd[j]) {
      CodProd[j + 1] = CodProd[j];
      CodProv[j + 1] = CodProv[j];
      Cant[j + 1] = Cant[j];
      Pre[j + 1] = Pre[j];
      j--;
    }

    CodProd[j + 1] = nuevoCodProd;
    CodProv[j + 1] = nuevoCodProv;
    Cant[j + 1] = nuevaCant;
    Pre[j + 1] = nuevoPre;
  }
}

// ----------------------------------------------------
// Buscar producto en la lista (devuelve posición o 0 si no existe)
int buscarProducto(CodProducto CodProd, int n, int codigoBuscado) {
  int i = 1;
  while (i <= n && CodProd[i] < codigoBuscado) i++;

  if (i <= n && CodProd[i] == codigoBuscado)
    return i;
  else
    return 0;  // no encontrado
}

// ----------------------------------------------------
// Actualizar precios o agregar nuevos productos
void actualizarPrecios(CodProducto CodProd, CodProveedor CodProv, Cantidad Cant,
                       Precio Pre, int* m) {
  int n, i, pos;
  int nuevoCodProd, nuevoCodProv;
  float nuevoPre;
  int actualizados = 0, agregados = 0;

  printf("Ingrese la cantidad de productos a actualizar: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("\nProducto actualizado %d:\n", i);
    printf("Codigo de producto: ");
    scanf("%d", &nuevoCodProd);
    printf("Codigo de proveedor: ");
    scanf("%d", &nuevoCodProv);
    printf("Nuevo precio de venta: ");
    scanf("%f", &nuevoPre);

    pos = buscarProducto(CodProd, *m, nuevoCodProd);

    if (pos != 0) {
      // Producto existente → se actualiza el precio
      Pre[pos] = nuevoPre;
      actualizados++;
    } else {
      // Producto nuevo → se inserta ordenado
      int j = *m;
      while (j >= 1 && nuevoCodProd < CodProd[j]) {
        CodProd[j + 1] = CodProd[j];
        CodProv[j + 1] = CodProv[j];
        Cant[j + 1] = Cant[j];
        Pre[j + 1] = Pre[j];
        j--;
      }

      CodProd[j + 1] = nuevoCodProd;
      CodProv[j + 1] = nuevoCodProv;
      Cant[j + 1] = 0;  // nuevo producto → cantidad cero
      Pre[j + 1] = nuevoPre;
      (*m)++;
      agregados++;
    }
  }

  printf("\nProductos actualizados: %d", actualizados);
  printf("\nProductos nuevos agregados: %d\n", agregados);
}
