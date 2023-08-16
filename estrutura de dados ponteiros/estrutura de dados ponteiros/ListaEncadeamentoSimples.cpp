//////////////////////////////////////////////
// Programa de lista de encadeamento Simples//
//////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>


// Declara��o da estrutura do N�

struct no {
	int numero;
	struct no *proximo;
};

// Declara��o de variaveis

struct no *cabeca = NULL;

// Fun��o que inseri um n� na lista

void inserir(int numero){
	// Aloca��o do espa�o de mem�ria
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if(cabeca == NULL){
		//caso facil, a lista esta vazia
		cabeca = novoNo;
	} else {
		//caso dificil, a lista n�o est� vazia
		struct no *ponteiro = cabeca;
		
		while(ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
		
	}
	
}

// Fun��o que imprime os nos da lista

void imprimir(){
	printf("==================================\n");
	
	
	struct no*ponteiro = cabeca;
	
	while (ponteiro != NULL){
		printf("%d\n", ponteiro->numero);
		ponteiro = ponteiro -> proximo;
	}
}
// fun��o que exclui o no da lista

void remover(int numero){
	if (cabeca != NULL){
		if (cabeca -> numero == numero){
			struct no *ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free (ponteiroExcluir);
		} else {
			struct no *ponteiroAnterior = cabeca;
			
			while((ponteiroAnterior -> proximo != NULL) &&
				  (ponteiroAnterior -> proximo -> numero != numero)){
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

// fun��o principal de execu��o do programa

int main(int argc, char *argv[]){

	int opcao =0;
	int numero = 0;
	
	while (opcao != 4){
		printf("+=======================+\n");
		printf("|     Menu de Opcoes    |\n");
		printf("+=======================+\n");
		printf("|  1 - Inserir          |\n");
		printf("|  2 - Remover          |\n");
		printf("|  3 - Imprimir         |\n");
		printf("|  4 - Sair             |\n");
		printf("+=======================+\n");
		printf("Digite a opcao:  ");
		scanf("%d", &opcao);
		
		
		switch (opcao){
			case 1:
				printf("Digite o numero:  ");
				scanf("%d", &numero);
				inserir(numero);
				break;
			case 2:
				printf("Digite o numero:  ");
				scanf("%d", &numero);
				remover(numero);
				break;
			case 3:
				imprimir();
				break;
						
		}
	}
	

}



