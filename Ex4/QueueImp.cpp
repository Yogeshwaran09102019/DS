#include"Queue.h"

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
	cout<<real<<" + "<<imaginary<<"i\n";
}

Queue::Queue()
{
	data=NULL;
	front=rear=-1;
	capacity=5;
	for(int i=0;i<5;i++)
		data[i]=Complex();
}

Queue::Queue(Complex *c,int f,int r,int c1)
{
	data=new Complex[c1];
	front=f;
	rear=r-1;
	capacity=c1;
	for(int i=0;i<=rear;i++)
		data[i]=c[i];
	for(int i=rear+1;i<capacity;i++)
		data[i]=Complex();
}

Queue::Queue(const Queue &q)
{
	data=new Complex[q.capacity];
	for(int i=0;i<q.rear;i++)
		data[i]=q.data[i];
	front=q.front;
	rear=q.rear;
	capacity=q.capacity;
	for(int i=rear+1;i<capacity;i++)
		data[i]=Complex();
}

Queue::~Queue()
{
	front=rear=-1;
	capacity=0;
	delete data;
	data=NULL;
}

int Queue::isEmpty()
{
	if((front==-1 && rear==-1) || front>rear)
		return 1;
	else
		return 0;
}

int Queue::isFull()
{
	if(capacity-1==rear)
		return 1;
	else
		return 0;
}

int Queue::enQueue(Complex c)
{
	if(!isFull())
	{
		if(isEmpty())
		{
			front=rear=0;
			data[rear]=c;
		}
		else
		{
			rear++;
			data[rear]=c;
		}
		return 1;
	}
	else
		return 0;
}

Complex Queue::deQueue()
{
	if(!isEmpty())
	{
		Complex c=data[front];
		front++;
		return c;
	}
	else
		cout<<"Empty Queue ... Deletion not possible..\n";
}

int Queue::size()
{
	int c=0;
	if(isEmpty())
		return c;	
	else
	{
		c=(rear-front)+1;
		return c;
	}
}

Complex Queue::peak()
{
	if(isEmpty())
		cout<<"Queue Empty ... No peak Element..\n";
	else
		return data[front];
}

bool Queue::makeEmpty()
{
	if(isEmpty())
		cout<<"List is Already Empty...\n";
	else
	{
		while(!isEmpty())
			Complex c=deQueue();
		return true;
	}
	return false;
}

void Queue::displayQueue()
{
	if(isEmpty())
		cout<<"Empty Stack nothing to Display...\n";
	else
	{
	int i=0;
	for(i=front;i<=rear-1;i++)
		cout<<data[i].real<<" + "<<data[i].imaginary<<"i"<<" -> ";
	cout<<data[i].real<<" + "<<data[i].imaginary<<"i"<<endl;
	}
}
