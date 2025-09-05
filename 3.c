#include <stdio.h>
#include <math.h>

int main() {
    double A;
    printf("Ingrese un número real: ");
    scanf("%lf", &A);              // Usuario escribe 123.4567 → A = 123.4567

    // -----------------------------
    // PARTE ENTERA
    // -----------------------------
    int parteEntera = (int)A;      // parteEntera = 123 (descarta decimales)
    int cifrasEntera;

    if (parteEntera == 0) {
        cifrasEntera = 1;          // Caso especial: si A está entre 0 y 1 → la parte entera es 0 → 1 cifra
    } else {
        // log10(123) ≈ 2.089...
        // floor(2.089) = 2
        // 2 + 1 = 3 → tiene 3 cifras
        cifrasEntera = floor(log10(fabs(parteEntera))) + 1;
    }

    // -----------------------------
    // PARTE DECIMAL
    // -----------------------------
    double parteDecimal = A - parteEntera;    // parteDecimal = 123.4567 - 123 = 0.4567
    // Multiplico por 1,000,000 para "convertir" a entero (considero 6 cifras decimales)
    int parteDecimalEntera = (int)(parteDecimal * 1000000 + 0.5); 
    // parteDecimal * 1,000,000 = 456700.000...
    // (int)(456700.000 + 0.5) = 456700

    int cifrasDecimal;
    if (parteDecimalEntera == 0) {
        cifrasDecimal = 0;         // Si no hay decimales (ej: 25.0) → 0 cifras
    } else {
        // log10(456700) ≈ 5.659...
        // floor(5.659) = 5
        // 5 + 1 = 6 → hay 6 cifras decimales consideradas
        cifrasDecimal = floor(log10(parteDecimalEntera)) + 1;
    }

    // -----------------------------
    // SALIDA
    // -----------------------------
    printf("Parte entera: %d cifras\n", cifrasEntera);   // imprime 3
    printf("Parte decimal: %d cifras\n", cifrasDecimal); // imprime 6

    return 0;
}
