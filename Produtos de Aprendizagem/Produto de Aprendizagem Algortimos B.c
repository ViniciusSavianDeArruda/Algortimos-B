//TRABALHO SOBRE ALGORTIMOS B 
// Nome: Vinicius Arruda, Samuel e Gabreil Sacool


// TRABALHO SOBRE ALGORITMOS B
// Nome: Vinicius Arruda, Samuel e Gabriel Saccol

#include <stdio.h>
#include <string.h>

struct UltimaVenda {
    int dia;
    int mes;
    int ano;
    int quantidade;
    float valorTotal;
};

struct Medicamento {
    char nome[50];
    char principioAtivo[50];
    int quantidadeEstoque;
    int validadeDia;
    int validadeMes;
    int validadeAno;
    float precoCusto;
    int codigo;
    char laboratorio[50];
    char unidade[20];
    struct UltimaVenda ultimaVenda;
};

// Variáveis globais
struct Medicamento farmacia[100];
int contador = 0;

// Função para cadastrar medicamentos
void cadastrarMedicamento() {
    char continuar = 'S';
    while (continuar == 'S' || continuar == 's') {
        printf("\n--- Cadastro de Medicamento ---\n");

        printf("Nome: ");
        scanf(" %49[^\n]", farmacia[contador].nome);

        printf("Codigo: ");
        scanf("%d", &farmacia[contador].codigo);

        printf("Principio Ativo: ");
        scanf(" %49[^\n]", farmacia[contador].principioAtivo);

        printf("Laboratorio: ");
        scanf(" %49[^\n]", farmacia[contador].laboratorio);

        printf("Quantidade em estoque: ");
        scanf("%d", &farmacia[contador].quantidadeEstoque);

        printf("Unidade (caixa, ml, comprimido): ");
        scanf(" %19[^\n]", farmacia[contador].unidade);

        printf("Validade (DD MM AAAA): ");
        scanf("%d %d %d", &farmacia[contador].validadeDia,
                          &farmacia[contador].validadeMes,
                          &farmacia[contador].validadeAno);

        printf("Preco de custo (R$): ");
        scanf("%f", &farmacia[contador].precoCusto);

        // Inicializa última venda
        farmacia[contador].ultimaVenda.dia = 0;
        farmacia[contador].ultimaVenda.mes = 0;
        farmacia[contador].ultimaVenda.ano = 0;
        farmacia[contador].ultimaVenda.quantidade = 0;
        farmacia[contador].ultimaVenda.valorTotal = 0;

        contador++;

        printf("\nMedicamento cadastrado com sucesso!\n");
        printf("Deseja cadastrar outro medicamento? (S/N): ");
        scanf(" %c", &continuar);
    }
}

