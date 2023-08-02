// programa de ordenação Busca exaustiva

#include <stdio.h>
#include <stdlib.h>

// declaração de variaveis //

int vetor [10000];
int i = 0;
int busca = 0;
int achei = 0;

// Função principal de execução do programa //

int main (){
	// inicialização da memória	
	for( i = 0; i < 10000; i ++){
		vetor[i] = (rand() %10000);
		
	}
	// impressão de vetor
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
		printf("Se fudeu ! Não existe !");
	}else {
		printf("ACHEI PORRA !!!!! Na posição %d\n", achei);
	}
	
}
