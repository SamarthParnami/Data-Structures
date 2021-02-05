#include<bits/stdc++.h>
using namespace std;

int linearSearch (vector<variable> a, variable target)
{
    int index=-1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==target)
        {
            index=i;
            break;
        }
    }
    return index;
}

int binarySearch(vector<variable> a,variable target,int left,int right)
{
    int middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(a[middle]==target)
        {
            return middle;
        }
        else if(a[middle]>target)
        {
            right=middle-1;
        }
        else if(a[middle]<target)
        {
            left=middle+1;
        }
    }
    return -1;
}
void printVector(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> array={84,54,65,2,5,975,98,1225,11,436,20,14,7,9,6,201,-9,-4};
    cout<<"11 found at index "<<linearSearch(array,11);<<" of array"<<endl;
    printVector(array);

    
    
    return 0;
}


