#ifndef _Patient_
#define _Patient_
#include <string>

class Patient {
private:
	string name;
	int tirage_num;
	int arrival_time;

public:
	//Constructor
	Patient(string pname, int triage, int p_arrival_time) {
		name = pname;
		triage_num = tirage;
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
	bool operator<(const Patient &other) {
		if (triage< other.get_triage_num()) {
			return true;
		}
		else if (name == other.get_triage_num() && age < other.get_arrival_time()) {
			return true;
		}
		else
			return false;
	}
};

#endif
