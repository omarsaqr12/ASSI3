#include <iostream> 

#include "mechanic.h" 
#include "person.h" 
#include "customer.h" 
#include <string> 
#include <fstream> 
#include "mechanic.cpp" 
#include "person.cpp" 
#include "customer.cpp" 
#include "template.h" 
#include "template.cpp" 
const int Size = 4; 
 void sor(customer customers[]){// we sort the customers ascendingly in order if their appoinments 
    for (int i = 0; i < 14; i++)
    {
        for (int j = i+1; j < 15; j++)
        {
            if(customers[i]>customers[j]){swap(customers[i],customers[j]);}
        }
        
    }
    
 }

string searchbyID(mechanic a[Size], int x ){// we get the name of the mechanics by their ids
    for (int i=0; i<Size; i++){
        if (x == a[i].get_id())
        return a[i].get_name();
    }
}
main (){ 
 
	queue<customer> custque;
mechanic mechanics[Size] ;//assuming only 4 mechanics 
customer customers [15]; // assuming only 15 customers 
ifstream a,b; 
a.open("Mechanic.txt"); //we open the input text files
b.open("Customer.txt"); 
 
string Name = ""; 
int Age, Id; 
 
int i=0; 
while (!a.eof()){ 
    a>> Name >> Age >> Id; 
    mechanics[i].set_name(Name); 
    mechanics[i].set_age(Age); 
    mechanics[i].set_id(Id); 
    i++; 
} 
int hours, mins, o=0; 
appointment app; 
while (!b.eof()){ 
    appointment nu;nu.hours=0;nu.mins=0;
    b>> Name >> Age >> hours >> mins; 
    app.hours = hours; 
    app.mins = mins; 
    customers[o].set_name(Name); 
    customers[o].set_age(Age); 
    int cur=0; 
    for (int l=(o)%4; l<Size; l++){ 
        if (mechanics[l].isavailable(app)){ 
        customers[o].setappointment(app); 
        mechanics[l].setappointments(app); 
        customers[o].print(); 
        mechanics[l].print(); 
     customers[o].setMechanicID(mechanics[l].get_id()); 
 
      cout<<app.hours<<":"<<app.mins; 
        cur++; 
        l=Size; 
      
 
        } 
    } 
    if (cur==0){ 
        cout << "\n"<<" Appointment for "<< customers[o].get_name() << " was cancelled."; customers[o].setMechanicID(0);customers[o].setappointment(nu); 

    } 
    o++; 
}; 
 

cout<<"\n"<<"After sorting the output is "<<"\n";
sor(customers);
 for (int j = 0; j < 15; j++)
        {
            custque.push(customers[j]);
        }
        for (int j =0; j<15; j++){
            custque.peek();
            
if(custque.peek().getMechanicID()==0){custque.peek().print();cout<<"no one";}
    else{custque.peek().print();cout << searchbyID(mechanics, custque.peek().getMechanicID())<<" "<<custque.peek().getappointment().hours<<":"<<custque.peek().getappointment().mins;}
    custque.pop();
    cout << endl << endl;
}
a.close(); 
b.close(); 
    return 0; 
}
