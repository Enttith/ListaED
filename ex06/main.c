#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[100];
    char telefone[15];
    char email[100];
} Contato;

typedef struct Node {
    Contato contato;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} ListaContatos;

// Cria lista vazia
ListaContatos* criarLista() {
    ListaContatos *lista = (ListaContatos *)malloc(sizeof(ListaContatos));
    lista->head = NULL;
    return lista;
}

// Cria um novo nó
Node* criarNode(Contato contato) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->contato = contato;
    novo->next = NULL;
    return novo;
}

// Insere contato na lista
void inserirContato(ListaContatos *lista, Contato contato) {
    Node *novo = criarNode(contato);
    novo->next = lista->head;
    lista->head = novo;
    printf("Contato inserido com sucesso!\n");
}

// Função para remover um contato pelo nome
bool removerContato(ListaContatos *lista, const char *nome) {
    Node *current = lista->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->contato.nome, nome) == 0) {
            if (prev == NULL) {
                lista->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Contato removido com sucesso!\n");
            return true;
        }
        prev = current;
        current = current->next;
    }
    printf("Contato não encontrado!\n");
    return false;
}

// Função que buscar um contato pelo nome
Node* buscarContato(ListaContatos *lista, const char *nome) {
    Node *current = lista->head;

    while (current != NULL) {
        if (strcmp(current->contato.nome, nome) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Função atualiza o nome do contato
void atualizarNome(Node *node, const char *novoNome) {
    strcpy(node->contato.nome, novoNome);
    printf("Nome atualizado com sucesso!\n");
}

// Função que atualiza o telefone do contato
void atualizarTelefone(Node *node, const char *novoTelefone) {
    strcpy(node->contato.telefone, novoTelefone);
    printf("Telefone atualizado com sucesso!\n");
}

// Função atualiza o email do contato
void atualizarEmail(Node *node, const char *novoEmail) {
    strcpy(node->contato.email, novoEmail);
    printf("Email atualizado com sucesso!\n");
}

// Função para imprimir a lista de contatos
void imprimirContatos(ListaContatos *lista) {
    Node *current = lista->head;

    if (current == NULL) {
        printf("A lista de contatos está vazia!\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    while (current != NULL) {
        printf("Nome: %s\n", current->contato.nome);
        printf("Telefone: %s\n", current->contato.telefone);
        printf("Email: %s\n\n", current->contato.email);
        current = current->next;
    }
}

// Função para liberar a memória da lista
void liberarLista(ListaContatos *lista) {
    Node *current = lista->head;

    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(lista);
}

void interface() {
    ListaContatos *lista = criarLista();
    int opcao;
    char nome[100], telefone[15], email[100];

    do {
        printf("\n--- Agenda de Contatos ---\n");
        printf("1. Inserir Contato\n");
        printf("2. Remover Contato\n");
        printf("3. Buscar Contato\n");
        printf("4. Atualizar Contato\n");
        printf("5. Listar Contatos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);
                printf("Digite o telefone: ");
                scanf(" %[^\n]", telefone);
                printf("Digite o email: ");
                scanf(" %[^\n]", email);

                Contato novoContato;
                strcpy(novoContato.nome, nome);
                strcpy(novoContato.telefone, telefone);
                strcpy(novoContato.email, email);

                inserirContato(lista, novoContato);
                break;

            case 2:
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removerContato(lista, nome);
                break;

            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);

                Node *busca = buscarContato(lista, nome);
                if (busca) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", busca->contato.nome);
                    printf("Telefone: %s\n", busca->contato.telefone);
                    printf("Email: %s\n", busca->contato.email);
                } else {
                    printf("Contato não encontrado!\n");
                }
                break;

            case 4:
                printf("Digite o nome do contato a ser atualizado: ");
                scanf(" %[^\n]", nome);

                Node *atualizar = buscarContato(lista, nome);
                if (atualizar) {
                    printf("Digite o novo nome (ou pressione Enter para manter): ");
                    scanf(" %[^\n]", nome);
                    atualizarNome(atualizar, nome);

                    printf("Digite o novo telefone (ou pressione Enter para manter): ");
                    scanf(" %[^\n]", telefone);
                    atualizarTelefone(atualizar, telefone);

                    printf("Digite o novo email (ou pressione Enter para manter): ");
                    scanf(" %[^\n]", email);
                    atualizarEmail(atualizar, email);
                } else {
                    printf("Contato não encontrado!\n");
                }
                break;

            case 5:
                imprimirContatos(lista);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    liberarLista(lista);
}

int main() {
    interface();
    return 0;
}
