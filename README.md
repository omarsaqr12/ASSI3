# Mechanic appointment scheduler (C++ course project)

A console-based object-oriented programming exercise that reads mechanics and customer appointment requests, assigns each customer to an available mechanic, then sorts and prints the resulting schedule using a custom circular queue. It demonstrates `person` inheritance (`customer` and `mechanic`), appointment-time comparisons, and a templated queue. This is a classroom scheduling simulation, not a production booking service.

## Build and run

Requires a C++17 compiler. Run from the repository root so the two input files can be found:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp customer.cpp mechanic.cpp person.cpp -o appointments
./appointments
```

Input files use whitespace-delimited records without headings: [`Mechanic.txt`](Mechanic.txt) contains `name age id`; [`Customer.txt`](Customer.txt) contains `name age hour minute`. The repository includes example records. Mechanic IDs must be positive and unique; hours use 0–23, minutes 0–59. The educational maximum is four mechanics, fifteen customers, and twenty-four bookings per mechanic. Malformed data or missing files produce an error and a nonzero exit code.

## Scheduling behavior

Customers are processed in input order. For customer index `i`, the scheduler first tries mechanic `i % number_of_mechanics`, then tries the remaining mechanics **with wraparound**. Two appointments conflict only if their hour and minute are exactly equal; duration, calendar date, opening hours, and persistence are not modeled. If every mechanic already has that time booked, the customer's booking is cancelled (mechanic ID 0, time 00:00). The final list is stably sorted by assigned time; cancelled entries therefore appear first. Names are single whitespace-delimited tokens.

## Test

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fno-omit-frame-pointer -g tests/test_appointments.cpp customer.cpp mechanic.cpp person.cpp -o /tmp/assi3-tests
/tmp/assi3-tests
```

The tests cover booking collisions, wraparound, cancellation, last-booking lookup, circular-queue behavior and empty-queue errors, invalid times and malformed records. This does not constitute exhaustive scheduling validation. The demonstration is also manually exercised with the included input files.

## Repository map and provenance

- [`main.cpp`](main.cpp): file parsing, appointment assignment and console workflow.
- [`person.h`](person.h), [`person.cpp`](person.cpp): abstract base class and shared fields.
- [`customer.h`](customer.h), [`customer.cpp`](customer.cpp): customer appointment and comparisons.
- [`mechanic.h`](mechanic.h), [`mechanic.cpp`](mechanic.cpp): bounded booking records and availability.
- [`template.h`](template.h), [`template.cpp`](template.cpp): custom circular queue; `template.cpp` is included from `main.cpp` because template definitions must be available at instantiation. Do not compile `template.cpp` separately with the command above.
- [`tests/test_appointments.cpp`](tests/test_appointments.cpp): reproducible assertions.
- [`readme.txt`](readme.txt) and [`output.pdf`](output.pdf): original submission note and report, retained unmodified. The historical note describes a post-submission correction; this maintenance branch makes additional changes and does **not** represent the original submitted source. The PDF was inaccessible to the automated review, so its content has not been independently verified.

No particular grade, user scale, production reliability or independent evaluation is claimed. The implementation intentionally retains the original simplified appointment model and assignment capacities.
