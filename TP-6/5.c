#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char tCad[MAX];
typedef struct {
  tCad Ape, Nom, Dir, Cel;
  long fechaNac;
} tContacto;

typedef tContacto tVec[MAX];

// Prototipos
void leeCad(tCad, int);
tContacto cargar_registro();
void mostrar_registro(tContacto);
void agregar_contacto(tVec, int);
void cargar_lista(tVec, int*);
void mostrar_lista(tVec, int);

int main() {
  tVec Agenda;
  int N;
  cargar_lista(Agenda, &N);
  mostrar_lista(Agenda, N);
  return 0;
}

// Lectura de cadenas
void leeCad(tCad cad, int tam) {
  int j = 0;
  char c = getchar();
  while (c != EOF && c != '\n' && j < tam - 1) {
    cad[j] = c;
    j++;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}

// Cargar un registro
tContacto cargar_registro() {
  tContacto reg;
  printf("\nIngrese Apellido: ");
  leeCad(reg.Ape, MAX);
  printf("Ingrese Nombre: ");
  leeCad(reg.Nom, MAX);
  printf("Ingrese Dirección: ");
  leeCad(reg.Dir, MAX);
  printf("Ingrese Celular: ");
  leeCad(reg.Cel, MAX);
  printf("Ingrese Fecha de nacimiento (AAAAMMDD): ");
  scanf("%ld", &reg.fechaNac);
  getchar();
  return reg;
}

// Mostrar un registro
void mostrar_registro(tContacto reg) {
  printf("\n-----------------------------");
  printf("\nApellido: %s", reg.Ape);
  printf("\nNombre: %s", reg.Nom);
  printf("\nDirección: %s", reg.Dir);
  printf("\nCelular: %s", reg.Cel);
  printf("\nFecha Nac: %ld\n", reg.fechaNac);
}

// Insertar contacto ordenado por apellido y nombre
void agregar_contacto(tVec vec, int N) {
  int j;
  vec[0] = cargar_registro();
  j = N;
  while (j >= 1 && strcmp(vec[j].Ape, vec[0].Ape) > 0) {
    vec[j + 1] = vec[j];
    j--;
  }
  while (j >= 1 && strcmp(vec[j].Ape, vec[0].Ape) == 0 &&
         strcmp(vec[j].Nom, vec[0].Nom) > 0) {
    vec[j + 1] = vec[j];
    j--;
  }
  vec[j + 1] = vec[0];
}

// Cargar lista de contactos
void cargar_lista(tVec vec, int* N) {
  int b = 0;
  int i = 0;
  printf("\n--- CARGA DE CONTACTOS ---\n");
  do {
    i++;
    agregar_contacto(vec, i - 1);
    printf("\n0. Seguir  -  1. Finalizar: ");
    scanf("%d", &b);
    getchar();
  } while (b == 0);
  *N = i;
}

// Mostrar lista completa
void mostrar_lista(tVec vec, int N) {
  int i;
  printf("\n=== AGENDA TELEFÓNICA ===\n");
  for (i = 1; i <= N; i++) mostrar_registro(vec[i]);
}
