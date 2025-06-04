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
