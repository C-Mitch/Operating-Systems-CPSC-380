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
	this->setBoard();
}

Simulation::~Simulation()
{
	
}

void Simulation::runValidation()
{
	parameters *subgrid1 = (parameters *) malloc(sizeof(parameters));
	subgrid1->row = 0;
	subgrid1->column = 0;
	
	parameters *subgrid2 = (parameters *) malloc(sizeof(parameters));
	subgrid2->row = 0;
	subgrid2->column = 3;
	
	parameters *subgrid3 = (parameters *) malloc(sizeof(parameters));
	subgrid3->row = 0;
	subgrid3->column = 6;
	
	parameters *subgrid4 = (parameters *) malloc(sizeof(parameters));
	subgrid4->row = 3;
	subgrid4->column = 0;
	
	parameters *subgrid5 = (parameters *) malloc(sizeof(parameters));
	subgrid5->row = 3;
	subgrid5->column = 3;
	
	parameters *subgrid6 = (parameters *) malloc(sizeof(parameters));
	subgrid6->row = 3;
	subgrid6->column = 6;
	
	parameters *subgrid7 = (parameters *) malloc(sizeof(parameters));
	subgrid7->row = 6;
	subgrid7->column = 0;
	
	parameters *subgrid8 = (parameters *) malloc(sizeof(parameters));
	subgrid8->row = 6;
	subgrid8->column = 3;
	
	parameters *subgrid9 = (parameters *) malloc(sizeof(parameters));
	subgrid9->row = 6;
	subgrid9->column = 6;
	
	void * square1;
	void * square2;
	void * square3;
	void * square4;
	void * square5;
	void * square6;
	void * square7;
	void * square8;
	void * square9;
		
	pthread_create(&thread_1, NULL, subgridValidator, (void *) subgrid1);
	pthread_create(&thread_2, NULL, subgridValidator, (void *) subgrid2);
	pthread_create(&thread_3, NULL, subgridValidator, (void *) subgrid3);
	pthread_create(&thread_4, NULL, subgridValidator, (void *) subgrid4);
	pthread_create(&thread_5, NULL, subgridValidator, (void *) subgrid5);
	pthread_create(&thread_6, NULL, subgridValidator, (void *) subgrid6);
	pthread_create(&thread_7, NULL, subgridValidator, (void *) subgrid7);
	pthread_create(&thread_8, NULL, subgridValidator, (void *) subgrid8);
	pthread_create(&thread_9, NULL, subgridValidator, (void *) subgrid9);
	
	pthread_join(thread_1, &square1);
	pthread_join(thread_2, &square2);
	pthread_join(thread_3, &square3);
	pthread_join(thread_4, &square4);
	pthread_join(thread_5, &square5);
	pthread_join(thread_6, &square6);
	pthread_join(thread_7, &square7);
	pthread_join(thread_8, &square8);
	pthread_join(thread_9, &square9);
	
	
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
	this->printBoard();

}

void Simulation::printBoard()
{
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

void *subgridValidator(void *params)
{
	
	
}
