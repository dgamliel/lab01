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

		Blockchain();

		void new_block(int amount, string sender, string receiver);
		bool verify_and_print();
		void print_chain();
		void find_transaction(string sender);
		string gen_nonce();
	
	private:
		Transaction* head;
		bool is_not_valid(string hash);
		string get_hash(string s);
};

#endif
