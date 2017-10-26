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
