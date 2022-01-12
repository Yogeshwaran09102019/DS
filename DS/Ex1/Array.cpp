#include"Array.h"
Complex::Complex()
{
	real=imaginary=0;
}
Complex::Complex(int r,int i)
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
	c[capacity];
	for(i=0;i<size;i++)
		c[i]=c1[i];
}

arrayADT::arrayADT(const arrayADT &a)
{
	int i=0;
	capacity=a.capacity;
	size=a.size;
	c[capacity];
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
