#include <stdio.h>
#include <unistd.h>
#include <math.h>

/*
    Autor: Henrique Casellato
    ID-USP: 13781858
    E-mail Institucional: hcasellato@usp.br

    Descrição do exercício:
        Faça um programa que leia 5 números. Este programa deve ter um menu que permita ao
        usuário escolher qual opção de cálculo ele deseja realizar: média aritmética simples,
        média ponderada (ler os pesos associados a cada nota que serão informados pelo
        usuário), desvio padrão, maior valor e menor valor. A leitura dos 5 valores também deve
        ser uma das opções do menu.
*/

/* ====| Função para impressão dos valores do vetor |======================================== */

int impressao(int vetor[5]){
    for(int t = 0; t < 5; t++){
        switch(t){
            case 0:
                printf("[%d, ", vetor[t]);
                break;
            case 4:
                printf("%d]", vetor[t]);
                break;
            default:
                printf("%d, ", vetor[t]);
                break;
        }
    }
}

/* ====| Função para impressão do cabeçalho de N/P |========================================= */

int cab_np(int n_p){
    if(n_p == 0){
        printf("|===| Números |====================================\n");
    } else {
        printf("|===| Pesos |======================================\n");
    }
}

/* ====| Função para leitura dos valores do vetor |========================================== */

int leitura(int vetor[5], int n_p){
    // Variáveis:
    int x, index, sim;
    sim = 0;

    // Início com a impressão do cabeçalho
    INIC:
    cab_np(n_p);

    // Leitura dos valores
    printf("| Insira 5 valores desejados:\n|\n");
    for(int i = 0; i < 5; i++){
        printf("|\tValor para o índice %d:\n", i);
    }

    // Menu de opções
    printf("|\n| Escolha uma opção:\n");
    printf("|\t0. Mudar um valor\n");
    printf("|\t1. Refazer a leitura\n");
    printf("|\t2. Prosseguir\n|\n");
    printf("| Opção: ");

    // Volta ao incio do menu
    printf("\033[11A\r");
    for(int k = 0; k < 5; k++){
        printf("|\tValor para o índice %d: ", k);
        scanf("%d", &vetor[k]);
    }

    // Volta para a coluna da opção
    printf("\033[6B\033[9C");
    scanf("%d", &x);

    // Impressão do vetor caso já exista
    OP:
    if(sim == 1){printf("| "); impressao(vetor); printf("\n");}


    switch(x){
        // Mudança de valor único, adicionando cabeçalho
        case 0:
            printf("\033[H\33[0J");
            cab_np(n_p);
            printf("| Índice da mudança: ");
            scanf("%d", &index);
            int antigo = vetor[index];
            printf("\033[A\33[2K\r");
            printf("| Valor para o índice %d: ", index);
            scanf("%d", &vetor[index]);
            printf("\033[H\33[0J");
            cab_np(n_p);

            sim = 1;
            goto OP;

        // Refazer seleção inteira, perda do vetor na memória.
        case 1:
            sim = 0;
            printf("\033[H\33[0J");
            goto INIC;

        // Saída da leitura do vetor
        case 2:
            printf("\033[H\33[0J");
            break;
    }
}

/* ====| Função da média com possibilidade de pesos |======================================== */

float media(int vetor[5], int pesos[5]){
    float soma = 0.0;
    float soma_b = 0.0;
    for(int i = 0; i < 5; i++){soma += (float)(vetor[i] * pesos[i]);}
    for(int i = 0; i < 5; i++){soma_b += (float)(pesos[i]);}
    return (soma / soma_b);
}

/* ====| Corpo da função para o exercício |================================================== */

