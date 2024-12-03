#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Função para verificar se a lista está em ordem crescente
bool isOrdenadaCrescente(Node *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node *current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

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

int main() {
    Node *lista = NULL;

    inserirInicio(&lista, 5);
    inserirInicio(&lista, 3);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 1);

    imprimirLista(lista);
    if (isOrdenadaCrescente(lista)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista NÃO está em ordem crescente.\n");
    }

    // Insere um elemento fora de ordem
    inserirInicio(&lista, 10);
    imprimirLista(lista);
    if (isOrdenadaCrescente(lista)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista NÃO está em ordem crescente.\n");
    }

    return 0;
}
