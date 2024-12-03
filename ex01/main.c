#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Estrutura que armazena os elementos e suas contagens
typedef struct {
    int elem;
    int count;
} ElementCount;

// Função para verificar se a lista está ordenada
bool isOrdered(int L1[], int n) {
    bool crescente = true, decrescente = true;
    for (int i = 1; i < n; i++) {
        if (L1[i] < L1[i - 1]) crescente = false;
        if (L1[i] > L1[i - 1]) decrescente = false;
    }
    return crescente || decrescente;
}

// Função para copiar L1 para L2
void copyList(int L1[], int n, int L2[]) {
    for (int i = 0; i < n; i++) {
        L2[i] = L1[i];
    }
}

// Função para copiar L1 para L2 eliminando elementos repetidos
int copyUnique(int L1[], int n, int L2[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || L1[i] != L1[i - 1]) {
            L2[k++] = L1[i];
        }
    }
    return k;
}

// Função para inverter L1 e armazenar em L2
void reverseList(int L1[], int n, int L2[]) {
    for (int i = 0; i < n; i++) {
        L2[i] = L1[n - i - 1];
    }
}

// Função para inverter L1 na própria lista
void reverseInPlace(int L1[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = L1[i];
        L1[i] = L1[n - i - 1];
        L1[n - i - 1] = temp;
    }
}

// Função para intercalar L1 e L2 gerando L3
int mergeLists(int L1[], int n1, int L2[], int n2, int L3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) L3[k++] = L1[i++];
        else L3[k++] = L2[j++];
    }
    while (i < n1) L3[k++] = L1[i++];
    while (j < n2) L3[k++] = L2[j++];
    return k;
}

// Função para gerar L2 com elementos e suas contagens
int generateCountList(int L1[], int n, ElementCount L2[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || L1[i] != L1[i - 1]) {
            L2[k].elem = L1[i];
            L2[k].count = 1;
            k++;
        } else {
            L2[k - 1].count++;
        }
    }
    return k; 
}

// Função para remover todas as ocorrências de um elemento de L1
int removeOccurrences(int L1[], int n, int elem) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (L1[i] != elem) {
            L1[k++] = L1[i];
        }
    }
    return k;
}

// Função para encontrar os elementos com maior e menor número de ocorrências
void findMinMaxOccurrences(int L1[], int n, int *minElem, int *maxElem, int *minCount, int *maxCount) {
    ElementCount counts[MAX];
    int size = generateCountList(L1, n, counts);
    *minCount = counts[0].count;
    *maxCount = counts[0].count;
    *minElem = counts[0].elem;
    *maxElem = counts[0].elem;

    for (int i = 1; i < size; i++) {
        if (counts[i].count < *minCount) {
            *minCount = counts[i].count;
            *minElem = counts[i].elem;
        }
        if (counts[i].count > *maxCount) {
            *maxCount = counts[i].count;
            *maxElem = counts[i].elem;
        }
    }
}

int main() {
    int L1[] = {1, 1, 2, 2, 3, 4, 4, 4, 5};
    int n1 = 9, n2, n3;
    int L2[MAX], L3[MAX];
    ElementCount L2Count[MAX];

    printf("A lista está ordenada? %s\n", isOrdered(L1, n1) ? "Sim" : "Não");

    copyList(L1, n1, L2);
    printf("Cópia de L1 em L2:\n");
    for (int i = 0; i < n1; i++) printf("%d ", L2[i]);
    printf("\n");

    n2 = copyUnique(L1, n1, L2);
    printf("Cópia de L1 em L2 sem repetidos:\n");
    for (int i = 0; i < n2; i++) printf("%d ", L2[i]);
    printf("\n");

    reverseList(L1, n1, L2);
    printf("L1 invertida em L2:\n");
    for (int i = 0; i < n1; i++) printf("%d ", L2[i]);
    printf("\n");

    reverseInPlace(L1, n1);
    printf("L1 invertida na própria lista:\n");
    for (int i = 0; i < n1; i++) printf("%d ", L1[i]);
    printf("\n");

    int L2Copy[] = {0, 2, 6};
    n2 = 3;
    n3 = mergeLists(L1, n1, L2Copy, n2, L3);
    printf("Intercalando L1 e L2:\n");
    for (int i = 0; i < n3; i++) printf("%d ", L3[i]);
    printf("\n");

    int sizeCount = generateCountList(L1, n1, L2Count);
    printf("Lista L2 com contagem:\n");
    for (int i = 0; i < sizeCount; i++) {
        printf("Elemento: %d, Contagem: %d\n", L2Count[i].elem, L2Count[i].count);
    }

    int newSize = removeOccurrences(L1, n1, 2);
    printf("L1 após remover todas as ocorrências de 2:\n");
    for (int i = 0; i < newSize; i++) printf("%d ", L1[i]);
    printf("\n");

    int minElem, maxElem, minCount, maxCount;
    findMinMaxOccurrences(L1, newSize, &minElem, &maxElem, &minCount, &maxCount);
    printf("Elemento com menor ocorrências: %d (%d vezes)\n", minElem, minCount);
    printf("Elemento com maior ocorrências: %d (%d vezes)\n", maxElem, maxCount);

    return 0;
}
