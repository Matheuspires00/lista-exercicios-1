#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int buscar_produto(Produto produtos[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void atualizar_estoque(Produto *p, int qtd_alteracao, int tipo) {
    if (tipo == 1) {
        p->quantidade += qtd_alteracao;
    } else if (tipo == 2) {
        p->quantidade -= qtd_alteracao;
    }
}

int main() {
    Produto produtos[15];
    int total_produtos = 0;
    int opcao;

    do {
        printf("\n--- MENU DE PRODUTOS ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Repor estoque\n");
        printf("4. Registrar venda\n");
        printf("5. Consultar por codigo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (total_produtos >= 15) {
                    printf("\nLimite de 15 produtos atingido!\n");
                    break;
                }
                int cod;
                printf("\nCodigo do produto: ");
                scanf("%d", &cod);

                if (buscar_produto(produtos, total_produtos, cod) != -1) {
                    printf("\nErro: Ja existe um produto com esse codigo!\n");
                    break;
                }

                produtos[total_produtos].codigo = cod;
                printf("Nome do produto: ");
                scanf(" %49[^\n]", produtos[total_produtos].nome);
                printf("Preco: ");
                scanf("%f", &produtos[total_produtos].preco);
                printf("Quantidade em estoque: ");
                scanf("%d", &produtos[total_produtos].quantidade);
                total_produtos++;

                printf("\nProduto cadastrado com sucesso!\n");
                break;
            }
            case 2: {
                if (total_produtos == 0) {
                    printf("\nNenhum produto cadastrado.\n");
                    break;
                }
                printf("\n--- LISTA DE PRODUTOS ---\n");
                float maior_valor_total = -1;
                char nome_maior_valor[50];
                float valor_geral_estoque = 0;

                for (int i = 0; i < total_produtos; i++) {
                    float valor_total_prod = produtos[i].preco * produtos[i].quantidade;
                    valor_geral_estoque += valor_total_prod;

                    if (valor_total_prod > maior_valor_total) {
                        maior_valor_total = valor_total_prod;
                        strcpy(nome_maior_valor, produtos[i].nome);
                    }
                    printf("Cod: %d | Nome: %-15s | Preco: R$ %.2f | Qtd: %d | Total: R$ %.2f\n",
                           produtos[i].codigo, produtos[i].nome, produtos[i].preco,
                           produtos[i].quantidade, valor_total_prod);
                }
                printf("\nValor total de todos os produtos no estoque: R$ %.2f\n", valor_geral_estoque);
                printf("Produto com maior valor total em estoque: %s (R$ %.2f)\n",
                       nome_maior_valor, maior_valor_total);
                break;
            }
            case 3: {
                int cod, qtd;
                printf("\nCodigo do produto para reposicao: ");
                scanf("%d", &cod);
                int idx = buscar_produto(produtos, total_produtos, cod);
                if (idx == -1) {
                    printf("\nProduto nao encontrado!\n");
                    break;
                }
                printf("Quantidade a adicionar: ");
                scanf("%d", &qtd);
                if (qtd <= 0) {
                    printf("\nErro: quantidade invalida!\n");
                    break;
                }
                atualizar_estoque(&produtos[idx], qtd, 1);
                printf("\nEstoque atualizado! Nova quantidade: %d\n", produtos[idx].quantidade);
                break;
            }
            case 4: {
                int cod, qtd;
                printf("\nCodigo do produto para venda: ");
                scanf("%d", &cod);
                int idx = buscar_produto(produtos, total_produtos, cod);
                if (idx == -1) {
                    printf("\nProduto nao encontrado!\n");
                    break;
                }
                printf("Quantidade a vender: ");
                scanf("%d", &qtd);
                if (qtd <= 0) {
                    printf("\nErro: quantidade invalida!\n");
                } else if (qtd > produtos[idx].quantidade) {
                    printf("\nErro: Quantidade indisponivel em estoque! (Disponivel: %d)\n",
                           produtos[idx].quantidade);
                } else {
                    atualizar_estoque(&produtos[idx], qtd, 2);
                    printf("\nVenda realizada com sucesso! Estoque restante: %d\n",
                           produtos[idx].quantidade);
                }
                break;
            }
            case 5: {
                int cod;
                printf("\nDigite o codigo para consulta: ");
                scanf("%d", &cod);
                int idx = buscar_produto(produtos, total_produtos, cod);
                if (idx == -1) {
                    printf("\nProduto nao encontrado!\n");
                } else {
                    printf("\nEncontrado: Cod: %d | Nome: %s | Preco: R$ %.2f | Qtd: %d\n",
                           produtos[idx].codigo, produtos[idx].nome,
                           produtos[idx].preco, produtos[idx].quantidade);
                }
                break;
            }
            case 6:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}
