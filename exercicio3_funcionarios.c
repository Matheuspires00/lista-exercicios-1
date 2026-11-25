#include <stdio.h>
#include <string.h>

struct funcionario {
    int codigo;
    char nome[50];
    char cargo[30];
    float salario;
    int horasExtras;
};

int main() {
    struct funcionario f[8];
    int i;
    float valorHora, extras, bruto, desconto, liquido;
    float totalFolha = 0, maiorLiquido = 0;
    char nomeMaior[50];

    for (i = 0; i < 8; i++) {
        printf("\nFuncionario %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &f[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", f[i].nome);
        printf("Cargo: ");
        scanf(" %29[^\n]", f[i].cargo);
        printf("Salario base: ");
        scanf("%f", &f[i].salario);
        printf("Horas extras: ");
        scanf("%d", &f[i].horasExtras);
    }

    printf("\n===== FOLHA DE PAGAMENTO =====\n");
    for (i = 0; i < 8; i++) {
        valorHora = f[i].salario / 160;
        extras = f[i].horasExtras * (valorHora * 1.5);
        bruto = f[i].salario + extras;
        desconto = bruto * 0.1;
        liquido = bruto - desconto;

        totalFolha += liquido;

        if (liquido > maiorLiquido) {
            maiorLiquido = liquido;
            strcpy(nomeMaior, f[i].nome);
        }

        printf("\nNome: %s (%s)\n", f[i].nome, f[i].cargo);
        printf("Bruto: R$ %.2f\n", bruto);
        printf("Desconto 10%%: R$ %.2f\n", desconto);
        printf("Liquido: R$ %.2f\n", liquido);
    }

    printf("\nCusto total da folha: R$ %.2f\n", totalFolha);
    printf("Maior salario liquido: %s - R$ %.2f\n", nomeMaior, maiorLiquido);

    return 0;
}
