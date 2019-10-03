#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Company
{ 
	float Capital;
	float Change;
	string Name;
public:
	void setCapital(float capital);
	float totalCap(vector<Company> vect);
	void setName(string name);
	void setChange(float change);
	float getCapital();
	float getChange();
	string getName();
	float profit();
	//void moveCapital(Company x, Company y);
	//float Baseline(vector<Company>);
	//float evaluateMove(float base, Company x, Company y);
	Company();
	Company(string name, float capital, float change);
};

