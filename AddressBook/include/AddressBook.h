#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
using namespace std;

struct addressNode{
    string first;
    string last;
    string phone;
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
        void findPerson(string last);
        void deletePerson(string last);
        void sendEmail(string last);
        void printAddresses();
    protected:
    private:
        void printAddresses(addressNode *node);
        addressNode* search(string last);
        addressNode *root= NULL;
        addressNode *findMin(addressNode *node);
};

#endif // ADDRESSBOOK_H
