#include <stdio.h>
#include <stdlib.h>

#define SIM 1
#define NAO 0

int num;

int ePar(int);

int main()
{
    do {
        printf("Digite um numero: ");
        scanf("%i", &num);
        if (ePar(num))
        {
            printf("%i e par\n", num);
        } else {
            printf("%i e impar\n", num);
        }
    } while (SIM);
    
    return 0;
}



int ePar(int num)
{
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}