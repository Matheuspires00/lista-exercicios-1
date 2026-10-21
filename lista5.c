#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const float PI = 3.1414592;

/* ---------- Exercicio 1 ---------- */
float maior(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

void exercicio1() {
    float n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("O maior numero e: %.2f\n", maior(n1, n2));
}

/* ---------- Exercicio 2 ---------- */
void mostrarMes(int numero) {
    const char *meses[] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho",
                           "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (numero < 1 || numero > 12) {
        printf("Numero invalido, digite de 1 a 12.\n");
    } else {
        printf("%s - %d dias\n", meses[numero - 1], dias[numero - 1]);
    }
}

void exercicio2() {
    int numero;

    printf("Digite o numero do mes (1 a 12): ");
    scanf("%d", &numero);

    mostrarMes(numero);
}

/* ---------- Exercicio 3 ---------- */
float fahrenheitParaCelsius(float f) {
    float c = (f - 32.0) * (5.0 / 9.0);
    return c;
}

void exercicio3() {
    float f;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &f);

    printf("Temperatura em Celsius: %.2f\n", fahrenheitParaCelsius(f));
}

/* ---------- Exercicio 4 ---------- */
float volumeCilindro(float altura, float raio) {
    return PI * raio * raio * altura;
}

void exercicio4() {
    float altura, raio;

    printf("Digite a altura do cilindro: ");
    scanf("%f", &altura);
    printf("Digite o raio do cilindro: ");
    scanf("%f", &raio);

    printf("Volume do cilindro: %.2f\n", volumeCilindro(altura, raio));
}

/* ---------- Exercicio 5 ---------- */
float volumeEsfera(float raio) {
    return (4.0 / 3.0) * PI * raio * raio * raio;
}

void exercicio5() {
    float raio;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    printf("Volume da esfera: %.2f\n", volumeEsfera(raio));
}

/* ---------- Exercicio 6 ---------- */
char menuPagamento() {
    char opcao;

    printf("\nOpcoes de pagamento:\n");
    printf("a) A vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preco da etiqueta)\n");
    printf("c) De 3 ate 10 vezes com 3%% de juros ao mes (so acima de R$ 100,00)\n");
    printf("Escolha a opcao: ");
    scanf(" %c", &opcao);

    return tolower(opcao);
}

void pagamentoAVista(float total) {
    float valor = total * 0.90;
    printf("A vista com desconto: R$ %.2f\n", valor);
}

void pagamentoDuasVezes(float total) {
    float parcela = total / 2;
    printf("2 parcelas de R$ %.2f (total R$ %.2f)\n", parcela, total);
}

void pagamentoParcelado(float total) {
    int parcelas, i;
    float totalComJuros, valorParcela;

    if (total <= 100) {
        printf("Parcelamento de 3 a 10 vezes so vale para compras acima de R$ 100,00.\n");
        return;
    }

    printf("Em quantas vezes (3 a 10)? ");
    scanf("%d", &parcelas);

    if (parcelas < 3 || parcelas > 10) {
        printf("Quantidade de parcelas invalida.\n");
        return;
    }

    totalComJuros = total;
    for (i = 0; i < parcelas; i++) {
        totalComJuros *= 1.03;
    }
    valorParcela = totalComJuros / parcelas;

    printf("%d parcelas de R$ %.2f (total R$ %.2f)\n", parcelas, valorParcela, totalComJuros);
}

void exercicio6() {
    float total;
    char opcao;

    printf("Digite o total gasto pelo cliente: R$ ");
    scanf("%f", &total);

    opcao = menuPagamento();

    if (opcao == 'a') {
        pagamentoAVista(total);
    } else if (opcao == 'b') {
        pagamentoDuasVezes(total);
    } else if (opcao == 'c') {
        pagamentoParcelado(total);
    } else {
        printf("Opcao invalida.\n");
    }
}

/* ---------- Exercicio 7 ---------- */
void locacoesGratis(int A[], int gratis[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        gratis[i] = A[i] / 15;
    }
}

void exercicio7() {
    const int TAM = 500;
    int A[500], gratis[500];
    int i;

    for (i = 0; i < TAM; i++) {
        A[i] = rand() % 101;
    }

    locacoesGratis(A, gratis, TAM);

    printf("Primeiros 10 clientes (filmes retirados / locacoes gratis):\n");
    for (i = 0; i < 10; i++) {
        printf("Cliente %d: %d filmes -> %d gratis\n", i + 1, A[i], gratis[i]);
    }
}

