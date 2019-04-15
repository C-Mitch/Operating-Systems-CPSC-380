//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

#include <pthread.h>
#include <iostream>
#include <semaphore.h> 
#include <unistd.h> 

using namespace std;

#ifndef Simulation_HPP
#define Simulation_HPP


void* fredSee(void* params);
void* wilmaSaw(void* params);
void heightValidator();

class Simulation
{
	public:
		Simulation();
		~Simulation();
	
	private:
		void runSimulation();
	
	
};

#endif