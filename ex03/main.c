#include <stdio.h>
#include <string.h>

#define NUM_PRODUTOS 20

typedef struct {
    char nome[80];
    float preco;
} PROD;

// Função para ler os dados dos produtos
void lerProdutos(PROD produtos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", produtos[i].nome);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }
}

// Função para ordenar os produtos em ordem alfabética pelo nome
void ordenarProdutos(PROD produtos[], int n) {
    PROD temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

// Função para atualizar o preço dos produtos com valor menor que 100
void inflacionarPrecos(PROD *produto) {
    if (produto->preco < 100) {
        produto->preco *= 1.05;
    }
}

void imprimirProdutos(PROD produtos[], int n) {
    printf("\nLista de Produtos:\n");
    printf("%-30s %10s\n", "Produto", "Preço (R$)");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s %10.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

int main() {
    PROD produtos[NUM_PRODUTOS];

    printf("=== Cadastro de Produtos ===\n");
    lerProdutos(produtos, NUM_PRODUTOS);

    ordenarProdutos(produtos, NUM_PRODUTOS);

    for (int i = 0; i < NUM_PRODUTOS; i++) {
        inflacionarPrecos(&produtos[i]);
    }

    imprimirProdutos(produtos, NUM_PRODUTOS);

    return 0;
}
