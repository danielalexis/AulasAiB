#include <stdio.h>

int tempoSeg, horas, mins, segundos;

int main()
{
    int resto_horas;
    printf("Tempo (em segundos): ");
    scanf("%i", &tempoSeg);
    horas = tempoSeg / 3600;        // Dá um número inteiro da quantidade de horas
    resto_horas = tempoSeg % 3600;  // O número restante de segundos que não dão 1 horas
    mins = resto_horas / 60;        // O número de restante de segundos a dividr por 60 (número de minutos em 1 hora) dá a quantidade de minutos
    segundos = resto_horas % 60;    // O resto dos minutos são os segundos que faltam
    printf("%i Horas %i Minutos e %i Segundos\n", horas, mins, segundos);
    printf("Formato horas:mins:segundos: %i:%i:%i", horas, mins, segundos);
    return 0;
}
