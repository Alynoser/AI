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
	void setCapital(float capital);
	void setName(string name);
	void setChange(float change);
	float getCapital();
	float getChange();
	string getName();
	float profit();
	void moveCapital(Company x, Company y);
	float Baseline(Company a, Company b, Company c, Company d, Company e, Company f, Company g, Company h, Company i, Company j);
	float evaluateMove(float base, Company x, Company y);
	Company();
	Company(string name, float capital, float change);
	~Company();
};

