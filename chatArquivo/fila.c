#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

Fila f;

void inicializar() {
    f.inicio = NULL;
    f.fim = NULL;
}

int verificarVazia() {
    return f.inicio == NULL;
}

void enqueue(int numero) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->dado = numero;
        novo->proximo = NULL;

        if (verificarVazia())
            f.inicio = novo;
        else
            f.fim->proximo = novo;

        f.fim = novo;
    } else {
        printf("\nSem memoria disponivel.");
    }
}

int dequeue() {
    if (!verificarVazia()) {
        No *aux = f.inicio;
        int dado = aux->dado;

        f.inicio = aux->proximo;

        if (f.inicio == NULL)
            f.fim = NULL;

        free(aux);
        return dado;
    } else {
        printf("\nA fila esta vazia.");
        return 0;
    }
}

void imprimir() {
    if (!verificarVazia()) {
        No *aux = f.inicio;

        while (aux != NULL) {
            printf(" %d", aux->dado);
            aux = aux->proximo;
        }
    } else {
        printf("\nA fila esta vazia.");
    }
}

int main() {
    int opcao, temp;
    inicializar();

    do {
        printf("\n--- MENU FILA ---");
        printf("\n1. Inserir");
        printf("\n2. Remover");
        printf("\n3. Imprimir");
        printf("\n4. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &temp);
                enqueue(temp);
                break;

            case 2:
                temp = dequeue();
                printf("\nRemovido: %d", temp);
                break;

            case 3:
                imprimir();
                break;

            case 4:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpcao invalida!");
        }

    } while (opcao != 4);
}

