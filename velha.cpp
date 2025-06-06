#include "velha.hpp"

int CheckTicTacToeResult(int hash[3][3]) {
    for (int i = 0; i < 3; ++i) {
    if (hash[i][0] == hash[i][1] && hash[i][1] == hash[i][2]) {
        if (hash[i][0] == 1) return 1; // X venceu
        if (hash[i][0] == 2) return 2; // O venceu
    }
}

    for (int j = 0; j < 3; ++j) {
    if (hash[0][j] == hash[1][j] && hash[1][j] == hash[2][j] && hash[0][j] != 0) {
        if (hash[0][j] == 1) return 1; // X venceu
        if (hash[0][j] == 2) return 2; // O venceu
    }
}

    if (hash[0][0] == hash[1][1] && hash[1][1] == hash[2][2] && hash[0][0] != 0) {
        if (hash[0][0] == 1) return 1;

}

    return -1; 


}
