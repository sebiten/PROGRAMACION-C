#include <stdio.h>
// Dada una lista de números naturales, se pide contabilizar cuántos de ellos son capicúas  e indicar los capicúas que están formados sólo por dígitos impares.
int esCapicua(int num)
{
    int inverso = 0, original = num;
    while (num > 0)
    {
        inverso = inverso * 10 + num % 10;
        num /= 10;
    }
    return inverso == original;
}
int soloImpares(int num)
{
    while (num > 0)
    {
        int digito = num % 10;
        if (digito % 2 == 0)
            return 0;
        num /= 10;
    }
    return 1;
}
int main()
{
    int n, numero;
    int contadorCapicuas = 0;

    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);

    printf("Ingrese los números:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        if (esCapicua(numero))
        {
            contadorCapicuas++;
            if (soloImpares(numero))
            {
                printf("Capicúa solo con dígitos impares: %d\n", numero);
            }
        }
    }

    printf("Cantidad de capicúas: %d\n", contadorCapicuas);

    return 0;
}
// Ejemplo de entrada:
// 5
// 121
// 12321
// 13531
// 24642
// 12345
// Ejemplo de salida:
// Capicúa solo con dígitos impares: 13531
// Cantidad de capicúas: 3
// Explicación: En el ejemplo, hay tres números capicúas (121, 12321, 13531), pero solo uno de ellos (13531) está formado únicamente por dígitos impares.