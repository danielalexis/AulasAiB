#include <stdio.h>
const float IVA = 0.23;
int quant;
float price, total_price;

int main()
{
    printf("Bem-vindo a loja de Bananas! Diga-me o preco de uma banana!\n");
    printf("Preco de uma banana: ");
    scanf("%f", &price);
    printf("Quantas bananas deseja levar? ");
    scanf("%i", &quant);
    total_price = (price * quant) * (1 + IVA);
    printf("O seu total e %.2f euros!", total_price);
    return 0;
}
