/////////////////////////////////////////////////////////////////////////////
// Programa que implementa uma arvore binaria e suas respectivas navega��es//
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////
// declara��o de estruturas//
/////////////////////////////

struct no{
	int numero;
	struct no *esquerda;
	struct no *direita;

};


///////////////////////////////////////
// fun��o que inseri um n� na arvore//
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
// Navega��o em Pr� Ordem//
///////////////////////////

void navegarPreOrdem(struct no *raiz){
	if (raiz != NULL){
		printf("%d\t", raiz -> numero);
		navegarPreOrdem(raiz -> esquerda);
		navegarPreOrdem(raiz -> direita);
		
	}
	
}
////////////////////////////
// Navega��o em EM Ordem //
///////////////////////////
void navegarEmOrdem(struct no *raiz){
	if (raiz != NULL){
		navegarEmOrdem(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
		
	}
	
}

////////////////////////////
// Navega��o em POS Ordem //
///////////////////////////
void navegarPosOrdem(struct no *raiz){
	if (raiz != NULL){
		navegarEmOrdem(raiz -> esquerda);
		navegarEmOrdem(raiz -> direita);
		printf("%d\t", raiz -> numero);
		
	}
	
}

//////////////////////////////////
// fun�ao principal do programa//
/////////////////////////////////

int main(){
	// declara��o de variaveis
	struct no *raiz = NULL;
	
	// inicializa��o da aleatoriedade
	time_t t;
	srand((unsigned)time(&t));
	
	// preenchimento da �rvore
	int i = 0;
	for (i = 0; i < 10; i++){
		raiz = inserir(raiz, i);
		
	}
	
	// navega��es
	printf("\n ======================================== PRE-ORDEM ========================================\n");
	navegarPreOrdem(raiz);
	
	printf("\n ======================================== EM-ORDEM ========================================\n");
	navegarEmOrdem(raiz);
	
	printf("\n ======================================== POS-ORDEM ========================================\n");
	navegarPosOrdem(raiz);
}










