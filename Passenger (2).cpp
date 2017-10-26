#include <string>
#include <iostream>
#include <fstream>
#include "Passenger.h"
#include <iomanip>

using namespace std;

Passenger::Passenger()
{
	name[0]='\0';
	surname[0]='\0';
	year=0;
}
Passenger::Passenger(int k)
{
	cout<<"Name passenger: ";    cin>>name;
	cout<<"Surname passenger: "; cin>>surname;
	cout<<"Year: ";    cin>>year; cin.get();
}
Passenger::Passenger(ifstream &fin)
{
	fin>>name;
	fin>>surname;
	fin>>year;

}
Passenger::Passenger(const Passenger &ob)
{
	strcpy(name, ob.name);
	strcpy(surname, ob.surname);
	year=ob.year;
}
Passenger& Passenger::operator=(const Passenger &ob)
{
	strcpy(name, ob.name);
	strcpy(surname, ob.surname);
	year=ob.year;
	return *this;
}
char * Passenger::getName()
{
	return name;
}
char * Passenger::getSurname()
{
	return surname;
}
int Passenger::getYear()
{
	return year;
}
void Passenger::info()
{
	cout.setf(ios::left);
	cout<<left<<setw(15)<<name<<setw(15)<<surname<<year<<" Years"<<endl;
}
Passenger::~Passenger()
{  }
