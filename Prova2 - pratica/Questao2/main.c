#include <stdio.h>
#include "pilha.h"
#include "string.h"

int main(int argc, char *argv[]) {
	int temp, opcao;
	anilha auxiliar;
	inicializarPilha();

	do {
		//exibir o menu
		printf("\n\n\nQUESTAO 1 - EMPILHAMENTO DE CAIXAS");
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializarPilha();
				break;
			case 2:
				printf("Digite o diametro: ");
				scanf("%d", &auxiliar.diametro);
				printf("Digite o peso: ");
				scanf("%d", &auxiliar.peso);
				push(auxiliar);
				break;
			case 3:
				auxiliar = pop();
				if(auxiliar.diametro > 0) {
					printf("\n Anilha removida \n\t\tDiametro: %d cm \tPeso: %d kg", 
                		auxiliar.diametro, auxiliar.peso);
            	}
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 5);
}

