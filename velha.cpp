#include "velha.hpp"

int CheckTicTacToeResult(int hash[3][3]) {
    bool xWon = false, oWon = false;
    int xCount = 0;
    int oCount = 0;

    // Verifica linhas
    for (int i = 0; i < 3; i++) {
        if (hash[i][0] == hash[i][1] && hash[i][1] == hash[i][2]) {
            if (hash[i][0] == 1) xWon = true;
            else if (hash[i][0] == 2) oWon = true;
        }
    }

    // Verifica colunas
    for (int j = 0; j < 3; j++) {
        if (hash[0][j] == hash[1][j] && hash[1][j] == hash[2][j]) {
            if (hash[0][j] == 1) xWon = true;
            else if (hash[0][j] == 2) oWon = true;
        }
    }

    // Verifica diagonais
    if (hash[0][0] == hash[1][1] && hash[1][1] == hash[2][2]) {
        if (hash[0][0] == 1) xWon = true;
        else if (hash[0][0] == 2) oWon = true;
    }
    if (hash[0][2] == hash[1][1] && hash[1][1] == hash[2][0]) {
        if (hash[0][2] == 1) xWon = true;
        else if (hash[0][2] == 2) oWon = true;
    }

    // Contagem de jogadas
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (hash[i][j] == 1) xCount++;
        else if (hash[i][j] == 2) oCount++;
    }    
    }

    if ((xCount - oCount > 1) || (oCount - xCount > 1)) {
        return -2; // Jogo impossível (diferença de peças > 1)
    }
    // Verifica empate ou jogo em andamento
    bool hasEmptySpace = false;
    for (int i = 0; i < 3 && !hasEmptySpace; i++) {
        for (int j = 0; j < 3; j++) {
            if (hash[i][j] == 0) {
                hasEmptySpace = true;
                break;
            }
        }
    }

    if (xWon && oWon) return -2;  // Ambos venceram (inválido)
    if (xCount == 9) return -2;   // Todas as posições = X
    if (oCount == 9) return -2;   // Todas as posições = O
    if (xWon) return (xCount >= oCount) ? 1 : -2;  // Verifica vitória de X e contagem de jogadas
    if (oWon) return (oCount >= xCount) ? 2 : -2;  // Verifica vitória de O e contagem de jogadas
    if (oWon) return 2;           // O venceu
    if (!hasEmptySpace) return 0; // Empate
    return -1;                    // Jogo em andamento
}