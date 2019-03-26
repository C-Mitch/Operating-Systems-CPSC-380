//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include <iostream>
#include <fstream>
#include <istream>
#include <limits>
#include <string>
#include <chrono>


using namespace std;

#ifndef Assignment1_HPP
#define Assignment1_HPP

//A general object to get and validate file/standard input
class GenIn
{
	public:
		GenIn();
		~GenIn();
		
		void setPath(); //Sets a file path to be used
		void setPath(std::string p); //Sets a file path to be used
		std::string getStringInput(); //Gets general string input
		int getIntInput(); //Gets general integer input
		double getDoubleInput(); //Gets general double input
		std::string getPath(); //Gets a file path and validates it, loops till valid file path found
		bool validatePath(); //A test to check if a path is valid, returns true if path connects, false if not
		bool validatePath(std::string pathy); //Overloaded test to check if given path is valid, returns true if path connects, false if not
		
	private:
		std::string path; //Std::string to hold a file path
	
};

//An object to read CSV content from given file and write to an array
class FileIn
{
	public:
		FileIn();
		FileIn(std::string p);
		~FileIn();
		
		void readInput(); //Read CSV input from given file and transfer to array
		double* getArray(); //Return Double* array containing file contents
		int getSize(); //Return size of array for iteration
		
	private:
		std::string path;
		double *holder;
		int size = 0;
};
	
#endif