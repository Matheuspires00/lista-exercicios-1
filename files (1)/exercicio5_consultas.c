#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
} Paciente;

typedef struct {
    int id_consulta;
    Paciente paciente;
    Data data_consulta;
    char descricao[100];
} Consulta;

int buscar_paciente(Paciente pacientes[], int total_pacientes, int codigo) {
    for (int i = 0; i < total_pacientes; i++) {
        if (pacientes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main() {
    Paciente pacientes[15];
    Consulta consultas[30];
    int total_pacientes = 0;
    int total_consultas = 0;

    printf("=== CADASTRO DE PACIENTES ===\n");
    printf("Quantos pacientes deseja cadastrar (max 15)? ");
    int qtd_p;
    scanf("%d", &qtd_p);
    if (qtd_p > 15) qtd_p = 15;
    if (qtd_p < 0) qtd_p = 0;

    for (int i = 0; i < qtd_p; i++) {
        printf("\nPaciente %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &pacientes[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", pacientes[i].nome);
        printf("Telefone: ");
        scanf(" %19[^\n]", pacientes[i].telefone);
        total_pacientes++;
    }

    char continuar = 's';
    while ((continuar == 's' || continuar == 'S') && total_consultas < 30) {
        printf("\n--- REGISTRAR CONSULTA %d ---\n", total_consultas + 1);
        int cod_pac;
        printf("Codigo do paciente: ");
        scanf("%d", &cod_pac);

        int idx_pac = buscar_paciente(pacientes, total_pacientes, cod_pac);
        if (idx_pac == -1) {
            printf("Erro: Paciente nao cadastrado!\n");
        } else {
            consultas[total_consultas].id_consulta = total_consultas + 1;
            consultas[total_consultas].paciente = pacientes[idx_pac];
            printf("Data da consulta (DD MM AAAA): ");
            scanf("%d %d %d",
                  &consultas[total_consultas].data_consulta.dia,
                  &consultas[total_consultas].data_consulta.mes,
                  &consultas[total_consultas].data_consulta.ano);
            printf("Descricao do atendimento: ");
            scanf(" %99[^\n]", consultas[total_consultas].descricao);
            total_consultas++;
            printf("Consulta registrada com sucesso!\n");
        }

        if (total_consultas < 30) {
            printf("Deseja registrar outra consulta? (s/n): ");
            scanf(" %c", &continuar);
        } else {
            printf("\nLimite maximo de 30 consultas atingido!\n");
        }
    }

    printf("\n\n=== PESQUISA DE CONSULTAS POR PACIENTE ===\n");
    int busca_cod;
    printf("Digite o codigo do paciente para ver o historico: ");
    scanf("%d", &busca_cod);

    int encontrou_pac = buscar_paciente(pacientes, total_pacientes, busca_cod);
    if (encontrou_pac == -1) {
        printf("Paciente nao encontrado.\n");
    } else {
        printf("Consultas do paciente %s:\n", pacientes[encontrou_pac].nome);
        int qtd_atendimentos = 0;
        for (int i = 0; i < total_consultas; i++) {
            if (consultas[i].paciente.codigo == busca_cod) {
                printf("- Data: %02d/%02d/%04d | Descricao: %s\n",
                       consultas[i].data_consulta.dia,
                       consultas[i].data_consulta.mes,
                       consultas[i].data_consulta.ano,
                       consultas[i].descricao);
                qtd_atendimentos++;
            }
        }
        printf("Total de atendimentos para este paciente: %d\n", qtd_atendimentos);
    }

    printf("\n=== CONSULTAS POR DATA ===\n");
    Data data_busca;
    printf("Digite a data que deseja buscar (DD MM AAAA): ");
    scanf("%d %d %d", &data_busca.dia, &data_busca.mes, &data_busca.ano);
    printf("Consultas em %02d/%02d/%04d:\n", data_busca.dia, data_busca.mes, data_busca.ano);

    int count_data = 0;
    for (int i = 0; i < total_consultas; i++) {
        if (consultas[i].data_consulta.dia == data_busca.dia &&
            consultas[i].data_consulta.mes == data_busca.mes &&
            consultas[i].data_consulta.ano == data_busca.ano) {
            printf("- Paciente: %s | Descricao: %s\n",
                   consultas[i].paciente.nome, consultas[i].descricao);
            count_data++;
        }
    }
    if (count_data == 0) {
        printf("Nenhuma consulta encontrada nesta data.\n");
    }

    int contador_consultas[15] = {0};
    for (int i = 0; i < total_consultas; i++) {
        int idx_p = buscar_paciente(pacientes, total_pacientes, consultas[i].paciente.codigo);
        if (idx_p != -1) {
            contador_consultas[idx_p]++;
        }
    }

    printf("\n=== CONSULTAS POR PACIENTE ===\n");
    for (int i = 0; i < total_pacientes; i++) {
        printf("%s: %d consulta(s)\n", pacientes[i].nome, contador_consultas[i]);
    }

    int max_atendimentos = -1;
    int idx_paciente_top = -1;
    for (int i = 0; i < total_pacientes; i++) {
        if (contador_consultas[i] > max_atendimentos) {
            max_atendimentos = contador_consultas[i];
            idx_paciente_top = i;
        }
    }

    printf("\n=== ESTATISTICAS GERAIS ===\n");
    if (idx_paciente_top != -1 && max_atendimentos > 0) {
        printf("Paciente com maior numero de atendimentos: %s (Total: %d consultas)\n",
               pacientes[idx_paciente_top].nome, max_atendimentos);
    } else {
        printf("Nenhum atendimento registrado para estatisticas.\n");
    }

    return 0;
}
