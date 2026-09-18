#ifndef ASSI3_CUSTOMER_H
#define ASSI3_CUSTOMER_H

#include "person.h"

class customer : public person {
private:
    int MechanicID = 0; // 0 means no booking.
    appointment Appointment{};

public:
    void setMechanicID(int);
    void setappointment(appointment);
    int getMechanicID();
    appointment getappointment();
    bool operator<(const customer&);
    bool operator>(const customer&);
    bool operator==(const customer&);
    void print() override;
};

#endif