int main(){
    // Limpa a tela antes do programa iniciar
    printf("\033[H\33[0J");

    // Vetores
    int numeros[5];
    int peso_simples[5] = {1,1,1,1,1};
    int pesos[5];

    // Variáveis inteiras
    int memo, memo_pesos, menor_val, maior_val, key;
    memo = memo_pesos = menor_val = maior_val = key = 0;

    // Variáveis flutuantes
    float media_simples, media_ponderada, dp;
    media_simples = media_ponderada = dp = 0.0;

    // Menu de fato
    while(key != 6){
        printf("\033[H\33[0J");
        printf("|===| Menu Principal |=============================\n");

        // Início do menu com as funções
        printf("| Escolha uma função a ser realizada:\n|\n");

        // Impressão dos números e pesos caso existam
        if(memo){printf("| Números: "); impressao(numeros); printf("\n");}
        if(memo_pesos){printf("| Pesos: "); impressao(pesos); printf("\n");}
        if(memo_pesos == 1 || memo == 1){printf("|\n");}

        // Média Aritmética, impressão caso exista
        printf("|\t0. Média Aritmética Simples:");
        if(media_simples){printf(" %.2f\n", media_simples);}else{printf("\n");}

        // Média Aritmética Ponderada, impressão caso exista
        printf("|\t1. Média Aritmética Ponderada:");
        if(media_ponderada){printf(" %.2f\n", media_ponderada);}else{printf("\n");}

        // Desvio Padrão, impressão caso exista
        printf("|\t2. Desvio Padrão:");
        if(dp){printf(" %.3f\n", dp);}else{printf("\n");}

        // Maior Valor, impressão caso exista
        printf("|\t3. Maior Valor:");
        if(maior_val){printf(" %d\n", maior_val);}else{printf("\n");}

        // Menor Valor, impressão caso exista
        printf("|\t4. Menor Valor:");
        if(menor_val){printf(" %d\n", menor_val);}else{printf("\n");}

        // Funções auxiliares
        printf("|\t5. Leitura dos Valores\n");
        printf("|\t6. Sair do Programa\n|\n");
        printf("| Opção: ");
        scanf("%d", &key);

        // Limpar o menu
        printf("\033[H\33[0J");

        // Caso o usuário queira realizar uma função sem que exista
        if(memo == 0 && key != 5 && key != 6){
            leitura(numeros, 0);
            memo = 1;
        }

        // Funções
        switch(key){
            case 0: // Média Simples
                media_simples = media(numeros, peso_simples);
                break;

            case 1: // Média Ponderada
                if(memo_pesos == 0){leitura(pesos, 1); memo_pesos = 1;}
                media_ponderada = media(numeros, pesos);
                break;

            case 2: // Desvio Padrão
                if(!media_simples){media(numeros, peso_simples);}
                float soma_dp = 0.0;
                for(int q = 0; q < 5; q++){
                    soma_dp += pow((media_simples - numeros[q]), 2);
                }
                dp = sqrt(soma_dp/5.0);
                break;

            case 3: // Maior Valor
                maior_val = numeros[0];
                for(int w = 1; w < 5; w++){
                    if(numeros[w] >= maior_val){
                        maior_val = numeros[w];
                    }
                }
                break;

            case 4: // Menor Valor
                menor_val = numeros[0];
                for(int e = 1; e < 5; e++){
                    if(numeros[e] <= menor_val){
                        menor_val = numeros[e];
                    }
                }
                break;

            case 5: // Leitura dos valores para números e pesos
                LEITURA_INICIO:
                printf("\033[H\33[0J");
                printf("|===| Leitura |====================================\n");
                printf("| Escolha um vetor para modificar ou criar:\n|\n");

                int key_leitura;
                if(memo){printf("|\t0. Números: "); impressao(numeros); printf("\n");}else{printf("|\t0. Numeros\n");}
                if(memo_pesos){printf("|\t1. Pesos: "); impressao(pesos); printf("\n");}else{printf("|\t1. Pesos\n");}
                printf("|\t2. Voltar\n|\n");
                printf("| Opção: ");
                scanf("%d", &key_leitura);
                switch(key_leitura){
                    case 0:
                        printf("\033[H\33[0J");
                        leitura(numeros, 0);
                        memo = 1;
                        goto LEITURA_INICIO;
                        media_simples = media_ponderada = dp = maior_val = menor_val = 0.0;
                    case 1:
                        printf("\033[H\33[0J");
                        leitura(pesos, 1);
                        memo_pesos = 1;
                        media_ponderada = 0.0;
                        goto LEITURA_INICIO;
                    case 2:
                        break;
                    }
                break;

            case 6: // Sair do programa
                break;
        }
    }
}
// gcc -c trab_1a.c -o trab_1a.o && gcc -o trab_1a trab_1a.o -lm && ./trab_1a
