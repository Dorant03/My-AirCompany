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
string Airport::getName()
{
	return name;
}
string Airport::getCity()
{
	return city;
}
string Airport::getCountry()
{
	return country;
}
void Airport::info()
{
	cout<<"Airport "<<name<<endl;
	cout<<"City "<<city<<endl;
	cout<<"Country "<<country<<endl;
	cout<<"\n";
}
void Airport::writeFile(ofstream &fout)
{
	fout<<name<<"\n";
	fout<<city<<"\n";
	fout<<country<<"\n";
}
Airport::~Airport()
{ }