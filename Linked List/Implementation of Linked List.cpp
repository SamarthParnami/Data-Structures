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
int main()
{
    int aa;
    cout<<"Enter value to list:";
    cin>>aa;
    List<int>* kid=new List<int>(aa);
    cin.clear();
    string command;
    cin>>command;
    do
    {
        if(toLower(command)=="pushback")
        {
            int a;
            cout<<"value:";
            cin>>a;
            kid->pushBack(a);
        }
        else if(toLower(command)=="print")
        {
            kid->printList();
        }
        else if(toLower(command)=="invert")
        {
            kid=kid->invertList();
        }
        else if(toLower(command)=="pop")
        {
            kid->pop();
        }
        else if(toLower(command)=="popfront")
        {
            kid=kid->popFront();
        }
        else if(toLower(command)=="cls"||toLower(command)=="clear"||toLower(command)=="clrscr")
        {
            system("cls");
        }
        else if(toLower(command)=="exit")
        {
            break;
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
