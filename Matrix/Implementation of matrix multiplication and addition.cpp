#include <iostream>

using namespace std;

void printArray(int a[],int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

class matrix
{
public:
    int** grid;
    int row;
    int column;
    matrix(int row,int column)
    {
        this->row=row;
        this->column=column;
        grid= new int*[this->row];
        for(int i=0;i<this->row;i++)
        {
            grid[i]=new int[this->column];
        }
    }
    void printGrid()
    {
        for(int i=0;i<row;i++)
        {
            printArray(grid[i],column);
        }
    }
    void setMatrix()
    {
        cout<<"Enter elements with "<<row<<" rows & "<<column<<" column: "<<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cin>>grid[i][j];
            }
        }
    }
    void matrixMultiplication(matrix &result,matrix one,matrix two)
{
    int prop=one.column;
    for(int i=0;i<result.row;i++)
    {
        for(int j=0;j<result.column;j++)
        {
            for(int m=0;m<prop;m++)
            {
                result.grid[i][j]+=one.grid[i][(j+m)%prop]*two.grid[(i+m)%prop][j];
            }
        }
    }
}
    matrix operator*(matrix two)
    {
        if(this->column==two.row)
        {
            matrix result(this->row,two.column);
            matrixMultiplication(result,*this,two);
            return result;
        }
        else
        {
            cout<<"Matrices not eligible for multiplication."<<endl;
        }
        return *(new matrix(0,0));
    }
    matrix matrixAddition(matrix two)
    {
        matrix result(row,column);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                result.grid[i][j]=grid[i][j]+two.grid[i][j];
            }
        }
        return result;
    }
    matrix operator+(matrix two)
    {
        if(this->row==two.row&&this->column==two.column)
        {
            matrix result=matrixAddition(two);
            return result;
        }
        else
        {
            cout<<"Matrices not eligible for addition."<<endl;
        }
        return *(new matrix(0,0));
    }
};

void matrixProperty(int &row,int &column)
{
    cout<<"Enter number of rows: ";
    cin>>row;
    cout<<"Enter number of columns: ";
    cin>>column;
}
int main()
{
    int row,column;
    matrixProperty(row,column);
    matrix kit(row,column);
    kit.setMatrix();
    matrixProperty(row,column);
    matrix bag(row,column);
    bag.setMatrix();
    matrix result=kit*bag;
    cout<<"\nResultant matrix of multiplication of two matrices is:"<<endl;
    result.printGrid();
    matrix addResult=kit+bag;
    cout<<"\nResultant matrix of addition of two matrices is:"<<endl;
    addResult.printGrid();
    return 0;
}
