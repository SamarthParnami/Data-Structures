#include <bits/stdc++.h>
#include<Windows.h>
#include"List.h"
using namespace std;

string toLower(string &a)           //accessory function to allow easy implementation of console commands by converting uppercase to lowercase
{
    for(unsigned i=0;i<a.size();i++)
    {
        if(a[i]>=65&&a[i]<=90)
        {
            a[i]=a[i]+('A'-'a');
        }
    }
    return a;

}



template<typename variable>
class Queue{
    List<variable>* head;
    int size;
    int count;
public:
    Queue(int size=20)
    {
        head=nullptr;
        this->size=size;
        count=0;
    }
    Queue(int size,variable val)
    {
        this->size=size;
        head=new List<variable>(val);
        count=1;
    }
    bool isEmpty()
    {
        return head==nullptr?true:false;
    }
    bool isFull()
    {
        return count==size?true:false;
    }
    void enqueue(variable val)
    {
        if(head==nullptr)
        {
            head=new List<variable>(val);
        }
        else
        {
            head->pushBack(val);
        }
        count++;
    }
    variable top()
    {
        return head->val;
    }
    variable dequeue()
    {
        count--;
        variable val=head->val;
        head=head->popFront();
        return val;
    }
};
int main()
{
    Queue<string> people;
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
