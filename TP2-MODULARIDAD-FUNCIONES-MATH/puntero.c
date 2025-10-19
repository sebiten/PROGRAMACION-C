#include <stdio.h>

void modificarNumero(int* n);

int main() {
  int n;

  printf("Antes de llamar a la funcion:\n");
  printf("Valor de n = %d\n", n);  // puede estar sin inicializar
  printf("Direccion de n (&n) = %p\n", &n);

  modificarNumero(&n);  // le paso la dirección de n

  printf("\nDespues de volver de la funcion:\n");
  printf("Valor de n = %d\n", n);
  printf("Direccion de n (&n) = %p\n", &n);

  return 0;
}

void modificarNumero(int* n) {
  printf("\nDentro de la funcion:\n");
  printf("Valor recibido en n (direccion) = %p\n", n);
  printf("Direccion del puntero (&n) = %p\n", &n);

  printf("\nIngrese un nuevo valor: ");
  scanf("%d", n);  // guarda directamente en la direccion original (del main)

  printf("Nuevo valor (accedido con *n) = %d\n", *n);
}
