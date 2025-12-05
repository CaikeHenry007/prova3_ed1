#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct lista {
    No *inicio;
} Lista;

Lista l;

void inicializar() {
    l.inicio = NULL;
}

int verificarVazia() {
    return l.inicio == NULL;
}

void inserirInicio(int numero) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->dado = numero;
        novo->proximo = l.inicio;
        l.inicio = novo;
    } else {
        printf("\nSem memoria disponivel.");
    }
}

int removerInicio() {
    if (!verificarVazia()) {
        No *aux = l.inicio;
        int dado = aux->dado;

        l.inicio = aux->proximo;
        free(aux);
        return dado;
    } else {
        printf("\nA lista esta vazia.");
        return 0;
    }
}

void imprimir() {
    if (!verificarVazia()) {
        No *aux = l.inicio;

        while (aux != NULL) {
            printf(" %d", aux->dado);
            aux = aux->proximo;
        }
    } else {
        printf("\nA lista esta vazia.");
    }
}

int main() {
    int opcao, temp;
    inicializar();

    do {
        printf("\n--- MENU LISTA ---");
        printf("\n1. Inserir no inicio");
        printf("\n2. Remover do inicio");
        printf("\n3. Imprimir");
        printf("\n4. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &temp);
                inserirInicio(temp);
                break;

            case 2:
                temp = removerInicio();
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
