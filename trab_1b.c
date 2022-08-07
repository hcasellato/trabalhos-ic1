#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
    Autor: Henrique Casellato
    ID-USP: 13781858
    E-mail Institucional: hcasellato@usp.br

    Descrição do exercício:
        Faça um programa para o “jogo de adivinhar um número”. O computador deve sortear
        um número entre 0 e 100 e pedir para o usuário tentar adivinhar este número. O usuário
        vai dizer o seu palpite, e o computador deve responder, se ele é maior ou menor que o
        número que ele sorteou. O programa termina somente quando o usuário acertar
        exatamente qual o número que o computador tinha sorteado, escrevendo uma mensagem
        de felicitações para o nosso usuário e indicando o número total de tentativas feitas.
*/

/* ====| Função Principal |================================================================== */

int main(){

    // Inteiro para validação do menu
    int continuar = 1;
    
    while(continuar == 1){
        // Semente para gerar um número randômico sempre que o programa inicia
        srand(time(0));

        // Número randômico gerado no intervalo [0,100]
        int comp_num = rand() % 100;

        /* ====| Menu |============================================================================== */
        // Variáveis usadas
        int acerto, humano, tentativas, menor, maior;

        menor = acerto = tentativas = 0;
        tentativas = 1;
        maior = 100;

        while(acerto == 0){
            // Limpa tela, imprime cabeçalho:
            printf("\033[H\33[0J");
            printf("|=== Advinhe! =========================\n");
            printf("| O número está entre %d e %d\n", menor, maior);
            printf("| Tentativa: ");
            scanf("%d", &humano);
            if(humano == comp_num){
            	// Tela de acerto
                acerto = 1;
                printf("\033[H\33[0J");
                printf("|=== Advinhe! =========================\n");
                printf("| Parabéns! O número era realmente %d!\n", comp_num);
                printf("| Você acertou em %d tentativas!\n", tentativas);
                printf("| Continuar? \n| 0. Não\n| 1. Sim\n| Opção: ");
                scanf("%d", &continuar);
            }else{
                tentativas++;
                // Atualiza o chão e o teto do intervalo onde o número está
                // caso o usuário não acerte
                if(humano > comp_num && humano < maior){
                    maior = humano;
                }else if(humano < comp_num && humano > menor){
                    menor = humano;
                }
            }
        }
    }
    printf("\033[H\33[0J");
}
// gcc -c trab_1b.c -o trab_1b.o && gcc -o trab_1b trab_1b.o && ./trab_1b
