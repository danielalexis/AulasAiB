#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rnum, dificuldade, num, tentativas;
bool acertou = false;

int main()
{
    printf("\n    |-----------------------|\n");
    printf("    |    Jogo da Adivinha   |\n");
    printf("    |      Dificuldade:     |\n");
    printf("    |      1 - Facil        |\n");
    printf("    |      2 - Medio        |\n");
    printf("    |      3 - Dificil      |\n");
    printf("    |-----------------------|\n");
    while (!rnum) {
        // O jogador escolhe a dificuldade
        printf("Dificuldade: ");
        scanf("%i", &dificuldade);
        //inciar o Random Number Generator
        srand(time(NULL));
        // Escolher o numero aleatorio

        // Tabela de dificuldade:
        // Facil - Numero entre 1 a 15
        // Medio - Numero entre 1 a 30
        // Dificl - Numero entre 1 a 60
        switch (dificuldade){
            case 1:
                rnum = rand() % 15 + 1;
                tentativas = 3;
                break;
            case 2:
                rnum = rand() % 30 + 1;
                tentativas = 6;
                break;
            case 3:
                rnum = rand() % 60 + 1;
                tentativas = 9;
                break;
            default:
                printf("Opcao invalida\n"); //Se a opção for invalida repete até ao jogador escolher uma opção valida
        }
    }

    printf("Tens %i tentativas\n", tentativas);
    while (acertou != true) {
        if (tentativas == 0) {
            break; //sai do loop se o jogador ficou sme tentativas
        }
        printf("Adivinha: ");
        scanf("%i", &num);


        if (num == rnum) {
            acertou = true; //o jogador ganhou
        } else if (num > rnum) {
            printf("Dica o numero e menor do que %i\n", num); // Dica 1
        } else if (num < rnum) {
            printf("Dica o numero e maior do que %i\n", num); // Dica 3
        }
        tentativas--; // Remover 1 tentativa
    }
    if (acertou == true) {
        printf("Ganhou!!!");
    } else {
        printf("Ficou sem tentativas! Boa sorte da proxima!");
    }
    return 0;
}
