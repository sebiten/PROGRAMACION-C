#ifndef TAD_ARTICULO_H
#define TAD_ARTICULO_H

#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
  int codigo;
  char nombre[30];
  char proveedor[30];
  int stock;
  float precio;
} TArticulo;

typedef TArticulo TVecArticulos[TAM];

void mostrarMenu();
void cargarLista(TVecArticulos, int*);
void insertarOrdenado(TVecArticulos, int*, TArticulo);
void mostrarLista(TVecArticulos, int);
void mostrarPorProveedor(TVecArticulos, int, char[]);
void eliminarPorCodigo(TVecArticulos, int*, int);
void mostrarMenorStock(TVecArticulos, int, int);

#endif
