#include "AddressBook.h"
#include <fstream>
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

void AddressBook::sendEmail(string last, string first,string message){
    addressNode *n= search(last,first);
    if(n==NULL){
        cout<<"Contact does not exist"<<endl;
    }
    else{
        cout<<"Sending email....."<<endl;
        n->message=message;
        cout<<"Message: "<<n->message<<endl;
        cout<<"Sent to: "<<n->first<<" "<<n->last<<endl;
        cout<<"At: "<<n->email<<endl;
    }
}

addressNode* AddressBook::findMin(addressNode *node){
    addressNode* temp=node;
    while(temp->leftChild!=NULL){
        temp=temp->leftChild;
    }
    return temp;
}

void AddressBook::changeContact(string last, string first){
    addressNode *n= search(last,first);
    if(n==NULL){
        cout<<"Contact does not exist"<<endl;
    }
    else{
        cout<<"===Change Options==="<<endl;
        cout<<"1. Change email"<<endl;
        cout<<"2. Change phone number"<<endl;
        cout<<"3. Change address"<<endl;
        string answer;
        getline(cin,answer);
        if(answer=="1"){
            cout<<"Enter a new email"<<endl;
            string newE;
            getline(cin,newE);
            n->email=newE;
        }
         else if(answer=="2"){
            cout<<"Enter a new phone number"<<endl;
            string newN;
            getline(cin,newN);
            n->phone=newN;
        }
        else if(answer=="3"){
            cout<<"Enter a new address"<<endl;
            string newA;
            getline(cin,newA);
            n->address=newA;
        }
        cout<<"Contact successfully changed."<<endl;
    }
}

void AddressBook::deletePerson(string last, string first){
    addressNode *node=search(last,first);
    if(node==NULL){
        cout<<"Contact does not exist."<<endl;
    }
    else{
        if(node->leftChild==NULL&& node->rightChild==NULL){ ///Case I: Node has no children
            if(node!=root){
                if(node->parent->leftChild==node) ///Handles left side
                    node->parent->leftChild=NULL;
                else{ ///Handles right side
                    node->parent->rightChild=NULL;
                }
            }
            else
                root=NULL;
        }
        else if(node->leftChild!=NULL && node->rightChild!=NULL){ ///Case II: Node has 2 Children
            addressNode *Min= findMin(node->rightChild); ///Calls find min function
            if(node==root){
                if(Min==node->rightChild){
                    Min->parent=NULL;
                    Min->leftChild=node->leftChild;
                    Min->leftChild->parent=Min;
                }
                else{
                    Min->parent->leftChild=Min->rightChild;
                    if(Min->rightChild!=NULL){
                        Min->rightChild->parent=Min->parent;
                    }
                    Min->parent=NULL;
                    Min->leftChild=node->leftChild;
                    Min->rightChild=node->rightChild;
                    node->rightChild->parent=Min;
                    node->leftChild->parent=Min;
                    }
                root=Min;
            }
            else if(Min==node->rightChild){ ///Case where min is a right child of node
                if(node->parent->leftChild==node){ ///Handles left side
                    node->parent->leftChild= Min;
                    Min->parent= node->parent;
                    node->leftChild->parent= Min;
                    Min->leftChild= node->leftChild;
                }
                else{ ///Handles left side
                    node->parent->rightChild= Min;
                    Min->parent= node->parent;
                    node->leftChild->parent= Min;
                    Min->leftChild= node->leftChild;
                }
            }
            else{ ///Min is not the right child
                if(node->parent->leftChild==node){ ///Handles left side
                    Min->parent->leftChild= Min->rightChild;
                    Min->rightChild->parent= Min->parent;
                    Min->parent=node->parent;
                    node->parent->leftChild= Min;
                    Min->leftChild= node->leftChild;
                    Min->rightChild= node->rightChild;
                    node->rightChild->parent= Min;
                    node->leftChild->parent= Min;
                }
                else{ ///Handles right side
                    Min->parent->leftChild= Min->rightChild;
                    Min->rightChild->parent= Min->parent;
                    Min->parent=node->parent;
                    node->parent->rightChild= Min;
                    Min->leftChild= node->leftChild;
                    Min->rightChild= node->rightChild;
                    node->rightChild->parent= Min;
                    node->leftChild->parent= Min;
                }
            }
        }
        else{ ///Case III: Node has 1 child
            if(node==root){
               if(node->rightChild!=NULL){
                    root=node->rightChild;
               }
               else{
                    root=node->leftChild;
               }
            }
           else if(node->parent->leftChild==node){ ///if one child is left child
                if(node->leftChild!=NULL){ ///Handles left side
                    addressNode *n= node->leftChild;
                    node->parent->leftChild=n;
                    n->parent= node->parent;
                }
                else{ ///Handles right side
                    addressNode *n= node->rightChild;
                    node->parent->leftChild=n;
                    n->parent= node->parent;
                }
            }
            else{ ///If one child is right child
                if(node->leftChild!=NULL){ ///Handles left side
                    addressNode *n= node->leftChild;
                    node->parent->rightChild=n;
                    n->parent= node->parent;
                }
                else{ ///Handles right side
                    addressNode *n= node->rightChild;
                    node->parent->rightChild=n;
                    n->parent= node->parent;
                }
            }
        }
        delete node; ///Deletes node


    }
}
