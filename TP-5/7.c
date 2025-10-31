#include <stdio.h>
#define MAX 100
typedef char tCad[MAX];

typedef struct {
  int Dia, Mes, Anio;
} tregFecha;

typedef struct {
  tCad apellido;
  tCad nombres;
  tCad domicilio;
  int dni;
  tregFecha fechaNacimiento;
} Alumno;

int main(void) {
  printf("Hola mundo!\n");
  return 0;
}