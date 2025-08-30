#include <stdio.h>

int main() {
    int K;

    printf("Ingrese un número: ");
    scanf("%d", &K);

    for (int n = 2; n < K; n++) {
        int esPrimo = 1;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                esPrimo = 0;
                break;
            }
        }

        if (esPrimo == 1) {
            printf("%d ", n);
        }
    }

    return 0;
}
