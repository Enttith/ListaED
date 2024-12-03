#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *prox;
} Nodo;

Nodo* criarNodo(int dado) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

void inserirFinal(Nodo **cabeca, int dado) {
    Nodo *novo = criarNodo(dado);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        Nodo *temp = *cabeca;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}
int verificarOrdemCrescenteIterativa(Nodo *cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) {
        return 1; // Retorna uma lista vazia
    }

    Nodo *atual = cabeca;
    while (atual->prox != NULL) {
        if (atual->dado > atual->prox->dado) {
            return 0; // Indica quando não está em ordem crescente
        }
        atual = atual->prox;
    }
    return 1; // Vai retornar em ordem crescente
}
int verificarOrdemCrescenteRecursiva(Nodo *cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) {
        return 1; // Retorna uma lista vazia
    }

    if (cabeca->dado > cabeca->prox->dado) {
        return 0; // Não está em ordem crescente
    }

    return verificarOrdemCrescenteRecursiva(cabeca->prox);
}
int main() {
    Nodo *lista = NULL;

    inserirFinal(&lista, 1);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 4);

    printf("A lista está em ordem crescente (iterativa)? %s\n",
           verificarOrdemCrescenteIterativa(lista) ? "Sim" : "Não");

    printf("A lista está em ordem crescente (recursiva)? %s\n",
           verificarOrdemCrescenteRecursiva(lista) ? "Sim" : "Não");

    inserirFinal(&lista, 0);

    printf("A lista está em ordem crescente (iterativa)? %s\n",
           verificarOrdemCrescenteIterativa(lista) ? "Sim" : "Não");

    printf("A lista está em ordem crescente (recursiva)? %s\n",
           verificarOrdemCrescenteRecursiva(lista) ? "Sim" : "Não");

    return 0;
}
