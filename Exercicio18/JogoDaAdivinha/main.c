/*
    Autor: Daniel Pereira
    Data: 22/11/2021

    Titulo: Jogo da Adivinha
    Descricao. Adivinha um numero e ve se esta correto
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Funções
int menu();
int jogar(int tentativas, int numR);

// Constantes
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3
#define SAIR 4


int num_aleatorio, dificuldade, tentativas;
bool repetir = true;
char repetirInput;


int main() {
    int dificuldade, tentativas, res;
    while (repetir) {
        //inciar o Random Number Generator
        srand(time(NULL));
        do {
            dificuldade = menu();
        
            switch (dificuldade) {
                case FACIL:
                    tentativas = 5;
                    num_aleatorio = rand() % 15 + 1;
                    break;
                case MEDIO:
                    tentativas = 10;
                    num_aleatorio = rand() % 20 + 1;
                    break;
                case DIFICIL:
                    tentativas = 15;
                    num_aleatorio = rand() % 30 + 1;
                    break;
                default:
                    printf("OPCAO INVALIDA");
                    break;
            } 
        } while (!num_aleatorio);
        printf("Tens %i tentativas\n", tentativas);
        res = jogar(tentativas, num_aleatorio);
        if (res) {
            printf("Ganhou!!!!!\n");
        } else if (res == 2) {
            printf("Xau!\n");
        } else {
            printf("Ganhou\n");
        }
        printf("Quer repetir? (s/n)");
        scanf(" %c", &repetirInput);
        if (repetirInput == 'n') {
            printf("Adeus");
            break;
        }
    }
}


int menu() {
    int escolha;
    printf("\n");
    printf("    |-----------------------|\n");
    printf("    |    Jogo da Adivinha   |\n");
    printf("    |      Dificuldade:     |\n");
    printf("    |      1 - Facil        |\n");
    printf("    |      2 - Medio        |\n");
    printf("    |      3 - Dificil      |\n");
    printf("    |      4 - Sair         |\n");
    printf("    |-----------------------|\n");
    printf("Escolha uma opcao: ");
    scanf("%i", &escolha);
    return escolha;
}

int jogar(int tentativas, int numR) {
    int num;
    int acertou = 0; // 0 - Perdeu
                     // 1 - Ganhou
                     // 2 - Sair
    while (!acertou) {
            if (tentativas == 0) {
                acertou = 0;
                break; //sai do loop se o jogador ficou sem tentativas
            }
            printf("Adivinha: ");
            scanf("%i", &num);

            if (num == 0) { //Se o jogador escrever zero o programa termina
            acertou = 2;
                break;
            }

            if (num == numR) {
                acertou = 1; // O jogador ganhou
            } else if (num > num_aleatorio && tentativas != 1) { // Se só tiver 1 tentativa não mostrar a dica
                printf("Dica o numero e menor do que %i\n", num);
            } else if (num < num_aleatorio && tentativas != 1) {
                printf("Dica o numero e maior do que %i\n", num); // Se só tiver 1 tentativa não mostrar a dica
            }
            tentativas--; // Remover 1 tentativa
    }
    return acertou;
}