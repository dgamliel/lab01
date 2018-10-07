#include <iostream>
#include "blockchain.h"
#include <cstdlib>

using namespace std;

int main() {

	srand(time(NULL));	

	Blockchain new_chain(5, "Daniel", "Jensen");

	for (int i = 0; i < 10; i++)
	{
		new_chain.new_block(rand() % 100, "Beenis", "Cheenis");
	}

	new_chain.print_chain();

	return 0;
	
}
