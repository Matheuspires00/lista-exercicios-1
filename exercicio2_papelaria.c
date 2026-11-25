#include <stdio.h>
#include <string.h>

struct produto {
    int codigo;
    char nome[50];
    float preco;
    int qtd;
};

// retorna a posicao do produto no vetor ou -1 se nao achar
int procura(struct produto p[], int total, int cod) {
    int i;
    for (i = 0; i < total; i++) {
        if (p[i].codigo == cod) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct produto prod[15];
    int total = 0, op, i, cod, q, pos;
    float valorTotal, maior, v;
    char nomeMaior[50];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Repor estoque\n");
        printf("4 - Registrar venda\n");
        printf("5 - Consultar produto\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (total == 15) {
                    printf("Limite de produtos atingido!\n");
                    break;
                }
                printf("Codigo: ");
                scanf("%d", &cod);
                if (procura(prod, total, cod) != -1) {
                    printf("Ja existe produto com esse codigo!\n");
                    break;
                }
                prod[total].codigo = cod;
                printf("Nome: ");
                scanf(" %49[^\n]", prod[total].nome);
                printf("Preco: ");
                scanf("%f", &prod[total].preco);
                printf("Quantidade: ");
                scanf("%d", &prod[total].qtd);
                total++;
                printf("Produto cadastrado!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                    break;
                }
                valorTotal = 0;
                maior = -1;

                for (i = 0; i < total; i++) {
                    v = prod[i].preco * prod[i].qtd;
                    valorTotal += v;
                    if (v > maior) {
                        maior = v;
                        strcpy(nomeMaior, prod[i].nome);
                    }
                    printf("%d | %s | R$ %.2f | %d un. | R$ %.2f\n",
                           prod[i].codigo, prod[i].nome, prod[i].preco, prod[i].qtd, v);
                }
                printf("\nValor total do estoque: R$ %.2f\n", valorTotal);
                printf("Maior valor em estoque: %s (R$ %.2f)\n", nomeMaior, maior);
                break;

            case 3:
                printf("Codigo do produto: ");
                scanf("%d", &cod);
                pos = procura(prod, total, cod);
                if (pos == -1) {
                    printf("Produto nao encontrado!\n");
                    break;
                }
                printf("Quantidade a adicionar: ");
                scanf("%d", &q);
                if (q <= 0) {
                    printf("Quantidade invalida!\n");
                } else {
                    prod[pos].qtd += q;
                    printf("Estoque atualizado, agora tem %d\n", prod[pos].qtd);
                }
                break;

            case 4:
                printf("Codigo do produto: ");
                scanf("%d", &cod);
                pos = procura(prod, total, cod);
                if (pos == -1) {
                    printf("Produto nao encontrado!\n");
                    break;
                }
                printf("Quantidade vendida: ");
                scanf("%d", &q);
                if (q <= 0) {
                    printf("Quantidade invalida!\n");
                } else if (q > prod[pos].qtd) {
                    printf("Estoque insuficiente! So tem %d\n", prod[pos].qtd);
                } else {
                    prod[pos].qtd -= q;
                    printf("Venda feita! Restam %d no estoque\n", prod[pos].qtd);
                }
                break;

            case 5:
                printf("Codigo do produto: ");
                scanf("%d", &cod);
                pos = procura(prod, total, cod);
                if (pos == -1) {
                    printf("Produto nao encontrado!\n");
                } else {
                    printf("%d | %s | R$ %.2f | %d un.\n",
                           prod[pos].codigo, prod[pos].nome, prod[pos].preco, prod[pos].qtd);
                }
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 6);

    return 0;
}
