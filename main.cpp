#include <iostream>
#include "blockchain.h"
#include <cstdlib>

using namespace std;

int main() {

	cout << " ---------------------------------------------------------" << endl;
	cout << "|                     GOODGRADES.IO                       |" << endl;
	cout << " ---------------------------------------------------------" << endl << endl;
	cout << "Hello and welcome to my new startup 'GoodGrades.io (TM)'! \n" << endl
		 <<	"To begin investing please enter your first transaction. " << endl 
		 <<	"Your transaction should take the form of \n\t<amount> \n\t<sender> \n\t<receiver> \n" << endl
			
		 <<	"Please enter your transaction now: " << endl;

	int amount; string sender; string receiver;	
	Blockchain my_chain;
	
	while(cin)
	{
		cin >> amount >> sender >> receiver;
		if (sender == "QUIT" || receiver == "QUIT")
			break;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(9999999, '\n');
			cout << "Input Failed - First argument must be an integer" << endl;	
			break;
		}

		else 
		{
			my_chain.new_block(amount, sender, receiver);
			cout << "\nThank you for your investment! To continue inputting transactions please use the form : \n\t<amount> \n\t<sender> \n\t<receiver> \n To quit entering transactions please enter \"QUIT\" as a sender or receiver" << endl; 
			 
		}
	
	}

	my_chain.verify_and_print();

	return 0;
}


