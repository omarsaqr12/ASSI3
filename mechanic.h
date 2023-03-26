#ifndef MECHANIC
#define MECHANIC
#include <iostream>
#include "person.h"
class mechanic : public person{// we inherit publicily from class person
private:
int counter;// we declare th counter
appointment apps[24]; //assume a max of 24 appointments per day for each mechanic

public:
mechanic();

bool isavailable(appointment);

void setappointments(appointment );

int getcounter();

appointment getappointment();
void print();
};



#endif