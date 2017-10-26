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
}
Aircraft::Aircraft(ifstream &fin)
{
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
