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

//Structure for passing data to threads as suggested by Operating Systems Concepts - 9th Edition 
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
		
		bool runValidation();  //Initiate validation process; creates, exits, and joins threads used; returns true for valid board, false otherwise
		void runSolver();  //Solve for missing subgrid value; recursuvley validates and solves for multiple invalid subgrids in board
	
	private:
		string name;  //File name or Path
		FILE *file;
		
		void setBoard();  //Populate 2D Int array with 9X9 Sudoku file
		void printBoard();  //Display board to CML
		int rowValidator(int row);  //Validates 3 rows of specified subgrid by the passed value; returns the invalid number's row
		int columnValidator(int col);  //Validates 3 columns of specified subgrid by the passed value; returns the invalid number's column
		int reference[9];  //Array used to find missing value of subgrid; populated by numerical values 1-9
		int missingValue;  //Stores missig value of subgrid when found
	
};

#endif