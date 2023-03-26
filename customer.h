#include <iostream>
#include <string>
#include "person.h"
#ifndef CUSTOMER
#define CUSTOMER
using namespace std;


class customer : public person{

private:

int MechanicID;// we initialize the private variables of this class
appointment Appointment;


public:

void setMechanicID(int);

void setappointment(appointment);

int getMechanicID();

appointment getappointment();// we prototype our methods

bool operator <  (const customer &x);
bool operator >  (const customer &x);
bool operator == (const customer &x);

void print();
};

#endif