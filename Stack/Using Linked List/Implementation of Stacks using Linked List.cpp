#include <bits/stdc++.h>
#include<Windows.h>
#include"List.h"
using namespace std;

string toLower(string &a)			//accessory function to allow easy implementation of console commands by converting uppercase to lowercase
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
class Stack{
    List<variable>* head;
public:
    Stack()
    {
        head=nullptr;
    }
    Stack(variable a)
    {
        head=new List<variable>(a);
    }
    bool isEmpty()
    {
        return head==nullptr?true:false;
    }
    bool isFull()
    {
        return false;
    }
    variable pop()
    {
        List<variable>* start=head;
        List<variable>* prev=nullptr;
        while(start->next!=nullptr)
        {
            prev=start;
            start=start->next;
        }
        variable val=start->val;
        prev->next=nullptr;
        delete start;
        return val;
    }
    variable peep()
    {
        List<variable>* start=head;
        while(start->next!=nullptr)
        {
            start=start->next;
        }
        variable val=start->val;
        return val;

    }
    void push(variable val)
    {
        head->pushBack(val);
    }
};


int main()
{
    Stack<int> boxes;
    cout<<"Editor--Samarth Parnami"<<endl;
    Sleep(1000);

    return 0;
}
