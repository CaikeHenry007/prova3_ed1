#define TAM_MAX 5 

typedef struct _anilha {
    int peso;
    int diametro;
} anilha;

typedef struct _pilha {
    anilha vetor[TAM_MAX];
    int topo;
} pilha;

void inicializarPilha();
int verificarVazia();
int verificarCheia();
void push(anilha dado);
void imprimir();
anilha pop();
