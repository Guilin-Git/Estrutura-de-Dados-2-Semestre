//////////////////////////////////////////////
// Programa de lista de encadeamento Simples//
//////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>


// Declaração da estrutura do Nó

struct no {
	int numero;
	struct no *proximo;
};

// Declaração de variaveis

struct no *cabeca = NULL;

// Função que inseri um nó na lista

void inserir(int pnumero){
	// Alocação do espaço de memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = pnumero;
	novoNo -> proximo = NULL;
	
	if(cabeca == NULL){
		//caso facil, a lista esta vazia
		cabeca = novoNo;
	} else {
		//caso dificil, a lista não está vazia
		struct no *ponteiro = cabeca;
		
		while(ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
		
	}
	
}

// Função que imprime os nos da lista

void imprimir(){
	printf("==================================\n");
	
	
	struct no*ponteiro = cabeca;
	
	while (ponteiro != NULL){
		printf("%d\n", ponteiro->numero);
		ponteiro = ponteiro -> proximo;
	}
}
// função que exclui o no da lista

void remover(int pnumero){
	if (cabeca != NULL){
		if (cabeca -> numero == pnumero){
			struct no *ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free (ponteiroExcluir);
		} else {
			struct no *ponteiroAnterior = cabeca;
			
			while((ponteiroAnterior -> proximo != NULL) &&
				  (ponteiroAnterior -> proximo -> numero != pnumero)){
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			
			if(ponteiroAnterior -> proximo != NULL){
				struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);
			}
		}
	}	
}

// função principal de execução do programa

int main(int argc, char *argv[]){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	inserir(7);
	inserir(8);
	inserir(9);
	inserir(10);
	inserir(11);
	
	imprimir();
	
	
	remover(100);
	remover(1);
	remover(3);
	remover(10);
	
	imprimir();
}



