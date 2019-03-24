//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include "Assignment1.hpp"

using namespace std;

FileIn::FileIn() //Standard - Unused
{
	path = "";
}

FileIn::FileIn(std::string p) //Overloaded - Used
{
	path = p;
	size = 0;	
	readInput();
	
}

FileIn::~FileIn()
{

}

void FileIn::readInput() //Transfer file input to holder array
{
	int count, k = 0;
	double t;
	ifstream inn(path);
	while(inn >> t)
	{
		if(count == 0)
		{
			size = t;
			holder = new double[size];
			//cout << "Established Holder" << endl;
		}
		else holder[k++] = t;
		count++;
	}
	
	//for(int x = 0; x < size; ++x) cout << "Holder Contains: " << holder[x] << " at: " << x << endl;
	inn.close();
}

double* FileIn::getArray()
{
	return holder;
}

int FileIn::getSize()
{
	return size;
}