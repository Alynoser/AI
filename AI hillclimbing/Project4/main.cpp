#include <iostream>
#include "Company.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
float totalAllowCap = 10000;

void randomRestart(vector<Company> &vect)
{
	srand(time(NULL));
	setToZero(vect);

	float initCapital = 0, currCapTotal = 0;
	int difference = 0;

	for (int i = 0; i < vect.size(); i++)
	{
		currCapTotal = Company.Baseline(vect);
		difference = totalAllowCap - currCapTotal

			if (currCapTotal < totalAllowCap)
			{
				initCapital = rand() % difference; //Get random number between 0-1500
			}
			else if (currCapTotal == totalAllowCap)
			{
				//set v[i] = 0
			}
			else
			{
				//????
			}
	}
}

//setToZero()
//Purpose: Set all companies capitals to zero
//Input: a vector of Companies
//Output: NA
void setToZero(vector<Company> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i].Company.setCapital(0);
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
			int var1;
			ss >> name >> var1;
			Company temp(name, 1000, var1);
			companies.push_back(temp);
		}

	}
	return 0;
}