#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios

    char letras[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    printf("*** TABULEIRO SEM NAVIOS ***\n\n");

    for(int j = 0; j <= 10; j++) {
        printf("%c\t", letras[j]);
    }

    printf("\n\n");

    for(int i = 0; i <=9 ; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j <= 9; j++) {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    
    printf("*** TABULEIRO COM NAVIOS ***\n\n");

    // Posicionando os navios:

    for(int i = 3; i <= 5; i++) { // Navio Horizontal: Linha 5 e colunas D, E, F
        tabuleiro[4][i] = 3; // linha hardcoded
    }

    for(int i = 7; i <= 9; i++) { // Navio Vertical: Coluna A e linhas 8 a 10
        tabuleiro[i][0] = 3; // coluna hardcoded
    }

    for(int j = 0; j <= 10; j++) {
        printf("%c\t", letras[j]);
    }

    printf("\n\n");

    for(int i = 0; i <=9 ; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j <= 9; j++) {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");



    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
