#include"HashHeader.h"
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

HashTable::HashTable()	//parameterised constructor
{
	capacity=10;
	arr=new Travel[capacity];
	size=0;
}

int HashTable::hash(int id)	//hash function
{
	return id%10;
}

int HashTable::insert(Travel ele)		//insert an element
{
	if(size==capacity)
		return -1;	//hash table is full
	int hval=hash(ele.getID());
	while(arr[hval].getID()!=0 && arr[hval].getID()!=ele.getID())		//hast table is not empty in the hash value
	{
		hval=hash(hval+1);
	}
	if(arr[hval].getID()==ele.getID())
		return -2;	//duplicates
	arr[hval]=ele;
	size++;
	return 1;	//inserted
}

int HashTable::remove(int ele)			//remove an element
{
	if(size==0)
		return -1;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getID()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			continue;
		}
		else	//elemnt is found
		{
			arr[hval].~Travel();
			return 1;	//removed
		}
		flag++;
	}
	return -2;		//element not found
}

int HashTable::search(int ele)					//search for an element
{
	if(size==0)
		return -1;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getID()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			flag++;
			continue;
		}
		else
			return 1;	//element is found
	}
	return -2;		//element not found	
}

Travel HashTable::findElement(int ele)						//find an element
{
	Travel ret;
	if(size==0)
		return ret;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getID()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			continue;
		}
		else
			return arr[hval];	//element is found
		flag++;
	}
	return ret;		//element not found		
}

void HashTable::display()					//display all elements
{
	if(size==0)
		cout<<"No Details in the list\n";
	else
	{
		int i;
		for(i=0;i<capacity;i++)
			cout<<arr[i];
	}
}
