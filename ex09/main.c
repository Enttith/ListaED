#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node* criarNode(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

// Função para inserir um valor no final da lista
void inserirFinal(Node **head, int valor) {
    Node *novo = criarNode(valor);
    if (*head == NULL) {
        *head = novo;
        return;
    }

    Node *atual = *head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    atual->next = novo;
}

void imprimirLista(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


// Versão Interativa

int listasIguaisIterativa(Node *lista1, Node *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->data != lista2->data) {
            return 0;
        }
        lista1 = lista1->next;
        lista2 = lista2->next;
    }

    return (lista1 == NULL && lista2 == NULL);
}

// Versão Recursiva

int listasIguaisRecursiva(Node *lista1, Node *lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return 1;
    }
    if (lista1 == NULL || lista2 == NULL) {
        return 0;
    }
    if (lista1->data != lista2->data) {
        return 0;
    }

    return listasIguaisRecursiva(lista1->next, lista2->next);
}
int main() {
    Node *lista1 = NULL;
    Node *lista2 = NULL;

    inserirFinal(&lista1, 10);
    inserirFinal(&lista1, 20);
    inserirFinal(&lista1, 30);

    inserirFinal(&lista2, 10);
    inserirFinal(&lista2, 20);
    inserirFinal(&lista2, 30);

    printf("Lista 1: ");
    imprimirLista(lista1);
    printf("Lista 2: ");
    imprimirLista(lista2);

    if (listasIguaisIterativa(lista1, lista2)) {
        printf("As listas são iguais (versão iterativa).\n");
    } else {
        printf("As listas são diferentes (versão iterativa).\n");
    }

    if (listasIguaisRecursiva(lista1, lista2)) {
        printf("As listas são iguais (versão recursiva).\n");
    } else {
        printf("As listas são diferentes (versão recursiva).\n");
    }

    return 0;
}
