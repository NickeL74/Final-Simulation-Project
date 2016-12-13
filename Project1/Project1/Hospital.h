#ifndef _Hospital_
#define _Hostital_
#include <queue>
#include "Patient.h"

class Hospital {
public:
	Hospital(){}

private:
	std::priority_queue<Patient> patients;
};



#endif
