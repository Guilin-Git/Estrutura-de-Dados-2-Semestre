/////////////////////////////////////////////////////////////////////////////
// Programa que implementa uma arvore binaria e suas respectivas navegações//
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////
// declaração de estruturas//
/////////////////////////////

struct no{
	int numero;
	struct no *esquerda;
	struct no *direita;

};


///////////////////////////////////////
// função que inseri um nó na arvore//
//////////////////////////////////////

struct no *inserir(struct no *raiz, int numero){
	if (raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		
	}else{
		if ((rand() % 2) == 0){
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
			
		}else{
			raiz -> direita = inserir(raiz -> direita, numero);
		}
		
	}
	
	
	
	return raiz;
}

////////////////////////////
// Navegação em Pré Ordem//
///////////////////////////

void navegarPreOrdem(struct no *raiz){
	if (raiz != NULL){
		printf("%d\t", raiz -> numero);
		navegarPreOrdem(raiz -> esquerda);
		navegarPreOrdem(raiz -> direita);
		
	}
	
}
////////////////////////////
// Navegação em EM Ordem //
///////////////////////////
void navegarEmOrdem(struct no *raiz){
	if (raiz != NULL){
		navegarEmOrdem(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
		
	}
	
}

////////////////////////////
// Navegação em POS Ordem //
///////////////////////////
void navegarPosOrdem(struct no *raiz){
	if (raiz != NULL){
		navegarEmOrdem(raiz -> esquerda);
		navegarEmOrdem(raiz -> direita);
		printf("%d\t", raiz -> numero);
		
	}
	
}

//////////////////////////////////
// funçao principal do programa//
/////////////////////////////////

int main(){
	// declaração de variaveis
	struct no *raiz = NULL;
	
	// inicialização da aleatoriedade
	time_t t;
	srand((unsigned)time(&t));
	
	// preenchimento da árvore
	int i = 0;
	for (i = 0; i < 10; i++){
		raiz = inserir(raiz, i);
		
	}
	
	// navegações
	printf("\n ======================================== PRE-ORDEM ========================================\n");
	navegarPreOrdem(raiz);
	
	printf("\n ======================================== EM-ORDEM ========================================\n");
	navegarEmOrdem(raiz);
	
	printf("\n ======================================== POS-ORDEM ========================================\n");
	navegarPosOrdem(raiz);
}










