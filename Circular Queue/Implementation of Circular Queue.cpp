#include <bits/stdc++.h>
using namespace std;

template<typename variable>
class circularQueue
{
   
int size;
variable *array;
int rear,front;     //rear for addition of new elements, front for removal.
int count=0;
 public:
    circularQueue(int s=20):size(s)  //psuedo limit of INT_MIN-size
    {
        array=new variable[size];
        rear=0;
        front=0;
    }
    bool isFull()
    {
        if(rear-front==size)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        return rear==front&&count==0?true:false;
    }
    void enqueue(variable a)
    {

        array[rear%size]=a;
        rear++;
    }
    variable dequeue()
    {

        variable a=array[front++];
        return a;
    }
    variable top()
    {
        return array[front%size];
    }
    void traverse()
    {
        for(int i=front;i<rear;++i)
        {
            cout<<array[i%size]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    circularQueue<int> people(5);
    people.enqueue(1);
    people.enqueue(2);
    people.enqueue(3);
    cout<<"Is Queue Empty?: "<<people.isEmpty()<<"\n";
    cout<<"Is Queue Full?: "<<people.isFull()<<"\n";
    people.enqueue(4);
    people.enqueue(5);
    cout<<"Is Queue Empty?: "<<people.isEmpty()<<"\n";
    cout<<"Is Queue Full?: "<<people.isFull()<<"\n";
    people.enqueue(people.dequeue());
    cout<<"Is Queue Empty?: "<<people.isEmpty()<<"\n";
    cout<<"Is Queue Full?: "<<people.isFull()<<"\n";
    
    return 0;
}
