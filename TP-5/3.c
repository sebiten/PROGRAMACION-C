#include <stdio.h>
typedef char tCad[20]; /*declara una cadena*/

void leeCad(tCad cad, int t);
int main(void) {
  tCad dni;
  tCad nombre;
  tCad apellido;
  tCad fechaNac;
  printf("Ingrese DNI: ");
  leeCad(dni, 20);
  printf("Ingrese Nombre: ");
  leeCad(nombre, 20);
  printf("Ingrese Apellido: ");
  leeCad(apellido, 20);
  printf("Ingrese Fecha de Nacimiento: ");
  leeCad(fechaNac, 20);
  printf("\nDNI: %s\n", dni);
  printf("Nombre: %s\n", nombre);
  printf("Apellido: %s\n", apellido);
  printf("Fecha de Nacimiento: %s\n", fechaNac);

  return 0;
}

void leeCad(tCad cad, int t) {
  int j;
  char c;
  j = 0;
  c = getchar();
  while (c != EOF && c != '\n' && j < t - 1) {
    cad[j] = c;
    j++;
    c = getchar();
  }
  cad[j] = '\0';
  while (c != EOF && c != '\n') c = getchar();
}
