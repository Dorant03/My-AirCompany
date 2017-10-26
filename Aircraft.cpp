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
}
Aircraft& Aircraft::operator=(const Aircraft &ob)
{
}
string Aircraft::getName()
{
}
int Aircraft::getN()
{
}
string * Aircraft::getPlace()
{
}
void Aircraft::info()
{
}
Aircraft::~Aircraft()
{
}
