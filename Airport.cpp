#include <string>
#include <iostream>
#include <fstream>
#include "Airport.h"

using namespace std;

Airport::Airport()
{
	name="\0";
	city="\0";
	country="\0";
}
Airport::Airport(int k)
{
	cout<<"Name airport: "; getline(cin, name);
	cout<<"Name city: "; getline(cin, city);
	cout<<"Name country: "; getline(cin, country);
}
Airport::Airport(ifstream &fin)
{
	getline(fin, name);
	getline(fin, city);
	getline(fin, country);
}
Airport::Airport(const Airport &ob)
{
	name=ob.name;
	city=ob.city;
	country=ob.country;
}
Airport& Airport::operator=(const Airport &ob)
{
	name=ob.name;
	city=ob.city;
	country=ob.country;
	return *this;
}
Airport.h
Airport::~Airport()
{ }
