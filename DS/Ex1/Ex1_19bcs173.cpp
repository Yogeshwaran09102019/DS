#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // To Store the real number Value
			int imaginary; //  To store Imaginary Number
	public:
			Complex(int,int); // Constructors 
			Complex(const Complex&);
			~Complex(); // Destructor
			void getInput(); // Function to get Complex Number from user
	friend class arrayADT; // arrayADT is a Friend of this class 
};

class arrayADT
{
	private:
			Complex *c; // A pointer to store complex number
			int capacity; // Total capacity of the array
			int size; // Within capacity , size occupied
	public:
			arrayADT(); // Constructors
			arrayADT(Complex*,int,int);
			arrayADT(const arrayADT&);
			~arrayADT(); // Destructor
			int isEmpty(); // To Check the array is Empty
			int isFull(); // To check the array is Full
			void Display(); // Display the array Content
			Complex* insertAtFirst(Complex); // Insertion based on requirement
			Complex* insertAtLast(Complex);
			Complex* insertByPos(int,Complex);
			void deleteAtfirst(); // Deletion based on requirement
			void deleteAtLast();
			void deleteByPos(int);
			void makeEmpty(); // Making the complete array Empty
};

Complex::Complex(int r=0,int i=0)
{
	real=r;
	imaginary=i;
}

Complex::Complex(const Complex &c)
{
	real=c.real;
	imaginary=c.imaginary;
}

Complex::~Complex()
{
	real=0;
	imaginary=0;
}

void Complex::getInput()
{
	cout<<"Enter the Real Number:";
	cin>>real;
	cout<<"Enter the Imaginary Number:";
	cin>>imaginary;
}

void arrayADT::Display()
{
	int i;
	for(i=0;i<size-1;i++)
		cout<<c[i].real<<" + "<<c[i].imaginary<<"i"<<" -> ";
	cout<<c[i].real<<" + "<<c[i].imaginary<<"i\n";
}


arrayADT::arrayADT()
{
	c=NULL;
	size=0;
	capacity=0;
}
arrayADT::arrayADT(Complex *c1,int cc,int s)
{
	int i=0;
	capacity=cc;
	size=s;
	c=new Complex[capacity];
	for(i=0;i<size;i++)
		c[i]=c1[i];
}

arrayADT::arrayADT(const arrayADT &a)
{
	int i=0;
	capacity=a.capacity;
	size=a.size;
	c=new Complex[capacity];
	for(i=0;i<size;i++)
		c[i]=a.c[i];
}

arrayADT::~arrayADT()
{
	capacity=0;
	size=0;
	delete[]c;
	c=NULL;
}

int arrayADT::isEmpty()
{
	if(size==0)
		return 1;
	else
		return 0;
}

int arrayADT::isFull()
{
	if(size==capacity)
		return 1;
	else
		return 0;
}

Complex* arrayADT::insertAtFirst(Complex c1)
{
	if(isFull())
	{
		cout<<"Array full Not Possible...";
	}		
	else if(isEmpty())
	{
		c[size]=c1;
		cout<<"Success..";
	}
	else
	{
		for(int i=size;i>0;i--)
			c[i]=c[i-1];
		size++;
		c[0]=c1;
		cout<<"Success ...";
	}
	return c;

}

Complex* arrayADT::insertAtLast(Complex c1)
{
	if(isFull())
		cout<<"Array is Full  Not possible...\n";
	else if(isEmpty())
	{
		c[size]=c1;
		cout<<"Success..\n";
	}
	else
	{
		c[size++]=c1;
		cout<<"At Last inserted with elements\n";
	}
	return c;
}

