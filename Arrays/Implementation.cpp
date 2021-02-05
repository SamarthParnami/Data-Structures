#include<bits/stdc++.h>
using namespace std;


template<typename variable>
class Array{
    int length;
    int index;
public:
    variable* element;

    Array(int length)
    {
        this->length=length+1;
        index=-1;
        element= new variable[length];
    }
    bool isFull()
    {
        return index==length-1?true:false;
    }
    bool isEmpty()
    {
        return index==-1?true:false;
    }
    void pushBack(variable val)
    {
        if(isFull())
        {
            cout<<"Error!! Array is already full."<<endl;
        }
        else
        {
            element[++index]=val;
        }
    }
    void pushFront(variable val)
    {
        if(shiftUpFrom(0))
        {
            element[0]=val;
        }
        else
        {
            cout<<"Error!! Array is already full."<<endl;
        }
    }
    void pushAfter(variable after,variable val)
    {
        for(int i=0;i<=index;i++)
        {
            if(element[i]==after)
            {
                if(shiftUpFrom(i+1))
                {
                    element[i+1]=val;
                    break;
                }
                else
                {
                    cout<<"Error!! Array is already full."<<endl;
                }
            }
        }
    }
    variable popBack()
    {
        if(!isEmpty())
        {
            return element[index--];
        }
        else
        {
            cout<<"Array is empty."<<endl;
        }

    }
    variable popFront()
    {
        variable val=element[0];
        shiftDownFrom(1);
        return val;
    }
    void pop(variable val)
    {
        for(int i=0;i<=index;i++)
        {
            if(element[i]==val)
            {
                if(i<index)
                {
                    shiftDownFrom(i+1);
                }
                else if(i==index)
                {
                    index--;
                }
            }
        }
    }
    bool shiftUpFrom(int from,int by=1)
    {
        if(index+by<length-1)
        {
            for(int i=index;i>=from;i--)
            {
                element[i+by]=element[i];
            }
            index+=by;
            return true;
        }
        return false;
    }
    void shiftDownFrom(int from,int by=1)
    {
        for(int i=from;i<=index;i++)
        {
            element[i-by]=element[i];
        }
        index-=by;
    }
    void print()
    {
        for(int i=0;i<=index;i++)
        {
            cout<<element[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{

	Array<int> age(5);
    age.pushBack(5);
    age.pushFront(2);
    age.pushAfter(2,48);
    age.pushBack(99);
    age.pushAfter(48,7);
    cout<<"Array: ";
    age.print();
    age.popFront();
    cout<<"Array after removal from front: ";
    age.print();
    age.pop(48);
    cout<<"Array after removal of 48 from middle: ";
    age.print();
    age.popBack();
    cout<<"Array after removal from back: ";
    age.print();
	cout<<"--Editor-Samarth Parnami--"<<endl;
	return 0;
}
