#include <stdio.h>

int num;
double fatorial;

int main()
{
    printf("Fatorial a calcular: ");
    scanf("%i", &num);
    fatorial = 1.0;
    while (num > 0)
    {
        fatorial = fatorial * num;
        num = num - 1;
    }
    printf("Resultado: %G", fatorial);
    return 0;
}
