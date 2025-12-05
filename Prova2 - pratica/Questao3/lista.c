#include <stdio.h>
#include "lista.h"

Lista l;

void inicializar() {
    l.fim = -1;
}

int verificarVazia() {
    if(l.fim == -1) 
        return 1;
    else return 0;
}

int verificarCheia() {
    if(l.fim == TAM_MAX-1)
        return 1;
    else return 0;
}

void inserir(int dado, int posicao) {
    //verificar se a lista nao estah cheia
    if(!verificarCheia()) {
         //verifica se a posicao eh maior ao final
        if(posicao > l.fim) {
            //atualiza final
            l.fim++;
            //guarda elemento na posicao final
            l.vetor[l.fim] = dado;
        } else{
        //senao
            //deixar a posicao livre transladando os elementos
            int i;
            for(i = l.fim; i >= posicao; i--)
                l.vetor[i+1] = l.vetor[i];
            //guarda elemento na posicao desejada
            l.vetor[posicao] = dado;
            //atualiza final
            l.fim++;
        }
    } else {
        //se ela estiver cheia, avisar usuario
        printf("\nA lista estah cheia");
    }
}

void imprimir() {
	//verifica se a lista estah vazia
    if(!verificarVazia()) {
        int i;
        printf("Os elementos na lista sao: ");
        //percorre o vetor do inicio ao fim imprimindo os elementos
        for(i = 0; i <= l.fim; i++)
            printf(" %d", l.vetor[i]);
    } else {
    	//se a lista estiver vazia, informa o usuario
        printf("\nA lista estah vazia");
    }
}

int remover(int posicao)  {
    //verifica se a lista nao estah vazia
    if(!verificarVazia()) {
        //verifica se existe elemento valido na posicao desejada
        if(posicao <= l.fim) {
            //define uma variavel auxiliar
            int aux, i;
	        //variavel auxiliar guarda o elemento da posicao
            aux = l.vetor[posicao];
	        //transladar os elementos da posicao + 1 ate final
            for(i = posicao; i < l.fim; i++)
                l.vetor[i] = l.vetor[i+1];
	        //atualiza o final da lista
            l.fim--;
            //retorna o valor removido
            return aux;
        } else {
            //se nao existe elemento na posicao, informa usuario
            printf("\nA posicao informada nao possui elemento valido");       
        }
	 
    } else {
        //se lista vazia, informa o usuario
        printf("\nA lista estah vazia");
    }
}
