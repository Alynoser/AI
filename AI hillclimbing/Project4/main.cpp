#include <iostream>
#include "Company.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>


using namespace std;
float totalAllowCap = 10000;


//setToZero()
//Purpose: Set all companies capitals to zero
//Input: a vector of Companies
//Output: NA
double Baseline(vector<Company> vect)
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

void moveCapital(vector<Company> &vect, int x, int y) 
//moves the money once the move is selected
{
	if (vect[x].getCapital() != 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == x)
			{
				float x1 = (vect[i].getCapital() - 100);
				vect[i].setCapital(x1);
			}
			else if (i == y)
			{
				float y1 = (vect[i].getCapital() + 100);
				vect[i].setCapital(y1);
			}
		}
	}
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
				if (currCapTotal + initCapital > totalAllowCap)
				{
					vect[i].setCapital(totalAllowCap - currCapTotal);
					currCapTotal = totalAllowCap;
				}
				else
				{
					vect[i].setCapital(initCapital);
				}
				
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
					if ((move > bestMove) && (companies[i].getCapital() != 0))
					{
						xMove = i;
						yMove = j;
						bestMove = move;
					}
				}
			}
		}
		moveCapital(companies, xMove, yMove);
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
		int random = rand() % 250;
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
	cout << "With a total return of " <<highscore << endl;
	return timesEvale;
}

void annealing(int tryAllowed, vector <Company> companies)
{
	int temp = 9001;
	bool move = false;
	vector <Company> companiesHighscore = companies;
	float highscore = Baseline(companies);
	int trys = 0;
	while (trys < tryAllowed)
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
					float random = rand();
					float annel = exp(-(move - base) / temp);
					if ((annel > random) && (companies[i].getCapital() != 0))
					{
						moveCapital(companies, i, j);
						move = true;
						temp = temp * .95;
					}
					if ((move > bestMove) && (companies[i].getCapital() != 0))
					{
						xMove = i;
						yMove = j;
						bestMove = move;
					}

				}
			}
			if (move)
			{
				break;
			}
		}
		if (!move)
		{
			moveCapital(companies, xMove, yMove);
		}
		move = false;
		base = Baseline(companies);
		if (base > highscore)
		{
			highscore = base;
			companiesHighscore = companies;
		}
		trys++;
	}
	cout << "According to Simulated Annealing, the best investment stradegy is:" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << companiesHighscore[i].getName() << " with " << companiesHighscore[i].getCapital() << endl;
	}
	cout << "With a total return of " << highscore << endl;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	vector<Company> companies;
	vector<Company> otemp;
	vector<int> nums;
	string file;
	string line = "";
	int count = 0;
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
			otemp.push_back(temp);
		}
		while (count != 10)
		{
			bool found = true;
			int i = rand() % 30;
			if (count == 0)
			{
				nums.push_back(i);
				companies.push_back(otemp[i]);
				count++;
			}
			else
			{
				for (int j = 0; j < nums.size(); ++j)
				{
					if (nums[j] == i)
					{
						found = false;
					}
				}
				if (found)
				{
					nums.push_back(i);
					companies.push_back(otemp[i]);
					count++;
				}
			}

		}
		cout << "The TFB's recomended stragedy will net a total of " << Baseline(companies) << endl;
		vector<Company> companies2 = companies;
		int i = hillclimbing(companies);
		annealing(i, companies2);
		int input;
		cin >> input;
	}
	
	return 0;
}
