#ifndef "BLOCKCHAIN_H"
#define "BLOCKCHAIN_H"

#include <"transaction.h">
#include <string>
#include <cstdlib>

using namespace std;

class Blockchain{
	public:
		Blockchain();

	private:
		Transaction* head;
};

#endif
