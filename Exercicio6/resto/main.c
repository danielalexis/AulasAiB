#include <stdio.h>

int num, res;

int main()
{
    printf("Numero: ");
    scanf("%i", &num);
    if ((num % 2) == 0)
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
