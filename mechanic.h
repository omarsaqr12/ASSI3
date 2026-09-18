#ifndef ASSI3_MECHANIC_H
#define ASSI3_MECHANIC_H

#include "person.h"

class mechanic : public person {
private:
    int counter = 0;
    appointment apps[24]{}; // Exercise limit: at most 24 exact-time appointments.

public:
    mechanic();
    bool isavailable(appointment);
    void setappointments(appointment);
    int getcounter();
    appointment getappointment();
    void print() override;
};

#endif
