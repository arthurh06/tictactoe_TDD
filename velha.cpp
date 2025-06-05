#include "velha.hpp"

int CheckTicTacToeResult(int hash[3][3]) {
    for (int i = 0; i < 3; ++i) {
    if (hash[i][0] == hash[i][1] && hash[i][1] == hash[i][2]) {
        if (hash[i][0] == 1) return 1; // X venceu
    }
}

    return -1; 


}
