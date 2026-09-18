#ifndef ASSI3_PERSON_H
#define ASSI3_PERSON_H

#include <string>

struct appointment {
    int hours = 0;
    int mins = 0;
};

class person {
protected:
    std::string name;
    int id = 0;
    int age = 0;

public:
    person();
    virtual ~person() = default;
    void set_name(std::string);
    void set_id(int);
    void set_age(int);
    std::string get_name();
    int get_id();
    int get_age();
    virtual void print() = 0;
};

#endif
