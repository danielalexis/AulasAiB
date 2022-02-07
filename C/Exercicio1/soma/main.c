#include <stdio.h>

int num1, num2, soma;

int main()
{
    printf("Numero 1: ");
    scanf("%i", &num1);
    printf("Numero 2: ");
    scanf("%i", &num2);
    soma = num1 + num2;
    printf("A soma e: %i", soma);
    return 0;
}
