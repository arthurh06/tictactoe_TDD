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

TEST_CASE("Vitória de X na segunda linha") {
    int hash[3][3] = {
        {0, 2, 0},
        {1, 1, 1},
        {2, 0, 2}
    };

    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de X na terceira linha") {
    int hash[3][3] = {
        {0, 2, 0},
        {2, 0, 2},
        {1, 1, 1}
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

TEST_CASE("Vitória de O na segunda linha") {
    int hash[3][3] = {
        {1, 0, 0},
        {2, 2, 2},
        {0, 1, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de O na terceira linha") {
    int hash[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {2, 2, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de X na primeira coluna") {
    int hash[3][3] = {
        {1, 0, 2},
        {1, 2, 0},
        {1, 0, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de X na segunda coluna") {
    int hash[3][3] = {
        {0, 1, 0},
        {2, 1, 0},
        {0, 1, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de X na terceira coluna") {
    int hash[3][3] = {
        {0, 2, 1},
        {2, 0, 1},
        {0, 0, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de O na primeira coluna") {
    int hash[3][3] = {
        {2, 0, 1},
        {2, 1, 0},
        {2, 0, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de O na segunda coluna") {
    int hash[3][3] = {
        {1, 2, 0},
        {0, 2, 1},
        {1, 2, 0}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de O na terceira coluna") {
    int hash[3][3] = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de X na diagonal principal") {
    int hash[3][3] = {
        {1, 0, 2},
        {0, 1, 0},
        {2, 0, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de X na diagonal secundária") {
    int hash[3][3] = {
        {0, 2, 1},
        {0, 1, 0},
        {1, 0, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 1);
}

TEST_CASE("Vitória de O na diagonal principal") {
    int hash[3][3] = {
        {2, 1, 0},
        {1, 2, 0},
        {0, 0, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Vitória de O na diagonal secundária") {
    int hash[3][3] = {
        {1, 0, 2},
        {0, 2, 0},
        {2, 0, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == 2);
}

TEST_CASE("Jogo empatado", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 2, 1},
        {1, 1, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash) == 0);
}

TEST_CASE("Jogo indefinido", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 1, 2},
        {0, 2, 0},
        {1, 0, 0},
    };
    
    REQUIRE(CheckTicTacToeResult(hash) == -1);
}

TEST_CASE("Jogo indefinido2", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 1, 0},
        {2, 1, 2}
    };
    REQUIRE(CheckTicTacToeResult(hash) == -1);
}

TEST_CASE("Jogo indefinido3", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {1, 1, 0},
        {2, 0, 2},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -1);
}