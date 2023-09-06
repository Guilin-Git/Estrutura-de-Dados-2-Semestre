////////////////////////////////////////////////
// Programa que implementa uma matriz esparsa//
///////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////
// Declara��o de constante //
/////////////////////////////

const int MODULO = 3;


///////////////////////
// Declara��o do n� //
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
// Declara��o de variaveis //
/////////////////////////////

struct diretor *cabeca = NULL;


////////////////////////////////////////
// Fun��o que procura o diretor certo//
///////////////////////////////////////

struct diretor *proximoDiretor(int resto){
	struct diretor *ponteiro = cabeca;
	
	// varrendo a lista at� achar o resto certo ou chegar no final
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
// fun��o que inseri um no na matriz esparsa//
//////////////////////////////////////////////

void inserir(int numero){
	struct diretor *ponteiroDiretor = proximoDiretor(numero % MODULO);
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
	
	ponteiroDiretor -> proximoNo = novoNo;
	
	
}

/////////////////////////////////////////
// fun��o que imprime a matriz esparsa//
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
// fun��o que remove um valor da matriz//
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
// fun��o principal do programa//
/////////////////////////////////

int main(){
	int i = 0;
	int numero =0;
	char x;
	time_t t;
	
	srand((unsigned) time(&t));
	
	for (i = 0; i < 10; i++){
		inserir(rand());
	}
	
	imprimir();
	
	while(x == 's'){
		
	printf("digite um numero para excluir:  ");
	scanf("%d", &numero);
	
	remover(numero);
	
	imprimir();
	printf("deseja continuar excluindo ? s/n \n");
	scanf("%c", &x);
	if(x == 'n'){
		break;
	}
		
	}

}









