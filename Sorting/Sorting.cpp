
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

//sorting techniques    requires furter attention for string comparision ">=, <=, >, <"

void bubbleSort(vector<variable> &a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=1;j<a.size()-i;j++)
        {
            if(a[j]<a[j-1])
            {
                variable temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void selectionSort(vector<variable> &a)  
{  
    int minInd;  
    
    for (int i = 0; i < n-1; i++)  
    {  
        minInd = i;  
        for (int j = i+1; j < n; j++)  
        {
            if (a[j] < a[minInd])
            {
                minInd=j;
            }
        }  
        variable temp=a[minInd];
        a[minInd]=a[i];
        a[i]=temp;        
    }  
}  

void insertionSort(vector<variable> &a)
{
    for(int i=0;i<a.size();i++)
    {
        int comp=i-1;
        while(comp!=-1)
        {
            if(a[comp]>a[comp+1])
            {
                variable temp=a[comp];
                a[comp]=a[comp+1];
                a[comp+1]=temp;
                comp--;
            }
            else
            {
                break;
            }
        }
    }
}
void countSort(vector<int> &a,int upperLimit)
{
    vector<int> count(upperLimit+1,0);
    for(int i=0;i<a.size();i++)
    {
        count[a[i]]++;
    }
    a.clear();
    for(int i=0,i<=upperLimit;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            a.push_back(i);
        }
    }
}
void radixSort(vector<int> &a,int mltplr=1)
{
    vector<vector<int>> count(10,vector<int>(0,0));
    bool nextIter=false;
    for(int i=0;i<a.size();i++)
    {
        int temp=(a[i]/mltplr);
        if(temp/10>0)
        {
            nextIter=true;
        }
        count[temp%10].push_back(a[i]);
    }
    a.clear();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<count[i].size();j++)
        {
            a.push_back(count[i][j]);
        }
    }
    if(nextIter)
    {
        radixSort(a,mltplr*10);
    }
}
void quickSort(vector<variable> &a,int begin,int end)
{
    int pivot=end;
    int smaller=begin-1;
    for(int i=begin;i<end;i++)
    {
        if(a[i]<=a[pivot])
        {
            variable temp=a[++smaller];
            a[smaller]=a[i];
            a[i]=temp;
        }
    }
    variable temp=a[++smaller];
    a[smaller]=a[pivot];
    a[pivot]=temp;
    if(begin<smaller-1)
    {
        quickSort<variable>(a,begin,smaller-1);
    }

    if(smaller+1<end)
    {
        quickSort<variable>(a,smaller+1,end);
    }
}