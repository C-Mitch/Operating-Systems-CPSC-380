//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-380-01
//Assignment1

#include "Assignment1.hpp"

using namespace std;

GenIn::GenIn()
{
	path = " ";
}

GenIn::~GenIn()
{

}

std::string GenIn::getStringInput()  //General String Input Function
{
	cin.clear();
	std::string in;
	while(!(cin >> in))
	{
		cout << "Enter Valid String" << endl;
		cin.clear();
	}
	return in;
}

int GenIn::getIntInput() //General Integer Input Function
{
	cin.clear();
	int in;
	while(!(cin >> in))
	{
		cout << "Enter Valid Integer Value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return in;
}

double GenIn::getDoubleInput() //General Integer Input Function
{
	cin.clear();
	double in;
	while(!(cin >> in))
	{
		cout << "Enter Valid Double Value" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return in;
}

void GenIn::setPath()  //Valid File Path Setter
{
	while(true)
	{
		cout << "Enter Valid File Path: " << endl;
		path = getStringInput();
		if(validatePath() == false) cout << endl << "FILE NONEXISTANT" << endl << endl;
		else
		{
			cout << endl << "VALID FILE PATH" << endl;
			break;
		}
	}
	
}

void GenIn::setPath(std::string p)
{
	path = p;
}

bool GenIn::validatePath() //Validate A File Path
{
	ifstream in(path);
	if(in)
	{
		in.close();
		return true;
	}
	else if(!in)
	{
		in.close();
		return false;
	}
	
}

bool GenIn::validatePath(std::string pathy)
{
	path = pathy;
	validatePath();
}

std::string GenIn::getPath() //Get Validated File Path
{
	return path;
}