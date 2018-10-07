# Makefile

CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

#Tests and executables
main: blockchain.o transaction.o main.o
	${CXX} $^ -o $@

testTransaction: transaction.o testTransaction.o
	${CXX} $^ -o $@


#.O files listed below
main.o: main.cpp
	${CXX} $^ -c

blockchain.o: blockchain.cpp
	${CXX} $^ -c

transaction.o: transaction.cpp
	${CXX} $^ -c

testTransaction.o: testTransaction.cpp
	${CXX} $^ -c

clean:
	/bin/rm -f main testTransaction *.o *.gch .*.swp
