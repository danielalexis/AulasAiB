#include <stdio.h>

int num1, num2, res;
char oper;
int main()
{
    printf("Calculo: ");
    scanf("%i%c%i", &num1, &oper, &num2);
    switch(oper) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case 'x':
            res = num1 * num2;
            break;
        case '/':
            res = num1 / num2;
            break;
        default:
            printf("Operacao Invalida");
            return 1;
    }
    printf(" %i %c %i = %i", num1, oper, num2, res);
    return 0;
}
