#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

Nodo* criarNodo(int dado) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
void espelharArvore(Nodo *raiz) {
    if (raiz == NULL) {
        return;
    }

    // Troca as subárvores
    Nodo *temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    // Recursivamente espelha as subárvores
    espelharArvore(raiz->esquerda);
    espelharArvore(raiz->direita);
}
void imprimirEmOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        imprimirEmOrdem(raiz->direita);
    }
}
int main() {
    // Criando uma árvore
    Nodo *raiz = criarNodo(4);
    raiz->esquerda = criarNodo(2);
    raiz->direita = criarNodo(6);
    raiz->esquerda->esquerda = criarNodo(1);
    raiz->esquerda->direita = criarNodo(3);
    raiz->direita->esquerda = criarNodo(5);
    raiz->direita->direita = criarNodo(10);

    printf("Árvore original (em ordem):\n");
    imprimirEmOrdem(raiz);
    printf("\n");

    // Espelha a árvore
    espelharArvore(raiz);

    printf("Árvore espelhada (em ordem):\n");
    imprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}
