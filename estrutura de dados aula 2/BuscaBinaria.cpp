// programa de ordena��o Busca Binaria ( s� funciona se estiver ordenado)

#include <stdio.h>

// declara��o de variaveis //

int vetor [10000];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 0;
int meio = 0;

// Fun��o principal de execu��o do programa //

int main (){
	// inicializa��o da mem�ria	
	for( i = 0; i < 10000; i ++){
		vetor[i] = i;
		
	}
	// impress�o de vetor
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &busca);
	
	//busca propriamente dita
	inicio = 0;
	fim = 9999;
	while (fim >= inicio){
		meio = ((inicio + fim) / 2);
		
		if (busca == vetor[meio]){
			printf("ACHEI PORRA !!!!! Na posi��o %d\n", meio);
			return 0;
			
		}else if (busca > vetor[meio]){
			inicio = (meio + 1);			
		}else{
			fim = (meio - 1);
		}
	}
	printf("Se fudeu ! N�o existe !");
}
