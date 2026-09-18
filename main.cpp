#include "customer.h"
#include "mechanic.h"
#include "template.h"
// This course exercise keeps template definitions in a separate .cpp; include it
// at the point of instantiation. Other .cpp files are compiled separately.
#include "template.cpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

constexpr std::size_t MAX_MECHANICS = 4;
constexpr std::size_t MAX_CUSTOMERS = 15;

std::vector<mechanic> loadMechanics(std::istream& in) {
    std::vector<mechanic> result;
    std::string line;
    while (std::getline(in, line)) {
        if (line.find_first_not_of(" \t\r") == std::string::npos) continue;
        std::istringstream record(line);
        std::string name, extra;
        int age, id;
        if (!(record >> name >> age >> id) || (record >> extra))
            throw std::runtime_error("Malformed Mechanic.txt record");
        if (result.size() == MAX_MECHANICS) throw std::runtime_error("Too many mechanics (maximum 4)");
        if (age < 0 || id <= 0) throw std::runtime_error("Invalid mechanic age or ID");
        for (mechanic& previous : result)
            if (previous.get_id() == id) throw std::runtime_error("Duplicate mechanic ID");
        mechanic entry;
        entry.set_name(name);
        entry.set_age(age);
        entry.set_id(id);
        result.push_back(entry);
    }
    if (in.bad()) throw std::runtime_error("Could not read Mechanic.txt");
    if (result.empty()) throw std::runtime_error("No mechanics supplied");
    return result;
}

struct CustomerRequest {
    customer record;
    appointment requested;
};

std::vector<CustomerRequest> loadCustomers(std::istream& in) {
    std::vector<CustomerRequest> result;
    std::string line;
    while (std::getline(in, line)) {
        if (line.find_first_not_of(" \t\r") == std::string::npos) continue;
        std::istringstream record(line);
        std::string name, extra;
        int age, hours, mins;
        if (!(record >> name >> age >> hours >> mins) || (record >> extra))
            throw std::runtime_error("Malformed Customer.txt record");
        if (result.size() == MAX_CUSTOMERS) throw std::runtime_error("Too many customers (maximum 15)");
        if (age < 0 || hours < 0 || hours > 23 || mins < 0 || mins > 59)
            throw std::runtime_error("Invalid customer age or appointment time");
        CustomerRequest request;
        request.record.set_name(name);
        request.record.set_age(age);
        request.requested = {hours, mins};
        result.push_back(request);
    }
    if (in.bad()) throw std::runtime_error("Could not read Customer.txt");
    return result;
}

// Try every mechanic once, starting at customerIndex % number of mechanics.
bool scheduleCustomer(customer& c, appointment requested,
                      std::vector<mechanic>& mechanics, std::size_t customerIndex) {
    for (std::size_t step = 0; step < mechanics.size(); ++step) {
        mechanic& candidate = mechanics[(customerIndex + step) % mechanics.size()];
        if (candidate.isavailable(requested)) {
            candidate.setappointments(requested);
            c.setappointment(requested);
            c.setMechanicID(candidate.get_id());
            return true;
        }
    }
    c.setMechanicID(0);
    c.setappointment({});
    return false;
}

std::string searchbyID(std::vector<mechanic>& mechanics, int id) {
    for (mechanic& m : mechanics) if (id == m.get_id()) return m.get_name();
    return "unknown mechanic";
}

int main() {
    try {
        std::ifstream mechanicsFile("Mechanic.txt");
        std::ifstream customersFile("Customer.txt");
        if (!mechanicsFile || !customersFile)
            throw std::runtime_error("Run from a directory containing Mechanic.txt and Customer.txt");

        std::vector<mechanic> mechanics = loadMechanics(mechanicsFile);
        std::vector<CustomerRequest> requests = loadCustomers(customersFile);
        std::vector<customer> customers;
        customers.reserve(requests.size());

        for (std::size_t i = 0; i < requests.size(); ++i) {
            customer& c = requests[i].record;
            if (scheduleCustomer(c, requests[i].requested, mechanics, i)) {
                std::cout << c.get_name() << " booked with "
                          << searchbyID(mechanics, c.getMechanicID()) << " at "
                          << c.getappointment().hours << ':' << c.getappointment().mins << '\n';
            } else {
                std::cout << "Appointment for " << c.get_name() << " was cancelled.\n";
            }
            customers.push_back(c);
        }

        std::stable_sort(customers.begin(), customers.end(),
                         [](customer a, customer b) { return a < b; });
        queue<customer> ordered(static_cast<int>(customers.empty() ? 1 : customers.size()));
        for (const customer& c : customers) ordered.push(c);
        std::cout << "\nAfter sorting by assigned appointment time:\n";
        while (!ordered.isEmpty()) {
            customer current = ordered.peek();
            ordered.pop();
            std::cout << current.get_name() << " -> ";
            if (current.getMechanicID() == 0) std::cout << "no appointment";
            else std::cout << searchbyID(mechanics, current.getMechanicID()) << " "
                           << current.getappointment().hours << ':'
                           << current.getappointment().mins;
            std::cout << '\n';
        }
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
}
