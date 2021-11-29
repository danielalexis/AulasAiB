#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define EOT 4

/*
Aluno : Daniel Pereira
*/

int main()
{
    char caracter;
    do {
        printf("Caracter: ");
        caracter = getchar(); getchar(); // O segundo getchar() elimina o buffer
        if (isalpha(caracter)) { // Se for letra

            if (islower(caracter)) {
                printf("O caracter %c e alfabetico e minusculo\n", caracter);
            } else if (isupper(caracter)) {
                printf("O caracter %c e alfabetico e maiusculo\n", caracter);
            }

        } else if (isdigit(caracter)) { // se for numero
            printf("O caracter %c e um digito\n", caracter);
        } else if (ispunct(caracter)) { // se for pontuacao
            printf("O caracter %c e pontuacao\n", caracter);
        } else if (isspace(caracter)) { // se for espaço
            printf("O caracter e um espaco\n");
        } else if (iscntrl(caracter)) { // se for controlo
            printf("O caracter e uma tecla de controlo\n");
        }
    } while(caracter != EOT);
    printf("Adeus");
    return 0;
}
