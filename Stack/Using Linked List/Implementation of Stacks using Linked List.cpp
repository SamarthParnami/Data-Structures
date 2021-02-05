#include <bits/stdc++.h>
#include<Windows.h>
#include"List.h"

using namespace std;



template<typename variable>
class Stack{
    int size;
    int count;
    List<variable>* head;
public:
    Stack(int size=20)
    {
        count=0;
        head=nullptr;
    }
    Stack(variable a,int size=20)
    {
        count=0;
        head=new List<variable>(a);
    }
    bool isEmpty()
    {
        return head==nullptr?true:false;
    }
    bool isFull()
    {
        return count<size?false:true;
    }
    variable pop()
    {
        variable val;
        if(count==1)
        {
            val=head->val;
            delete head;
            head=nullptr;
            count--;
            return val;
        }
        List<variable>* start=head;
        List<variable>* prev=nullptr;
        while(start->next!=nullptr)
        {
            prev=start;
            start=start->next;
        }
        val=start->val;
        prev->next=nullptr;
        count--;
        delete start;
        return val;
    }
    variable peek()
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
        if(head==nullptr)
        {
            head=new List<variable>(val);
        }
        else if(count==size)
        {
            cout<<"Stack overflow"<<endl;
        }
        else{
            head->pushBack(val);
            count++;
        }
    }
};


int main()
{
    Stack <int> box;

    box.push(45);
    cout<<"1"<<endl;
    cout<<box.peek()<<endl;
    box.push(25);
    cout<<box.peek()<<endl;
    cout<<"Is stack empty?: "<<box.isEmpty()<<endl;
    cout<<"Is stack full?: "<<box.isFull()<<endl;
    box.pop();
    cout<<"Is stack empty?: "<<box.isEmpty()<<endl;


    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
