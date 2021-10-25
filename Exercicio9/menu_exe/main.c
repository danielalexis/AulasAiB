#include <stdio.h>
#include <stdlib.h>

char opcao;

int main()
{
    printf("|---------------Menu APPs---------------|\n");
    printf("|           (B)loco de Notas            |\n");
    printf("|               (P)aint                 |\n");
    printf("|            (C)alculadora              |\n");
    printf("|---------------------------------------|\n");
    printf("> "); scanf("%c", &opcao);
    switch(opcao)
    {
        case 'b': case 'B': system("notepad.exe"); break;
        case 'p': case 'P': system("mspaint.exe");   break;
        case 'c': case 'C': system("calc.exe");    break;
        default: printf("Opcao Invalida");
    }
    return 0;
}
