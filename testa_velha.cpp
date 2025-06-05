#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.hpp"

// Teste inicial: jogo vazio deve retornar UNDEFINED (-1)
TEST_CASE("Jogo vazio retorna indefinido", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::UNDEFINED);
}

TEST_CASE("Vitória de X na primeira linha") {
    int hash[3][3] = {
        {1, 1, 1},
        {0, 2, 0},
        {2, 0, 2}
    };

    REQUIRE(CheckTicTacToeResult(hash) == 1);
}


TEST_CASE("Vitória de O na primeira linha") {
    int hash[3][3] = {
        {2, 2, 2},
        {1, 0, 1},
        {0, 1, 0}
    };

    REQUIRE(CheckTicTacToeResult(hash) == 2);
}
