#include <stdio.h>
#include <stdbool.h>
int num1, num2, res;
char oper;
bool err = false;
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
            if (num2 != 0){
                res = num1 / num2;
            } else {
                printf("Divisao por 0 e impssivel");
                err = true;
            }
            break;
        default:
            printf("Operacao Invalida");
            err = true;
    }
    if (!err) {
            printf(" %i %c %i = %i", num1, oper, num2, res);
    }
    return 0;
}
