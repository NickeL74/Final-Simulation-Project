#ifndef _Hospital_
#define _Hostital_
#include <queue>
#include <map>
#include <random>
#include <iostream>
#include "Patient.h"
#include "CareGiver.h"

class Hospital {
public:
	Hospital(){
		//read in names of residents from file loctated in Repo folder
		//working diretory many need to be changed on other devices
		std::ifstream input("residents_of_273ville.txt");
		for (std::string line; getline(input, line); )
		{
			citizens.push_back(line);
		}
		int rate = read_int("Please enter the average hourly patient arrival rate (patients/hour): ", 1, 60);//collect patient rate
		arrival_rate = rate / 60.0;
		//collect num doc and nures and to respective vectors
		num_doctor = read_int("Please enter the number of doctors: ", 0, INT_MAX);
		num_nurse = read_int("Please enter the mnumber of nurses: ", 0, INT_MAX);
	}


private:
	std::priority_queue<Patient> *crit_patients;
	std::priority_queue<Patient> *std_patients;
	std::map<std::string, Patient> treated_patients;
	std::deque <Patient> doctors;
	int num_doctor;
	std::deque <Patient> nurses;
	int num_nurse;
	double arrival_rate;
	std::vector<std::string> citizens;


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
	void incoming_patients(int clock) {
		double num = double(rand()) / RAND_MAX;
		if (num < arrival_rate) {
			double num2 = double(rand()) / RAND_MAX;
			if (num2 < 0.1) {
				int triage = rand() / (RAND_MAX / 4) + 16;
				crit_patients->push(Patient(citizens[rand() / (RAND_MAX / 2000)], int(num2), clock));
			}
			else if (num2 < 0.2) {
				int triage = rand() / (RAND_MAX / 4) + 11;
				crit_patients->push(Patient(citizens[rand() / (RAND_MAX / 2000)], int(num2), clock));
			}
			else {
				int triage = rand() / (RAND_MAX / 9) + 1;
				std_patients->push(Patient(citizens[rand() / (RAND_MAX / 2000)], int(num2), clock));
			}
		}
	}
	void assign_patients(int clock) {
		while (doctors.size() < num_doctor) {
			if (crit_patients->empty() && std_patients->empty()) {
				return;
			}
			if (doctors.size() < num_doctor) {
				doctors.push_back(crit_patients->top());
				crit_patients->pop();
			}
			else if (doctors.size() < num_doctor && crit_patients->empty()) {
				doctors.push_back(std_patients->top());
				std_patients->pop();
			}
		}
		while (nurses.size() < num_nurse) {
			if (std_patients->empty())
				return;
			nurses.push_back(std_patients->top());
			std_patients->pop();
		}
	}
	void treat_patients(int clock) {
		for (int i = 0; i < num_doctor; i++) {
			doctors[i].treat();
			if (doctors[i].get_treat_time() < 1) {
				doctors.erase(doctors.begin() + i);
			}
		}
		for (int i = 0; i < num_nurse; i++) {
			nurses[i].treat();
			if (nurses[i].get_treat_time() < 1) {
				nurses.erase(nurses.begin() + i);
			}
		}
	}

		void run_simulation() {
			for (int clock = 0; clock < 10080; clock++) {
				incoming_patients(clock);
				assign_patients(clock);
				treat_patients(clock);
			}
		}
		
};



#endif
