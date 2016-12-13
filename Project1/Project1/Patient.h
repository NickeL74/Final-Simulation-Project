#ifndef _Patient_
#define _Patient_
#include <string>
#include <vector>

class Treatment {
private:
	int triage;
	int time_of;
public:
	Treatment(int p_triage, int p_time_of) {
		triage = p_triage;
		time_of = p_time_of;
	}
	int get_triage() {
		return triage;
	}
	int get_time_of() {
		return time_of;
	}
};


class Patient {
private:
	std::string name;
	int treat_time;
	int arrival_time;
	std::vector<Treatment> visits;

public:
	int triage_num;

	//Constructor
	Patient(std::string pname, int p_triage_num, int p_treat_time, int p_arrival_time) {
		name = pname;
		triage_num = p_triage_num;
		arrival_time = p_arrival_time;
		treat_time = p_treat_time;
	}
	void add_visit(int out_time) {
		visits.push_back(Treatment(triage_num, out_time - arrival_time));
	}
	//Accessor for triage_num
	int get_triage_num() const {
		return triage_num;
	}

	std::string get_name() {
		return name;
	}
	//Accessor for arrival_time
	int get_arrival_time() const{
		return arrival_time;
	}
	int get_treat_time() {
		return treat_time;
	}
	//Set treat time
	void set_treat_time(int time) {
		treat_time = time;
	}
	//Iterate treat_time
	void treat() {
		treat_time--;
	}
	//Overloaded < operator for priority queue
	bool operator<(const Patient &other) const {
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
