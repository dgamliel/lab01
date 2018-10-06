# Makefile

CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field


main: blockchain.o transaction.o main.o
	${CXX} $^ -o $@

main.o: main.cpp
	${CXX} $^ -c

blockchain.o: blockchain.cpp
	${CXX} $^ -c

transaction.o: transaction.cpp
	${CXX} $^ -c

clean:
	/bin/rm -f main *.o *.gch .*.swp
