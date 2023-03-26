#include <iostream>
#include <string>
#include "customer.h"


void customer::setMechanicID(int x){
  MechanicID = x;}

void customer::setappointment(appointment app){
  Appointment.hours = app.hours;
  Appointment.mins = app.mins;
  ;}

int customer::getMechanicID(){
  return MechanicID;}

appointment customer::getappointment(){
  return Appointment;}

bool customer::operator == (const customer &x)
{
	return(x.Appointment.hours == Appointment.hours)&&(x.Appointment.mins == Appointment.mins);// we overload the == operation
	
}
bool customer::operator > (const customer &x)// we overload the == operation
{
	return(Appointment.hours > x.Appointment.hours)||((Appointment.hours == x.Appointment.hours)&&(Appointment.mins > x.Appointment.mins));
	
}
bool customer::operator < (const customer &x)// we overload the == operation
{
	return(Appointment.hours < x.Appointment.hours)||((Appointment.hours == x.Appointment.hours)&&(Appointment.mins < x.Appointment.mins));
	
}

void customer::print(){
  cout << "\n"<<"Mr "<< name <<" has appointment with ";
  }
