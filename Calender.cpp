#include "Calender.h"
#include<iostream>
#include<ctime>

using namespace std;

Calender::Calender()
{
    //ctor
}
date* Calender::searchList(int in_time)
{
    if(head==NULL)
        return head;
    else{
        date*tmp=head;
        while (tmp->next!=NULL){
            if(tmp->next->time>in_time)
                return tmp;
            else
                tmp=tmp->next;
        }
            return tmp;
    }
}
void Calender::addDate(string title, int time)
{
    date* in_date= new date(title, time);
    date*tmp=searchList(time);
    if (tmp==NULL)
        head=in_date;
    else{
        if(tmp->next=NULL)
            tmp->next=in_date;
        else{
            in_date->next=tmp->next;
            tmp->next=in_date;
        }
    }
}

void Calender::cancel(string title)
{
    bool found=0;
    date* tmp=head;
    while(tmp->next!=NULL){
        if(tmp->title==title){
            if(tmp==head)
                head=tmp->next;
            else{
                date* tmp2=head;
                while(tmp2->next!=tmp)
                    tmp2=tmp2->next;
                tmp2->next=tmp->next;
            }
            delete tmp;
            found=1;
            cout<<title<<" successfully canceled."<<endl;
            break;
        }
    }
    if(!found)
        cout<<title<<" not found."<<endl;
}
void Calender::print()
{
    date*tmp=head;
    while(tmp!=NULL)
        cout<<tmp->time<<" "<<tmp->title<<endl;
}
void Calender::findDate(int time)
{
    bool found = 0;
    date*temp=head;
    while(temp!=NULL){
        if (temp->time==time){
            cout<<temp->title<<" is booked for "<<temp->time<<endl;
            found=1;
            break;
        }
    }
    if (!found)
        cout<<time<<" is free."<<endl;
}
Calender::~Calender()
{
    //dtor
}