Complex* arrayADT::insertByPos(int p,Complex c1)
{
	if(isFull())
		cout<<"Nope.....\n";
	else if(isEmpty())
	{
		if(p==0)
		{
			c[size]=c1;
			cout<<"SUccess..\n";
		}
		else
			cout<<"It is Empty Positional values cannot be inserted..\n";
	}
	else if(p>size)
		cout<<"Cannot Insert..... As pos is greater than alloted size..\n";
	else
	{
		for(int i=size;i>p-1;i--)
			c[i]=c[i-1];
		c[p-1]=c1;
		size++;
		cout<<"Inserted at in between...\n";
	}
	return c;
}

void arrayADT::deleteAtfirst()
{
	if(isEmpty())
		cout<<"Array is Empty Dude.... Cant delete \n";
	else
	{
		Complex c1;
		c1=c[0];
		for(int i=0;i<size;i++)
			c[i]=c[i+1];
		size--;
		//delete c1;
		//c1=NULL;
		cout<<"Deleted Successfully...\n";
	}
	
}

void arrayADT::deleteAtLast()
{
	Complex *c1;
	if(isEmpty())
		cout<<"Empty deletion not Possible....\n";
	else
	{
		c1=new Complex[size-1];
		for(int i=0;i<size-1;i++)
			c1[i]=c[i];
		size--;
		cout<<"Deleted Successfully..\n";
	}
		
}

void arrayADT::deleteByPos(int p)
{
	Complex c1;
	int i;
	if(isEmpty())
		cout<<"Empty!!!\n";
	else
	{
		c1=c[p-1];
		for(i=p-1;i<size;i++)
			c[i]=c[i+1];
		size--;
	}
	
}

void arrayADT::makeEmpty()
{
	while(size!=0)
		deleteAtfirst();
	cout<<"Array is made to be empty\n";
}
	
int main()
{
	Complex *c,*c2,c3;
	int s,c1,ch,pos;
	cout<<"Enter size and capacity:";
	cin>>s>>c1;
	c=new Complex[s];
	for(int i=0;i<s;i++)
		c[i].getInput();
	arrayADT a(c,c1,s);
	do
	{
		cout<<"	         -------------  OPERATIONS  ----------------- \n";
		cout<<endl;
		cout<<"				  1.INSERT AT FIRST               \n";
		cout<<endl;
		cout<<"				  2.INSERT AT LAST                 \n";
		cout<<endl;
		cout<<"				  3.INSERT BY POSITION				\n";
		cout<<endl;
		cout<<"				  4.DELETE AT FIRST               \n";
		cout<<endl;
		cout<<"				  5.DELETE AT LAST                 \n";
		cout<<endl;
		cout<<"				  6.DELETE BY POSITION				\n";
		cout<<endl;
		cout<<"				  7.MAKE EMPTY						\n";
		cout<<endl;
		cout<<"				  8.DISPLAY							\n";
		cout<<endl;
		cout<<"--------------------------------------------------\n";
		cout<<"Enter your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"Enter the element to be inserted:";
					c3.getInput();
					c2=new Complex[c1];
					c2=a.insertAtFirst(c3);
					break;
					
			case 2:
					cout<<"Enter the element to be inserted:";
					c3.getInput();
					c2=new Complex[c1];
					c2=a.insertAtLast(c3);
					break;
			
			case 3:
					cout<<"Enter the element to be inserted:";
					c3.getInput();
					cout<<endl;
					c2=new Complex[c1];
					cout<<"Enter the position to be inserted:";
					cin>>pos;
					cout<<endl;
					c2=a.insertByPos(pos,c3);
					break;
			
			case 4:
					a.deleteAtfirst();
					break;
			
			case 5:
					a.deleteAtLast();
					break;
					
			case 6:
					cout<<"Enter the position to be deleted:";
					cin>>pos;
					a.deleteByPos(pos);
					break;
					
			case 7:
					a.makeEmpty();
					break;
					
					
			case 8:
					a.Display();
					break;
					
			default:
					cout<<" OOPS !! INVALID INPUT TRY AGAIN...\n";
		}
		cout<<"\nEnter '1' to Continue \n";
		cin>>ch;
	}while(ch==1);
return 0;
}
