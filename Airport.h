#pragma once
#include <string>

using namespace std;

class Airport
{
protected:
	string name;
	string city;
	string country;
public:
	Airport();
	~Airport();
};