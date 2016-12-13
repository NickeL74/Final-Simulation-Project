#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include "Hospital.h"


using namespace std;


int main() {

	set<string> names;
	ifstream input("residents_of_273ville.txt");
	for (string line; getline(input, line); )
	{
		names.insert(line);
	}

}