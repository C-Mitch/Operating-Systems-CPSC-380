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

//pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7, thread_8, thread_9;

void *subgridValidator(void *param);

class Simulation
{
	public:
		Simulation(char* fileName);
		~Simulation();
		
		bool runValidation();
		void runSolver();
	
	private:
		string name;
		FILE *file;
		
		void setBoard();
		void printBoard();
		int rowValidator(int col, int row);
		int columnValidator(int col, int row);
		int reference[9];
		int missingValue;
	
};

#endif