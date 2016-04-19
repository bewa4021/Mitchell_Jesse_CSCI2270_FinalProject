#include <iostream>
#include "AddressBook.h"
using namespace std;

int main()
{
    cout<<"====Address Book Options===="<<endl;
    cout<<"1. Add a contact"<<endl;
    cout<<"2. Find contact information"<<endl;
    cout<<"3. Send an email"<<endl;
    cout<<"4. Delete a contact"<<endl;
    cout<<"5. Print all contacts"<<endl;
    cout<<"6. Quit"<<endl;
    string answer;
    getline(cin,answer);
    AddressBook ab;
    while(answer!="6"){
        if(answer=="1"){
            cout<<"Do you want to read in a contact file? y or n"<<endl;
            string a;
            getline(cin,a);
            if(a=="y"){
                cout<<"Reading in file!"<<endl;
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
            cout<<"3"<<endl;
        }
         else if(answer=="4"){
            cout<<"4"<<endl;
        }
         else if(answer=="5"){
            ab.printAddresses();
        }
        cout<<"====Address Book Options===="<<endl;
        cout<<"1. Add a contact"<<endl;
        cout<<"2. Find contact information"<<endl;
        cout<<"3. Send an email"<<endl;
        cout<<"4. Delete a contact"<<endl;
        cout<<"5. Print all contacts"<<endl;
        cout<<"6. Quit"<<endl;
        getline(cin,answer);
    }
    cout<<"Would you like to save your contacts to a file? y or n"<<endl;
    string a;
    getline(cin,a);
    if(a=="y"){
        cout<<"Saving to file!"<<endl;
        cout<<"Goodbye"<<endl;
    }
    else
        cout<<"Goodbye"<<endl;
    return 0;
}
