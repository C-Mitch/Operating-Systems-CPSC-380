//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment2

#include "Simulation.hpp"

using namespace std;

//Global Variables
sem_t mutex;

int timer = 0;
float FH = 1.0;
float WH = 7.0;
bool fredUp = true;

Simulation::Simulation()
{
	sem_init(&mutex, 0, 1);
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

void heightValidator()
{
	cout << "Fred Height: " << FH << "; Wilma Height: " << WH << "; Time: " << timer << endl;
	
	if(FH == 1)
	{
		fredUp = true;
		if (timer == 50) cout << "\nFred Decides He's Had Enough Fun For One Day And Gets Off The See-Saw\n" << endl;
		else cout << "\nFred Pushed Off The Ground With A Force Of 1.0\n" << endl;
	}
	else if(WH == 1)
	{
		fredUp = false;
		cout << "\nWilma Pushed Off The Ground With A Force Of 1.5\n" << endl;
	}
	
	if(fredUp)
	{
		FH+=1.0;
		WH-=1.0;
	}		
	else
	{
		WH+=1.5;
		FH-=1.5;
	}
	
	timer++;

}

void* fredSee(void* params)
{
	
	while(timer <= 50)
	{
		sem_wait(&mutex); 
		//cout << "\nFred Entered..\n";
		
		heightValidator();

		//cout << "\nFred Exiting...\n";
		sem_post(&mutex);
		sleep(1);
	}
}

void* wilmaSaw(void* params)
{
	
	while(timer <= 50)
	{
		sem_wait(&mutex); 
		//cout << "\nWilma Entered..\n";
	  
		heightValidator();
		  
		//cout << "\nWilma Exiting...\n";
		sem_post(&mutex);
		sleep(1);
	}
}