#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include "Hospital.h"


using namespace std;


int main() {
	for (int i = 0; i < 10; i++)
		cout << rand() / RAND_MAX << endl;
	Hospital cs_hospital;
//	cs_hospital.run_simulation();
	//cs_hospital.show_stats();
}