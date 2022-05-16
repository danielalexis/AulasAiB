/**
    Quiz de Cidadania
    Autores:
        Daniel Pereira
        Hugo Cordeiro
        Vasco Rego
        Mariana Peixoto
    Data: 28/02/2022

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>


#define limparEcra() system("cls");
#define TAMSCORE 10
#define TAMTEXT 256
#define TAMQST 256
#define MAXQST 256


int max = 10; // Numero de perguntas do quiz ( Para usar nos loops "for" i<max )
int respostasCertas, resultado; // Variaveis para calcular o resultado no final
int totalPerguntas, totalScore;

char quiz[MAXQST][TAMQST]; // Array bidimensional

const char perguntasFicheiro[] = "Quest_Cidadania.txt";    // Ficheiro onde est o guardadas perguntas e respostas
const char scoreFicheiro[] = "score.dat";            // Ficheiro onde est o guardadas as pontua  es

struct score
{
    char nome[32];
    int pontos;
};
typedef struct score tabScore;

tabScore tabela[TAMSCORE];
tabScore jogador;

int opcaoFinal;

// Declara  o de fun  es
void menuInicial(void);
int menuFinal(void);

void iniciarArray(char[][TAMQST]);
void iniciarScore(tabScore[TAMSCORE]);

int carregarPerguntas(const char *, char[][TAMQST]);
int carregarScore(const char *, tabScore[TAMSCORE]);

int guardarScore(tabScore[TAMSCORE], const char *);
void registarScore(tabScore *, tabScore[TAMSCORE]);

int executarQuiz(char[][TAMQST], int, int);
void MostrarScore(tabScore[TAMSCORE]);


int main()
{
    setlocale(LC_ALL,""); // Permitir a escrita em portugu s

    menuInicial();

    do{
        iniciarArray(quiz);
        iniciarScore(tabela);

        totalPerguntas = carregarPerguntas(perguntasFicheiro, quiz);
        totalScore = carregarScore(scoreFicheiro, tabela);

        executarQuiz(quiz, totalPerguntas, max);
        registarScore(&jogador, tabela);

        limparEcra();
        printf("Acertaste %i%% das perguntas! \nConseguiste %i pontos.", resultado, jogador.pontos);
        guardarScore(tabela, scoreFicheiro);

        menuFinal();
    }while(opcaoFinal == 1);

    return 0;
}

void menuInicial(void)
{
    printf("|------------------------------------|\n");
    printf("|           Quiz de Cidadania        |\n");
    printf("|------------------------------------|\n");
    printf("Nome: ");
    gets(jogador.nome);

    printf("\nPressiona ENTER para comecar a jogar\n");

    getchar(); // Server para o utilizador pressionar o ENTER e o programa continuar na normalidade
}



// Fun  es de inicializa  o
void iniciarArray(char quest[][TAMQST])
{
    int i;

    for( i=0; i<MAXQST; i++) {
        strcpy( quest[i], ""); // Copia uma string vazia para as questões para inicializar as questões dos quiz
    }
}

void iniciarScore(tabScore tab[TAMSCORE])
{
    int i;

    for( i=0; i<TAMSCORE; i++)
    {
        strcpy(tab[i].nome, ""); // Copia uma string vazia para o nome para inicializar o nome do jogador
        tab[i].pontos = 0;
    }
}



// Fun  es de leitura
int carregarPerguntas(const char file[TAMTEXT], char quest[][TAMQST])
{
    FILE *apf;
    char perg[TAMQST];
    int contador;

    apf = fopen(file, "r"); // Abre o ficheiro em leitura
    if(!apf)
    {
        return 0;
    }
    contador = 0;
    while(fgets(perg, TAMQST, apf) != NULL)
    {
        perg[strlen(perg)-1] = '\0';
        strcpy(quest[contador], perg); // Copia a pergunta para o seu sitio
        contador++;
    }
    fclose(apf);
    return contador;
}

int carregarScore(const char *fic, tabScore tab[TAMSCORE])
{
    FILE *apf;
    tabScore classif;
    int contador;

    apf = fopen(fic, "r");
    if(!apf)
    {
        return 0;
    }
    contador = 0;
    while(fread( &classif, sizeof( tabScore), 1, apf) > 0)
    {
        strcpy( tab[contador].nome, classif.nome); // Coloca o nome no sitio correto
        tab[contador].pontos = classif.pontos; // Define os pontos
        contador++;
    }
    fclose( apf);
    return contador;
}



// Função para guardar as pontuações no ficheiro "score.dat"
int guardarScore(tabScore tab[TAMSCORE], const char *fic)
{
    FILE *apf;
    int i, contador;

    apf = fopen( fic, "w"); // Ficheiro em modo binário
    if( !apf)
    {
        return 0;
    }

    contador = 0;
    for( i=0; i<TAMSCORE; i++)
    {
        if( strcmp( tab[i].nome, "") != 0)
        {
            fwrite( &tab[i], sizeof( tabScore), 1, apf);
            contador++;
        }
    }
    fclose( apf);
    return contador;
}


// Função principal - Onde o quiz é executado
int executarQuiz(char quest[][TAMQST], int total, int max)
{
    srand(time(NULL));

    char pergunta[TAMTEXT], resp1[TAMTEXT], resp2[TAMTEXT], resp3[TAMTEXT], resp4[TAMTEXT]; // (string) Inicia as variaveis de texto da pergunta e das respostas para cada questão.
    char aux[TAMQST]; // Variavel auxiliar
    respostasCertas = 0;
    char separador[] = "|"; // As perguntas, as respostas e o número da resposta certa estão separadas por este símbolo no ficheiro das perguntas
    char *aptd;
    int i, indice, solucao, numResposta;

    for(i=0; i<max; i++) // Baralhar as perguntas
    {
        indice = rand() % total;
        strcpy(aux, quest[i]);
        strcpy(quest[i], quest[indice]);
        strcpy(quest[indice], aux);
    }

    for(i=0; i<max; i++)
    {
        limparEcra();
        aptd = strtok(quest[i], separador);
        printf("%s", quest[i]);
        strcpy(pergunta, aptd);
        aptd = strtok(NULL, separador);
        strcpy(resp1, aptd);
        aptd = strtok(NULL, separador);
        strcpy(resp2, aptd);
        aptd = strtok(NULL, separador);
        strcpy(resp3, aptd);
        aptd = strtok(NULL, separador);
        strcpy(resp4, aptd);
        aptd = strtok(NULL, separador);
        solucao = atoi(aptd);



        printf("%s", pergunta);
        printf("\n_____________________________________\n");
        printf("\n1 - %s", resp1);
        printf("\n2 - %s", resp2);
        printf("\n3 - %s", resp3);
        printf("\n4 - %s", resp4);
        printf("\n_____________________________________");


        do{
            char buffer[255];

            printf("\nResposta: ");

            scanf("%s", buffer);
            numResposta = atoi(buffer);

            if(numResposta > 0 && numResposta < 5)
            {
                if(numResposta == solucao)
                {
                    respostasCertas++; // Somar 1 unidade a cada resposta certa para depois calcular a pontuação correta
                }

            }
            else
            {
                printf("Opcao invalida. \n");
            }
        }while(numResposta < 1 || numResposta > 4);

    }

    resultado = respostasCertas * 100 / max;
    jogador.pontos = resultado/10;

    return resultado;
}

void registarScore(tabScore *jog, tabScore tab[TAMSCORE])
{
    int i, j, h, comp;

    i = 0;

    while(i<TAMSCORE && strcmp(jogador.nome, tab[i].nome) != 0)
    {
        i++;
    }

    if(i<TAMSCORE)
    {
        if(jogador.pontos > tab[i].pontos)
        {
            tab[i].pontos = jog->pontos;
        }
    }
    else
    {
        i = 0;
        while(i<TAMSCORE && tab[i].pontos > jog->pontos)
        {
            i++;
        }
        if(tab[i].pontos == 0) // Entrada vazia
        {
            strcpy(tab[i].nome, jog->nome);
            tab[i].pontos = jog->pontos;
        }
        else
        {

            for( j=TAMSCORE-1; j>i; j--)
            {
                strcpy( tab[j].nome, tab[j-1].nome);
                tab[j].pontos = tab[j-1].pontos;
            }

            strcpy( tab[i].nome, jog->nome);
            tab[i].pontos = jog->pontos;
        }
    }
}

void mostrarScore(tabScore tab[TAMSCORE])
{
    limparEcra();

    int i;

    printf("\n---\t--------------------\t---\n");
    printf("Pos\t%-20s\t%s\n", "Nome", "Pts");
    printf("---\t--------------------\t---\n");
    for( i=0; i<TAMSCORE; i++)
    {
        if( strcmp( tab[i].nome, "") != 0) // Entrada n o vazia
        {
            printf("%3i\t%-20s\t%3i\n", i+1, tab[i].nome, tab[i].pontos);
        }
    }
    printf("---\t--------------------\t---\n\n");

    //sleep(3);
    menuFinal();
}



// Menu final onde pergunta ao  utilizador se quer voltar a jogar
int menuFinal(void)
{
    printf("\n_____________________________________");
    printf("\nQueres tentar outra vez?");
    printf("\n\n   1. Sim");
    printf("\n   2. Nao");
    printf("\n   3. Mostrar tabela dos melhores resultados");
    printf("\n_____________________________________\n");

    scanf("%i", &opcaoFinal);

    if(opcaoFinal == 3)
    {
        mostrarScore(tabela);
    }
    else
    {
        return opcaoFinal;
    }
}

