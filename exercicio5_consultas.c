#include <stdio.h>

struct data {
    int dia, mes, ano;
};

struct paciente {
    int codigo;
    char nome[50];
    char telefone[20];
};

struct consulta {
    int id;
    int codPaciente;
    struct data dt;
    char descricao[100];
};

int procuraPaciente(struct paciente p[], int n, int cod) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].codigo == cod) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct paciente pac[15];
    struct consulta cons[30];
    int nPac, nCons = 0, i, cod, pos, cont;
    int contagem[15];
    char resp = 's';
    struct data busca;

    printf("Quantos pacientes quer cadastrar (max 15)? ");
    scanf("%d", &nPac);
    if (nPac > 15) {
        nPac = 15;
    }

    for (i = 0; i < nPac; i++) {
        printf("\nPaciente %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &pac[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", pac[i].nome);
        printf("Telefone: ");
        scanf(" %19[^\n]", pac[i].telefone);
        contagem[i] = 0;
    }

    while ((resp == 's' || resp == 'S') && nCons < 30) {
        printf("\n--- Consulta %d ---\n", nCons + 1);
        printf("Codigo do paciente: ");
        scanf("%d", &cod);

        pos = procuraPaciente(pac, nPac, cod);
        if (pos == -1) {
            printf("Paciente nao cadastrado!\n");
        } else {
            cons[nCons].id = nCons + 1;
            cons[nCons].codPaciente = cod;
            printf("Data (DD MM AAAA): ");
            scanf("%d %d %d", &cons[nCons].dt.dia, &cons[nCons].dt.mes, &cons[nCons].dt.ano);
            printf("Descricao: ");
            scanf(" %99[^\n]", cons[nCons].descricao);
            contagem[pos]++;
            nCons++;
            printf("Consulta registrada!\n");
        }

        if (nCons < 30) {
            printf("Registrar outra? (s/n): ");
            scanf(" %c", &resp);
        } else {
            printf("Limite de 30 consultas atingido!\n");
        }
    }

    // historico de um paciente
    printf("\n=== HISTORICO DO PACIENTE ===\n");
    printf("Codigo do paciente: ");
    scanf("%d", &cod);
    pos = procuraPaciente(pac, nPac, cod);
    if (pos == -1) {
        printf("Paciente nao encontrado.\n");
    } else {
        printf("Consultas de %s:\n", pac[pos].nome);
        for (i = 0; i < nCons; i++) {
            if (cons[i].codPaciente == cod) {
                printf("- %02d/%02d/%04d: %s\n", cons[i].dt.dia, cons[i].dt.mes,
                       cons[i].dt.ano, cons[i].descricao);
            }
        }
        printf("Total: %d\n", contagem[pos]);
    }

    // consultas de uma data
    printf("\n=== CONSULTAS POR DATA ===\n");
    printf("Data (DD MM AAAA): ");
    scanf("%d %d %d", &busca.dia, &busca.mes, &busca.ano);
    cont = 0;
    for (i = 0; i < nCons; i++) {
        if (cons[i].dt.dia == busca.dia && cons[i].dt.mes == busca.mes && cons[i].dt.ano == busca.ano) {
            pos = procuraPaciente(pac, nPac, cons[i].codPaciente);
            printf("- %s: %s\n", pac[pos].nome, cons[i].descricao);
            cont++;
        }
    }
    if (cont == 0) {
        printf("Nenhuma consulta nessa data.\n");
    }

    printf("\n=== CONSULTAS POR PACIENTE ===\n");
    for (i = 0; i < nPac; i++) {
        printf("%s: %d\n", pac[i].nome, contagem[i]);
    }

    // paciente com mais consultas
    pos = -1;
    cont = 0;
    for (i = 0; i < nPac; i++) {
        if (contagem[i] > cont) {
            cont = contagem[i];
            pos = i;
        }
    }
    if (pos == -1) {
        printf("\nNenhuma consulta registrada.\n");
    } else {
        printf("\nPaciente com mais consultas: %s (%d)\n", pac[pos].nome, cont);
    }

    return 0;
}
