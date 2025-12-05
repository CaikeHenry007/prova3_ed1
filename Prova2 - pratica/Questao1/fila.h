#define TAM_MAX 5

typedef struct fila {
	int vetor[TAM_MAX];
	int final;
} Fila;

void inicializar();
int verificarVazia();
int verificarCheia();
void inserir(int numero);
void imprimir();
int remover();
