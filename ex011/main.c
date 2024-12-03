#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Estrutura para armazenar cada palavra
typedef struct Palavra {
    char texto[MAX_WORD_LEN];
    int frequencia;
    struct Palavra *prox;
} Palavra;

Palavra* criarPalavra(const char *texto) {
    Palavra *nova = (Palavra*)malloc(sizeof(Palavra));
    strcpy(nova->texto, texto);
    nova->frequencia = 1;
    nova->prox = NULL;
    return nova;
}

void inserirOuAtualizar(Palavra **lista, const char *texto) {
    Palavra *atual = *lista;
    while (atual != NULL) {
        if (strcmp(atual->texto, texto) == 0) {
            atual->frequencia++;
            return;
        }
        atual = atual->prox;
    }
    Palavra *nova = criarPalavra(texto);
    nova->prox = *lista;
    *lista = nova;
}

// Função para liberar a memória da lista
void liberarLista(Palavra *lista) {
    while (lista != NULL) {
        Palavra *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Funções de Estatísticas
int contarPalavras(Palavra *lista) {
    int total = 0;
    Palavra *atual = lista;
    while (atual != NULL) {
        total += atual->frequencia;
        atual = atual->prox;
    }
    return total;
}

// Contar Palavras Distintas
int contarPalavrasDistintas(Palavra *lista) {
    int total = 0;
    Palavra *atual = lista;
    while (atual != NULL) {
        total++;
        atual = atual->prox;
    }
    return total;
}

// Calcular a Quantidade Média de Letras
float mediaLetras(Palavra *lista) {
    int totalLetras = 0, totalPalavras = 0;
    Palavra *atual = lista;
    while (atual != NULL) {
        totalLetras += strlen(atual->texto) * atual->frequencia;
        totalPalavras += atual->frequencia;
        atual = atual->prox;
    }
    return (float)totalLetras / totalPalavras;
}

// Encontrar a Maior Palavra
char* maiorPalavra(Palavra *lista, char *buffer) {
    Palavra *atual = lista;
    strcpy(buffer, atual->texto);
    while (atual != NULL) {
        if (strlen(atual->texto) > strlen(buffer)) {
            strcpy(buffer, atual->texto);
        }
        atual = atual->prox;
    }
    return buffer;
}

// Encontrar a Menor Palavra
char* menorPalavra(Palavra *lista, char *buffer) {
    Palavra *atual = lista;
    strcpy(buffer, atual->texto);
    while (atual != NULL) {
        if (strlen(atual->texto) < strlen(buffer)) {
            strcpy(buffer, atual->texto);
        }
        atual = atual->prox;
    }
    return buffer;
}

// Encontrar a Palavra mais Frequente
char* palavraMaisFrequente(Palavra *lista, char *buffer) {
    Palavra *atual = lista;
    strcpy(buffer, atual->texto);
    int maxFrequencia = atual->frequencia;
    while (atual != NULL) {
        if (atual->frequencia > maxFrequencia) {
            maxFrequencia = atual->frequencia;
            strcpy(buffer, atual->texto);
        }
        atual = atual->prox;
    }
    return buffer;
}

// Encontrar a Palavra mais Rara
char* palavraMaisRara(Palavra *lista, char *buffer) {
    Palavra *atual = lista;
    strcpy(buffer, atual->texto);
    int minFrequencia = atual->frequencia;
    while (atual != NULL) {
        if (atual->frequencia < minFrequencia) {
            minFrequencia = atual->frequencia;
            strcpy(buffer, atual->texto);
        }
        atual = atual->prox;
    }
    return buffer;
}

// Função para Processar o Texto
int main() {
    Palavra *lista = NULL;
    char texto[] = "O meu Hobby é assistir: animes, filmes, séries e práticar esportes. Qual o seu Hobby favórito?";
    char *token = strtok(texto, " ");
    char buffer[MAX_WORD_LEN];

    while (token != NULL) {
        inserirOuAtualizar(&lista, token);
        token = strtok(NULL, " ");
    }

    printf("Total de palavras: %d\n", contarPalavras(lista));

    printf("Total de palavras distintas: %d\n", contarPalavrasDistintas(lista));

    printf("Média de letras por palavra: %.2f\n", mediaLetras(lista));

    printf("Maior palavra: %s\n", maiorPalavra(lista, buffer));

    printf("Menor palavra: %s\n", menorPalavra(lista, buffer));

    printf("Palavra mais frequente: %s\n", palavraMaisFrequente(lista, buffer));

    printf("Palavra mais rara: %s\n", palavraMaisRara(lista, buffer));

    liberarLista(lista);
    return 0;
}
