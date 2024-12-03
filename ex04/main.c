#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char *string;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *inicio;
    int totalSlots;
    int usados;
} Lista;

void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->totalSlots = 0;
    lista->usados = 0;
}

Nodo* criarNodo(const char *str) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->string = strdup(str);  // Duplica a string
    novo->prox = NULL;
    return novo;
}

void liberarNodo(Nodo *nodo) {
    free(nodo->string);
    free(nodo);
}

void liberarLista(Lista *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        liberarNodo(temp);
    }
    lista->inicio = NULL;
    lista->totalSlots = 0;
    lista->usados = 0;
}
// Função para inserir
void inserir(Lista *lista, const char *str) {
    Nodo *novo = criarNodo(str);
    lista->totalSlots++;
    lista->usados++;
    
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Nodo *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}
// Função para remover
int remover(Lista *lista, const char *str) {
    Nodo *atual = lista->inicio, *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->string, str) == 0) {
            if (anterior == NULL) {
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            liberarNodo(atual);
            lista->usados--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}
// Função para busca
Nodo* buscar(Lista *lista, const char *str) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->string, str) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}
// Função para detecção de fim de lista
int fimDeLista(Nodo *nodo) {
    return nodo == NULL;
}
int tamanhoLista(Lista *lista) {
    return lista->usados;
}
int perdaMemoria(Lista *lista) {
    return lista->totalSlots - lista->usados;
}
int main() {
    Lista lista;
    inicializarLista(&lista);

    inserir(&lista, "Alice");
    inserir(&lista, "Bob");
    inserir(&lista, "Charlie");
    printf("Após inserção:\n");
    Nodo *atual = lista.inicio;
    while (!fimDeLista(atual)) {
        printf("%s\n", atual->string);
        atual = atual->prox;
    }

    remover(&lista, "Bob");
    printf("\nApós remoção:\n");
    atual = lista.inicio;
    while (!fimDeLista(atual)) {
        printf("%s\n", atual->string);
        atual = atual->prox;
    }

    Nodo *encontrado = buscar(&lista, "Alice");
    if (encontrado) {
        printf("\nElemento encontrado: %s\n", encontrado->string);
    } else {
        printf("\nElemento não encontrado.\n");
    }

    // Tamanho e Perda de Memória
    printf("\nTamanho da lista: %d\n", tamanhoLista(&lista));
    printf("Perda de memória: %d\n", perdaMemoria(&lista));

    liberarLista(&lista);
    return 0;
}
