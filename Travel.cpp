#include <string>
#include <iostream>
#include <fstream>
#include "Travel.h"

using namespace std;

Travel::Travel()
{
	time_start="\0";
	time_end="\0";
	number_passenger=0;
}
Travel::Travel(int)
{
	string name; ifstream fin; 
	cout<<"\tAIRPORT START\nName City: ";   getline(cin, name);  fin.open(name+".txt");
	port_start=Airport(fin);                                     fin.close();
	cout<<"\tAIRPORT END\nName City: ";     getline(cin, name);  fin.open(name+".txt");
	port_end=Airport(fin);                                       fin.close();
	cout<<"\tTIME\n";
	cout<<"Time start: ";                   getline(cin, time_start);
	cout<<"Time end: ";                     getline(cin, time_end);
	cout<<"\tAIRCRAFT\nName Aircraft: ";    getline(cin, name);  fin.open(name+".txt");
	craft_name=Aircraft(fin);                                    fin.close();
	number_passenger=0;
	array_passenger=new Passenger [craft_name.getN()];
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
void Travel::setPassenger(Passenger * _array)
{
	array_passenger=_array;
}
int Travel::getNumberPassenger()
{
	return number_passenger;
}
void Travel::setPassenger(Passenger &passenger)
{
	array_passenger[number_passenger]=passenger;
	number_passenger++;
}
void Travel::info()
{
	cout<<"\n\tAIRPORT START\n";
    port_start.info();
	cout<<"\tAIRPORT END\n";
	port_end.info();
	cout<<"\tTIME\n";
	cout<<"Time start: "<<time_start<<endl;
	cout<<"Time end: "<<time_end<<endl;
	cout<<"\tAIRCRAFT\n";
	craft_name.info();
	cout<<"\tPASSENGER\n";
	for(int i=0; i<craft_name.getN(); i++)
	{
		array_passenger[i].info();
	}
	cout<<"\n";
}
void Travel::writeFile()
{
	ofstream fout(port_start.getCity()+"-"+port_end.getCity()+"-"+time_start.substr(time_start.find(" ")+1)+".txt");
	port_start.writeFile(fout);
	port_end.writeFile(fout);
	fout<<time_start<<endl;
	fout<<time_end<<endl;
	craft_name.writeFile(fout);
	for(int i=0; i<craft_name.getN(); i++)
	{
		array_passenger[i].writeFile(fout);
	}
}
Travel::~Travel()
{  }