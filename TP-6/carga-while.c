#include <stdio.h>
#include <string.h>
#define TAM 100

/*------------------------------------
  Tipos de datos (al estilo UNSa)
------------------------------------*/
typedef char tCad[TAM];

typedef struct {
  tCad Ape, Nom, Dir, Cel;
  long FechaNac;
} tContacto;

typedef tContacto tVec[TAM];

/*------------------------------------
  Prototipos de módulos
------------------------------------*/
void leeCad(tCad, int);
tContacto cargar_registro();
void mostrar_registro(tContacto);
void cargar_lista(tVec, int*);
void mostrar_lista(tVec, int);

/*------------------------------------
  Programa principal
------------------------------------*/
int main() {
  tVec Agenda;
  int N;

  cargar_lista(Agenda, &N);  // carga inicial
  mostrar_lista(Agenda, N);  // muestra todo

  return 0;
}

void leeCad(tCad cad, int tam) {
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

/* Cargar un solo registro */
tContacto cargar_registro() {
  tContacto reg;
  printf("\nIngrese Apellido: ");
  leeCad(reg.Ape, TAM);
  printf("Ingrese Nombre: ");
  leeCad(reg.Nom, TAM);
  printf("Ingrese Dirección: ");
  leeCad(reg.Dir, TAM);
  printf("Ingrese Celular: ");
  leeCad(reg.Cel, TAM);
  printf("Ingrese Fecha de Nacimiento (AAAAMMDD): ");
  scanf("%ld", &reg.FechaNac);
  getchar();
  return reg;
}

/* Mostrar un registro */
void mostrar_registro(tContacto reg) {
  printf("\n-----------------------------");
  printf("\nApellido: %s", reg.Ape);
  printf("\nNombre: %s", reg.Nom);
  printf("\nDirección: %s", reg.Dir);
  printf("\nCelular: %s", reg.Cel);
  printf("\nFecha Nac: %ld", reg.FechaNac);
}

/* Cargar lista SIN ordenar */
void cargar_lista(tVec vec, int* N) {
  int b = 0;
  int i = 0;

  printf("\n--- CARGA DE CONTACTOS ---\n");
  do {
    i++;
    vec[i] = cargar_registro();  // se guarda al final
    printf("\n0. Seguir cargando  -  1. Terminar: ");
    scanf("%d", &b);
    getchar();
  } while (b == 0);

  *N = i;
}

/* Mostrar toda la lista */
void mostrar_lista(tVec vec, int N) {
  int i;
  printf("\n=== AGENDA TELEFÓNICA ===\n");
  for (i = 1; i <= N; i++) mostrar_registro(vec[i]);
}
