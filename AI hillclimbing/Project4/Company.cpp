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
{
	float x1 = (x.getCapital() - 100);
	x.setCapital(x1);
	float y1 = (y.getCapital() + 100);
	y.setCapital(y1);
}

float Company::profit()
{
	return (Capital * Change);
}

float Company::Baseline(Company a, Company b, Company c, Company d, Company e, Company f, Company g, Company h, Company i, Company j)
{
	float p = (a.profit() + b.profit() + c.profit() + d.profit() + e.profit() + f.profit() + g.profit() + h.profit() + i.profit() + j.profit());
	return p;
}

float Company::evaluateMove(float base, Company x, Company y)
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
