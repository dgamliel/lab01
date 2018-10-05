#ifndef "TRANSACTION_H"
#define "TRANSACTION_H"

#include <string>
using namespace std;

class Transaction{
	
	public: 
		Transaction(int amount,
					string sender,
					string receiver);

	void setAmount(int amount){this.amount = amount;}
	int getAmount(){return this.amount;}

	void setSender(string sender){this.sender = sender;}
	string getSender(){return this.sender}

	void setReceiver(string receiver){this.receiver = receiver;}
	string getReceiver(){return this.receiver}

	void setNonce(string nonce){this.nonce = nonce;}
	string getNonce(){return this.nonce}

	void setHash(string hash){this.hash = hash;}
	string getHash(){return this.hash}

	void setNext(Transaction& transaction_address){this.next = transaction_address;}
	Transaction* getNext(){return next;} 
	
	private:
		Transaction *next;
		int amount;
		string sender;
		string receiver;
		string nonce;
		string hash;
};

#endif
