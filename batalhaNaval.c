#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];  
    int navio[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // 1. Inicializar o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio horizontal
    int linhaH = 2, colunaH = 1; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Navio vertical
    int linhaV = 5, colunaV = 7; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Navio diagonal
    int linhaD1 = 7, colunaD1 = 1;  
    int valido = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD1 + i >= TAM || colunaD1 + i >= TAM || tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) {
            valido = 0;
            break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        }
    }

    // Navio diagonal
    int linhaD2 = 1, colunaD2 = 6;  
    valido = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD2 + i >= TAM || colunaD2 - i < 0 || tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) {
            valido = 0;
            break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
        }
    }

    // EXIBIR TABULEIRO
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
