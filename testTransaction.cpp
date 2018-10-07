#include "transaction.h"
#include <iostream>

using namespace std;

int main() 
{
	Transaction newTransaction(5, "Daniel", "Jensen");
	newTransaction.printBlock();

	return 0;
}