/* ---------- Exercicio 8 ---------- */
void trocarMatriz(int A[10][10]) {
    int i, j, aux;

    /* linha 2 com linha 8 */
    for (j = 0; j < 10; j++) {
        aux = A[1][j];
        A[1][j] = A[7][j];
        A[7][j] = aux;
    }

    /* coluna 4 com coluna 10 */
    for (i = 0; i < 10; i++) {
        aux = A[i][3];
        A[i][3] = A[i][9];
        A[i][9] = aux;
    }

    /* diagonal principal com a secundaria */
    for (i = 0; i < 10; i++) {
        aux = A[i][i];
        A[i][i] = A[i][9 - i];
        A[i][9 - i] = aux;
    }

    /* linha 5 com coluna 10 */
    for (j = 0; j < 10; j++) {
        aux = A[4][j];
        A[4][j] = A[j][9];
        A[j][9] = aux;
    }
}

void exercicio8() {
    int matriz[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matriz[i][j] = i * 10 + j + 1;
        }
    }

    printf("Matriz original:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    trocarMatriz(matriz);

    printf("\nMatriz alterada:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

/* ---------- Exercicio 9 ---------- */
void somarColunas(int M[61][10]) {
    int i, j, soma;

    for (j = 0; j < 10; j++) {
        soma = 0;
        for (i = 0; i < 60; i++) {
            soma += M[i][j];
        }
        M[60][j] = soma;
    }
}

void exercicio9() {
    int M[61][10];
    int i, j;

    for (i = 0; i < 60; i++) {
        for (j = 0; j < 10; j++) {
            M[i][j] = rand() % 9 + 1;
        }
    }
    for (j = 0; j < 10; j++) {
        M[60][j] = 0;
    }

    somarColunas(M);

    printf("Soma de cada coluna (61a linha):\n");
    for (j = 0; j < 10; j++) {
        printf("Coluna %d: %d\n", j + 1, M[60][j]);
    }
}

/* ---------- Exercicio 10 ---------- */
int diasNoMes(int mes, int ano) {
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) {
        return 29;
    }
    return dias[mes - 1];
}

void calcularIdade(int dia, int mes, int ano) {
    time_t agora = time(NULL);
    struct tm *hoje = localtime(&agora);
    int diaH = hoje->tm_mday;
    int mesH = hoje->tm_mon + 1;
    int anoH = hoje->tm_year + 1900;

    int anos = anoH - ano;
    int meses = mesH - mes;
    int dias = diaH - dia;
    int mesAnt, anoAnt;
    struct tm nasc = {0};
    time_t tNasc;
    long totalDias;

    if (dias < 0) {
        meses--;
        mesAnt = mesH - 1;
        anoAnt = anoH;
        if (mesAnt == 0) {
            mesAnt = 12;
            anoAnt--;
        }
        dias += diasNoMes(mesAnt, anoAnt);
    }

    if (meses < 0) {
        anos--;
        meses += 12;
    }

    nasc.tm_mday = dia;
    nasc.tm_mon = mes - 1;
    nasc.tm_year = ano - 1900;
    nasc.tm_hour = 12;
    tNasc = mktime(&nasc);
    totalDias = (long)(difftime(agora, tNasc) / 86400);

    printf("Idade: %d anos, %d meses e %d dias\n", anos, meses, dias);
    printf("Total de dias vividos: %ld\n", totalDias);
}

void exercicio10() {
    int dia, mes, ano;

    printf("Digite o dia de nascimento: ");
    scanf("%d", &dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
        printf("Data invalida.\n");
    } else {
        calcularIdade(dia, mes, ano);
    }
}

/* ---------- Menu principal ---------- */
int main() {
    int opcao;

    srand(time(NULL));

    printf("=== Lista de Exercicios - Funcoes em C ===\n");
    printf("Digite o numero do exercicio que deseja executar (1 a 10): ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
        case 1:  exercicio1();  break;
        case 2:  exercicio2();  break;
        case 3:  exercicio3();  break;
        case 4:  exercicio4();  break;
        case 5:  exercicio5();  break;
        case 6:  exercicio6();  break;
        case 7:  exercicio7();  break;
        case 8:  exercicio8();  break;
        case 9:  exercicio9();  break;
        case 10: exercicio10(); break;
        default:
            printf("Opcao invalida. Escolha um numero de 1 a 10.\n");
    }

    return 0;
}
