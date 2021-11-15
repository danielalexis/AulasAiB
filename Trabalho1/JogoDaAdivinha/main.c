#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int num_aleatorio, dificuldade, num, tentativas;
bool acertou = false;

int main()
{
    printf("\n    |-----------------------|\n");
    printf("    |    Jogo da Adivinha   |\n");
    printf("    |      Dificuldade:     |\n");
    printf("    |      1 - Facil        |\n");
    printf("    |      2 - Medio        |\n");
    printf("    |      3 - Dificil      |\n");
    printf("    |      4 - Sair         |\n");
    printf("    |-----------------------|\n");
    while (!num_aleatorio) {
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
                num_aleatorio = rand() % 15 + 1;
                tentativas = 3;
                break;
            case 2:
                num_aleatorio = rand() % 30 + 1;
                tentativas = 6;
                break;
            case 3:
                num_aleatorio = rand() % 60 + 1;
                tentativas = 9;
                break;
            case 4:
                printf("Adeus");
                exit(1);
                break;
            default:
                printf("Opcao invalida\n"); //Se a opção for invalida repete até ao jogador escolher uma opção valida
        }
    }
    printf("\nNota: escreva '0' para sair do programa\n");
    printf("Tens %i tentativas\n", tentativas);
    while (!acertou) {
        if (tentativas == 0) {
            break; //sai do loop se o jogador ficou sme tentativas
        }
        printf("Adivinha: ");
        scanf("%i", &num);

        if (num == 0) {
            break;
        }

        if (num == num_aleatorio) {
            acertou = true; //o jogador ganhou
        } else if (num > num_aleatorio && tentativas != 1) { // Se só tiver 1 tentativa não mostrar a dica
            printf("Dica o numero e menor do que %i\n", num);
        } else if (num < num_aleatorio && tentativas != 1) {
            printf("Dica o numero e maior do que %i\n", num); // Se só tiver 1 tentativa não mostrar a dica
        }
        tentativas--; // Remover 1 tentativa
    }
    if (acertou) {
        printf("Ganhou!!!");
    } else if (num == 0) {
        printf("O numero aleatorio era %i", num_aleatorio);
        printf("\nAdeus");
    } else {
        printf("Ficou sem tentativas! Boa sorte da proxima!");
    }
    return 0;
}
