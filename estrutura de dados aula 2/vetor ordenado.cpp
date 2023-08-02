// programa de ordena��o direta //

#include <stdio.h>
#include <stdlib.h>

// declara��o de variaveis //

int vetor [10000];
int i = 0;
int j = 0;

// Fun��o principal de execu��o do programa //

int main (){
	// inicializa��o da mem�ria	
	for( i = 0; i < 10000; i ++){
		vetor[i] = (rand() %10000);
		
	}
	// impress�o de vetor
	printf("Come�o do vetor desordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}
	
	// ordena��o propriamente dita
	for(i = 0; i < 9999; i++){ // do primeiro ao penultimo
		for(j = (i + 1); j <10000; j++){
			if (vetor[i] > vetor[j]){
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
			
		}
		
		
	}
	
	// impress�o de vetor ordenado
	printf("Come�o do vetor ordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}		
	
	
}
