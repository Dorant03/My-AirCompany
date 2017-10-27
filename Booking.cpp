#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Booking.h"

using namespace std;

Booking::Booking()
{
	money=0;
	profit.open("Profit.txt", std::ofstream::app);
}
void Booking::ADD()
{
	string name;
	cout<<"Name Travel: "; getline(cin, name);
	money+=500;
	profit<<name<<" +500   Suma="<<money;
	ofstream fout;
	fout.open(name+".txt", std::ofstream::app);
	Passenger passenger(1);
	passenger.writeFile(fout);
	fout.close();
}
void Booking::SUB()
{
	string name;
	cout<<"Name Travel: "; getline(cin, name);
	money-=250;
	profit<<name<<" -250   Suma="<<money;
	ifstream fin;
	fin.open(name+".txt", std::ifstream::in);
	Travel travel(fin);       fin.close();
	cout<<"Name Place: "; getline(cin, name);
	Aircraft craft=travel.getCraftName();
	Passenger *_array=travel.getPassenger();
	for(int i=0; i<craft.getN(); i++)
	{
		if(_array[i].getPlace()==name){ _array[i].del(); break;   }
	}
	travel.setPassenger(_array);
	travel.writeFile();
	delete [] _array;
}
Booking::~Booking()
{
	profit.close();
}