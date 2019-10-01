#include "Helpers.h"
#include "Company.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Helpers::randomRestart(vector<Company> vect)
{
	srand(time(NULL));

	initCapital = rand() % 1500; //Get random number between 0-1500

}