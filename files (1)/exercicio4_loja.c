#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    int id_venda;
    Produto produto;
    int quantidade_vendida;
    float valor_total;
} Venda;

int buscar_produto(Produto produtos[], int total_prod, int codigo) {
    for (int i = 0; i < total_prod; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main() {
    Produto produtos[10];
    Venda vendas[20];
    int total_produtos = 0;
    int total_vendas = 0;

    printf("=== CADASTRO DE PRODUTOS ===\n");
    printf("Quantos produtos deseja cadastrar (max 10)? ");
    int qtd_cad;
    scanf("%d", &qtd_cad);
    if (qtd_cad > 10) qtd_cad = 10;
    if (qtd_cad < 0) qtd_cad = 0;

    for (int i = 0; i < qtd_cad; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);
        printf("Preco (R$): ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        total_produtos++;
    }

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        if (total_vendas >= 20) {
            printf("\nLimite maximo de 20 vendas atingido!\n");
            break;
        }

        printf("\n--- REGISTRAR VENDA %d ---\n", total_vendas + 1);
        int cod, qtd;
        printf("Digite o codigo do produto vendido: ");
        scanf("%d", &cod);

        int idx = buscar_produto(produtos, total_produtos, cod);
        if (idx == -1) {
            printf("Erro: Produto nao encontrado!\n");
        } else {
            printf("Quantidade desejada: ");
            scanf("%d", &qtd);

            if (qtd <= 0) {
                printf("Erro: quantidade invalida!\n");
            } else if (qtd > produtos[idx].quantidade) {
                printf("Erro: Estoque insuficiente! Disponivel: %d\n", produtos[idx].quantidade);
            } else {
                produtos[idx].quantidade -= qtd;
                vendas[total_vendas].id_venda = total_vendas + 1;
                vendas[total_vendas].produto = produtos[idx];
                vendas[total_vendas].quantidade_vendida = qtd;
                vendas[total_vendas].valor_total = qtd * produtos[idx].preco;
                total_vendas++;
                printf("Venda registrada com sucesso! Total da venda: R$ %.2f\n",
                       vendas[total_vendas - 1].valor_total);
            }
        }

        if (total_vendas < 20) {
            printf("Deseja registrar outra venda? (s/n): ");
            scanf(" %c", &continuar);
        } else {
            break;
        }
    }

    float faturamento_total = 0;
    float faturamento_por_produto[10] = {0};

    for (int i = 0; i < total_vendas; i++) {
        faturamento_total += vendas[i].valor_total;
        int idx = buscar_produto(produtos, total_produtos, vendas[i].produto.codigo);
        if (idx != -1) {
            faturamento_por_produto[idx] += vendas[i].valor_total;
        }
    }

    float maior_faturamento = -1;
    int idx_maior_faturamento = -1;
    for (int i = 0; i < total_produtos; i++) {
        if (faturamento_por_produto[i] > maior_faturamento) {
            maior_faturamento = faturamento_por_produto[i];
            idx_maior_faturamento = i;
        }
    }

    printf("\n\n=== RELATORIO DE VENDAS ===\n");
    printf("Faturamento total da loja: R$ %.2f\n", faturamento_total);
    if (idx_maior_faturamento != -1 && maior_faturamento > 0) {
        printf("Produto que gerou o maior faturamento: %s (R$ %.2f)\n",
               produtos[idx_maior_faturamento].nome, maior_faturamento);
    } else {
        printf("Nenhuma venda realizada para calcular o maior faturamento.\n");
    }

    return 0;
}
