#include <stdio.h>
#include "lista.h"


void inicializar(){
}

int verificarVazia(){
}

void inserir(int numero, int posicao){
	//alocar memoria para um novo noh da lista
	//se foi alocada memoria, adiciona o novoNo na lista
		//atribuir o elemento ao membro dado do novo noh
		//atribuir NULL ao campo proximo do novo noh
		//verificar se a lista estah vazia ou se deseja inserir elemento na primeira posicao
			//o campo proximo do novo noh devera apontar para o noh apontado no inicio
			//atualiza o inicio da lista
		//senao
			//criar um ponteiro para no chamado auxiliar
			//criar uma variavel contador para saber qual a posicao do noh que auxiliar aponta e inicia com 1
			//ponteiro auxiliar aponta para o primeiro noh da lista
			//percorre a lista ateh encontrar o noh na posicao-1 ou o final da lista
			//atualiza o campo proximo do novoNoh
			//atualiza o campo proximo do noh auxiliar
	//senao informa o usuario que nao ha mais memoria
}

void imprimir() {
	//verificar se a lista nao estah vazia
		//Declara uma variavel ponteiro auxiliar para percorrer os nohs da lista
		//comeca a percorrer a partir do inicio
		//enquanto nao chegar no fim
			//imprimir o dado do noh apontado pelo ponteiro auxiliar
			//vai para o proximo noh
	//se estiver vazia, informa o usuario
}

int remover(int posicao) {
	//verifica se a lista nao estah vazia
		//cria variavel auxiliar ponteiro para um noh
		//cria variavel para guardar o dado do noh a ser removido
		//verificar se eh o primeiro elemento q sera removido
			//variavel auxiliar aponta para o primeiro noh
			//atualiza o inicio da lista
		//senao
			//declara uma variavel ponteiro noAnterior para percorrer os nohs da lista
			//criar uma variavel contador para saber qual a posicao do noh que anoAnterior aponta e inicia com 1
			//ponteiro noAnterior aponta para o primeiro noh da lista
			//percorre a lista ateh encontra o noh de posicao anterior ao noh da posicao a remover ou final da lista
			//se existir um noh na posicao desejada
				//ponteiro auxiliar aponta para o noh a ser removido
				//atualiza o membro proximo do noh anterior para apontar para o noh seguinte ao no apontado pelo ponteiro auxiliar
			//se nao existe um noh na posicao desejada
				//informa ao usuario que nao existe elemento na posicao indicada
		//atribuir o dado do noh a remover para a variavel dado	
		//libera a memoria ocupada pelo noh removido
		//retorna o valor do noh removido
	//senao informa que a lista estah vazia
}


//Funcoes para testes automatizados
void emitirResultado(int resultado) {
	if(resultado) 
		printf("\nGREEN: Passou!");
	else printf("\nRED: Nao passou!");
}

void testar1_VaziaLista(){
	printf("\nTeste 1: Este teste irah verificar a lista vazia");
	inicializar();
	if(verificarVazia()) {
		emitirResultado(1);
	} else emitirResultado(0);
}


void testar3_RemoverLista(){
	int removido = 0;
	printf("\nTeste 3: Este teste irah tentar remover de uma lista vazia");
	inicializar();
	removido = remover(0);
	if(verificarVazia())
		emitirResultado(1);
	else emitirResultado(0);
}

void testar4_RemoverLista(int quant){
	if(quant > 10) {
		printf("\nSo eh possivel testar com lista com ateh 10 elementos");
	} else {
		int i, respostaEsperada, removido,
		    numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
			posicao[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
			posicaoRemover[10][10] = {
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
								{4, 2, 0, 1, 0, 0, 0, 0, 0, 0},
								{3, 4, 0, 2, 0, 0, 0, 0, 0, 0},
								{6, 1, 4, 0, 2, 1, 0, 0, 0, 0},
								{5, 2, 5, 2, 0, 2, 1, 0, 0, 0},
								{7, 7, 3, 5, 0, 2, 2, 1, 0, 0},
								{5, 5, 5, 0, 4, 4, 2, 1, 1, 0}
								},
				saida[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
								 {3, 1, 2, 0, 0, 0, 0, 0, 0, 0},
								 {3, 4, 2, 1, 0, 0, 0, 0, 0, 0},
								 {5, 3, 1, 4, 2, 0, 0, 0, 0, 0},
								 {4, 6, 1, 5, 2, 3, 0, 0, 0, 0},
								 {7, 2, 6, 1, 5, 4, 3, 0, 0, 0},
								 {6, 3, 8, 4, 1, 7, 5, 2, 0, 0},
								 {8, 9, 4, 7, 1, 5, 6, 3, 2, 0},
								 {6, 7, 8, 1, 9, 10, 4, 3, 5, 2}
								};
		printf("\nTeste 4: Este teste irah inserir %d elemento na lista e remove-lo, deixando a lista vazia", quant);

		inicializar();
		for(i = 0; i < quant; i++)
			inserir(numeros[i], posicao[i]+1);

		if(quant > TAM_MAX)
			respostaEsperada = TAM_MAX-1;
		else respostaEsperada = quant-1;
		
		for(i = 0; i < quant && i < TAM_MAX; i++) {
			removido = remover(posicaoRemover[respostaEsperada][i]+1);
			
			if(removido != saida[respostaEsperada][i]) {
				emitirResultado(0);
				return;
			}
		}
		//verifica se a lista ficou vazia
		if(verificarVazia())
			emitirResultado(1);
		else emitirResultado(0);
		}
}

