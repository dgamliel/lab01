#ifndef DANIEL_GAMLIEL_BCHAIN
#define DANIEL_GAMLIEL_BCHAIN

#include "transaction.h"
#include <string>
#include <cstdlib>

using namespace std;

class Blockchain{

	public:
		Blockchain(int amount,
				   string sender,
				   string receiver);

		void new_block(int amount, string sender, string receiver);
		void print_chain();

	private:
		Transaction* head;
};

#endif
