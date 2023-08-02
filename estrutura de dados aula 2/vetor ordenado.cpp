// programa de ordenação direta //

#include <stdio.h>
#include <stdlib.h>

// declaração de variaveis //

int vetor [10000];
int i = 0;
int j = 0;

// Função principal de execução do programa //

int main (){
	// inicialização da memória	
	for( i = 0; i < 10000; i ++){
		vetor[i] = (rand() %10000);
		
	}
	// impressão de vetor
	printf("Começo do vetor desordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}
	
	// ordenação propriamente dita
	for(i = 0; i < 9999; i++){ // do primeiro ao penultimo
		for(j = (i + 1); j <10000; j++){
			if (vetor[i] > vetor[j]){
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
			
		}
		
		
	}
	
	// impressão de vetor ordenado
	printf("Começo do vetor ordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}		
	
	
}