// Função para registrar venda
void registrarVenda() {
    if (contador == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    char busca[50];
    int encontrado = -1;
    int codigoBusca;
    int i; 
    
    printf("\nDigite nome ou codigo do medicamento: ");
    scanf(" %49[^\n]", busca);

    // Busca por nome
    for (i = 0; i < contador; i++) {
        if (strcmp(farmacia[i].nome, busca) == 0) {
            encontrado = i;
            break;
        }
    }

    // Se nao encontrou pelo nome, tenta pelo código
    if (encontrado == -1) {
        sscanf(busca, "%d", &codigoBusca);
        for (i = 0; i < contador; i++) {
            if (farmacia[i].codigo == codigoBusca) {
                encontrado = i;
                break;
            }
        }
    }

    if (encontrado == -1) {
        printf("Medicamento nao encontrado.\n");
        return;
    }

    int quantidade;
    printf("Quantidade vendida: ");
    scanf("%d", &quantidade);

    if (quantidade > farmacia[encontrado].quantidadeEstoque) {
        printf("Estoque insuficiente!\n");
        return;
    }

    farmacia[encontrado].quantidadeEstoque -= quantidade;

    printf("Data da venda (DD MM AAAA): ");
    scanf("%d %d %d", &farmacia[encontrado].ultimaVenda.dia,
                      &farmacia[encontrado].ultimaVenda.mes,
                      &farmacia[encontrado].ultimaVenda.ano);

    farmacia[encontrado].ultimaVenda.quantidade = quantidade;
    farmacia[encontrado].ultimaVenda.valorTotal = quantidade * farmacia[encontrado].precoCusto;

    printf("\nVenda registrada com sucesso!\n");
}

// Função para visualizar venda
void visualizarVenda() {
    if (contador == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    char busca[50];
    int encontrado = -1;
    int codigoBusca;
    int i; 

    printf("\nDigite nome ou codigo do medicamento: ");
    scanf(" %49[^\n]", busca);

    for (i = 0; i < contador; i++) {
        if (strcmp(farmacia[i].nome, busca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        sscanf(busca, "%d", &codigoBusca);
        for (i = 0; i < contador; i++) {
            if (farmacia[i].codigo == codigoBusca) {
                encontrado = i;
                break;
            }
        }
    }

    if (encontrado == -1) {
        printf("Medicamento nao encontrado.\n");
        return;
    }

    struct Medicamento m = farmacia[encontrado];

    printf("\n--- Dados do Medicamento ---\n");
    printf("Nome: %s\n", m.nome);
    printf("Codigo: %d\n", m.codigo);
    printf("Principio Ativo: %s\n", m.principioAtivo);
    printf("Laboratorio: %s\n", m.laboratorio);
    printf("Quantidade em estoque: %d\n", m.quantidadeEstoque);
    printf("Unidade: %s\n", m.unidade);
    printf("Validade: %02d/%02d/%04d\n", m.validadeDia, m.validadeMes, m.validadeAno);

    printf("\n--- Ultima Venda ---\n");
    printf("Data: %02d/%02d/%04d\n", m.ultimaVenda.dia, m.ultimaVenda.mes, m.ultimaVenda.ano);
    printf("Quantidade vendida: %d\n", m.ultimaVenda.quantidade);
    printf("Valor total pago: R$ %.2f\n", m.ultimaVenda.valorTotal);
}

// Função para listar todos os medicamentos
void listarMedicamentos() {
    if (contador == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    int i; 
    for (i = 0; i < contador; i++) {
        struct Medicamento m = farmacia[i];
        printf("\n--- Medicamento %d ---\n", i + 1);
        printf("Nome: %s\n", m.nome);
        printf("Codigo: %d\n", m.codigo);
        printf("Principio Ativo: %s\n", m.principioAtivo);
        printf("Laboratorio: %s\n", m.laboratorio);
        printf("Quantidade em estoque: %d\n", m.quantidadeEstoque);
        printf("Unidade: %s\n", m.unidade);
        printf("Validade: %02d/%02d/%04d\n", m.validadeDia, m.validadeMes, m.validadeAno);
        printf("Ultima venda: %02d/%02d/%04d, Qnt: %d, Valor: R$ %.2f\n",
               m.ultimaVenda.dia, m.ultimaVenda.mes, m.ultimaVenda.ano,
               m.ultimaVenda.quantidade, m.ultimaVenda.valorTotal);
    }
}

// Função para informações de vendas
void informacoesVendas() {
    if (contador == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    int mes, ano;
    int i; 
    printf("\nInforme mes e ano para calcular vendas: ");
    scanf("%d %d", &mes, &ano);

    float total = 0;
    for (i = 0; i < contador; i++) {
        if (farmacia[i].ultimaVenda.mes == mes && farmacia[i].ultimaVenda.ano == ano) {
            total += farmacia[i].ultimaVenda.valorTotal;
        }
    }

    printf("\nValor total recebido no mes %02d/%04d: R$ %.2f\n", mes, ano, total);
}

int main() {
    char opcao;

    do {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("A - Cadastrar Medicamentos\n");
        printf("B - Registrar Venda\n");
        printf("C - Visualizar Venda\n");
        printf("D - Listar Medicamentos\n");
        printf("E - Informacoes Vendas\n");
        printf("F - Finalizar\n");
        printf("------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'A': case 'a':
                cadastrarMedicamento();
                break;
            case 'B': case 'b':
                registrarVenda();
                break;
            case 'C': case 'c':
                visualizarVenda();
                break;
            case 'D': case 'd':
                listarMedicamentos();
                break;
            case 'E': case 'e':
                informacoesVendas();
                break;
            case 'F': case 'f':
                printf("\nFinalizando programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 'F' && opcao != 'f');

    return 0;
}

