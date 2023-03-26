#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;
struct appointment{
int hours;
int mins;
};// we declare the structure 
class person{
    protected:// we declare the protected variables
    string name;
    int id;
    int age;

    public:
    person();
    void set_name(string);
    void set_id(int );
   void set_age(int );
    string get_name();
    int get_id();
    int get_age();
    virtual void print()=0;// we make print function pure virtual to make the class abstract
};


#endif