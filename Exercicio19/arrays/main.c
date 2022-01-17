#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int menu();
int ordenar(int * array);

int main()
{
    printf("Hello world!\n");
    return 0;
}


int menu() {
    int escolha;
    printf("1. Apresente a sequência ordenada por ordem crescente\n");
    printf("2. Obtenha o menor valor da sequência\n");
    printf("3. Obtenha o maior valor da sequência\n");
    printf("4. Obtenha a mediana da sequência\n");
    printf("5. Obtenha a média da sequência\n");
    scanf("%i", &escolha);
    return escolha;
}

int ordenar(int * array) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}