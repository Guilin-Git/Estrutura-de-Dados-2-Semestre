// programa de ordenação BubbleSoft

// programa de ordenação direta //

#include <stdio.h>
#include <stdlib.h>

// declaração de variaveis //

int vetor [10000];
int i = 0;
int troquei = 0;

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
	troquei = 1;
	while (troquei){
		troquei = 0;
		
		
		for (i = 0; i < 9999; i++){
			if (vetor [i] > vetor[i + 1]){
				int temp = vetor [i];
				vetor [i] = vetor[i + 1];
				vetor[i + 1] = temp;
				troquei = 1;
			}
		}
		
		
		
	}
	
	// impressão de vetor ordenado
	printf("Começo do vetor ordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}		
	
	
}
