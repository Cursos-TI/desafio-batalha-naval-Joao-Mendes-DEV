#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_NAVIO 3
#define TAM_HAB 5

// Criar Cone
void criarCone(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i))
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Criar Cruz
void criarCruz(int m[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB/2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Criar Octaedro
void criarOctaedro(int m[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB/2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Sobrepor matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int linhaOrigem, int colOrigem) {
    int centro = TAM_HAB/2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int linhaT = linhaOrigem + (i - centro);
                int colT = colOrigem + (j - centro);
                if (linhaT >= 0 && linhaT < TAM && colT >= 0 && colT < TAM) {
                    if (tab[linhaT][colT] == AGUA) {
                        tab[linhaT][colT] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Exibir tabuleiro
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tab[i][j] == AGUA) printf("~ ");
            else if (tab[i][j] == NAVIO) printf("N ");
            else if (tab[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM][TAM];
    int navio[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // inicializar tabuleiro
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Navio horizontal
    int linhaH = 2, colunaH = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    // Navio vertical
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    // Navio diagonal
    int linhaD1 = 7, colunaD1 = 1;
    int valido = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD1 + i >= TAM || colunaD1 + i >= TAM || tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) {
            valido = 0; break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
        }
    }

    // Navio diagonal
    int linhaD2 = 1, colunaD2 = 6;
    valido = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaD2 + i >= TAM || colunaD2 - i < 0 || tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) {
            valido = 0; break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
        }
    }

    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);

    exibirTabuleiro(tabuleiro);

    return 0;
}
