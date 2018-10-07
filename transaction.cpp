#include "transaction.h"
#include <string>
#include <sstream>
#include <iostream>
#include "sha.h"

using namespace std;

Transaction::Transaction(int amount, string sender, string receiver)
{
	this->amount = amount;
	this->sender = sender;
	this->receiver = receiver;
}

string Transaction::gen_hash(string nonce)
{

	// any STL sequantial container (vector, list, dequeue...)
	std::string src_str = to_string(this->amount) + this->sender + this->receiver + nonce;

	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());

	std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	
	return hex_str;
}

void Transaction::print_block()
{
	ostringstream oss;
	
	oss << "Amount Transfered : " << this->amount << "\n" 
		<< "Sender            : " << this->sender << "\n"
		<< "Receiver          : " << this->receiver << "\n"
		<< "Nonce             : " << this->nonce << "\n"
		<< "Hash              : " << this->hash << "\n" << endl;
		
	string print_str = oss.str();
	cout << print_str << endl;
}
