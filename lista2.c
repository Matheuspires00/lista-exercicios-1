#include <stdio.h>
#include <string.h>

void exercicio01() {
    int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    printf("Digite o valor de C: ");
    scanf("%d", &c);

    if (a + b < c) {
        printf("A soma de A + B (%d) e menor que C (%d)\n", a + b, c);
    } else {
        printf("A soma de A + B (%d) NAO e menor que C (%d)\n", a + b, c);
    }
}

void exercicio02() {
    char nome[100];
    char sexo;
    char estadoCivil[20];
    int tempoCasamento;

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("Digite o estado civil (ex: SOLTEIRA, CASADA): ");
    scanf(" %s", estadoCivil);

    if (sexo == 'F' && strcmp(estadoCivil, "CASADA") == 0) {
        printf("Digite o tempo de casamento (em anos): ");
        scanf("%d", &tempoCasamento);
        printf("\nNome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Estado civil: %s\n", estadoCivil);
        printf("Tempo de casamento: %d anos\n", tempoCasamento);
    } else {
        printf("\nNome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Estado civil: %s\n", estadoCivil);
    }
}

void exercicio03() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("%d e PAR\n", numero);
    } else {
        printf("%d e IMPAR\n", numero);
    }
}

void exercicio04() {
    int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    if (a == b) {
        c = a + b;
    } else {
        c = a * b;
    }

    printf("O resultado armazenado em C e: %d\n", c);
}

void exercicio05() {
    float numero, resultado;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    if (numero > 0) {
        resultado = numero * 2;
        printf("O numero e positivo. O dobro e: %.2f\n", resultado);
    } else if (numero < 0) {
        resultado = numero * 3;
        printf("O numero e negativo. O triplo e: %.2f\n", resultado);
    } else {
        printf("O numero e zero. Nao ha calculo a ser feito.\n");
    }
}

void exercicio06() {
    int valor1, valor2;

    printf("Digite o primeiro valor logico (1 = VERDADEIRO, 0 = FALSO): ");
    scanf("%d", &valor1);
    printf("Digite o segundo valor logico (1 = VERDADEIRO, 0 = FALSO): ");
    scanf("%d", &valor2);

    if (valor1 == 1 && valor2 == 1) {
        printf("Ambos os valores sao VERDADEIROS\n");
    } else if (valor1 == 0 && valor2 == 0) {
        printf("Ambos os valores sao FALSOS\n");
    } else {
        printf("Os valores sao diferentes entre si\n");
    }
}

void exercicio07() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        resultado = numero + 5;
    } else {
        resultado = numero + 8;
    }

    printf("Resultado da operacao: %d\n", resultado);
}

void exercicio08() {
    int a, b, c;

    printf("Digite tres valores inteiros diferentes entre si:\n");
    printf("Valor 1: ");
    scanf("%d", &a);
    printf("Valor 2: ");
    scanf("%d", &b);
    printf("Valor 3: ");
    scanf("%d", &c);

    if (a > b && a > c) {
        if (b > c) {
            printf("Ordem decrescente: %d, %d, %d\n", a, b, c);
        } else {
            printf("Ordem decrescente: %d, %d, %d\n", a, c, b);
        }
    } else if (b > a && b > c) {
        if (a > c) {
            printf("Ordem decrescente: %d, %d, %d\n", b, a, c);
        } else {
            printf("Ordem decrescente: %d, %d, %d\n", b, c, a);
        }
    } else {
        if (a > b) {
            printf("Ordem decrescente: %d, %d, %d\n", c, a, b);
        } else {
            printf("Ordem decrescente: %d, %d, %d\n", c, b, a);
        }
    }
}

void exercicio09() {
    float altura, pesoIdeal;
    char sexo;

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo);

    if (sexo == 'M' || sexo == 'm') {
        pesoIdeal = (72.7 * altura) - 58;
        printf("Peso ideal: %.2f kg\n", pesoIdeal);
    } else if (sexo == 'F' || sexo == 'f') {
        pesoIdeal = (62.1 * altura) - 44.7;
        printf("Peso ideal: %.2f kg\n", pesoIdeal);
    } else {
        printf("Sexo invalido\n");
    }
}

void exercicio10() {
    float peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);
    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("IMC calculado: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Condicao: Abaixo do peso\n");
    } else if (imc < 25) {
        printf("Condicao: Peso normal\n");
    } else if (imc < 30) {
        printf("Condicao: Acima do peso\n");
    } else {
        printf("Condicao: Obeso\n");
    }
}

void exercicio11() {
    float preco, valorFinal;
    int codigo;

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);

    printf("Digite o codigo da condicao de pagamento:\n");
    printf("1 - A vista em dinheiro ou cheque (10%% de desconto)\n");
    printf("2 - A vista no cartao de credito (15%% de desconto)\n");
    printf("3 - Duas parcelas, sem juros\n");
    printf("4 - Duas parcelas, com 10%% de acrescimo\n");
    printf("Codigo: ");
    scanf("%d", &codigo);

    if (codigo == 1) {
        valorFinal = preco - (preco * 0.10);
        printf("Valor final a pagar: %.2f\n", valorFinal);
    } else if (codigo == 2) {
        valorFinal = preco - (preco * 0.15);
        printf("Valor final a pagar: %.2f\n", valorFinal);
    } else if (codigo == 3) {
        valorFinal = preco;
        printf("Valor final a pagar: %.2f\n", valorFinal);
    } else if (codigo == 4) {
        valorFinal = preco + (preco * 0.10);
        printf("Valor final a pagar: %.2f\n", valorFinal);
    } else {
        printf("Codigo de pagamento invalido\n");
    }
}

