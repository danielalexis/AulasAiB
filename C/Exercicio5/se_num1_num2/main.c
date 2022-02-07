#include <stdio.h>

int num1, num2, maior;

int main()
{
    printf("Numero 1: ");
    scanf("%i", &num1);
    printf("Numero 2: ");
    scanf("%i", &num2);
    if (num1 > num2)
    {
        maior = num1;
    }
    else
    {
        maior = num2;
    }
    printf("O numero maior e %i", maior);
    return 0;
}
