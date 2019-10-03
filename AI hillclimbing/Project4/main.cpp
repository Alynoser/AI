#include <iostream>
#include "Company.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


using namespace std;
float totalAllowCap = 10000;


//setToZero()
//Purpose: Set all companies capitals to zero
//Input: a vector of Companies
//Output: NA
float Baseline(vector<Company> vect)
//creates the base profit made my the companys in the vector. Creates a baseline to find the most optimal move
{
	float p = 0;
	for (int i = 0; i < vect.size(); i++)
	{
		p += vect[i].profit();
	}
	return p;
}

void setToZero(vector<Company> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i].setCapital(0);
	}
}

void moveCapital(Company x, Company y)
//moves the money once the move is selected
{
	float x1 = (x.getCapital() - 100);
	x.setCapital(x1);
	float y1 = (y.getCapital() + 100);
	y.setCapital(y1);
}

float evaluateMove(float base, Company x, Company y)
//returns the new total profit value of the move
{
	float nBase = (base - x.profit() - y.profit());
	float xProfit = (x.getChange() * (x.getCapital() - 100));
	float yProfit = (y.getChange() * (y.getCapital() + 100));
	nBase = nBase + xProfit + yProfit;
	return nBase;
}

void randomRestart(vector<Company> &vect)
{
	
	setToZero(vect);

	float initCapital = 0, currCapTotal = 0;
	int difference = 0;
	Company tmp;
	for (int i = 0; i < vect.size(); i++)
	{
		currCapTotal = tmp.totalCap(vect);
		difference = totalAllowCap - currCapTotal;
			if (currCapTotal < totalAllowCap && i != 9)
			{
				initCapital = (rand() % 15) * 100; //Get random number between 0-1500
				vect[i].setCapital(initCapital);
			}
			else if (currCapTotal < totalAllowCap && i == 9)
			{
				vect[i].setCapital(difference);
			}
			else if (currCapTotal == totalAllowCap)
			{
				vect[i].setCapital(0);
			}
			else
			{
				cout << "Something broke" << endl;
				exit(0);
			}
	}
}



int hillclimbing(vector <Company> companies)
{
	bool onRestart = false;
	int timesEvale = 0;
	int randomRestartTry = 100;
	vector <Company> companiesHighscore = companies;
	float highscore = Baseline(companies);
	int timesRestart = 0;
	while (timesRestart < randomRestartTry)
	{
		float base = Baseline(companies);
		int xMove = 0;
		int yMove = 0;
		float bestMove = base;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i != j)
				{
					float move = evaluateMove(base, companies[i], companies[j]);
					if (move > bestMove)
					{
						xMove = i;
						yMove = j;
						bestMove = move;
					}
				}
			}
		}
		moveCapital(companies[xMove], companies[yMove]);
		base = Baseline(companies);
		if (base > highscore)
		{
			highscore = base;
			companiesHighscore = companies;
			if ((timesRestart > 0) && (onRestart))
			{
				onRestart = false;
				randomRestartTry = randomRestartTry + 10;
			}
		}
		int random = rand() % 100;
		if (random == 42)
		{
			randomRestart(companies);
			timesRestart++;
			onRestart = true;

		}

		timesEvale++;
	}
	cout << "According to Hillclimbing, the best investment stradegy is:" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << companiesHighscore[i].getName() << " with " << companiesHighscore[i].getCapital() << endl;
	}
	return timesEvale;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	vector<Company> companies;
	string file;
	string line = "";
	if (argc > 0)
	{
		// file = argv[1];
		ifstream inputFile("file.txt");

		while(getline(inputFile, line))
		{
			istringstream ss(line);
			string name;
			float var1;
			ss >> name >> var1;
			Company temp(name, 1000, var1);
			companies.push_back(temp);
		}
		int i = hillclimbing(companies);
	}

	return 0;
}