void exercicio12() {
    int idAluno;
    float nota1, nota2, nota3, mediaExercicios, ma;
    char conceito;
    char situacao[10];

    printf("Digite o numero de identificacao do aluno: ");
    scanf("%d", &idAluno);
    printf("Digite a nota 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota 3: ");
    scanf("%f", &nota3);
    printf("Digite a media dos exercicios: ");
    scanf("%f", &mediaExercicios);

    ma = (nota1 + nota2 * 2 + nota3 * 3 + mediaExercicios) / 7;

    if (ma >= 90) {
        conceito = 'A';
    } else if (ma >= 75) {
        conceito = 'B';
    } else if (ma >= 60) {
        conceito = 'C';
    } else if (ma >= 40) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }

    if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
        sprintf(situacao, "Aprovado");
    } else {
        sprintf(situacao, "Reprovado");
    }

    printf("\n--- Resultado ---\n");
    printf("Numero de identificacao: %d\n", idAluno);
    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);
    printf("Media dos exercicios: %.2f\n", mediaExercicios);
    printf("Media de aproveitamento: %.2f\n", ma);
    printf("Conceito obtido: %c\n", conceito);
    printf("Situacao final: %s\n", situacao);
}

void exercicio13() {
    float velocidadeMaxima, velocidadeRegistrada, percentualExcedido;
    char classificacao[80];

    printf("Digite a velocidade maxima permitida na via (km/h): ");
    scanf("%f", &velocidadeMaxima);
    printf("Digite a velocidade registrada do veiculo (km/h): ");
    scanf("%f", &velocidadeRegistrada);

    if (velocidadeRegistrada <= velocidadeMaxima) {
        printf("\nLimite da via: %.2f km/h\n", velocidadeMaxima);
        printf("Velocidade registrada: %.2f km/h\n", velocidadeRegistrada);
        printf("Nao houve infracao.\n");
    } else {
        percentualExcedido = ((velocidadeRegistrada - velocidadeMaxima) / velocidadeMaxima) * 100;

        if (percentualExcedido <= 20) {
            sprintf(classificacao, "Infracao media");
        } else if (percentualExcedido <= 50) {
            sprintf(classificacao, "Infracao grave");
        } else {
            sprintf(classificacao, "Infracao gravissima");
        }

        if (velocidadeRegistrada > 120) {
            strcat(classificacao, " - ALERTA: velocidade extremamente elevada");
        }

        printf("\nLimite da via: %.2f km/h\n", velocidadeMaxima);
        printf("Velocidade registrada: %.2f km/h\n", velocidadeRegistrada);
        printf("Percentual excedido: %.2f%%\n", percentualExcedido);
        printf("Classificacao final: %s\n", classificacao);
    }
}

void exercicio14() {
    int codigo;

    printf("--- CARDAPIO ---\n");
    printf("1 - Hamburguer com fritas   R$ 28,00\n");
    printf("2 - File de frango grelhado R$ 32,00\n");
    printf("3 - Lasanha a bolonhesa     R$ 35,00\n");
    printf("4 - File de peixe com arroz R$ 42,00\n");
    printf("5 - Salada especial         R$ 25,00\n");

    printf("\nDigite o codigo do prato desejado: ");
    scanf("%d", &codigo);

    switch (codigo) {
        case 1:
            printf("Prato escolhido: Hamburguer com fritas - R$ 28,00\n");
            break;
        case 2:
            printf("Prato escolhido: File de frango grelhado - R$ 32,00\n");
            break;
        case 3:
            printf("Prato escolhido: Lasanha a bolonhesa - R$ 35,00\n");
            break;
        case 4:
            printf("Prato escolhido: File de peixe com arroz - R$ 42,00\n");
            break;
        case 5:
            printf("Prato escolhido: Salada especial - R$ 25,00\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }
}

int main() {
    int opcao;

    do {
        printf("\n=========================================\n");
        printf(" LISTA DE EXERCICIOS 2 - ESTRUTURAS COND.\n");
        printf("=========================================\n");
        printf(" 1  - Soma A+B menor que C\n");
        printf(" 2  - Dados pessoais e tempo de casamento\n");
        printf(" 3  - Par ou impar\n");
        printf(" 4  - Soma ou multiplicacao de A e B\n");
        printf(" 5  - Dobro ou triplo de um numero\n");
        printf(" 6  - Comparacao de valores logicos\n");
        printf(" 7  - Soma 5 ou 8 conforme paridade\n");
        printf(" 8  - Tres valores em ordem decrescente\n");
        printf(" 9  - Peso ideal por sexo\n");
        printf(" 10 - Calculo de IMC\n");
        printf(" 11 - Valor a pagar por condicao de pagamento\n");
        printf(" 12 - Media de aproveitamento e conceito\n");
        printf(" 13 - Multa de transito\n");
        printf(" 14 - Cardapio de restaurante (switch)\n");
        printf(" 0  - Sair\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:  exercicio01(); break;
            case 2:  exercicio02(); break;
            case 3:  exercicio03(); break;
            case 4:  exercicio04(); break;
            case 5:  exercicio05(); break;
            case 6:  exercicio06(); break;
            case 7:  exercicio07(); break;
            case 8:  exercicio08(); break;
            case 9:  exercicio09(); break;
            case 10: exercicio10(); break;
            case 11: exercicio11(); break;
            case 12: exercicio12(); break;
            case 13: exercicio13(); break;
            case 14: exercicio14(); break;
            case 0:  printf("Encerrando o programa...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n"); break;
        }

    } while (opcao != 0);

    return 0;
}
