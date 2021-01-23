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
public:
    Queue()
    {
        head=nullptr;
    }
    Queue(variable val)
    {

        head=new List<variable>(val);
    }
    bool isEmpty()
    {
        return head==nullptr?true:false;
    }
    bool isFull()
    {

        return false;
    }
    void enqueue(variable val)
    {
        head.pushBack(val);
    }
    variable top()
    {
        return head->val;
    }
    variable dequeue()
    {
        variable val=head->val;
        head=head->popFront();
        return val;
    }
};
int main()
{
    Queue<string> people;
    cout<<"Editor--Samarth Parnami"<<endl;
    Sleep(1000);

    return 0;
}
