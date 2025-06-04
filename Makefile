CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = 


.PHONY: all compile test cpplint gcov debug cppcheck clean

all: test


testa_velha: testa_velha.cpp velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) velha.cpp testa_velha.cpp -o testa_velha $(LDFLAGS)


compile: testa_velha


test: testa_velha
	./testa_velha


cpplint: testa_velha.cpp velha.cpp velha.hpp
	clang-format -i velha.cpp velha.hpp testa_velha.cpp
	cpplint --exclude=catch.hpp *.cpp *.hpp


gcov: testa_velha.cpp velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage velha.cpp testa_velha.cpp -o testa_velha
	./testa_velha
	gcov velha.cpp


debug: testa_velha.cpp velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -g velha.cpp testa_velha.cpp -o testa_velha
	gdb ./testa_velha


cppcheck: testa_velha.cpp velha.cpp velha.hpp
	cppcheck --enable=warning,performance,portability .


clean:
	rm -rf *.o *.exe *.gcda *.gcno *.gcov testa_velha


velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp