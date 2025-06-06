#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.hpp"


TEST_CASE("Jogo vazio retorna indefinido", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::UNDEFINED);
}

TEST_CASE("Vitória de X por linhas") {
    int hash[3][3] = {
        {1, 1, 1},
        {0, 2, 0},
        {2, 0, 2}
    };
    int hash2[3][3] = {
        {0, 2, 0},
        {1, 1, 1},
        {2, 0, 2}
    };
    int hash3[3][3] = {
        {0, 2, 0},
        {2, 0, 2},
        {1, 1, 1}
    };
    REQUIRE(CheckTicTacToeResult(hash) == X_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == X_WIN);
    REQUIRE(CheckTicTacToeResult(hash3) == X_WIN);
}

TEST_CASE("Vitória de O por linhas") {
    int hash[3][3] = {
        {2, 2, 2},
        {1, 0, 1},
        {0, 1, 0}
    };
    int hash2[3][3] = {
        {1, 0, 0},
        {2, 2, 2},
        {0, 1, 1}
    };
    int hash3[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {2, 2, 2}
    };

    REQUIRE(CheckTicTacToeResult(hash) == O_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == O_WIN);
    REQUIRE(CheckTicTacToeResult(hash3) == O_WIN);
}

TEST_CASE("Vitória de X por colunas") {
    int hash[3][3] = {
        {1, 0, 2},
        {1, 2, 0},
        {1, 0, 2}
    };
    int hash2[3][3] = {
        {0, 1, 0},
        {2, 1, 0},
        {0, 1, 2}
    };
    int hash3[3][3] = {
        {0, 2, 1},
        {2, 0, 1},
        {0, 0, 1}
    };

    REQUIRE(CheckTicTacToeResult(hash) == X_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == X_WIN);
    REQUIRE(CheckTicTacToeResult(hash3) == X_WIN);
}

TEST_CASE("Vitória de O por colunas") {
    int hash[3][3] = {
        {2, 0, 1},
        {2, 1, 0},
        {2, 0, 1}
    };
    int hash2[3][3] = {
        {1, 2, 0},
        {0, 2, 1},
        {1, 2, 0}
    };
    int hash3[3][3] = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };

    REQUIRE(CheckTicTacToeResult(hash) == O_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == O_WIN);
    REQUIRE(CheckTicTacToeResult(hash3) == O_WIN);
  
}

TEST_CASE("Vitória de X por diagonais") {
    int hashMain[3][3] = {
        {1, 0, 2},
        {0, 1, 0},
        {2, 0, 1}
    };
    int hash2[3][3] = {
        {0, 2, 1},
        {0, 1, 0},
        {1, 0, 2}
    };

    REQUIRE(CheckTicTacToeResult(hashMain) == X_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == X_WIN);
}

TEST_CASE("Vitória de O por diagonais") {
    int hashMain[3][3] = {
        {2, 1, 0},
        {1, 2, 0},
        {0, 0, 2}
    };
    int hash2[3][3] = {
        {1, 0, 2},
        {0, 2, 0},
        {2, 0, 1}
    };

    REQUIRE(CheckTicTacToeResult(hashMain) == O_WIN);
    REQUIRE(CheckTicTacToeResult(hash2) == O_WIN);
}

TEST_CASE("Jogo empatado", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 2, 1},
        {1, 1, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::TIE);
}

TEST_CASE("Jogo indefinido", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 1, 2},
        {0, 2, 0},
        {1, 0, 0},
    };
    int hash2[3][3] = {
        {1, 2, 1},
        {2, 1, 0},
        {2, 1, 2}
    };
    int hash3[3][3] = {
        {1, 2, 1},
        {1, 1, 0},
        {2, 0, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::UNDEFINED);
    REQUIRE(CheckTicTacToeResult(hash2) == GameResult::UNDEFINED);
    REQUIRE(CheckTicTacToeResult(hash3) == GameResult::UNDEFINED);
}

TEST_CASE("Jogo com mais de um vencedor","[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {0, 0, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}

TEST_CASE("Todas as posições são X", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}

TEST_CASE("Todas as posições são O", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}

TEST_CASE("Perdedor O joga mais vezes que o vencedor X", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 0},
        {2, 1, 0},
        {2, 2, 1},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}

TEST_CASE("Perdedor X joga mais vezes que o vencedor O", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {2, 1, 0},
        {1, 2, 0},
        {1, 1, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}

TEST_CASE("Quantidade de jogadas de X invalida", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 0, 1},
        {0, 1, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash) == GameResult::IMPOSSIBLE);
}