#include <bits/stdc++.h>
#include<Windows.h>

using namespace std;
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
     List* pushFront(variable val)
    {
        List<variable>* newhead=new List<variable>(val);
        newhead->next=this;
        return newhead;
    }
    List* push(variable after,variable val)
    {

        List* temp=this;
        while(temp!=nullptr&&temp->val!=val)
        {
            temp=temp->next;
        }
        if(temp)
        {
            List<variable>* node=new List<variable>(val);
            node->next=temp->next;
            temp->next=node;
        }
        else{
            return nullptr;
        }
        return temp;

    }
    List* popFront()
    {
        List* nex=this->next;
        delete this;
        return nex;
    }

    void popBack()
    {

        List* start=this;
        while(start->next->next!=nullptr)
        {
            start=start->next;
        }
        delete start->next;
        start->next=nullptr;
    }
    List* pop(variable val)
    {
        List* prev=nullptr;
        List* temp=this;
        while(temp!=nullptr&&temp->val!=val)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return temp;

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
    void printList()
    {
        List* start=this;
        while(start->next!=nullptr)
        {
            cout<<start->val<<" ";
            start=start->next;
        }
        cout<<start->val<<endl;
    }

};
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
int main()
{
    string command;
    cout<<"Type 'yes' to create List object :";
    cin>>command;
    List<int>* kid=nullptr;
    if(toLower(command)=="yes")
    {
        int a;
        cout<<"Value of ListNode: ";
        cin>>a;
        kid=new List<int>(a);
    }
    else
    {
        exit(0);
    }
    cout<<"\n ------Type \"list/help/command to see available actions.------\n";
    cin.clear();

    cin>>command;
    do
    {
        if(toLower(command)=="pushback")
        {
            int a=0;
            cout<<"Value of node:";
            cin>>a;
            kid->pushBack(a);
            cout<<a<<" pushed to the end of the list\n"<<endl;
        }
        else if(toLower(command)=="pushfront")
        {
            int a=0;
            cout<<"Value of node:";
            cin>>a;
            kid=kid->pushFront(a);
            cout<<a<<" pushed to the front of the list\n"<<endl;
        }
        else if(toLower(command)=="print")
        {
            cout<<"List: ";
            kid->printList();
            cout<<endl;
        }
        else if(toLower(command)=="invert")
        {
            kid=kid->invertList();
            cout<<"Successfully Inverted List.\n"<<endl;
        }
        else if(toLower(command)=="popback")
        {
            kid->popBack();
            cout<<"Successfully removed element from the end of the List.\n"<<endl;
        }
        else if(toLower(command)=="popfront")
        {
            kid=kid->popFront();
            cout<<"Successfully removed element from the front of the List.\n"<<endl;
        }
        else if(toLower(command)=="cls"||toLower(command)=="clear"||toLower(command)=="clrscr")
        {
            system("cls");
            cout<<"\n ------Type \"list/help/command to see available actions.------\n";
        }
        else if(toLower(command)=="exit")
        {

            break;
        }
        else if(toLower(command)=="pop")
        {
            int a=0;
            cout<<"Value of node:";
            cin>>a;
            if(kid->pop(a))
            {
                cout<<a<<" successfully removed from the list\n"<<endl;
            }
            else{
                cout<<"No such node with value "<<a<<" exists.\n"<<endl;
            }

        }
        else if(toLower(command)=="push")
        {
            int a=0;
            cout<<"Value of node:";
            cin>>a;
            int node;
            cout<<"Value of node to insert after:";
            cin>>node;

            if(kid->push(node,a))
            {
               cout<<a<<" pushed after node"<<node<<" of the list \n"<<endl;
            }
            else{
                cout<<"Node with value "<<node<<" exists.\n"<<endl;
            }

        }
        else if(toLower(command)=="help"||command=="list"||command=="commands"||command=="command")
        {
            cout<<"\nprint    - to print all the elements of the list."<<endl;
            cout<<"invert   - to invert the order of the list."<<endl;
            cout<<"pushback - to add element to the end of the list."<<endl;
            cout<<"pushfront- to add element to the front of the list."<<endl;
            cout<<"popback  - to remove an element from the end of the list."<<endl;
            cout<<"popfront - to remove an element from the front of the list."<<endl;
            cout<<"pop      - to remove a specific element in list."<<endl;
            cout<<"push     - to add an element after an element in the list."<<endl;
            cout<<"cls      - to clear the screen."<<endl;
            cout<<"exit     - to close the list.\n\n";

        }
        else if(command=="")
        {

        }
        else{
            cout<<"No such Command exists"<<endl;
        }
    }while(getline(cin,command));

    cout<<"Editor--Samarth Parnami"<<endl;
    Sleep(1000);

    return 0;
}
