#include <stdio.h>

/* ---------- Exercicio 1 ---------- */
void exercicio1() {
    int A[6] = {1, 0, 5, -2, -5, 7};
    int soma;
    int i;

    soma = A[0] + A[1] + A[5];
    printf("Soma de A[0] + A[1] + A[5] = %d\n", soma);

    A[4] = 100;

    printf("Vetor A apos a modificacao:\n");
    for (i = 0; i < 6; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }
}

/* ---------- Exercicio 2 ---------- */
void exercicio2() {
    int valores[6];
    int i;

    for (i = 0; i < 6; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    printf("\nValores lidos:\n");
    for (i = 0; i < 6; i++) {
        printf("%d\n", valores[i]);
    }
}

/* ---------- Exercicio 3 ---------- */
void exercicio3() {
    const int TAM = 10;
    float numeros[10];
    float quadrados[10];
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &numeros[i]);
        quadrados[i] = numeros[i] * numeros[i];
    }

    printf("\nVetor original:\n");
    for (i = 0; i < TAM; i++) {
        printf("%.2f\n", numeros[i]);
    }

    printf("\nVetor com os quadrados:\n");
    for (i = 0; i < TAM; i++) {
        printf("%.2f\n", quadrados[i]);
    }
}

/* ---------- Exercicio 4 ---------- */
void exercicio4() {
    const int TAM = 8;
    int vetor[8];
    int x, y;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Digite a posicao X (0 a 7): ");
    scanf("%d", &x);
    printf("Digite a posicao Y (0 a 7): ");
    scanf("%d", &y);

    printf("Soma dos valores nas posicoes %d e %d = %d\n", x, y, vetor[x] + vetor[y]);
}

/* ---------- Exercicio 5 ---------- */
void exercicio5() {
    const int TAM = 10;
    int vetor[10];
    int i, contPares = 0;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0) {
            contPares++;
        }
    }

    printf("Quantidade de valores pares: %d\n", contPares);
}

/* ---------- Exercicio 6 ---------- */
void exercicio6() {
    const int TAM = 10;
    int vetor[10];
    int i, maior, menor;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 1; i < TAM; i++) {
        if (vetor[i] > maior) maior = vetor[i];
        if (vetor[i] < menor) menor = vetor[i];
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
}

/* ---------- Exercicio 7 ---------- */
void exercicio7() {
    const int TAM = 10;
    int vetor[10];
    int i, maior, posMaior;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    posMaior = 0;

    for (i = 1; i < TAM; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posMaior = i;
        }
    }

    printf("\nVetor:\n");
    for (i = 0; i < TAM; i++) {
        printf("%d\n", vetor[i]);
    }

    printf("\nMaior elemento: %d\n", maior);
    printf("Posicao do maior elemento: %d\n", posMaior);
}

/* ---------- Exercicio 8 ---------- */
void exercicio8() {
    const int TAM = 6;
    int vetor[6];
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nValores na ordem inversa:\n");
    for (i = TAM - 1; i >= 0; i--) {
        printf("%d\n", vetor[i]);
    }
}

/* ---------- Exercicio 9 ---------- */
void exercicio9() {
    const int TAM = 6;
    int vetor[6];
    int i;

    for (i = 0; i < TAM; i++) {
        do {
            printf("Digite um valor par %d: ", i + 1);
            scanf("%d", &vetor[i]);
            if (vetor[i] % 2 != 0) {
                printf("Valor invalido, digite um numero par.\n");
            }
        } while (vetor[i] % 2 != 0);
    }

    printf("\nValores pares na ordem inversa:\n");
    for (i = TAM - 1; i >= 0; i--) {
        printf("%d\n", vetor[i]);
    }
}

/* ---------- Exercicio 10 ---------- */
void exercicio10() {
    const int TAM = 15;
    float notas[15];
    float soma = 0, media;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / TAM;

    printf("\nMedia geral da turma: %.2f\n", media);
}

/* ---------- Exercicio 11 ---------- */
void exercicio11() {
    const int TAM = 10;
    float vetor[10];
    float somaPositivos = 0;
    int contNegativos = 0;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%f", &vetor[i]);

        if (vetor[i] < 0) {
            contNegativos++;
        } else if (vetor[i] > 0) {
            somaPositivos += vetor[i];
        }
    }

    printf("\nQuantidade de numeros negativos: %d\n", contNegativos);
    printf("Soma dos numeros positivos: %.2f\n", somaPositivos);
}

/* ---------- Exercicio 12 ---------- */
void exercicio12() {
    const int TAM = 5;
    float vetor[5];
    float soma = 0, media, maior, menor;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 1; i < TAM; i++) {
        if (vetor[i] > maior) maior = vetor[i];
        if (vetor[i] < menor) menor = vetor[i];
    }

    media = soma / TAM;

    printf("\nValores lidos:\n");
    for (i = 0; i < TAM; i++) {
        printf("%.2f\n", vetor[i]);
    }

    printf("\nMaior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Media: %.2f\n", media);
}

/* ---------- Exercicio 13 ---------- */
void exercicio13() {
    const int TAM = 5;
    float vetor[5];
    float maior, menor;
    int posMaior, posMenor;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];
    posMaior = 0;
    posMenor = 0;

    for (i = 1; i < TAM; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posMaior = i;
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
            posMenor = i;
        }
    }

    printf("\nO maior valor (%.2f) esta na posicao %d\n", maior, posMaior);
    printf("O menor valor (%.2f) esta na posicao %d\n", menor, posMenor);
}

/* ---------- Menu principal ---------- */
int main() {
    int opcao;

    printf("=== Lista de Exercicios - Vetores em C ===\n");
    printf("Digite o numero do exercicio que deseja executar (1 a 13): ");
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
        case 11: exercicio11(); break;
        case 12: exercicio12(); break;
        case 13: exercicio13(); break;
        default:
            printf("Opcao invalida. Escolha um numero de 1 a 13.\n");
    }

    return 0;
}
