////////////////////////////////////////////////////
// Programa que implementa uma Arvore rubro-negra//
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////
// declara��o de estruturas//
/////////////////////////////

struct no{
	int numero;
	struct no *esquerda;
	struct no *direita;
	int cor; // 0: preto   1: vermelho
	
};

/////////////////////////////////////////////
//fun��o que rotaciona a arvore � esquerda//
///////////////////////////////////////////

struct no *rotacionarEsquerda(struct no *raiz){
	// rota��o propriamente dita
	struct no *temp = raiz -> direita;
	raiz -> direita = temp -> esquerda;
	temp -> esquerda = raiz;
	
	//ajuste de cor
	temp -> cor = raiz -> cor;
	raiz -> cor = 1;
	
	// retorno
	return temp;
}

/////////////////////////////////////////////
//fun��o que rotaciona a arvore � Direita //
///////////////////////////////////////////

struct no *rotacionarDireita(struct no *raiz){
	// rota��o propriamente dita
	struct no *temp = raiz -> esquerda;
	raiz -> esquerda = temp -> direita;
	temp -> direita = raiz;
	
	//ajuste de cor
	temp -> cor = raiz -> cor;
	raiz -> cor = 1;
	
	// retorno
	return temp;
}

////////////////////////////////
//fun��o que sobe o vermelho //
///////////////////////////////

void subirVermelho(struct no *raiz){
	raiz -> cor = 1;
	raiz -> esquerda -> cor = 0;
	raiz -> direita -> cor = 0;
}

//////////////////////////////////////
// fun��o que determina a cor do n�//
/////////////////////////////////////

int vermelho(struct no *raiz){
	int retorno = 0;
	
	if (raiz != NULL){
		retorno = raiz -> cor;
	}
	
	return retorno;
}

////////////////////////////////////////
// fun��o que insere um n� na arvore //
///////////////////////////////////////

struct no *inserir(struct no *raiz, int numero){
	// inser��o como arvore de busca
	if (raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		raiz -> cor = 1;
		
	} else {
		if (numero < raiz -> numero){
			raiz -> esquerda = inserir(raiz -> esquerda, numero);			
		} else {
			raiz -> direita = inserir( raiz -> direita, numero);
		}
	}
	
	// balanceamento da arvore
	if ((! vermelho(raiz -> esquerda)) && (vermelho(raiz -> direita))){
		raiz = rotacionarEsquerda(raiz);
	}
	
	if (vermelho(raiz -> esquerda) && vermelho(raiz -> esquerda -> esquerda)){
		raiz = rotacionarDireita(raiz);

	}
	
	if (vermelho(raiz -> esquerda) && vermelho(raiz -> direita)){
		subirVermelho(raiz);
	}
	// retorno
	return raiz;
}

//////////////////////////////////
// Fun��o que imprime a arvore //
////////////////////////////////

void imprimir (struct no *raiz, char *endentacao){
	if (raiz != NULL){
		printf("%s%d\n", endentacao, raiz -> numero);
		
		char *temp = (char *) malloc(1024 * sizeof(char));
		strcpy(temp, "---");
		strcat(temp, endentacao);
		
		
		imprimir(raiz -> esquerda, temp);
		imprimir(raiz -> direita, temp);
	}
		
}

///////////////////////
// fun��o principal //
/////////////////////

int main(){
	struct no *raiz = NULL;
	int i = 0;
	for (i = 0; i < 10; i++){
		raiz = inserir(raiz, i);
		
	}
	
	imprimir(raiz, "");
}
