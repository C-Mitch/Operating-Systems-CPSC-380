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

void* fredSee(void* params); //Fred Behavior
void* wilmaSaw(void* params); //Wilma Behavior
void heightValidator(); //Main Height Incrementor/Decrementor

class Simulation
{
	public:
		Simulation(); //Initialize Binary Semaphore
		~Simulation(); //Destory Binary Semaphore
	
	private:
		void runSimulation();  //Initialize And Run Threads
	
	
};

#endif