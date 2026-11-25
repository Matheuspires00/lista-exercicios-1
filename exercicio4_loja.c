#include <stdio.h>

struct produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

struct venda {
    int id;
    int codProduto;
    int qtd;
    float total;
};

int procura(struct produto p[], int n, int cod) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].codigo == cod) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct produto prod[10];
    struct venda vendas[20];
    int nProd, nVendas = 0, i, cod, q, pos;
    char resp = 's';
    float faturamento = 0, fatProduto[10], maior;
    int posMaior;

    printf("Quantos produtos quer cadastrar (max 10)? ");
    scanf("%d", &nProd);
    if (nProd > 10) {
        nProd = 10;
    }

    for (i = 0; i < nProd; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &prod[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", prod[i].nome);
        printf("Preco: ");
        scanf("%f", &prod[i].preco);
        printf("Estoque: ");
        scanf("%d", &prod[i].estoque);
        fatProduto[i] = 0;
    }

    while ((resp == 's' || resp == 'S') && nVendas < 20) {
        printf("\n--- Venda %d ---\n", nVendas + 1);
        printf("Codigo do produto: ");
        scanf("%d", &cod);

        pos = procura(prod, nProd, cod);
        if (pos == -1) {
            printf("Produto nao encontrado!\n");
        } else {
            printf("Quantidade: ");
            scanf("%d", &q);

            if (q <= 0) {
                printf("Quantidade invalida!\n");
            } else if (q > prod[pos].estoque) {
                printf("Estoque insuficiente (tem %d)\n", prod[pos].estoque);
            } else {
                prod[pos].estoque -= q;
                vendas[nVendas].id = nVendas + 1;
                vendas[nVendas].codProduto = cod;
                vendas[nVendas].qtd = q;
                vendas[nVendas].total = q * prod[pos].preco;

                faturamento += vendas[nVendas].total;
                fatProduto[pos] += vendas[nVendas].total;

                printf("Venda registrada! Total: R$ %.2f\n", vendas[nVendas].total);
                nVendas++;
            }
        }

        if (nVendas < 20) {
            printf("Registrar outra venda? (s/n): ");
            scanf(" %c", &resp);
        } else {
            printf("Limite de 20 vendas atingido!\n");
        }
    }

    // acha o produto que mais faturou
    maior = 0;
    posMaior = -1;
    for (i = 0; i < nProd; i++) {
        if (fatProduto[i] > maior) {
            maior = fatProduto[i];
            posMaior = i;
        }
    }

    printf("\n===== RELATORIO =====\n");
    printf("Faturamento total: R$ %.2f\n", faturamento);
    if (posMaior == -1) {
        printf("Nenhuma venda foi feita.\n");
    } else {
        printf("Produto que mais faturou: %s (R$ %.2f)\n", prod[posMaior].nome, maior);
    }

    return 0;
}
