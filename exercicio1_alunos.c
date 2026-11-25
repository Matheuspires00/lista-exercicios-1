#include <stdio.h>

struct aluno {
    int matricula;
    char nome[50];
    float nota1, nota2, media;
};

float calculaMedia(float a, float b) {
    return (a + b) / 2;
}

int main() {
    struct aluno turma[10];
    int i, acima = 0, posMaior = 0, posMenor = 0;
    float soma = 0, mediaGeral;

    for (i = 0; i < 10; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &turma[i].matricula);
        printf("Nome: ");
        scanf(" %49[^\n]", turma[i].nome);
        printf("Nota 1: ");
        scanf("%f", &turma[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &turma[i].nota2);

        turma[i].media = calculaMedia(turma[i].nota1, turma[i].nota2);
        soma = soma + turma[i].media;

        // guarda a posicao do maior e do menor
        if (turma[i].media > turma[posMaior].media) {
            posMaior = i;
        }
        if (turma[i].media < turma[posMenor].media) {
            posMenor = i;
        }
    }

    mediaGeral = soma / 10;

    for (i = 0; i < 10; i++) {
        if (turma[i].media > mediaGeral) {
            acima++;
        }
    }

    printf("\n===== RELATORIO =====\n");
    printf("Media geral da turma: %.2f\n", mediaGeral);
    printf("Maior media: %.2f - %s\n", turma[posMaior].media, turma[posMaior].nome);
    printf("Menor media: %.2f - %s\n", turma[posMenor].media, turma[posMenor].nome);
    printf("Alunos acima da media geral: %d\n", acima);

    printf("\n--- Situacao dos alunos ---\n");
    for (i = 0; i < 10; i++) {
        printf("%d | %s | %.2f | ", turma[i].matricula, turma[i].nome, turma[i].media);
        if (turma[i].media >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}
