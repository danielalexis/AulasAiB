#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int dificuldade, num, tentativas;
bool repetir = true, acertou = false;
char jogar;
int main()
{
    while (repetir) {
        int num_aleatorio;

        //system("cls"); //limpa o ecr�
        printf("\n    |-----------------------|\n");
        printf("    |    Jogo da Adivinha   |\n");
        printf("    |      Dificuldade:     |\n");
        printf("    |      1 - Facil        |\n");
        printf("    |      2 - Medio        |\n");
        printf("    |      3 - Dificil      |\n");
        printf("    |      4 - Sair         |\n");
        printf("    |-----------------------|\n");
        while (!tentativas) {
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
                    tentativas = 4;
                    break;
                case 2:
                    num_aleatorio = rand() % 30 + 1;
                    tentativas = 8;
                    break;
                case 3:
                    num_aleatorio = rand() % 60 + 1;
                    tentativas = 12;
                    break;
                case 4:
                    printf("Adeus");
                    exit(1);
                    break;
                default:
                    printf("Opcao invalida\n"); //Se a opcão for invalida repete até ao jogador escolher uma opcão valida
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
            } else if (num > num_aleatorio && tentativas != 1) { // Se s� tiver 1 tentativa n�o mostrar a dica
                printf("Dica o numero e menor do que %i\n", num);
            } else if (num < num_aleatorio && tentativas != 1) {
                printf("Dica o numero e maior do que %i\n", num); // Se s� tiver 1 tentativa n�o mostrar a dica
            }
            tentativas--; // Remover 1 tentativa
        }
        if (acertou) {
            printf("Ganhou!!!\n");
        } else if (num == 0) {
            printf("O numero aleatorio era %i\n", num_aleatorio);
            printf("Adeus\n");
        } else {
            printf("Ficou sem tentativas! Boa sorte da proxima!\n");

        }
            printf("Quer jogar novamente (s/n)? ");
            scanf(" %c", &jogar);
            if (jogar == 'n') {
                repetir = false;
                break;
            }  
    }

    return 0;
}
