#ifndef VELHA_HPP
#define VELHA_HPP

// Enum para representar os resultado possíveis
enum GameResult {
    X_WIN = 1,
    O_WIN = 2,
    TIE = 0,
    UNDEFINED = -1,
    IMPOSSIBLE = -2
};

// Função que verifica o estado do jogo da velha
int CheckTicTacToeResult(int hash[3][3]);

#endif 
