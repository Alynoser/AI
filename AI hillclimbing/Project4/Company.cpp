#include "Company.h"
#include <string>
#include <iostream>
using namespace std;


Company::Company()
{
	Name = "CyberDyne Systems";
	Capital = 1000;
	Change = 666.66;
}

Company::Company(string name, float capital, float change)
{
	Name = name;
	Capital = capital;
	Change = change;
}

void Company::setCapital(float capital)
{
	Capital = capital;
}

void Company::setChange(float change)
{
	Change = change;
}

void Company::setName(string name)
{
	Name = name;
}

float Company::getCapital()
{
	return Capital;
}

float Company::getChange()
{
	return Change;
}

string Company::getName()
{
	return Name;
}

void Company::moveCapital(Company x, Company y)
//moves the money once the move is selected
{
	float x1 = (x.getCapital() - 100);
	x.setCapital(x1);
	float y1 = (y.getCapital() + 100);
	y.setCapital(y1);
}

float Company::profit()
//returns the money made by each company
{
	return (Capital * Change);
}

float Company::Baseline(vector<Company> vect)
//creates the base profit made my the companys in the vector. Creates a baseline to find the most optimal move
{
	float p = 0;
	for(int i = 0; i < vect.size(); i++)
	{
		p += vect[i].profit();
	}
	return p;
}

float Company::evaluateMove(float base, Company x, Company y)
//returns the new total profit value of the move
{
	float nBase = (base - x.profit() - y.profit());
	float xProfit = (x.getChange() * (x.getCapital() - 100));
	float yProfit = (y.getChange() * (y.getCapital() + 100));
	nBase = nBase + xProfit + yProfit;
	return nBase;
}

Company::~Company()
{
}
