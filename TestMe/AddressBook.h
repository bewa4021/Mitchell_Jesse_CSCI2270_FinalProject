#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
#include <fstream>
using namespace std;

struct addressNode{
    string first;
    string last;
    string phone;
    string address;
    string email;
    string message;
    addressNode *parent;
    addressNode *leftChild;
    addressNode *rightChild;
};
class AddressBook
{
    public:
        AddressBook();
        ~AddressBook();
        void addAddress(string first, string last, string address, string phone,string email);
        void findPerson(string last,string first);
        void deletePerson(string last, string first);
        void sendEmail(string last, string first, string message);
        void printAddresses();
        void changeContact(string last, string first);
    protected:
    private:
        void printAddresses(addressNode *node);
        addressNode* search(string last, string first);
        addressNode *root= NULL;
        addressNode *findMin(addressNode *node);
};

#endif // ADDRESSBOOK_H
