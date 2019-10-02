#include "Helpers.h"
#include "Company.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float totalAllowCap = 10000;

//randomRestart()
//Purpose: Randomly assign capitol to companies
//Input: A vector of companies
//Output: NA
void Helpers::randomRestart(vector<Company> &vect)
{
	srand(time(NULL));
	setToZero(vect);

	float initCapital = 0, currCapTotal = 0;
	int difference = 0;

	for(int i = 0; i < vect.size(); i++)
	{
		currCapTotal = Company.Baseline(vect);
		difference = totalAllowCap - currCapTotal

		if(currCapTotal < totalAllowCap)
		{
			initCapital = rand() % difference; //Get random number between 0-1500
		}
		else if(currCapTotal == totalAllowCap)
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
void Helpers::setToZero(vector<Company> &v)
{
	for(int i = 0; i < v.size(); i++)
	{
		v[i].Company.setCapital(0);
	}
}