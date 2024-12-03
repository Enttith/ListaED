#include <stdio.h>
#define MAX 50

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

void imprimirLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}
// Inserção em ordem crescente
int inserirCrescente(Lista *lista, int x) {
    if (lista->tamanho >= MAX) {
        return 0; // Lista cheia
    }

    int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] > x) {
            break;
        }
    }

    for (int j = lista->tamanho; j > i; j--) {
        lista->elementos[j] = lista->elementos[j - 1];
    }

    lista->elementos[i] = x;
    lista->tamanho++;
    return 1;
}
// Inserção em ordem decrescente
int inserirDecrescente(Lista *lista, int x) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] < x) {
            break;
        }
    }

    for (int j = lista->tamanho; j > i; j--) {
        lista->elementos[j] = lista->elementos[j - 1];
    }

    lista->elementos[i] = x;
    lista->tamanho++;
    return 1;
}
// Função main
int main() {
    Lista lista;
    inicializarLista(&lista);

    printf("Inserindo em ordem crescente:\n");
    inserirCrescente(&lista, 5);
    inserirCrescente(&lista, 3);
    inserirCrescente(&lista, 8);
    inserirCrescente(&lista, 1);
    inserirCrescente(&lista, 7);
    imprimirLista(&lista);

    inicializarLista(&lista);

    printf("Inserindo em ordem decrescente:\n");
    inserirDecrescente(&lista, 5);
    inserirDecrescente(&lista, 3);
    inserirDecrescente(&lista, 8);
    inserirDecrescente(&lista, 1);
    inserirDecrescente(&lista, 7);
    imprimirLista(&lista);

    return 0;
}
