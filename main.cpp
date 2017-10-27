#include <string>
#include <iostream>
#include <fstream>
#include "Aircraft.h"
#include "Airport.h"
#include "Passenger.h"
#include "Booking.h"
#include "Travel.h"

using namespace std;
void menu()
{
	cout<<"Меню:"<<endl;
	cout<<"1.Створити рейс"<<endl;
	cout<<"2.Информацию про рейс"<<endl;
	cout<<"3.Додати пасажира"<<endl;
	cout<<"4.Видняти пасажира"<<endl;
	cout<<"5.Информацыя про Лытак"<<endl;
	cout<<"6.Информацыя про Аеропорт"<<endl;
	cout<<"7.Clear window"<<endl;
}
int main()
{
	setlocale (LC_ALL, "ukr");
	Booking booking;
	menu();
	int vybir;
	cout<<"Vybir: "; cin>>vybir; cin.get();
	while(vybir)
	{   
		if(0<vybir && vybir<=7)
		{
			switch(vybir)
			{
			    case 1:
				{
					Travel travel(1);
					travel.writeFile();
					break;
				}
				case 2:
				{
					string name;
					cout<<"Name Travel: "; getline(cin, name);
					ifstream fin(name+".txt");
					Travel travel(fin);
					travel.info();
					fin.close();
					break;

				}
				case 3:
				{
					booking.ADD();
					break;
				}
				case 4:
				{
					booking.SUB();
					break;
				}
				case 5:
				{
					string name;
					cout<<"Name Aircraft: "; getline(cin, name);
					ifstream fin(name+".txt");
					Aircraft aircraft(fin);
					aircraft.info();
					fin.close();
					break;
				}
				case 6:
				{
					string name;
					cout<<"Name Aircraft: "; getline(cin, name);
					ifstream fin(name+".txt");
					Airport airport(fin);
					airport.info();
					fin.close();
					break;
				}
				case 7:
				{
					system("cls");
					menu();
					break;
				}
			}
		}
		else{  cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;                 }
		cout<<"Vybir: ";
		cin>>vybir; cin.get();
	}
	
	cout<<"END"<<endl;
	system("pause");
	return 0;
}