#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList* createList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert(LinkedList *list, const char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = strdup(str);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Função para remover uma string da lista
bool removeNode(LinkedList *list, const char *str) {
    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            if (prev == NULL) { // Remoção do primeiro nó
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            list->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Função para buscar uma string na lista
bool search(LinkedList *list, const char *str) {
    Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Função para verificar se a lista chegou ao fim
bool isEnd(Node *node) {
    return node == NULL;
}

int getSize(LinkedList *list) {
    return list->size;
}

int calculateMemoryLoss(LinkedList *list) {
    Node *current = list->head;
    int usedMemory = 0;

    while (current != NULL) {
        usedMemory += strlen(current->data) + 1;
        current = current->next;
    }

    return (sizeof(Node) * list->size) - usedMemory;
}

void printList(LinkedList *list) {
    Node *current = list->head;
    printf("Lista:\n");
    while (current != NULL) {
        printf("  %s\n", current->data);
        current = current->next;
    }
    printf("Total de elementos: %d\n", list->size);
}

// Função para liberar a memória da lista
void freeList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(list);
}

int main() {
    LinkedList *list = createList();

    insert(list, "Hello");
    insert(list, "World");
    insert(list, "Dynamic");
    insert(list, "List");

    printList(list);

    printf("\nRemovendo 'World'...\n");
    if (removeNode(list, "World")) {
        printf("Removido com sucesso.\n");
    } else {
        printf("String não encontrada.\n");
    }
    printList(list);

    // Busca de uma string
    printf("\nBuscando 'Dynamic': %s\n", search(list, "Dynamic") ? "Encontrada" : "Não encontrada");

    // Tamanho da lista
    printf("\nTamanho da lista: %d\n", getSize(list));

    // Perda de memória
    printf("Perda de memória: %d bytes\n", calculateMemoryLoss(list));

    freeList(list);

    return 0;
}
