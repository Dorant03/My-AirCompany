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
	//place[0]='\0';
}
Passenger::Passenger(int k)
{
	cout<<"Name passenger: ";    cin>>name;
	cout<<"Surname passenger: "; cin>>surname;
	cout<<"Year: ";    cin>>year; //cin.get();
	cout<<"Place: "; cin>>place;
}
Passenger::Passenger(ifstream &fin)
{
	fin>>name;
	fin>>surname;
	fin>>year;
	fin>>place;
}
Passenger::Passenger(const Passenger &ob)
{
	strcpy(place, ob.place);
	strcpy(name, ob.name);
	strcpy(surname, ob.surname);
	year=ob.year;
}
Passenger& Passenger::operator=(const Passenger &ob)
{
	strcpy(place, ob.place);
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
char * Passenger::getPlace()
{
	return place;
}
void Passenger::del()
{
	name[0]='\0';
	surname[0]='\0';
	year=0;
}
void Passenger::info()
{
	cout.setf(ios::left);
	if(name[0]!='\0')
	cout<<left<<setw(15)<<name<<setw(15)<<surname<<year<<setw(10)<<" Years"<<"Place "<<place<<endl;
}
void Passenger::writeFile(ofstream &fout)
{
	fout.setf(ios::left);
	if(name[0]!='\0')
	fout<<"\n"<<name<<" "<<surname<<" "<<year<<" "<<place;
}
Passenger::~Passenger()
{  }