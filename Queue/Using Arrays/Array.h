#ifndef Array_h
#define Array_h
template<typename Variable>
class Array
{
	int size=0;			//capacity of the array
public:
	Variable* serial;     //pointer to very first element of the array
	int lastIndex=-1;	//indexof the last element int he array
	

	Array(int size=20)
	{
		this->size=size;
		serial=new Variable [this->size];
	}
	Array(Variable arr[],int size)
	{
		this->size=size+20;
		serial=new int [this->size];
		for(int i=0;i<size;i++)
		{
			serial[++lastIndex]=arr[i];
		}
	}
	
	bool isFull()
	{
		return lastIndex==size-1?true:false;
	}
//insertion at end
	void push_back(Variable a[],int size) //for insertion of  array at end
											//also takes care of size and lastIndex elemnt of class 
	{
		if(lastIndex-1+size==this->size)				//if size of incoming array will not fit 
														//inside preset array.Present array is redeclared
														//with new size to accomodate the incoming elements.
		{
			Variable* temp=serial;
			serial=new Variable[this->size+size+20];
			lastIndex=-1;
			for(int i=0;i<this->size;i++)
			{
				serial[++lastIndex]=temp[i];
			}
			for(int i=0;i<size;i++)
			{
				serial[++lastIndex]=a[i];
			}
			this->size=this->size+size+20;

		}
		else
		{
			for(int i=0;i<size;i++)
				{
					serial[++lastIndex]=a[i];
				}
		}
	}


	void push_back(Variable a)		//for insertion of single element at end
										//also takes care of size and lastIndex elemnt of class 
	{
		if(lastIndex-1+1==this->size)					//if size of incoming element will not fit 
														//inside preset array.Present array is redeclared
														//with new size to accomodate the incoming element.

		{
			Variable* temp=serial;
			serial=new Variable[this->size+20];
			lastIndex=-1;
			for(int i=0;i<this->size;i++)
			{
				serial[++lastIndex]=temp[i];
			}
			serial[++lastIndex]=a;
			this->size=this->size+20;

		}
		else
		{
			serial[++lastIndex]=a;
		}
	}


//insertion in middle
	void insertMiddle(Variable a[],int size,int atIndex)			//for insertion of  array at end
																	//also takes care of size and lastIndex element of class 
	{
		if(lastIndex-1+size>this->size)					//if size of incoming array will not fit 
														//inside preset array.Present array is redeclared
														//with new size to accomodate the incoming elements.
		{
			Variable* temp=serial;
			serial=new Variable[size+this->size+20];
			lastIndex=-1;
			for(int i=0;i<atIndex;i++)
			{
				serial[++lastIndex]=temp[i];
			}
			for(int i=atIndex;i<atIndex+size;i++)
			{
				serial[++lastIndex]=a[i-atIndex];
			}
			for(int i=atIndex;i<this->size;i++)
			{
				serial[++lastIndex]=temp[i];
			}
			size=this->size+size+20;
		}
		else
		{
			Variable temp[lastIndex-atIndex];
			int tempSize=lastIndex-atIndex;
			for(int i=atIndex;i<lastIndex;i++)
			{
				temp[i-atIndex]=serial[i];
			}
			lastIndex=lastIndex-size;
			for(int i=0;i<size;i++)
			{
				serial[++lastIndex]=a[i];
			}
			for(int i=0;i<tempSize;i++)
			{
				serial[++lastIndex]=temp[i];
			}
		}
	}
	void deletingElement(Variable a)
	{
		int i;
		for(i=0;i<lastIndex;i++)
		{
			if(serial[i]==a)
			{
				break;
			}
		}
		for(int j=i+1;i<lastIndex;i++)
		{
			serial[j]=serial[j-1];
		}
		lastIndex--;
	}
};

#endif