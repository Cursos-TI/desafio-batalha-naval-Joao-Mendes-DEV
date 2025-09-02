#include<stdio.h>

int main (){

    int tabuleiro[10][10] = { // Inicialização do array com valores
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 3, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
 
    // Saída dos dados que representa o tabuleiro
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
