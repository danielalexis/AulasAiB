#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Tamanho da Sequencia
#define TAMSEQ 10

//
int sequencia[TAMSEQ];

// Funções
int menu();
int LerSeq();
int OrdenarSeq( int[TAMSEQ]);
void ImprimirSeq( int[TAMSEQ]);
int NumMaiorSeq( int[TAMSEQ]);
int NumMenorSeq( int[TAMSEQ]);
float MediaSeq( int[TAMSEQ]);
int MedianaSeq( int[TAMSEQ]);

int main()
{
    int escolha;
    setlocale(LC_ALL, "*");
    while (true) {
        escolha = menu();
        switch (escolha) {
            case 1:
                LerSeq();
                ImprimirSeq(sequencia);
                break;
            case 2:
                OrdenarSeq(sequencia);
                ImprimirSeq(sequencia);
                break;
            case 3:
                ImprimirSeq(sequencia);
                break;
            case 4:
                printf("O numero maior da sequência é: %i\n", NumMaiorSeq(sequencia));
                break;
            case 5:
                printf("O numero menor da sequência é: %i\n", NumMenorSeq(sequencia));
                break;
            case 6:
                printf("A media da sequência é: %f\n", MediaSeq(sequencia));
                break;
            case 7:
                printf("A mediana da sequência é: %i\n", MedianaSeq(sequencia));
                break;
            case 0:
                printf("Obrigado por utilizar o programa!\n");
                break;
        }
    }
    
    return 0;
}

int menu() {
    int opcao;
    printf("------------------\n");
    printf("1 - Ler Sequência\n");
    printf("2 - Ordenar Sequência\n");
    printf("3 - Imprimir Sequência\n");
    printf("4 - Número Maior da Sequência\n");
    printf("5 - Número Menor da Sequência\n");
    printf("6 - Média da Sequência\n");
    printf("7 - Mediana da Sequência\n");
    printf("0 - Sair\n");
    printf("------------------\n");
    do {
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);
    return opcao;
}

int LerSeq() {
    int i;
    for (i = 0; i < TAMSEQ; i++) {
        printf("Digite o %i número da sequência: ", i+1);
        scanf("%i", &sequencia[i]);
    }
    return 0;
}

int OrdenarSeq( int sequencia[TAMSEQ]) {
    printf("A ordenar sequência\n");
    // Ordenar a Sequencia
    for (int i = 0; i < TAMSEQ; i++) {
        for (int j = 0; j < TAMSEQ; j++) {
            if (sequencia[i] < sequencia[j]) {
                int aux = sequencia[i];
                sequencia[i] = sequencia[j];
                sequencia[j] = aux;
            }
        }
    }
}

void ImprimirSeq( int sequencia[TAMSEQ]) {
    printf("Sequncia: ");
    // Imprimir a Sequencia
    for (int i = 0; i < TAMSEQ; i++) {
        printf("%i ", sequencia[i]);
    }
    printf("\n");
}

int NumMaiorSeq(int sequencia[TAMSEQ]) {
    int maior = sequencia[0];
    for (int i = 0; i < TAMSEQ; i++) {
        if (sequencia[i] > maior) {
            maior = sequencia[i];
        }
    }
    return maior;
}

int NumMenorSeq(int sequencia[TAMSEQ]) {
    int menor = sequencia[0];
    for (int i = 0; i < TAMSEQ; i++) {
        if (sequencia[i] < menor) {
            menor = sequencia[i];
        }
    }
    return menor;
}

float MediaSeq(int sequencia[TAMSEQ]) {
    int soma = 0;
    for (int i = 0; i < TAMSEQ; i++) {
        soma += sequencia[i];
    }
    return (float)soma / TAMSEQ;
}

int MedianaSeq(int sequencia[TAMSEQ]) {
    int mediana;
    if (TAMSEQ % 2 == 0) {
        mediana = (sequencia[TAMSEQ/2] + sequencia[TAMSEQ/2 - 1]) / 2;
    } else {
        mediana = sequencia[TAMSEQ/2];
    }
    return mediana;
}