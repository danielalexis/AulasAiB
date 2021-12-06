#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente);


int base, expoente;

int main()
{
    // Indicar a base e oexpoente e calcular-la
    printf("Indique a base e o expoente: ");
    scanf("%d^%d", &base, &expoente);
    printf("%d elevado a %d = %d\n", base, expoente, potencia(base, expoente));
    return 0;
}


int potencia(int base, int expoente)
{
    int i, potencia = 1;
    for (i = 0; i < expoente; i++)
    {
        potencia *= base;
    }
    return potencia;
}