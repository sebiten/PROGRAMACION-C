#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char tcad[MAX];
typedef struct {
  long dni;
  tcad nombre;
  tcad apellido;
  tcad direccion;
  int preferencias;
} tdcliente;
typedef tdcliente tvec[MAX];

// prototipos
tdcliente cargar_registro();
void cargar_lista(tvec, int*);
void mostrar_lista(tvec, int);
void Mostrar_Cliente(tdcliente);  // ✅ FALTABA ESTE PROTOTIPO
void leeCad(tcad, int);
int contarpref(tvec, int);
int buscardni(tvec, int, long);
void modificardni(tvec, int, int);

int main(void) {
  int n;
  tvec lista;
  long dni_ingresado;

  cargar_lista(lista, &n);
  mostrar_lista(lista, n);

  int contador = contarpref(lista, n);
  printf("\nla cantidad de preferencia por comedia son: %d", contador);
  printf("\ningrese el dni a modificar: ");
  scanf("%ld", &dni_ingresado);
  int pos = buscardni(lista, n, dni_ingresado);
  if (pos != 0) {
    modificardni(lista, n, pos);
    printf("Lista luego de la modificacion del dni");
    mostrar_lista(lista, n);

  } else {
    printf("DNI no encontrado\n");
  }
  return 0;
}

void leeCad(tcad cad, int tam) {
  int j = 0;
  char c;
  c = getchar();
  while (c != EOF && c != '\n' && j < tam - 1) {
    cad[j] = c;
    j++;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}

tdcliente cargar_registro() {
  tdcliente Aux;
  printf("\nDNI: ");
  scanf("%ld", &Aux.dni);
  fflush(stdin);
  printf("\nApellido: ");
  leeCad(Aux.apellido, 30);
  fflush(stdin);
  printf("\nNombre: ");
  leeCad(Aux.nombre, 30);
  fflush(stdin);
  printf("\nDireccion: ");
  leeCad(Aux.direccion, 30);
  printf("\nPreferencia ingrese: 1 [Series], 2 [Comedia]");
  fflush(stdin);
  printf("\n3 [Terror], 4 [Accion], 5 [Romanticas] ");
  scanf("%d", &Aux.preferencias);
  return Aux;
}

void cargar_lista(tvec lista, int* n) {
  int i;
  printf("ingrese la cantidad de clientes: ");
  scanf("%d", n);
  for (i = 1; i <= *n; i++) {
    printf("ingrese los datos del cliente %d", i);
    lista[i] = cargar_registro();
  }
}

void Mostrar_Cliente(tdcliente Aux) {
  printf("\nDNI: %ld - Apellido y Nombre: %s, %s", Aux.dni, Aux.apellido,
         Aux.nombre);

  printf("\nDireccion: %s ", Aux.direccion);

  switch (Aux.preferencias) {
    case 1:
      printf("\nPreferencia: Series");
      break;
    case 2:
      printf("\nPreferencia: Comedia");
      break;
    case 3:
      printf("\nPreferencia: Terror");
      break;
    case 4:
      printf("\nPreferencia: Accion");
      break;
    case 5:
      printf("\nPreferencia: Romanticas");
      break;
  }
}

void mostrar_lista(tvec lista, int n) {
  int i;
  printf("\n--- LISTA DE CLIENTES (INVERTIDA) ---\n");
  for (i = 1; i <= n; i++) {
    Mostrar_Cliente(lista[i]);
  }
}

int contarpref(tvec lista, int n) {
  int i, cont = 0;
  for (i = 1; i <= n; i++) {
    if (lista[i].preferencias == 2) {
      cont++;
    }
  }
  return cont;
}

int buscardni(tvec lista, int n, long dni_ingresado) {
  int i = 1;
  while (i <= n && lista[i].dni != dni_ingresado) {
    i++;
  }
  if (i <= n) {
    return i;  // lo encontró
  } else {
    return 0;  // no está
  }
}

void modificardni(tvec lista, int n, int pos) {
  long nvo_dni;
  printf("\nIngrese el nuevo DNI: ");
  scanf("%ld", &nvo_dni);

  if (buscardni(lista, n, nvo_dni) != 0) {
    printf("Ese DNI ya existe. No se modificó.\n");
  } else {
    lista[pos].dni = nvo_dni;
    printf("DNI modificado correctamente.\n");
  }
}
