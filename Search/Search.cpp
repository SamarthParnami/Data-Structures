
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

