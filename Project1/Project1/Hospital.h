#ifndef _Hospital_
#define _Hostital_
#include <queue>
#include "Patient.h"
#include "CarGiver.h"

class Hospital {
public:
	Hospital(){}

private:
	std::priority_queue<Patient> patients;
};



#endif
