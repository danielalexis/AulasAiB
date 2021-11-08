#include <stdio.h>
#include <stdbool.h>

int num;
bool ePrimo;

int main() {


    int nDivisores, divisor;
    printf("Indique um numero: ");
    scanf("%i", &num);
    nDivisores = 0;
    for(divisor = 1; divisor <= num; divisor++) {
        if(num % divisor == 0) {
            nDivisores++;
        }
    }
    if(nDivisores > 2) {
        ePrimo = false;
    } else {
        ePrimo = true;
    }
    if(ePrimo) {
        printf("O numero %i e primo.", num);
    } else {
        printf("O numero %i nao e primo.", num);
    }
    return 0;
}

