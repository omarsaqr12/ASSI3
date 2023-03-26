#include <iostream>
#include <string>
#include "person.h"
using namespace std;
person::person(){// we initialize using the default constructor the protected variable of the class
  name = "";
  id =0;
  age = 0;}

string person::get_name(){
  return name;}

int person::get_id(){
  return id;}

int person::get_age(){
  return age;}

void person::set_name(string x){
  name = x;}

void person::set_id(int x){
  id = x;}

void person::set_age(int x){
  age = x;}


// we then implement the setters and the getters


