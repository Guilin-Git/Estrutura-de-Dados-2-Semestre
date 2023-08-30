//////////////////////////////////////////////////////////////
// programa que implementa uma fila FIFO(First in First out)//
/////////////////////////////////////////////////////////////
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

void inserir(int numero){
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

/////////////////////////////////////
// Fun��o que Remove um no da fila//
////////////////////////////////////

int remover(){
	int retorno = -1;
	
	if (cabeca != NULL){
		// A FILA TEM UM N�
		if (cabeca -> proximo == NULL){
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		}else{
		// A FILA TEM MAIS DE 1 N�
		struct no *ponteiroAnterior = cabeca;
	
		
		// Procura o penultimo n� da fila
		while (ponteiroAnterior -> proximo -> proximo !=NULL){
			ponteiroAnterior = ponteiroAnterior -> proximo;
		}
		
		retorno = ponteiroAnterior -> proximo -> numero;
		free(ponteiroAnterior -> proximo);
		ponteiroAnterior -> proximo = NULL;
	}

 }
 
 	return retorno;
 	
}

void imprimir (){
	struct no *ponteiro = cabeca;
	
	printf("=============== FILA ===============\n");
	while (ponteiro != NULL){
		printf("%d\t", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
	printf("\n");
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
				printf("Removi o numero %d da fila\n", remover());
				break;
			case 3:
				imprimir();
				break;
						
		}
	}
	

}







