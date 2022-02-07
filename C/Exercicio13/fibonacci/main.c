#include <stdio.h>
#include <stdlib.h>

int nelemento, n1, n2, n3;

int main()
{
    printf("Ate que elemnto quer calcular: ");
    scanf("%i", &nelemento);
    //primeiro termo
    n1 = 0;
    // segundo termo
    n2 = 1;
    printf("Fibonacci: %i, %i, ", n1, n2);
    for (int i = 3; i <= nelemento; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%i, ", n3);
    }
    return 0;
}
