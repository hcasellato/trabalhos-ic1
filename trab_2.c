#include <stdio.h>
#include <stdlib.h>

/*
    Autor: Henrique Casellato
    ID-USP: 13781858
    E-mail Institucional: hcasellato@usp.br

1. Faça um programa que leia dois números n e m e:
	- Crie e leia um vetor de inteiros de n posições;
	- Crie e leia um vetor de inteiros de m posições;
	- Crie e construa um vetor de inteiros que seja a interseção entre os dois vetores
	  anteriores, ou seja, que contém apenas os números que estão em ambos os vetores.
	  Não deve conter números repetidos.
*/

/* ====| |=================================================================================== */
int main(){

	// Cabeçalho	
	INICIO:
        printf("\033[H\033[0J");
	int exit;
	printf("|===============| Interseção entre Vetores |===============|\n");
	// Valores iniciais em n e m
	int n, m;
	
	printf("| Insira o valor máximo do 1º Vetor: ");
	scanf("%d", &n);
	
	printf("\033[1A\033[2K");
	printf("| Insira o valor máximo do 2º Vetor: ");
	scanf("%d", &m);
	
	// Vetor N
	int *vetor_n = malloc(n * sizeof(int));
	
	printf("\033[1A\033[2K");
	printf("| 1º Vetor\n");
	for(int i = 0; i < n; i++){
		printf("| Índice %d -> ", i);
		scanf("%d", (vetor_n + i));
	}
	
	// Vetor M
	int *vetor_m = malloc(m * sizeof(int));
	
	printf("\033[H\033[1B\033[0J");
	printf("| 2º Vetor\n");
	for(int j = 0; j < m; j++){
		printf("| Índice %d -> ", j);
		scanf("%d", (vetor_m + j));
	}
	
	// Vetor Interseção
	int c = 0;
	int in = (n >= m) ? n : m;
	int *vetor_in = malloc(in * sizeof(int));
	*(vetor_in + 0) = -2022;
	
	// Debug 
	
	/*
	int n = 5;
	int m = 1;
	int vetor_n[5] = {4,0,2,1,4};
	int vetor_m[1] = {235};
	*/
	
	// Criação do vetor interseção
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(*(vetor_n + i) == *(vetor_m + j)){
				// Declara valor igual para análise
				*(vetor_in + c) = *(vetor_n + i);
				if(c > 0){			
					for(int y = 0; y < c; y++){
						if(*(vetor_n + i) == *(vetor_in + y)){
							// Caso exista no vetor interseção, o valor em questão,
							// volta uma posição para trás.
							c--;
							break;
						}			
					}
				}
				// Avança uma posição no vetor.
				c++;
				break;
			}
		}
	}
	
	printf("\033[H\033[0J");
	printf("|===============| Interseção entre Vetores |===============|\n");
	printf("| Vetor Interseção:\n");
	
	// Imprimir itens em vetor_in caso hajam
	if(vetor_in[0] == -2022){
		printf("\033[1A\033[2K");
		printf("| Não há interseção entre os vetores indicados!\n");
	
	}else{	
		int o = 0;
		do{
			printf("| Índice %d -> %d\n", o, *(vetor_in + o));
			o++;
		}while(o < c);
	}
	printf("|\n| Continuar?\n| 0. Não\n| 1. Sim\n| Resposta:");
	scanf("%d", &exit);
	if(exit){goto INICIO;}else{printf("\033[H\033[0J");}
}

// gcc -c trab_2.c -o trab_2.o && gcc -o trab_2 trab_2.o -lm && ./trab_2
