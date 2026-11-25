#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

float calcular_media(float n1, float n2) {
    return (n1 + n2) / 2;
}

int main() {
    Aluno alunos[10];
    float soma_geral = 0;
    float maior_media = -1, menor_media = 11;
    int idx_maior = 0, idx_menor = 0;
    int acima_media_geral = 0;

    printf("=== CADASTRO DE ALUNOS ===\n");
    for (int i = 0; i < 10; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcular_media(alunos[i].nota1, alunos[i].nota2);
        soma_geral += alunos[i].media;

        if (i == 0 || alunos[i].media > maior_media) {
            maior_media = alunos[i].media;
            idx_maior = i;
        }
        if (i == 0 || alunos[i].media < menor_media) {
            menor_media = alunos[i].media;
            idx_menor = i;
        }
    }

    float media_geral = soma_geral / 10.0;
    for (int i = 0; i < 10; i++) {
        if (alunos[i].media > media_geral) {
            acima_media_geral++;
        }
    }

    printf("\n\n=== RELATORIO DA TURMA ===\n");
    printf("Media geral da turma: %.2f\n", media_geral);
    printf("Maior media: %.2f (%s)\n", maior_media, alunos[idx_maior].nome);
    printf("Menor media: %.2f (%s)\n", menor_media, alunos[idx_menor].nome);
    printf("Alunos acima da media geral: %d\n", acima_media_geral);

    printf("\n--- Situacao Final de Cada Aluno ---\n");
    for (int i = 0; i < 10; i++) {
        char *situacao = (alunos[i].media >= 6.0) ? "Aprovado" : "Reprovado";
        printf("Matricula: %d | Nome: %-15s | Media: %.2f | Situacao: %s\n",
               alunos[i].matricula,
               alunos[i].nome,
               alunos[i].media,
               situacao);
    }

    return 0;
}
