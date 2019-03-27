//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include "Simulation.hpp"

using namespace std;

Simulation::Simulation(char* fileName)
{
	this->name = fileName;
	setBoard();
}

Simulation::~Simulation()
{
	
}

void Simulation::setBoard()
{	
	
	this->file = fopen(this->name.c_str(),"r");
	
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
				fscanf(this->file,"%d%*c",&board[i][j]);
		}
	}
	cout << "Board Set" << endl;
	for(int i = 0; i < 9; ++i)
	{
		int count = 0;
		for(int j = 0; j < 9; ++j)
		{
			cout << board[i][j];
			if(count>7){ cout << endl;}
			count++;
		}
	}
	
	
}


