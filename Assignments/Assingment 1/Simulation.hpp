//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

#ifndef Simulation_HPP
#define Simulation_HPP

typedef struct
{
    int row;
    int column;
    
}parameters;

void *subgridValidator(void *param);

class Simulation
{
	public:
		Simulation(char* fileName);
		~Simulation();
		
		void runValidation();
	
	private:
		int board[9][9];
		int validationArray[9];
		string name;
		FILE *file;
		
		void setBoard();
		void printBoard();
	
};

#endif