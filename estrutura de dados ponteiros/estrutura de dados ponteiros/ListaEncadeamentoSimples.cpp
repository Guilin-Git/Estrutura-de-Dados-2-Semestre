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

void inserir(int numero){
	// Alocação do espaço de memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
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

// função principal de execução do programa

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



