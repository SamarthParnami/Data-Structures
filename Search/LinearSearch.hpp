#include <bits/stdc++.h>
template<typename variable>
int LinearSearch (vector<variable> a, variable target)
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