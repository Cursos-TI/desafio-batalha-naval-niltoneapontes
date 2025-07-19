#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

#define LINHAS_HABILIDADE 3
#define COLUNAS_HABILIDADE 5

#define INDICADOR_MAR 0
#define INDICADOR_NAVIO 3
#define INDICADOR_AREA_AFETADA 5

int main() {
    // Nível Novato - Posicionamento dos Navios

    char letras[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[LINHAS][COLUNAS];

    int cone[LINHAS_HABILIDADE][COLUNAS_HABILIDADE], cruz[LINHAS_HABILIDADE][COLUNAS_HABILIDADE], octaedro[LINHAS_HABILIDADE][COLUNAS_HABILIDADE];

    int linha_inicio = 4, coluna_inicio = 4;

    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = INDICADOR_MAR; // Preenchendo os espacos do tabuleiro com 0;
        }
    }

    printf("*** TABULEIRO SEM NAVIOS ***\n\n");

    for(int j = 0; j <= 10; j++) {
        printf("%c\t", letras[j]);
    }

    printf("\n\n");

    for(int i = 0; i <= COLUNAS - 1 ; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j <= COLUNAS - 1; j++) {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    
    printf("*** TABULEIRO COM NAVIOS ***\n\n");

    // Posicionando os navios:

    for(int i = 7; i <= COLUNAS - 1; i++) { // Navio Horizontal: Linha 5 e colunas D, E, F
        tabuleiro[6][i] = INDICADOR_NAVIO; // linha hardcoded
    }

    for(int i = 3; i <= 5; i++) { // Navio Vertical: Coluna A e linhas 8 a 10
        tabuleiro[i][0] = INDICADOR_NAVIO; // coluna hardcoded
    }

    for(int i = 0; i <= 2; i++) { // Navio Diagonal Principal
        for(int j = 0; j <= 2; j++) {
            if(i == j) {
                tabuleiro[i][j] = INDICADOR_NAVIO;
            }
        }
    }

    for(int i = 7; i <= COLUNAS - 1; i++) { // Navio Diagonal Secundaria
        for(int j = 0; j <= 2; j++) {
            if(i + j == COLUNAS - 1) {
                tabuleiro[i][j] = INDICADOR_NAVIO;
            }
        }
    }

    // Exibindo o tabuleiro

    for(int j = 0; j <= 10; j++) {
        printf("%c\t", letras[j]);
    }

    printf("\n\n");

    for(int i = 0; i <= COLUNAS - 1 ; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j <= COLUNAS - 1; j++) {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");


    printf("*** TABULEIRO COM NAVIOS E AREAS AFETADAS ***\n\n");

    // Criando as areas afetadas:


    printf("\nCriando o cone...\n");

    for (int i = 0; i < LINHAS_HABILIDADE; i++) {
        for (int j = 0; j < LINHAS_HABILIDADE - i - 1; j++) {
            cone[i][j] = INDICADOR_MAR;
            printf("%d ", cone[i][j]);

        }

        for (int k = 0; k < 2 * i + 1; k++) {
            cone[i][k] = INDICADOR_AREA_AFETADA;
            printf("%d ", cone[i][k]);
        }

         for (int j = LINHAS_HABILIDADE + i; j < COLUNAS_HABILIDADE; j++) {
            cone[i][j] = INDICADOR_MAR;
            printf("%d ", cone[i][j]);

        }

        printf("\n");
    }

    printf("\nCriando a cruz...\n");

    for (int i = 0; i < LINHAS_HABILIDADE; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++) {
            if (i == LINHAS_HABILIDADE / 2 || j == COLUNAS_HABILIDADE / 2) {
                cruz[i][j] = INDICADOR_AREA_AFETADA;
                printf("%d ", cruz[i][j]);
            } else {
                cruz[i][j] = INDICADOR_MAR;
                printf("%d ", cruz[i][j]);
            }
        }      

        printf("\n");
    }

    printf("\nCriando o octaedro...\n");

    for (int i = 0; i < LINHAS_HABILIDADE; i++) {
        for (int j = 0; j < COLUNAS_HABILIDADE; j++) {
            if (i == LINHAS_HABILIDADE / 2 || j == COLUNAS_HABILIDADE / 2) {
                if(j == 0 || j == COLUNAS_HABILIDADE - 1) {
                    octaedro[i][j] = INDICADOR_MAR;
                    printf("%d ", octaedro[i][j]);
                } else {
                    octaedro[i][j] = INDICADOR_AREA_AFETADA;
                    printf("%d ", octaedro[i][j]);
                }
            } else {
                octaedro[i][j] = INDICADOR_MAR;
                printf("%d ", octaedro[i][j]);
            }
        }      

        printf("\n");
    }

    printf("\n\n");


    // Sobrepondo as areas afetadas no tabuleiro

    for(int i = 0; i < LINHAS_HABILIDADE; i++) {
        int x = i + linha_inicio;
        int centro_cone = coluna_inicio + COLUNAS_HABILIDADE / 2;
        int inicio_cone = centro_cone - i;
        int fim_cone = centro_cone + i;

        for (int y = inicio_cone, j = 0; y <= fim_cone; j++, y++) {
            tabuleiro[x][y] = cone[i][j];
        }

        // // Cruz ou Octaedro
        // for(int j = 0; j < COLUNAS_HABILIDADE; j++) {
        //     int x = i + linha_inicio;
        //     int y = j + coluna_inicio;

        //     if(x < LINHAS && y < COLUNAS) {
        //         tabuleiro[x][y] = cruz[i][j];
        //     }
        // }
    }

    for(int j = 0; j <= 10; j++) {
        printf("%c\t", letras[j]);
    }

    printf("\n\n");

    for(int i = 0; i <= COLUNAS - 1 ; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j <= COLUNAS - 1; j++) {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

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
