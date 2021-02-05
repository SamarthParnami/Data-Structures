#include <bits/stdc++.h>
#include "Array.h"
using namespace std;


template<typename variable>
class Queue{
Array<variable>* serial;
int sizes;
int tail=-1;
int head=-1;
public:
    Queue(int sizes=20)
    {
        this->sizes=sizes;
        serial=new Array<variable>(this->sizes);
    }
    bool isEmpty()
    {
        return head==tail?true:false;
    }
    bool isFull()
    {
        return tail==sizes-1?true:false;
    }
    void enqueue(variable val)
    {
        tail++;
        serial->push_back(val);
    }
    variable dequeue()
    {
        head++;
        variable var=*(serial->serial+head);
        return var;
    }
    variable top()
    {
        variable var=*(serial->serial+head+1);
        return var;
    }
};



int main()
{
    Queue <string> people;
    cout<<"Is the Queue empty?: "<<people.isEmpty()<<endl;
    people.enqueue("david");
    people.enqueue("jason");
    people.enqueue("ilya");
    people.enqueue("jeff");
    cout<<"Top element in the Queue: "<<people.top()<<endl;
    cout<<"Is the Queue full?: "<<people.isFull()<<endl;

    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
