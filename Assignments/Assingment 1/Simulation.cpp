//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include "Simulation.hpp"

using namespace std;

int board[9][9];
int validationArray[9];
int validationArrayCt;

Simulation::Simulation(char* fileName)
{
	this->name = fileName;
	this->setBoard();
}

Simulation::~Simulation()
{
	
}

bool Simulation::runValidation()
{
	pthread_t thread_1, thread_2, thread_3, thread_4, thread_5, thread_6, thread_7, thread_8, thread_9;
	
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
	
	for(int i = 0; i < 9; ++i)
	{
		cout << "Thread " << i << " status: " << validationArray[i] << endl;
	}
	for(int i = 0; i < 9; ++i)
	{
		if(validationArray[i] == 0) {return false;}
	}
	return true;
}

void Simulation::runSolver()
{
	
	cout << "Board is Invalid" << endl;
	
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
		if(i%3==0) {cout << endl;}
		for(int j = 0; j < 9; ++j)
		{
			if(count%3==0) {cout << "  ";}
			cout << board[i][j];
			if(count>7){ cout << endl;}
			count++;
		}
	}
	cout << endl;
}

void *subgridValidator(void *params)
{
    int i, j;

    parameters * validator = (parameters *) params;
    int startRow = validator->row;
    int startCol = validator->column;
   
    int sorted[9] = {0}; //1d array to hold sorted 3x3 square

    for (i = startRow; i < startRow + 3; ++i)
	{
        for (j = startCol; j < startCol + 3; ++j)
		{
			int val = board[i][j];
	   
            if (sorted[val-1] == 0 && val > 0)
			{
                sorted[val-1] = val;
            }
            else
			{
                validationArray[validationArrayCt] = 0;
				validationArrayCt++;
				pthread_exit(0);
            }
        }
    }	
    validationArray[validationArrayCt] = 1;
    validationArrayCt++;
    pthread_exit(0);
}
