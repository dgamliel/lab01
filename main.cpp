#include <iostream>
#include "blockchain.h"
#include <cstdlib>

using namespace std;

int main() {

	cout << " ---------------------------------------------------------" << endl;
	cout << "|                     GOODGRADES.IO                       |" << endl;
	cout << " ---------------------------------------------------------" << endl << endl;
	cout << "Hello and welcome to my new startup 'GoodGrades.io (TM)'! \n" << endl
		 <<	"To begin investing please enter your first actions. " << endl 
		 <<	"\n1.Create a new transaction on the blockchain\n2.Verify and print the chain\n3.Find a transaction with name of sender\n4.Exit" << endl
			
		 <<	"Please enter your action now: " << endl;


	Blockchain my_chain;

	int option;

	
	while(cin >> option)
	{
	
		if (option < 0 || option > 4 ) cout << "Error input! Please try again!" << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(9999999, '\n');
			cout << "Input Failed - must be an integer" << endl;	
			break;
		}
	
		if (option == 1)
		{
			cout << "Thank you for your transaction! We will only accept transactions in the form \n\t<amount>\n\t<sender>\n\t<receiver>" << endl;
			int amount; string sender; string receiver;
			cin >> amount >> sender >> receiver;

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
				cout << "\nThank you for your investment!" << endl; 
					 
			}
		}

		if (option == 2)my_chain.verify_and_print();
		
		if (option == 3)
		{
			cout << "Please enter the name of the sender whose transaction you would like to locate below:" << endl;
			string sender;
			cin >> sender;
			my_chain.find_transaction(sender);	
		}
	

		if (option == 4) 
		{
			cout << "Now Exiting." << endl;
			break;
		}

		cout << "\n1. Create a new transaction on the blockchain\n2.Verify and print the chain\n3.Find a transaction with name of sender\n------------------" <<endl; 
	}

	return 0;
}


