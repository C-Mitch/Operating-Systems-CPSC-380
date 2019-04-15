//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

#include <pthread.h>
#include <iostream>
#include <semaphore.h> 
#include <stdio.h>
#include <unistd.h> 

using namespace std;

#ifndef Simulation_HPP
#define Simulation_HPP

typedef struct
{
    int height;
    int force;
    
}parameters;

void* fredSee(void* arg);
void* wilmaSaw(void* arg);

class Simulation
{
	public:
		Simulation();
		~Simulation();
	
	private:
		void runSimulation();
		void printHeight();
		
		int time;
		int loopControl;
	
	
};

#endif