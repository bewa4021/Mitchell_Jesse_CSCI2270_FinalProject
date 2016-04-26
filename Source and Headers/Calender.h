#ifndef CALENDER_H
#define CALENDER_H
#include <iostream>
using namespace std;
struct date
{
    date(string in_title, int in_time)
    {
        title=in_title;
        time=in_time;
        next=NULL;
    };
    string title;
    int time;
    date* next=NULL;
};

class Calender
{
    public:
        Calender();
        virtual ~Calender();
        void addDate(string title, int time);
        void print();
        void findDate(int time);
        void cancel(string title);
    protected:
    private:
        date* head=NULL;
        date* searchList(int in_time);
};

#endif // CALENDER_H
