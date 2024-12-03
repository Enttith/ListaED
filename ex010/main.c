#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Cria um novo nó
Node* criarNode(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

// Insere um nó no início da lista
void inserirInicio(Node **head, int valor) {
    Node *novo = criarNode(valor);
    novo->next = *head;
    *head = novo;
}

// Função para encontrar o ponto médio da lista
Node* encontrarPontoMedio(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Função para imprimir a lista
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
    inserirInicio(&lista, 4);
    inserirInicio(&lista, 3);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 1);

    imprimirLista(lista);

    Node *pontoMedio = encontrarPontoMedio(lista);
    if (pontoMedio != NULL) {
        printf("Ponto médio da lista: %d\n", pontoMedio->data);
    } else {
        printf("A lista está vazia.\n");
    }

    return 0;
}
