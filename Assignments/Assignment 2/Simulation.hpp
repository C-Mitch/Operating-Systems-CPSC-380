//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

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
	int height;
	int velocity;
    
}parameters;


void *fredSee( );
void *wilmaSaw( );

class Simulation
{
	public:
		Simulation();
		~Simulation();
	
	private:
		void runSimulation();
	
	
};

#endif