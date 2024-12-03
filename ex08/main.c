#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* criarNode(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

void inserirInicio(Node **head, int valor) {
    Node *novo = criarNode(valor);
    novo->next = *head;
    *head = novo;
}

void imprimirLista(Node *head) {
    Node *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


// Versão Interativa

Node* encontrarMinimoIterativo(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *minNode = head;
    Node *current = head->next;

    while (current != NULL) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }

    return minNode;
}


// Versão Recursiva

Node* encontrarMinimoRecursivo(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *minRestante = encontrarMinimoRecursivo(head->next);

    return (head->data < minRestante->data) ? head : minRestante;
}
int main() {
    Node *lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirInicio(&lista, 8);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 15);

    imprimirLista(lista);

    Node *minNode = encontrarMinimoIterativo(lista);
    if (minNode != NULL) {
        printf("Menor valor (iterativo): %d\n", minNode->data);
    } else {
        printf("A lista está vazia (iterativo).\n");
    }

    minNode = encontrarMinimoRecursivo(lista);
    if (minNode != NULL) {
        printf("Menor valor (recursivo): %d\n", minNode->data);
    } else {
        printf("A lista está vazia (recursivo).\n");
    }

    return 0;
}