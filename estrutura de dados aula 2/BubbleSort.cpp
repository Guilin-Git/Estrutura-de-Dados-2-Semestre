// programa de ordena��o BubbleSoft

// programa de ordena��o direta //

#include <stdio.h>
#include <stdlib.h>

// declara��o de variaveis //

int vetor [10000];
int i = 0;
int troquei = 0;

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
	
	// impress�o de vetor ordenado
	printf("Come�o do vetor ordenado");
	for (i = 0; i < 10000; i++){
		printf("%d\n", vetor [i]);
		
	}		
	
	
}
