#include <stdio.h>

int main(void)
{
    int consumo,
        valor_basico = 3000,
        valor_exceso = 12,
        importe = 0, exceso = 0;

    printf("ingrese el consumo del mes:");
    scanf("%d", &consumo);
    if (consumo > 1000 && consumo < 2000)
    {
        exceso = consumo - 1000; // si tengo 1500 de consumo quedaria en 500 el exceso
        importe = valor_basico + exceso * valor_exceso;
    }
    else if (consumo <= 1000)
    {
        importe = valor_basico;
    }
    else
    {
        exceso = consumo - 1000;
        importe = valor_basico + exceso * (2 * valor_exceso);
    }
    printf("el importe a pagar por el comsumo de %d, es: %d", consumo, importe);

    return 0;
}