#include "blockchain.h"
#include "transaction.h"
#include "sha.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

Blockchain::Blockchain()
{
	this->head=NULL;
}

Blockchain::Blockchain(int amount, string sender, string receiver)
{
	this->head = new Transaction(amount, sender, receiver);
	this->head->setHash("");
	this->head->setNonce("");	
}

void Blockchain::new_block(int amount, string sender, string receiver)
{
	if (this->head == NULL)
	{
		this->head = new Transaction(amount, sender, receiver);
		return;
	}

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

bool Blockchain::verify_and_print()
{

	if (this->head == NULL)
	{
		cout << "EMPTY CHAIN" << endl;
		return true;
	}

	for (Transaction* tmp = head; tmp->getNext() != NULL; tmp = tmp->getNext())
	{
		string amount = to_string(tmp->getNext()->getAmount());
		string sender = tmp->getNext()->getSender();
		string receiver = tmp->getNext()->getReceiver();
		string nonce = tmp->getNonce();
		string _hash = amount + sender + receiver + nonce;
		if (get_hash(_hash) != tmp->getHash())
		{
			tmp->print_block();
			tmp->getNext()->print_block();
			return false;
		}

	}

	this->print_chain();
	return true;

}

void Blockchain::find_transaction(string sender)
{
	for (Transaction* p = head; p != NULL ; p = p->getNext())
	{
		if (p->getSender() == sender)
		{
			p->print_block();
		}
	}
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

string Blockchain::get_hash(string src_str)
{
	// any STL sequantial container (vector, list, dequeue...)

	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());

	std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	
	return hex_str;
}
