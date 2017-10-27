#include <string>
#include <iostream>
#include <fstream>
#include "Travel.h"

using namespace std;

Travel::Travel()
{
	time_start="\0";
	time_end="\0";
	array_passenger=new Passenger [craft_name.getN()];
	number_passenger=0;
}
Travel::Travel(int)
{
	Airport start(1);
	port_start=start;
	Airport end(1);
	port_end=end;
	cout<<"Time start: "; getline(cin, time_start);
	cout<<"Time end: "; getline(cin, time_end);
	Aircraft craft(1);
	craft_name=craft;
	number_passenger=0;
	array_passenger=new Passenger [craft_name.getN()];
	Passenger passenger(1);
	array_passenger[number_passenger]=passenger;
	number_passenger++;
}
Travel::Travel(ifstream &fin)
{
	Airport start(fin);
	port_start=start;
	Airport end(fin);
	port_end=end;
	getline(fin, time_start);
	getline(fin, time_end);
	Aircraft craft(fin);
	craft_name=craft;
	number_passenger=0;
	array_passenger=new Passenger [craft_name.getN()];
	for(int i=0; i<craft_name.getN(); i++)
	{
		if(!fin.eof())
		{ 
			Passenger passenger(fin);
			array_passenger[number_passenger]=passenger;
			number_passenger++;
		}
	}
}
Travel::Travel(const Travel &ob)
{
	port_start=ob.port_start;
	port_end=ob.port_end;
	time_start=ob.time_start;
	time_end=ob.time_start;
    craft_name=ob.craft_name;
	array_passenger=new Passenger [craft_name.getN()];
	for(int i=0; i<craft_name.getN(); i++)
	{
		array_passenger[i]=ob.array_passenger[i];
	}
	number_passenger=ob.number_passenger;
}
Travel & Travel::operator=(const Travel &ob)
{
	port_start=ob.port_start;
	port_end=ob.port_end;
	time_start=ob.time_start;
	time_end=ob.time_start;
    craft_name=ob.craft_name;
	array_passenger=new Passenger [craft_name.getN()];
	for(int i=0; i<craft_name.getN(); i++)
	{
		array_passenger[i]=ob.array_passenger[i];
	}
	number_passenger=ob.number_passenger;
	return *this;
}
Airport Travel::getPortStart()
{
	return port_start;
}
Airport Travel::getPortEnd()
{
	return port_end;
}
Aircraft Travel::getCraftName()
{
	return craft_name;
}
string  Travel::getTimeStart()
{
	return time_start;
}
string  Travel::getTimeEnd()
{
	return time_end;
}

Passenger * Travel::getPassenger()
{
	return array_passenger;
}
int Travel::getNumberPassenger()
{
	return number_passenger;
}

void Travel::info()
{
	cout<<"\nAirport start: "<<endl;
    port_start.info();
	cout<<"Airport end: "<<endl;
	port_end.info();
	cout<<"Time start: "<<time_start<<endl;
	cout<<"Time end: "<<time_end<<endl;
	cout<<"\n";
	cout<<"Aircraft: "<<endl;
	craft_name.info();
	for(int i=0; i<number_passenger; i++)
	{
		array_passenger[i].info();
	}
	cout<<"\n";
}
Travel::~Travel()
{  }
