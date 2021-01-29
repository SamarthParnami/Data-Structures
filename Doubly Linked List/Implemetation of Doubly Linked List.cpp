#include <bits/stdc++.h>
using namespace std;

template<typename variable>
class DoublyLinkedList{
public:
    variable val;
    DoublyLinkedList<variable>* next;
    DoublyLinkedList<variable>* prev;

    DoublyLinkedList(variable val,DoublyLinkedList<variable>* next=nullptr,DoublyLinkedList<variable>* prev=nullptr)
    {
        this->val=val;
        this->next=next;
        this->prev=prev;
    }
    DoublyLinkedList<variable>* searchByValue(variable val)
    {
        if(this->val==val)
        {
            return this;
        }
        return this->next->searchByValue(val);
    }
    DoublyLinkedList<variable>* searchByNextPointer(DoublyLinkedList<variable>* val)
    {
        if(this->next==val)
        {
            return this;
        }
        return this->next->searchByValue(val);
    }
    DoublyLinkedList<variable>* pushFront(variable val)
    {
        DoublyLinkedList<variable>* temp=new DoublyLinkedList<variable>(val,this);
        this->prev=temp;
        return temp;
    }
    void pushBack(variable val)
    {
        DoublyLinkedList<variable>* curLast=searchByNextPointer(nullptr);
        DoublyLinkedList<variable>* temp=new DoublyLinkedList<variable>(val,nullptr,curLast);
        curLast->next=temp;
    }
    void pushAfter(variable after, variable insert)
    {
        DoublyLinkedList<variable>* node=searchByValue(val);
        DoublyLinkedList<variable>* temp=new DoublyLinkedList<variable>(insert,node->next,node);
        node->next->prev=temp;
        node->next=temp;

    }
    DoublyLinkedList<variable>* change()
    {

    }
    DoublyLinkedList<variable>* popFront()
    {
        DoublyLinkedList<variable>* newHead=this->next;
        newHead->prev=nullptr;
        delete this;
        return newHead;
    }
    void popBack()
    {
        DoublyLinkedList<variable>* oldEnd=searchByNextPointer(nullptr);
        oldEnd->prev->next=nullptr;
        delete oldEnd;
    }
    void popValue(variable val)
    {
        DoublyLinkedList<variable>* node=searchByValue(val);
        node->prev->next=node->next;
        node->next->prev=node->prev;
        delete node;
    }
    void traverse()
    {
        DoublyLinkedList<variable>* node=this;
        while(node->next!=nullptr)
        {
            cout<<node->val<<" ";
            node=node->next;
        }
        cout<<node->val<<endl;
    }
};
int main()
{




    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}