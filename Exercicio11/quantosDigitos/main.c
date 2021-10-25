#include <stdio.h>

int num;
int numDigitos;

int main()
{
    printf("Numero: ");
    scanf("%i", &num);
    while (num != 0)
    {
        num = num / 10;
        numDigitos = numDigitos + 1;
    }
    printf("Numero de digitos: %i", numDigitos);
    return 0;
}
