#include"Heap.h"
Travel::Travel()
{
	P_id=0;
	name="";
	source="";
	dest="";
	amount=0;
}

Travel::Travel(int p,string na,string s,string d,long amt)
{
	P_id=p;
	name=na;
	source=s;
	dest=d;
	amount=amt;
}

Travel::Travel(const Travel&t)
{
	P_id=t.P_id;
	name=t.name;
	source=t.source;
	dest=t.dest;
	amount=t.amount;
}

void Travel::Display()
{
	cout<<P_id<<name<<source<<dest<<amount;
}

int Travel::getID()
{
	return P_id;
}
istream& operator>>(istream &in,Travel &t)
{
		cout<<" Enter the p Id   : ";
        in>>t.P_id;
        cout<<" Enter the Name : ";
        in>>t.name;
        cout<<" Enter the Vechicle Type : ";
        in>>t.source;

		cout<<" Enter the Vechicle Type : ";
        in>>t.dest;
        cout<<" Enter the Amount_Of_Toll : ";
        in>>t.amount;
        return in;
}

ostream& operator<<(ostream &out,Travel &t)
{
		cout<<" Enter the p Id   : ";
        out<<t.P_id;
        cout<<"\n Name : ";
        out<<t.name;
        cout<<"\n Source : ";
        out<<t.source;
		cout<<"\n Destination : ";
        out<<t.dest;
        cout<<"\nAmount : ";
        out<<t.amount;
        return out;
}

bool Travel::operator>(Travel t1)
{
	return (getID()>t1.getID());
}
bool Travel::operator<(Travel t1)
{
        return (getID()<t1.getID());
}
bool Travel::operator==(Travel j)
{
	if(getID()==j.getID())
	    return true;
	return false;
}
Travel Travel::operator=(Travel x)
{
	P_id=x.P_id;
	name=x.name;
	source=x.source;
	dest=x.dest;
	amount=x.amount;
	return *this;
}

BinHeap::BinHeap()
{
	hsize=0;
	capacity=10;
	arr=new Travel[capacity+1];
}

int BinHeap::isFull()
{
	return (capacity==hsize);
}

int BinHeap::isEmpty()
{
	return (hsize==0);
}

int BinHeap::enqueue(Travel ins)	//insert an element
{
	//ins - element to insert
	if(isFull())
		return -1;	//heap is full
	else
	{
		int ctnode=++hsize;
		while(ctnode!=1 && arr[ctnode/2].P_id > ins.P_id)	//if parent acc_num is greater than acc_num of element to insert
		{
			arr[ctnode]=arr[ctnode/2];
			ctnode/=2;
		}
		arr[ctnode]=ins;
		return 1;	//success
	}
}

Travel BinHeap::dequeue()			//remove an element (delete min)
{
	if(isEmpty())
	{
		Travel temp;
		return temp;
	}
	else
	{
		Travel temp=arr[1];	//first element (starts from 1) to return
		Travel last=arr[hsize--];
		int low_child=2;	//assuming left child as low_child 
		int ctnode=1;
		while(low_child<=hsize)
		{
			if(low_child<hsize && arr[low_child].P_id>arr[low_child+1].P_id)	//R-Child is min
				low_child++;	//changing low_child to right child since it is min than Left child

			if(last.P_id<=arr[low_child].P_id)	//last element replaced is the min element
				break;

			arr[ctnode]=arr[low_child];	//swapping parent with low_child
			ctnode=low_child;	//considering the low_child
			low_child*=2;	//assuming left child as low_child 
		}
		arr[ctnode]=last;
		return temp;
	}
}


Travel BinHeap::findMin()
{
	if(!isEmpty())
	{
		return arr[1];
	}
	else
	{
		Travel temp;
		return temp;
	}
}

int BinHeap::search(int id)
{
	int i;
	for(i=1;i<=hsize;i++)
		if(arr[i].P_id==id)
			return 1;
	return 0;
}

void BinHeap::displayHeap()
{
	if(isEmpty())
		cout<<"Empty nothing to display\n";
	else
	{
		for(int i=1;i<=hsize;i++)
			cout<<arr[i];
	}
}
