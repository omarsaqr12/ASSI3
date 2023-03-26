
#include "mechanic.h"
mechanic:: mechanic(){
  counter = 0;
}

bool mechanic::isavailable(appointment ap){ //incomplete
int f=0;
  for (int i = 0; i < counter+1; i++)
  {
    if(apps[i].hours==ap.hours&&apps[i].mins==ap.mins){f++;i=counter;}
  }
  if(f==0){return 1;}
  else{
    return 0;}// we check if the desired time is already booked for this mechanic
}




void mechanic::setappointments(appointment app){
  apps[counter].hours = app.hours;
  apps[counter].mins = app.mins;//we set the appointment then we increment the counter to move to the next 
  counter++;

}

int mechanic::getcounter(){
  return counter;}

appointment mechanic::getappointment(){
  return apps[counter];// we return the latest appointment
}
void mechanic::print(){
  cout << "Mr "<< name<<" on " ;
}


