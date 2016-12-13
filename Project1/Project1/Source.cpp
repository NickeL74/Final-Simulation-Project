#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include "Hospital.h"


using namespace std;


int main() {
	//read in names of residents from file loctated in Repo folder
	//working diretory many need to be changed on other devices
	set<string> names;
	ifstream input("residents_of_273ville.txt");
	for (string line; getline(input, line); )
	{
		names.insert(line);
	}

}