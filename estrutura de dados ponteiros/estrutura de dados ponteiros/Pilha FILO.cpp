///////////////////////////////////////////////////////////////
// programa que implementa uma Pilha FILO(First in Last out)//
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////
// Declara��o do n� //
/////////////////////

struct no{
	int numero;
	struct no *proximo;
};

//////////////////////////////
// Declara��o de variaveis //
/////////////////////////////

struct no *cabeca = NULL;

/////////////////////////////////////
// Fun��o que inseri o n� na fila //
////////////////////////////////////

void push(int numero){
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

/////////////////////////////////////
// Fun��o que Remove um no da fila//
////////////////////////////////////

int pop(){
	int retorno = -1;
	
	if(cabeca != NULL) {
		retorno = cabeca -> numero;
		struct no *ponteiro = cabeca;
		cabeca = cabeca -> proximo;
		free(ponteiro);
	}
	
	
	return retorno;
}

//////////////////////////////////////////////
// Fun��o principal de execu��o do programa//
/////////////////////////////////////////////
int main(){
	int opcao =0;
	int numero = 0;
	
	while (opcao != 4){
		printf("+=======================+\n");
		printf("|     Menu de Opcoes    |\n");
		printf("+=======================+\n");
		printf("|  1 - Inserir          |\n");
		printf("|  2 - Remover          |\n");
		printf("|  3 - Sair             |\n");
		printf("+=======================+\n");
		printf("Digite a opcao:  ");
		scanf("%d", &opcao);
		
		
		switch (opcao){
			case 1:
				printf("Digite o numero:  ");
				scanf("%d", &numero);
				push(numero);
				break;
			case 2:
				printf("Removi o numero %d da fila\n", pop());
				break;	
		}
	}
	

}







