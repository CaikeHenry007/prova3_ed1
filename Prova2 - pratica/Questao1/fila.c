#include <stdio.h>
#include "fila.h"

Fila f;

void inicializar(){
	f.final = -1;
}

int verificarVazia(){
	if(f.final == -1)
		return 1;
	else return 0;
}

int verificarCheia() {
	if(f.final == TAM_MAX - 1)
		return 1;
	else return 0;
}

void inserir(int numero){
	//verificar se a fila nao estah cheia
	if(!verificarCheia()) {
		//atualiza o final da fila	
		f.final++;
		//insere o numero no vetor no final
		f.vetor[f.final] = numero;
	} else {
		//informa o usuario que a fila estah cheia
		printf("\nA fila estah cheia.");
	}
}

void imprimir(){
	//verificar se a fila nao estah vazia
	if(!verificarVazia()) {
		int i;
		printf("\nOs elementos na fila sao: ");
		//percorrer o vetor de 0 ateh f.final
		for(i = 0; i <= f.final; i++)
			//imprimir o elemento na posicao i
			printf(" %d", f.vetor[i]);
	} else {
		printf("\nA fila estah vazia.");
	}
}

int remover() {
	//verificar se a fila nao estah vazia
	if(!verificarVazia()) {
		int aux, i;
		//aux irah guardar o elemento do inicio da fila
		aux = f.vetor[0];
		//translada os elementos do inicio ao fim -1
		for(i = 0; i <= f.final -1; i++)
			//a posicao i receber o valor da posicao i+1
			f.vetor[i] = f.vetor[i+1];
		//atualizar o final da fila
		f.final--;
		return aux;
	} else {
		printf("A fila estah vazia.");
	}
}
