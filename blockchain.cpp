#include "blockchain.h"
#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

Blockchain::Blockchain(int amount, string sender, string receiver){
	this->head = new Transaction(amount, sender, receiver);
}
