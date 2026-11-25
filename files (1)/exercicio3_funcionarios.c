#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char cargo[30];
    float salario_base;
    int horas_extras;
} Funcionario;

int main() {
    Funcionario funcionarios[8];
    float custo_total_folha = 0;
    float maior_salario_liquido = -1;
    char nome_maior_salario[50];

    printf("=== CADASTRO DE FUNCIONARIOS ===\n");
    for (int i = 0; i < 8; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &funcionarios[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", funcionarios[i].nome);
        printf("Cargo: ");
        scanf(" %29[^\n]", funcionarios[i].cargo);
        printf("Salario-base (R$): ");
        scanf("%f", &funcionarios[i].salario_base);
        printf("Quantidade de horas extras: ");
        scanf("%d", &funcionarios[i].horas_extras);
    }

    printf("\n\n=== FOLHA DE PAGAMENTO ===\n");
    for (int i = 0; i < 8; i++) {
        float valor_hora = funcionarios[i].salario_base / 160.0;
        float valor_hora_extra = valor_hora * 1.5;
        float total_horas_extras = funcionarios[i].horas_extras * valor_hora_extra;
        float salario_bruto = funcionarios[i].salario_base + total_horas_extras;
        float desconto = salario_bruto * 0.10;
        float salario_liquido = salario_bruto - desconto;

        custo_total_folha += salario_liquido;

        if (i == 0 || salario_liquido > maior_salario_liquido) {
            maior_salario_liquido = salario_liquido;
            strcpy(nome_maior_salario, funcionarios[i].nome);
        }

        printf("----------------------------------------\n");
        printf("Nome: %s | Cargo: %s\n", funcionarios[i].nome, funcionarios[i].cargo);
        printf("Salario Bruto: R$ %.2f\n", salario_bruto);
        printf("Desconto (10%%): R$ %.2f\n", desconto);
        printf("Salario Liquido: R$ %.2f\n", salario_liquido);
    }

    printf("\n========================================\n");
    printf("Custo total da folha de pagamento: R$ %.2f\n", custo_total_folha);
    printf("Maior salario liquido: %s (R$ %.2f)\n", nome_maior_salario, maior_salario_liquido);
    printf("========================================\n");

    return 0;
}
