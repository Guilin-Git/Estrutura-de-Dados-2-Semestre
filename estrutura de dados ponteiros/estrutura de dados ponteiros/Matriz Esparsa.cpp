#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////
// Declaração de constante //
/////////////////////////////

const int MODULO = 3;


///////////////////////
// Declaração do nó //
/////////////////////

struct no{
	int numero;
	struct no *proximoNo;
};

struct diretor{
	int resto;
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};

//////////////////////////////
// Declaração de variaveis //
/////////////////////////////

struct diretor *cabeca = NULL;


////////////////////////////////////////
// Função que procura o diretor certo//
///////////////////////////////////////

struct diretor *proximoDiretor(int resto){
	struct diretor *ponteiro = cabeca;
	
	// varrendo a lista até achar o resto certo ou chegar no final
	while((ponteiro != NULL) && (ponteiro -> resto != resto)){
		ponteiro = ponteiro -> proximoDiretor;
		
	}
	
	
	if (ponteiro == NULL){
		// Criar um diretor novo
		ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
		ponteiro -> resto = resto;
		ponteiro -> proximoNo = NULL;
		ponteiro -> proximoDiretor = cabeca;
		
		cabeca = ponteiro;
	}
	return ponteiro;
}

///////////////////////////////////////////////
// função que inseri um no na matriz esparsa//
//////////////////////////////////////////////

void inserir(int numero){
	struct diretor *ponteiroDiretor = proximoDiretor(numero % MODULO);
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
	
	ponteiroDiretor -> proximoNo = novoNo;
	
	
}

/////////////////////////////////////////
// função que imprime a matriz esparsa//
////////////////////////////////////////
void imprimir(){
	struct diretor *ponteiroDiretor = cabeca;
	
	printf("========================= MATRIZ ESPARSA =========================\n");
	while(ponteiroDiretor != NULL){
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
		
		printf("%d:\t", ponteiroDiretor -> resto);
		while (ponteiroNo != NULL){
			printf("%d\t", ponteiroNo -> numero);
			ponteiroNo = ponteiroNo -> proximoNo;
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
				
		
	}
}

//////////////////////////////////////////
// função que remove um valor da matriz//
/////////////////////////////////////////

void remover(int numero){
	struct diretor *ponteiroDiretor = proximoDiretor(numero % MODULO);
	
	if (ponteiroDiretor -> proximoNo != NULL){
		if (ponteiroDiretor -> proximoNo -> numero == numero){
			struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
			ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
			free (ponteiroExcluir);
			
			
		} else {
			struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;
			
			while((ponteiroAnterior -> proximoNo != NULL) &&
				  (ponteiroAnterior -> proximoNo -> numero != numero)){
				ponteiroAnterior = ponteiroAnterior -> proximoNo;
			}
			
			if(ponteiroAnterior -> proximoNo != NULL){
				struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
				ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
				free(ponteiroExcluir);
			}
		}
	}	
}






//////////////////////////////////
// função principal do programa//
/////////////////////////////////

int main() {
    int i = 0;
    int numero = 0;
    char x;
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < 10; i++) {
        inserir(rand());
    }

    imprimir();

    do {
        printf("Digite um número para excluir: ");
        scanf("%d", &numero);

        remover(numero);

        imprimir();
        printf("Deseja continuar excluindo? (s/n) \n");
        
        // Limpeza do buffer de entrada para evitar problemas com a leitura do caractere 'x'
        while (getchar() != '\n');

        scanf("%c", &x);
    } while (x == 's');

    return 0;
}






