#include "AddressBook.h"

AddressBook::AddressBook()
{
    //ctor
}

AddressBook::~AddressBook()
{
    //dtor
}

void AddressBook::addAddress(string first,string last, string address,string phone, string email){
    addressNode *n=new addressNode;
    n->first=first;
    n->last=last;
    n->address=address;
    n->phone=phone;
    n->email=email;
    n->parent=NULL;
    n->leftChild=NULL;
    n->rightChild=NULL;
    addressNode *temp= root;
    addressNode *parent= new addressNode;
    parent=NULL;
    while(temp!=NULL){
        parent=temp;
        if(n->last.compare(temp->last)<0){
            temp=temp->leftChild;
        }
        else{
            temp=temp->rightChild;
        }
    }
    if(parent==NULL){
        root=n;
    }
    else if(n->last.compare(parent->last)<0){
        parent->leftChild=n;
        n->parent=parent;
    }
    else{
        parent->rightChild=n;
        n->parent=parent;
    }
}

void AddressBook::printAddresses(){
    if(root==NULL){
        cout<<"No contacts in address book"<<endl;
    }
    else
        printAddresses(root);
}

void AddressBook::printAddresses(addressNode *node){
    if(node->leftChild!=NULL){
        printAddresses(node->leftChild);
    }
    cout<<"Name: "<< node->first<< " "<<node->last<<endl;
    cout<<"Phone: "<<node->phone<<endl;
    cout<<"Address: "<<node->address<<endl;
    cout<<"Email: "<<node->email<<endl;
    cout<<"************************"<<endl;
    if(node->rightChild!=NULL){
        printAddresses(node->rightChild);
    }
}

addressNode* AddressBook::search(string last,string first){
    addressNode *temp= root;
    bool found= false;
    while(temp!=NULL &&!found){
        if(last.compare(temp->last)<0){
            temp=temp->leftChild;
        }
        else if(last.compare(temp->last)>0){
            temp=temp->rightChild;
        }
        else{
            if(first==temp->first){
                return temp;
            }
            else{
                temp=temp->rightChild;
            }
        }
    }
    return NULL;
}

void AddressBook::findPerson(string last, string first){
    addressNode *n= search(last,first);
    if(n==NULL){
        cout<<"Contact not found"<<endl;
    }
    else{
        cout<<"Name: "<< n->first<< " "<<n->last<<endl;
        cout<<"Phone: "<<n->phone<<endl;
        cout<<"Address: "<<n->address<<endl;
        cout<<"Email: "<<n->email<<endl;
    }
}
