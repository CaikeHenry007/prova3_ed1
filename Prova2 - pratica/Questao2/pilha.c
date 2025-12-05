#include <stdio.h>
#include "pilha.h"

pilha p;

void inicializarPilha() {
    p.topo = -1;
}

int verificarVazia() {
    if(p.topo == -1)
        return 1;
    else return 0;
}

int verificarCheia() {
    if(p.topo == TAM_MAX-1)
        return 1;
    else return 0;
}

void push(anilha dado) {
	//verificar se a pilha nao estah cheia
    if(!verificarCheia()) {
            //atualiza o topo da pilha
            p.topo++;
            //insere o elemento no vetor na posição topo
            p.vetor[p.topo] = dado;
    } else {
	    //se estiver cheia, informa o usuário
        printf("\nA pilha estah");
    }
}

void imprimir() {
    //verificar se a pilha nao esta vazia
    if(!verificarVazia()) {
        //define uma variavel auxiliar
        int i;
        //percorre o vetor do topo ate a base
        for(i = p.topo; i >= 0; i--)
            //imprimir o elemento na posicao
            printf("\n Anilha \n\t\tDiametro: %d cm \tPeso: %d kg", 
                		p.vetor[i].diametro, p.vetor[i].peso);
    } else {
        //se estiver vazia, informa o usuario
        printf("\nA pilha estah vazia");
    }
}

anilha pop() {
    //verificar se a pilha nAo estah vazia
    if(!verificarVazia()) {
        //define variavel aux
        anilha aux;
        //aux irah guardar o elemento do topo da pilha
        aux = p.vetor[p.topo];
        //atualiza o topo da pilha
        p.topo--;
        //retorna numero removido
        return aux;
    } else {
        anilha aux = {-1, -1};
        //se estiver vazia, informa o usuario
        printf("A pilha estah vazia");
        return aux;
    }
}
