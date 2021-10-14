#include <stdio.h>

int num, res;

int main()
{
    printf("Numero: ");
    scanf("%i", &num);
    if (num % 2) //Se isto der 0 vai ser considerado verdadeiro
    {
        res = num / 2;
    }
    else
    {
        res = num * 2;
    }
    printf("O resultado e %i", res);
    return 0;
}
