/** Quiz Cidadania
 * Autor: Daniel Pereira, Vasco Rego, Mariana Peixoto e Hugo Cordeiro
 * Data: 27/12/2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h> // Para poder usar acentos, etc

// Constantes
#define TAMTEX   128    // A utilizar em strings com perguntas e respostas
#define TAMQST   500    // Tamanho da quest?o mais longa
#define MAXQST   100    // M?ximo de quest?es admitido
const char nomeFicheiro[] = "Quest_Cidadania.txt"; // Ficheiro com as perguntas

// Conjunto de todas as perguntas
char quest[MAXQST][TAMQST];

void menu();
void init( char[][TAMQST]);
int FazerQuest( char[][TAMQST], int, int);       // Faz questionário de x perguntas num total de y
// Funcoes de armazenamento em ficheiro
int CarregarQuest( const char *, char[][TAMQST]);   // Carrega quest?es a partir de ficheiro
int GuardarQuestoes( char[][TAMQST], const char *);    // Guarda quest?es em ficheiro


int main()
{
    int totalPergs, res, QuantPerguntas;

    setlocale(LC_ALL,""); // Para poder usar acentos, etc
    menu();
    init(quest);

    // Carrega as questões do ficheiro
    totalPergs = CarregarQuest(nomeFicheiro, quest);
    if( totalPergs > 0) {
        printf("Foram carregadas %i perguntas do ficheiro <%s>.\n", totalPergs, nomeFicheiro);
    } else {
        printf("Não foi possível abrir o ficheiro <%s> para leitura.\n", nomeFicheiro);
    }

    do {
        printf("\nIntroduza o número de perguntas a fazer (max %i): ", totalPergs);
        scanf("%i", &QuantPerguntas);
        if (QuantPerguntas > totalPergs) { printf("Erro: Número de perguntas inválido.\n"); }
    } while (QuantPerguntas > totalPergs);

    // Fazer o questionario
    res = FazerQuest( quest, totalPergs, QuantPerguntas);
    printf("Acertou %i das %i perguntas.\n", res, QuantPerguntas);
    // Guarda perguntas do question?rio atual em ficheiro de texto
    /*
    totalPergs = GuardarQuestoes(questionario, nomeFicheiro);
    if( totalPergs > 0)
        printf("Foram guardadas %i perguntas em ficheiro <%s> com sucesso.\n", totalPergs, nomeFicheiro);
    else
        printf( "Nao foi possivel abrir o ficheiro para escrita!\n");
    */
    return 0;
}

/** Apresentacao
 * Faz a apresentacao do Quiz
 * Logotipo gerado em: http://www.patorjk.com/software/taag/#p=display&f=Small&t=QuizExTexto
 */
void menu() {
    printf("//-----------------------------------------------//\n");
    printf("|                   Questionario                  |\n");
    printf("\\\\-----------------------------------------------//\n");
}

/*
*  Inicializa o conjunto de perguntas
*  Estrutura: Pergunta|Resposta|Resposta|Resposta|Resposta|Opção certa
*/
void init( char quest[][TAMQST])
{
    int i;

    for( i=0; i<MAXQST; i++)
        strcpy( quest[i], ""); // Inicializa as questões com uma string vazia
}

/** FazerQuestionario
 * Dadas todas as perguntas faz question?rio com max perguntas
 * Par?metros: question?rio, total de perguntas e m?ximo de perguntas a fazer
 * Retorno: Percentagem de respostas corretas (valor%)
 */
int FazerQuest( char quest[][TAMQST], int total, int max)
{
    char aux[TAMQST];
    char pergunta[TAMTEX];
    char resposta1[TAMTEX], resposta2[TAMTEX], resposta3[TAMTEX], resposta4[TAMTEX];
    int solucao, i, indice;
    int contaCorretas, numResposta;
    char *aptd;     // apontador para caracter (endere?o)
	char delim[] = "|";

    srand(time(NULL));
    // Baralhar primeiras max quest?es
    for( i=0; i<max; i++)
    {
        indice = rand() % total; // gera ?ndice de quest?o com que trocar posi??o
        strcpy( aux, quest[i]);
        strcpy( quest[i], quest[indice]);
        strcpy( quest[indice], aux);
    }
    printf("----------------- QUIZ --------------------\n");
    contaCorretas = 0;
    for( i=0; i<max; i++)
    {
       // Extrai dados da quest?o i
        aptd = strtok(quest[i], delim);
        strcpy(pergunta, aptd);
        aptd = strtok(NULL, delim);
        strcpy(resposta1, aptd);
        aptd = strtok(NULL, delim);
        strcpy(resposta2, aptd);
        aptd = strtok(NULL, delim);
        strcpy(resposta3, aptd);
        aptd = strtok(NULL, delim);
        strcpy(resposta4, aptd);
        aptd = strtok(NULL, delim);
        solucao = atoi(aptd);
        // Apresenta pergunta e hip?teses de resposta
        printf("%s\n", pergunta);
        printf("\t1 - %s\n", resposta1);
        printf("\t2 - %s\n", resposta2);
        printf("\t3 - %s\n", resposta3);
        printf("\t4 - %s\n", resposta4);
        printf("---------------------------------------\n");
        printf("Resposta: ");
        scanf("%i", &numResposta);
        if( numResposta == solucao)
            contaCorretas++;
    }
    return contaCorretas * 100 / max;   // retorna % de corretas
}

/** CarregarQuestoes
 * Funcao que faz o carregamento das quest?es a partir de ficheiro de texto
 * na forma:
 *      pergunta|resposta1|resposta2|resposta3|resposta4|solu??o
 * Par?metros: nome do ficheiro e question?rio
 * Retorno: quantidade de quest?es carregadas
 */
int CarregarQuest( const char file[TAMTEX], char quest[][TAMQST])
{
    FILE *apf;
    char perg[TAMQST];
    int contador;

    apf = fopen( file, "r");      // Abre ficheiro para leitura
    if( !apf)
    {
        return 0; // N?o foi poss?vel abrir o ficheiro para leitura
    }
    contador = 0;
    while( fgets( perg, TAMQST, apf) != NULL)
    {
        perg[strlen(perg)-1] = '\0';    // Apaga o '\n' final da linha
        strcpy( quest[contador], perg); // Adiciona quest?o carregada ao question?rio
        contador++;                     // Conta mais uma quest?o carregada
    }
    fclose( apf);
    return contador;    // retorna quantidade de quest?es carregadas
}

/** GuardarQuestoes
 * Funcao que guarda as quest?es em ficheiro
 * Par?metros: question?rio e nome do ficheiro
 */
int GuardarQuestoes( char quest[][TAMQST], const char file[TAMTEX])
{
    FILE *apf;
    int i, contador;

    // Abre ficheiro para escrita em modo texto
    apf = fopen( file, "w");
    if( !apf)
    {
        return 0; // Nao foi possivel abrir o ficheiro para escrita
    }
    // Guarda quest?es atuais em ficheiro
    contador = 0;
    for( i=0; i<MAXQST; i++)
    {
        // Se a quest?o n?o estiver vazia, guarda-a em ficheiro
        if( strcmp( quest[i], "") != 0)
        {
            fprintf(apf, "%s\n", quest[i]);
            contador++;
        }
    }
    fclose( apf);
    return contador;
}
