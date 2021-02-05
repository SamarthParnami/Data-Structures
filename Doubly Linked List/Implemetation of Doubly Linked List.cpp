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
    DoublyLinkedList<variable>* searchByNextPointer(DoublyLinkedList<variable>* pointer)
    {
        if(this->next==pointer)
        {
            return this;
        }
        return this->next->searchByNextPointer(pointer);
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
    void pushAfter(variable after, variable val)
    {
        DoublyLinkedList<variable>* node=searchByValue(after);
        DoublyLinkedList<variable>* temp=new DoublyLinkedList<variable>(val,node->next,node);
        node->next->prev=temp;
        node->next=temp;

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
    DoublyLinkedList<int>* names=new DoublyLinkedList<int>(2);
    names->pushBack(9);
    names->pushBack(7);
    cout<<"DoublyLinked List: ";
    names->traverse();
    names->popBack();
    cout<<"DoublyLinked List after removal from end: ";
    names->traverse();
    names=names->popFront();
    cout<<"DoublyLinked List after removal from front: ";
    names->traverse();
    names->pushBack(7);
    cout<<"DoublyLinked List after insertion at end: ";
    names->traverse();
    names->pushAfter(9,7);
    cout<<"DoublyLinked List after inserting in middle: ";
    names->traverse();
    names=names->pushFront(6);
    cout<<"DoublyLinked List after insertion in front: ";
    names->traverse();
    names->popValue(7);
    cout<<"DoublyLinked List after deletion in middle: ";
    names->traverse();



    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
