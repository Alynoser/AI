#include <iostream>
#include "Company.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;
float totalAllowCap = 10000;

//setToZero()
//Purpose: Set all companies capitals to zero
//Input: a vector of Companies
//Output: NA
void setToZero(vector<Company> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i].setCapital(0);
	}
}

void randomRestart(vector<Company> &vect)
{
	srand(time(NULL));
	setToZero(vect);

	float initCapital = 0, currCapTotal = 0;
	int difference = 0;
	Company tmp;
	for (int i = 0; i < vect.size(); i++)
	{
		currCapTotal = tmp.totalCap(vect);
		difference = totalAllowCap - currCapTotal;
		cout << difference << endl;
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

int main(int argc, char *argv[])
{
	vector<Company> companies;
	string file;
	string line = "";
	if (argc > 0)
	{
		file = argv[1];
		ifstream inputFile(file);

		while(getline(inputFile, line))
		{
			istringstream ss(line);
			string name;
			float var1;
			ss >> name >> var1;
			Company temp(name, 1000, var1);
			companies.push_back(temp);
		}
	}

	return 0;
}


int hillclimbing(vector <Company> companies)
{
	Company x;
	bool onRestart = false;
	int timesEvale = 0;
	int randomRestartTry = 10;
	vector <Company> companiesHighscore = companies;
	float highscore = x.Baseline(companies);
	int timesRestart = 0;
	while (timesRestat < randomRestartTry)
	{
		float base = x.Baseline(companies);
		int xMove = 0;
		int yMove = 0;
		int bestMove = base;
		for (int i; i++; i < 10)
		{
			for (int j; j++; j < 10)
			{
				if (i != j)
				{
					float move = x.evaluateMove(companies[i], companies[j]);
					if (move > bestMove)
					{
						xMove = i;
						yMove = j;
					}
				}
			}
		}
		x.moveCapital(companies[xMove], companies[yMove]);
		base = x.Baseline(companies);
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
	for (int i; i++; i < 10)
	{
		cout << companies[i].getName() << " with " cout << companies[i].getCapital() << endl;
	}
	return timesEvale;
}