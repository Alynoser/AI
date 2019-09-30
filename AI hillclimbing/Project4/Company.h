#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
class Company
{ 
	float Capital;
	float Change;
	string Name;
public:
	void setCapital(float);
	void setName(string);
	void setChange(float);
	float getCapital();
	float getChange();
	string getName();
	float profit();
	void moveCapital(Company, Company);
	float Baseline(Company, Company, Company, Company, Company, Company, Company, Company, Company, Company);
	float evaluateMove(float, Company, Company);
	Company();
	~Company();
};

