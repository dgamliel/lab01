#include "blockchain.h"
#include "transaction.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

Blockchain::Blockchain(int amount, string sender, string receiver){
	this->head = new Transaction(amount, sender, receiver);
	head->setNonce("FIRST BLOCK - NO NONCE");
}

void Blockchain::new_block(int amount, string sender, string receiver)
{
	Transaction* newBlock = new Transaction(amount, sender, receiver);
	
	//First set new head to be new block
	int last_index = 7;
	string nonce; 
	string hash;
	while (is_not_valid(hash))
	{
		nonce = gen_nonce();
		hash = head->gen_hash(nonce);	
	}

	//Pointer manipulation to create new block
	//Also set nonce and hash of new block
	newBlock->setNext(head);
	head = newBlock;
	head->setNonce(nonce);
	head->setHash(hash);

}

string Blockchain::gen_nonce()
{
	
	srand(time(NULL));

	//String length to be anywhere from 1 to 32
	int loop_limit = rand() % 32;
	string nonce;

	for (int i = 1; i <= loop_limit; i++)
	{
		nonce += char((rand() % 26) + 97);
	} 
	
	return nonce;

}

bool Blockchain::is_not_valid(string hash){
	char last_char = hash.back();

	if (int(last_char) > 52 || int(last_char) < 48)
	{
		return true;
	}
	return false;
}

void Blockchain::print_chain()
{
	for (Transaction* p = head; p != NULL; p = p->getNext())
	{
		p->print_block();
	}
}
