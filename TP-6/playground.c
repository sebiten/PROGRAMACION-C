//  Una plataforma de streaming necesita administrar una lista de N clientes. La
//  información que necesita llevar de cada cliente es: DNI, Apellido, Nombre,
//  E_Dirección, Preferencia (Series, Comedia, Terror, Acción, Románticos). Se
//  necesita un programa modularizado que permita: cargar la lista de clientes y
//  finalmente mostrar la lista de clientes desde la última posición hasta la
//  primera.

#include <stdio.h>
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
void leeCad(tcad, int);

int main(void) {
  int n;
  tvec lista;
  cargar_lista(lista, &n);
  mostrar_lista(lista, n);

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