#include <stdio.h>

int vel, time;
float dist;

int main()
{
    printf("Velocidade do Veiculo: ");
    scanf("%i", &vel);
    printf("Tempo que demorou: ");
    scanf("%i", &time);
    dist = (vel / 3.6) / time; // 3.6 vem de 1000/3600 (km/h) para 10/36 que é 3.6 (m/s)
    printf("A distancia percorrida foi %f metros", dist);
    return 0;
}
