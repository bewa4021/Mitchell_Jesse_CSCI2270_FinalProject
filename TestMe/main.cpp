#include <iostream>
#include "AddressBook.h"
#include <fstream>
#include "Calender.h"
#include <sstream>
using namespace std;

int main()
{
    cout<<"====Address Book and Appointment Book Options===="<<endl;
    cout<<"1. Add a contact"<<endl;
    cout<<"2. Find contact information"<<endl;
    cout<<"3. Send an email"<<endl;
    cout<<"4. Change/Add Contact Information"<<endl;
    cout<<"5. Print all contacts"<<endl;
    cout<<"6. Delete a contact"<<endl;
    cout<<"7. Add an appointment"<<endl;
    cout<<"8. Cancel an appointment"<<endl;
    cout<<"9. Print all appointments"<<endl;
    cout<<"10. Find an appointment"<<endl;
    cout<<"11. Quit"<<endl;
    string answer;
    getline(cin,answer);
    AddressBook ab;
    Calender c;
    while(answer!="11"){
        if(answer=="1"){
                cout<<"Enter first and last name: (Ex: Jane Doe)"<<endl;
                string first;
                string last;
                getline(cin,first, ' ');
                getline(cin,last);
                cout<<"Enter an address:"<<endl;
                string address;
                getline(cin, address);
                cout<<"Enter a phone number:"<<endl;
                string phone;
                getline(cin,phone);
                cout<<"Enter an email address:"<<endl;
                string email;
                getline(cin,email);
                ab.addAddress(first,last,address,phone,email);
        }
        else if(answer=="2"){
            cout<<"Enter first and last name: (Ex: Jane Doe)"<<endl;
            string first;
            string last;
            getline(cin,first, ' ');
            getline(cin,last);
            ab.findPerson(last,first);
        }
         else if(answer=="3"){
            cout<<"Enter first and last name: (Ex: Jane Doe)"<<endl;
            string first;
            string last;
            getline(cin,first, ' ');
            getline(cin,last);
            cout<<"Enter the message you wish to send"<<endl;
            string message;
            getline(cin,message);
            ab.sendEmail(last,first,message);
        }
         else if(answer=="4"){
            cout<<"Enter first and last name: (Ex: Jane Doe)"<<endl;
            string first;
            string last;
            getline(cin,first, ' ');
            getline(cin,last);
            ab.changeContact(last,first);
        }
         else if(answer=="5"){
            ab.printAddresses();
        }
        else if(answer=="6"){
            cout<<"Enter first and last name: (Ex: Jane Doe)"<<endl;
            string first;
            string last;
            getline(cin,first, ' ');
            getline(cin,last);
            ab.deletePerson(last, first);
        }
        else if(answer=="7"){
            string title;
            int time;
            string t;
            cout<<"Event Name: "<<endl;
            getline(cin, title);
            cout<<"Time: (Please enter military time. Ex: 0700 for 7:00 am)"<<endl;
            getline(cin, t);
            stringstream convert(t);
            convert>>time;
            c.addDate(title, time);
        }
        else if(answer=="8"){
            cout<<"Please enter the name of the appointment you would like to cancel:"<<endl;
            string name;
            getline(cin,name);
            c.cancel(name);
        }
        else if(answer=="9"){
            c.print();
        }
        else if(answer=="10"){
            cout<<"Please enter a time you would like to search for:"<<endl;
            string t;
            int time;
            getline(cin, t);
            stringstream convert(t);
            convert>>time;
            c.findDate(time);
        }
    cout<<"====Address Book and Appointment Book Options===="<<endl;
    cout<<"1. Add a contact"<<endl;
    cout<<"2. Find contact information"<<endl;
    cout<<"3. Send an email"<<endl;
    cout<<"4. Change/Add Contact Information"<<endl;
    cout<<"5. Print all contacts"<<endl;
    cout<<"6. Delete a contact"<<endl;
    cout<<"7. Add an appointment"<<endl;
    cout<<"8. Cancel an appointment"<<endl;
    cout<<"9. Print all appointments"<<endl;
    cout<<"10. Find an appointment"<<endl;
    cout<<"11. Quit"<<endl;
        getline(cin,answer);
    }

        cout<<"Goodbye!"<<endl;
    return 0;
}
