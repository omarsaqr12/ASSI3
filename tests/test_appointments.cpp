#define main assi3_interactive_main
#include "../main.cpp"
#undef main

#include <cassert>
#include <sstream>

int main() {
    std::istringstream mechanicsInput("Alice 30 1\nBob 40 2\n");
    auto mechanics = loadMechanics(mechanicsInput);
    assert(mechanics.size() == 2);
    std::istringstream customersInput("A 20 9 30\nB 21 9 30\nC 22 9 30\n");
    auto requests = loadCustomers(customersInput);
    assert(requests.size() == 3);
    assert(scheduleCustomer(requests[0].record, requests[0].requested, mechanics, 0));
    assert(scheduleCustomer(requests[1].record, requests[1].requested, mechanics, 1));
    assert(!scheduleCustomer(requests[2].record, requests[2].requested, mechanics, 0));
    assert(requests[0].record.getMechanicID() == 1);
    assert(requests[1].record.getMechanicID() == 2);
    assert(requests[2].record.getMechanicID() == 0);
    assert(mechanics[0].getcounter() == 1 && mechanics[1].getcounter() == 1);
    assert(mechanics[0].getappointment().hours == 9);
    assert(!mechanics[0].isavailable({9, 30}));
    assert(mechanics[0].isavailable({9, 31}));

    // Wraparound: start at busy mechanic 1, then find available mechanic 0.
    customer later;
    assert(scheduleCustomer(later, {10, 0}, mechanics, 1));
    assert(later.getMechanicID() == 2);
    customer wrap;
    assert(scheduleCustomer(wrap, {10, 0}, mechanics, 1));
    assert(wrap.getMechanicID() == 1);

    queue<int> q(2);
    q.push(1); q.push(2);
    assert(q.peek() == 1);
    q.pop(); q.push(3);
    assert(q.peek() == 2);
    q.pop(); assert(q.peek() == 3);
    q.pop();
    bool threw = false;
    try { q.peek(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);
    threw = false;
    try { q.pop(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);
    threw = false;
    try { queue<int> bad(0); } catch (const std::invalid_argument&) { threw = true; }
    assert(threw);

    std::istringstream invalidTime("Someone 30 24 0\n");
    threw = false;
    try { loadCustomers(invalidTime); } catch (const std::runtime_error&) { threw = true; }
    assert(threw);
    std::istringstream malformed("Someone 30 9 30\nBroken 45 nope 42\n");
    threw = false;
    try { loadCustomers(malformed); } catch (const std::runtime_error&) { threw = true; }
    assert(threw);

    std::istringstream incomplete("Name 20 9");
    threw = false;
    try { loadCustomers(incomplete); } catch (const std::runtime_error&) { threw = true; }
    assert(threw);
    std::istringstream duplicateIds("Alice 30 1\nBob 35 1\n");
    threw = false;
    try { loadMechanics(duplicateIds); } catch (const std::runtime_error&) { threw = true; }
    assert(threw);
    mechanic full;
    for (int i = 0; i < 24; ++i) full.setappointments({i, 0});
    assert(!full.isavailable({12, 1}));
    threw = false;
    try { full.setappointments({12, 1}); } catch (const std::logic_error&) { threw = true; }
    assert(threw);
    q.push(10); q.push(20);
    threw = false;
    try { q.push(30); } catch (const std::overflow_error&) { threw = true; }
    assert(threw);
}
