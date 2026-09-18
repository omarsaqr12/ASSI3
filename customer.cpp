#include "customer.h"
#include <iostream>
void customer::setMechanicID(int x) { MechanicID = x; }
void customer::setappointment(appointment app) { Appointment = app; }
int customer::getMechanicID() { return MechanicID; }
appointment customer::getappointment() { return Appointment; }
bool customer::operator==(const customer& x) {
    return Appointment.hours == x.Appointment.hours && Appointment.mins == x.Appointment.mins;
}
bool customer::operator>(const customer& x) {
    return Appointment.hours > x.Appointment.hours ||
           (Appointment.hours == x.Appointment.hours && Appointment.mins > x.Appointment.mins);
}
bool customer::operator<(const customer& x) {
    return Appointment.hours < x.Appointment.hours ||
           (Appointment.hours == x.Appointment.hours && Appointment.mins < x.Appointment.mins);
}
void customer::print() { std::cout << "Mr " << name << " has appointment with "; }
