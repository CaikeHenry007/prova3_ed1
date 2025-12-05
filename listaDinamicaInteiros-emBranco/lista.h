#define TAM_MAX 5

#include <stdio.h>
#include <stdlib.h>

void inserir(int numero, int posicao);
int remover(int posicao);
void imprimir();
void inicializar();
int verificarVazia();

//Funcoes para testes automatizados
void testar1_VaziaLista();
void testar3_RemoverLista();
void testar4_RemoverLista(int quant);
