#ifndef _Patient_
#define _Patient_
#include <string>

class Patient {
private:
	std::string name;
	int triage_num;
	int arrival_time;

public:
	//Constructor
	Patient(std::string pname, int triage, int p_arrival_time) {
		name = pname;
		triage_num = triage;
		arrival_time = p_arrival_time;
	}
	//Accessor for triage_num
	int get_triage_num() {
		return triage_num;
	}

	//Accessor for arrival_time
	int get_arrival_time() {
		return arrival_time;
	}

	//Overloaded < operator for priority queue
	bool operator<(Patient &other) {
		if (triage_num< other.get_triage_num()) {
			return true;
		}
		else if (triage_num == other.get_triage_num() && arrival_time < other.get_arrival_time()) {
			return true;
		}
		else
			return false;
	}
};

#endif
