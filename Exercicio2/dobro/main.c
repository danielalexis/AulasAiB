#include <stdio.h>

int num, dobro;

int main()
{
    printf("Numero: ");
    scanf("%i", &num);
    dobro = num * 2;
    printf("O dobro e %i", dobro);
    return 0;
}
