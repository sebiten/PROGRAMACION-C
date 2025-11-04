#include <stdio.h>
#include <string.h>
#define TAM 100

typedef char tCad[TAM];

typedef struct {
  tCad Ape, Nom, Dir, Cel;
  long FechaNac;
} tContacto;

typedef tContacto tVec[TAM];

void leeCad(tCad, int);
tContacto cargar_registro();
void mostrar_registro(tContacto);
void cargar_lista(tVec, int);
void mostrar_lista(tVec, int);

int main() {
  tVec Agenda;
  int N;

  printf("Ingrese la cantidad de contactos (N): ");
  scanf("%d", &N);
  getchar();  // limpia el buffer

  cargar_lista(Agenda, N);
  mostrar_lista(Agenda, N);

  return 0;
}

/* Lectura segura de cadenas (leeCad UNSa) */
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
  getchar();  // limpia buffer
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

/* Cargar lista con N conocido (incondicionada) */
void cargar_lista(tVec vec, int N) {
  int i;
  printf("\n--- CARGA DE CONTACTOS ---\n");
  for (i = 1; i <= N; i++) {
    printf("\nContacto #%d:\n", i);
    vec[i] = cargar_registro();  // se guarda en la posición i
  }
}

/* Mostrar toda la lista */
void mostrar_lista(tVec vec, int N) {
  int i;
  printf("\n=== AGENDA TELEFÓNICA ===\n");
  for (i = 1; i <= N; i++) mostrar_registro(vec[i]);
}
