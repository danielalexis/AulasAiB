#include <stdio.h>

int tempoSeg, horas, mins, segundos;

int main()
{
    int resto_horas;
    printf("Tempo (em segundos): ");
    scanf("%i", &tempoSeg);
    horas = tempoSeg / 3600;        // D� um n�mero inteiro da quantidade de horas
    resto_horas = tempoSeg % 3600;  // O n�mero restante de segundos que n�o d�o 1 horas
    mins = resto_horas / 60;        // O n�mero de restante de segundos a dividr por 60 (n�mero de minutos em 1 hora) d� a quantidade de minutos
    segundos = resto_horas % 60;    // O resto dos minutos s�o os segundos que faltam
    printf("%i Horas %i Minutos e %i Segundos\n", horas, mins, segundos);
    printf("Formato horas:mins:segundos: %i:%i:%i", horas, mins, segundos);
    return 0;
}
