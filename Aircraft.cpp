#include <string>
#include <iostream>
#include <fstream>
#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft()
{
	name="\0";
	N=0;
	place=new string;
}
Aircraft::Aircraft(int k)
{
	cout<<"Name aircraft: "; getline(cin, name);
	cout<<"Number place: "; cin>>N; cin.get();
	cout<<"Name places: "<<endl;
	place = new string [N];
	for(int i=0; i<N;i++)
	{
		getline(cin, place[i]);
	}
}
Aircraft::Aircraft(ifstream &fin)
{
	getline(fin, name);
	fin>>N; fin.get();
	place = new string [N];
	for(int i=0; i<N;i++)
	{
		getline(fin, place[i]);
	}
}
Aircraft::Aircraft(const Aircraft &ob)
{
	name=ob.name;
	N=ob.N;
	place=new string [ob.N];
	for(int i=0; i<ob.N; i++)
	{
		place[i]=ob.place[i];
	}

}
Aircraft& Aircraft::operator=(const Aircraft &ob)
{
	name=ob.name;
	N=ob.N;
	place=new string [ob.N];
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
string * Aircraft::getPlace()
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
Aircraft::~Aircraft()
{
}
