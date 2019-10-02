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