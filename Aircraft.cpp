#include <string>
#include <iostream>
#include <fstream>
#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft()
{
	name="\0";
	N=0;
	place=new char*;
}
Aircraft::Aircraft(ifstream &fin)
{
	getline(fin, name);
	fin>>N; fin.get();
	place = new char *[N];
	for(int i=0; i<N;i++)
	{
		place[i]=new char[10];
		fin>>place[i];
	}
}
Aircraft::Aircraft(const Aircraft &ob)
{
	name=ob.name;
	N=ob.N;
	place=new char *[ob.N];
	for(int i=0; i<ob.N; i++)
	{
		place[i]=ob.place[i];
	}
}
Aircraft& Aircraft::operator=(const Aircraft &ob)
{
	name=ob.name;
	N=ob.N;
	place=new char *[ob.N];
	for(int i=0; i<ob.N; i++)
	{
		place[i]=ob.place[i];
	}
	return *this;
}
string Aircraft::getName()
{
	return name;
}
int Aircraft::getN()
{
	return N;
}
char ** Aircraft::getPlace()
{
	return place;
}
void Aircraft::info()
{
	cout<<"Aircraft "<<name<<endl;
	cout<<"Number place "<<N<<endl;
	cout<<"Places: ";
	for(int i=0; i<N; i++)
	{
		if(!(i%10)) cout<<endl;
		cout<<place[i]<<ends;
	}
	cout<<"\n\n";
}
void Aircraft::writeFile(ofstream &fout)
{
	fout<<name<<endl;
	fout<<N<<endl;
	for(int i=0; i<N; i++)
	{
		if(!(i%10) && i!=0) fout<<"\n";
		fout<<place[i];
		if(i!=N-1) fout<<" ";
	}
}
Aircraft::~Aircraft()
{
	delete [] place;
}