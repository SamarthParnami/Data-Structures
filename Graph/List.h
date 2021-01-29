#ifndef List_H
#define List_H

template<typename variable>
class List{
public:
    variable val;
    List* next=nullptr;
    List(variable val=0,List* next=nullptr)
    {
        this->val=val;
        this->next=next;
    }
    void pushBack(variable val)
    {
        List* start=this;
        while(start->next!=nullptr)
        {
            start=start->next;
        }
        start->next=new List<variable>(val);
    }
    List* popFront()
    {
        List* nex=this->next;
        delete this;
        return nex;
    }
    void pop()
    {

        List* start=this;
        while(start->next->next!=nullptr)
        {
            start=start->next;
        }
        delete start->next;
        start->next=nullptr;
    }
    List* invertList()
    {
        List* head=this;
        List* prev=nullptr;
        while(head->next!=nullptr)
        {
            List* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        head->next=prev;
        return head;
    }
    

};
#endif