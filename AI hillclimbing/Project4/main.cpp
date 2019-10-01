#include <iostream>
#include "Company.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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
		}

	}
	return 0;
}