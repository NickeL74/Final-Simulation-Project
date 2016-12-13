#ifndef _Hospital_
#define _Hostital_
#include <queue>
#include "Patient.h"
#include "CareGiver.h"

class Hospital {
public:
	Hospital(){
		int rate = read_int("Please enter the average hourly patient arrival rate (patients/hour): ", 1, 60);//collect patient rate
		double arrival_rate = rate / 60.0;
		//collect num doc and nures and to respective vectors
		int num_doctor = read_int("Please enter the number of doctors: ", 0, INT_MAX);
		int num_nurse = read_int("Please enter the mnumber of nurses: ", 0, INT_MAX);
		for (int i = 0; i < num_doctor; i++) {
			Doctors.push_back(Doctor());
		}
		for (int i = 0; i < num_nurse; i++) {
			Nurses.push_back(Nurse());
		}
	}


private:
	std::priority_queue<Patient> patients;
	std::vector <Doctor> Doctors;
	std::vector <Nurse> Nurses;


	int read_int(const std::string &prompt, int low, int high)
	{
		if (low >= high) // invalid range
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					if (num >= low && num <= high) { // within the specified range
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}
	void collect_info()
	{
		int rate = read_int("Please enter the average hourly patient arrival rate (patients/hour): ", 1, 60);
		double arrival_rate = rate / 60.0;

		int num_doctor = read_int("Please enter the number of doctors: ", 0, INT_MAX);
		int num_nurse = read_int("Please enter the mnumber of nurses: ", 0, INT_MAX);

	}
};



#endif
