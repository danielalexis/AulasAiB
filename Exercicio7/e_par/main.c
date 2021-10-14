#include <stdio.h>
#include <stdbool.h>

int num;
bool ePar;
int main()
{
    printf("Numero: ");
    scanf("%i", &num);
    if ((num %2) == 0)
    {
        ePar = true;
    }
    else
    {
        ePar = false;
    }
    if (ePar)  { printf("O numero %i e par", num);   }
    if (!ePar) { printf("O numero %i e impar", num); }
    return 0;
}
