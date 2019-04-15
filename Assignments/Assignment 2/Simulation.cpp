//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

#include "Simulation.hpp"

using namespace std;

sem_t mutex; 

Simulation::Simulation()
{
	sem_init(&mutex, 0, 1);
	//cout << "Semaphore Created" << endl;
	time = 0;
	runSimulation();
}

Simulation::~Simulation()
{
	sem_destroy(&mutex);
	cout << "Semaphore Destroyed" << endl;
}

void Simulation::runSimulation()
{
	cout << "SIMULATION START" << endl;
	
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,fredSee,NULL); 
	pthread_create(&t2,NULL,wilmaSaw,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	
}

void Simulation::printHeight()
{
	
}

void* fredSee(void* arg)
{
	//wait 
    sem_wait(&mutex); 
    cout << "\nFred Entered..\n";
  
    //critical section 
    sleep(6); 
      
    //signal 
    cout << "\nJust Exiting...\n";
    sem_post(&mutex); 
}

void* wilmaSaw(void* arg)
{
	//wait 
    sem_wait(&mutex); 
    cout << "\nWilma Entered..\n";
  
    //critical section 
    sleep(2); 
      
    //signal 
    cout << "\nJust Exiting...\n";
    sem_post(&mutex); 
}