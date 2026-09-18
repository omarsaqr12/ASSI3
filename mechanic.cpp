#include "mechanic.h"

#include <iostream>
#include <stdexcept>

mechanic::mechanic() = default;

bool mechanic::isavailable(appointment ap) {
    if (counter >= 24) return false;
    for (int i = 0; i < counter; ++i) {
        if (apps[i].hours == ap.hours && apps[i].mins == ap.mins) return false;
    }
    return true;
}

void mechanic::setappointments(appointment ap) {
    if (!isavailable(ap)) throw std::logic_error("Mechanic unavailable at requested time");
    apps[counter++] = ap;
}

int mechanic::getcounter() { return counter; }

appointment mechanic::getappointment() {
    if (counter == 0) throw std::out_of_range("No appointments booked");
    return apps[counter - 1];
}

void mechanic::print() { std::cout << "Mr " << name << " on "; }
