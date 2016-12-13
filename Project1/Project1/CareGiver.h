#ifndef _Care_Giver_
#define _Care_Giver_

class CareGiver {
protected:
	int min_treat = 1;
	int max_treat;
	bool with_patient = false;
	
};

class Doctor : public CareGiver {
public:
	Doctor() {
		max_treat = 20;
	}
};
class Nurse : public CareGiver {
public:
	Nurse() {
		max_treat = 10;
	}
};

#endif