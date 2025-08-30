#include <stdio.h>
int main(void)
{
    int n, nro;
    int count0 = 0, countPos = 0, countNeg = 0;
    int max, min;
    int acupos = 0, acuneg = 0; // sumas
    double prompos = 0.0, promneg = 0.0;
    printf("Ingrese la cantidad de numeros a evaluar: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &nro);
        if (i == 0)
        {
            max = nro;
            min = nro;
        }
        else
        {
            if (nro > max)
                max = nro;
            if (nro < min)
                min = nro;
        }
        if (nro > 0)
        {
            countPos++;
            acupos += nro;
        }
        else if (nro == 0)
        {
            count0++;
        }
        else
        {
            countNeg++;
            acuneg += nro;
        }
    }
    if (countPos > 0)
        prompos = (double)acupos / countPos;
    if (countNeg > 0)
        promneg = (double)acuneg / countNeg;

    printf("\nResumen:\n");
    printf("Positivos: %d, Negativos: %d, Ceros: %d\n", countPos, countNeg, count0);
    printf("Maximo: %d\n", max);
    printf("Minimo: %d\n", min);
    printf("Suma (max + min): %d\n", max + min);

    if (countPos > 0)
        printf("Promedio de positivos: %.2f\n", prompos);
    else
        printf("Promedio de positivos: N/A (no hubo positivos)\n");

    if (countNeg > 0)
        printf("Promedio de negativos: %.2f\n", promneg);
    else
        printf("Promedio de negativos: N/A (no hubo negativos)\n");

    return 0;
}
