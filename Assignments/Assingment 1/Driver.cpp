//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include "Simulation.hpp"

using namespace std;


int main(int argc, char* argv[]) {
	
	//Test for text file
	if(argc != 2)
	{
		cout << "One Valid Text File Must Be Passed \nPlease Try Again" << endl;
		return 1;
	}
	
	Simulation *check = new Simulation(argv[1]);
	
}