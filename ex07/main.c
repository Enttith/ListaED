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

void inserirOrdenado(Node **head, int valor) {
    Node *novo = criarNode(valor);
    if (*head == NULL || (*head)->data > valor) {
        novo->next = *head;
        *head = novo;
        return;
    }

    Node *atual = *head;
    while (atual->next != NULL && atual->next->data < valor) {
        atual = atual->next;
    }
    novo->next = atual->next;
    atual->next = novo;
}

void imprimirLista(Node *head) {
    printf("Lista: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


// Versão de busca interativa

Node* buscaIterativa(Node *head, int valor) {
    while (head != NULL && head->data <= valor) {
        if (head->data == valor) {
            return head;
        }
        head = head->next; 
    }
    return NULL;
}



// Versão Recursiva da Busca

Node* buscaRecursiva(Node *head, int valor) {
    if (head == NULL || head->data > valor) {
        return NULL;
    }
    if (head->data == valor) {
        return head;
    }
    return buscaRecursiva(head->next, valor);
}
int main() {
    Node *lista = NULL;

    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 30);
    inserirOrdenado(&lista, 40);
    inserirOrdenado(&lista, 50);

    imprimirLista(lista);

    int valor = 30;

    Node *resultadoIterativa = buscaIterativa(lista, valor);
    if (resultadoIterativa != NULL) {
        printf("Busca Iterativa: Valor %d encontrado no endereço %p\n", valor, (void*)resultadoIterativa);
    } else {
        printf("Busca Iterativa: Valor %d não encontrado\n", valor);
    }

    Node *resultadoRecursiva = buscaRecursiva(lista, valor);
    if (resultadoRecursiva != NULL) {
        printf("Busca Recursiva: Valor %d encontrado no endereço %p\n", valor, (void*)resultadoRecursiva);
    } else {
        printf("Busca Recursiva: Valor %d não encontrado\n", valor);
    }

    return 0;
}
