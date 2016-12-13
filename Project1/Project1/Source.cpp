#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "Hospital.h"


using namespace std;


int main() {
	/*srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		cout << double(rand()) / RAND_MAX << endl;
	}
	*/
	srand(time(NULL));
	Hospital cs_hospital;
	cs_hospital.run_simulation();
	cs_hospital.show_stats();
}