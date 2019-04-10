//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

#include "Simulation.hpp"

using namespace std;


int main(int argc, char* argv[]) {
	
	//Test for text file
	if(argc != 2)
	{
		cout << "One Valid Text File Must Be Passed \nPlease Try Again" << endl;
		return 1;
	}
	
	Simulation *sim = new Simulation(argv[1]);
	bool result = sim->runValidation();
	if(!result) {sim->runSolver();}
	else {cout << endl << "Congradulations! This is a VALID board" << endl;}
}