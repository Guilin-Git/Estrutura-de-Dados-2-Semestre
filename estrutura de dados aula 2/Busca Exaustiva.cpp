// programa de ordena��o Busca exaustiva

#include <stdio.h>
#include <stdlib.h>

// declara��o de variaveis //

int vetor [10000];
int i = 0;
int busca = 0;
int achei = 0;

// Fun��o principal de execu��o do programa //

int main (){
	// inicializa��o da mem�ria	
	for( i = 0; i < 10000; i ++){
		vetor[i] = (rand() %10000);
		
	}
	// impress�o de vetor
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &busca);
	
	//busca propriamente dita
	achei = -1;
	for (i = 0; i < 10000; i++){
		if (vetor[i] == busca){
			achei = i;
		}	
		
	}	
	if (achei == -1){
		printf("Se fudeu ! N�o existe !");
	}else {
		printf("ACHEI PORRA !!!!! Na posi��o %d\n", achei);
	}
	
}
