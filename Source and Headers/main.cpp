#include <iostream>
#include "AddressBook.h"
#include <fstream>
#include <sstream>
#include "Calender.h"
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
    fstream addresses;
    addresses.open("AddressSave.txt");
    while(answer!="11"){
        if(answer=="1"){
            cout<<"Do you want to read in a contact file? y or n"<<endl;
            string a;
            getline(cin,a);
            if(a=="y"){
                if (addresses.good()){
                    cout<<"File successfully opened."<<endl;
                    string first, last, email, phone, address, line;
                    while (getline(addresses, line))
                    {
                        stringstream ss(line);
                        getline(ss, first, ',');
                        getline(ss,last, ',');
                        getline(ss,address,',');
                        getline(ss,email,',');
                        getline(ss,phone,',');
                        ab.addAddress(first,last,address,phone,email);
                    }
                    addresses.close();
                }
            }
            else{
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
            cout<<"Event Name: ";
            getline(cin, title);
            cout<<"Time: ";
            cin>>time;
            c.addDate(title, time);
        }
        else if(answer=="8"){
            cout<<"8"<<endl;
        }
        else if(answer=="9"){
            cout<<"9"<<endl;
        }
        else if(answer=="10"){
            cout<<"10"<<endl;
        }
        cin.ignore();
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
    cout<<"Would you like to save your contacts to a file? y or n"<<endl;
    string a;
    getline(cin,a);
    if(a=="y"){
        /*
        fstream inFile;
        inFile.open("SavedAddressBook.txt",std::fstream::trunc);
        ab.saveFile(inFile);
        inFile.close();
        */
        cout<<"Goodbye!"<<endl;
    }
    else
        cout<<"Goodbye!"<<endl;
    return 0;
}
