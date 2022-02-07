#include <stdio.h>

int contador, num;

int main()
{
    int divisor;
    printf("Numero: ");
    scanf("%i", &num);
    contador = 0;
    divisor = num;
    do {
        if ((num % divisor) == 0 )
        {
            printf("O numero %i tem o divisor %i\n", num, divisor);
            contador++;
        }
        divisor--;
    } while ( divisor > 0);
    printf("O numero %i tem %i divisores\n", num, contador);
    return 0;
}
