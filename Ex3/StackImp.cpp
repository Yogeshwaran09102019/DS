#include"Stack.h"
Complex::Complex()
{
	real=0;
	imaginary=0;
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
	cout<<"\nEnter the Real Number:";
	cin>>real;
	cout<<"\nEnter the Imaginary Number:";
	cin>>imaginary;
}

void Complex::display()
{
	cout<<real<<" + "<<imaginary<<"i";
}

Stack::Stack()
{
	data=NULL;
	top=capacity=0;
}

Stack::Stack(Complex *c1,int t,int cap)
{
	data[cap];
	for(int i=0;i<t;i++)
		data[i]=c1[i];
	top=t;
	capacity=cap;
}

Stack::Stack(const Stack &s)
{
	data[s.capacity];
	for(int i=0;i<s.top;i++)
		data[i]=s.data[i];
	top=s.top;
	capacity=s.capacity;
}

Stack::~Stack()
{
	top=capacity=0;
	delete data;
	data=NULL;
}

int Stack::isEmpty()
{
	if(top==0)
		return 1;
	else
		return 0;
}

int Stack::isFull()
{
	if(top==capacity-1)
		return 1;
	else
		return 0;
}

int Stack::push(Complex c)
{
	if(!isFull())
	{
		data[top]=c;
		top++;
		return 1;
	}
	else
		return 0;
}

Complex Stack::pop()
{
	if(!isEmpty())
	{
		Complex c;
		c=data[top-1];
		data[top]=Complex();
		top--;
		return c;
	}
	else
		cout<<"It is Empty... Deletion not Possible!!!\n";
}

int Stack::size()
{
	return top;
}

Complex Stack::peek()
{
	return data[top-1];
}

bool Stack::makeEmpty()
{
	Complex temp;
	while(!isEmpty())
	{
		temp=pop();
	}
	if(isEmpty())
		return true;
	else
		return false;
}


void Stack::displayStack()
{
	if(isEmpty())
		cout<<"Empty Stack nothing to Display...\n";
	else
	{
	int i;
	for(i=0;i<top-1;i++)
		cout<<data[i].real<<" + "<<data[i].imaginary<<"i"<<" -> ";
	cout<<data[i].real<<" + "<<data[i].imaginary<<"i"<<endl;
	}
}
