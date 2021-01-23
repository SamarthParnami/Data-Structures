#include <bits/stdc++.h>
#include "Array.h"
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
        return tail==sizes?true:false;
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
        variable var=*(serial->serial+tail);
        return var;
    }
};



int main()
{
    Queue <string> people;
    
    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
