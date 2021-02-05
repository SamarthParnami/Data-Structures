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
class Stack{
Array<variable>* serial;
int sizes;
int lastIndex;
public:
    Stack(int sizes=20)
    {
        lastIndex=-1;
        this->sizes=sizes;
        serial=new Array<variable>(this->sizes);
    }
    bool isEmpty()
    {
        return lastIndex==-1?true:false;
    }
    bool isFull()
    {
        return lastIndex==sizes?true:false;
    }
    void push(variable val)
    {
        lastIndex++;
        *(serial->serial+lastIndex)=val;
    }
    variable pop()
    {
        variable var=*(serial->serial+lastIndex);
        lastIndex--;
        return var;
    }
    variable peek()
    {
        variable var=*(serial->serial+lastIndex);
        return var;
    }
};



int main()
{
    Stack <int> box;
    box.push(45);
    cout<<box.peek()<<endl;
    cout<<"Is stack empty?: "<<box.isEmpty()<<endl;
    cout<<"Is stack full?: "<<box.isFull()<<endl;
    box.pop();
    cout<<"Is stack empty?: "<<box.isEmpty()<<endl;


    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
