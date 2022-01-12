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
	cout<<"Enter the Real Number:";
	cin>>real;
	cout<<"Enter the Imaginary Number:";
	cin>>imaginary;
}

void Complex::display()
{
	cout<<real<<" + "<<imaginary<<"i"<<endl;
}

Node::Node()
{
	data=new Complex();
	next=NULL;
}

void Node::gettInput()
{
	data->getInput();
}

Queue::Queue()
{
	first=NULL;
}

Queue::Queue(Node *n)
{
	first=n;
}

Queue::Queue(const Queue &q)
{
	first=q.first;
}

Queue::~Queue()
{
	delete first;
	first=NULL;
}

int Queue::isEmpty()
{
	if(first==NULL)
		return 1;
	else
		return 0;
}

int Queue::enQueue(Node *n)
{
	if(isEmpty())
		first=n;
	else
	{
		Node *t=first;
		while(t->next!=NULL)
			t=t->next;
		t->next=n;
	}
	return 1;
}

int Queue::deQueue()
{
	if(isEmpty())
		return 0;
	else
	{
		Node *t=first;
		first=first->next;
		delete t;
		t=NULL;
		return 1;
	}
}

Complex* Queue::peak()
{
	if(!isEmpty())
		return first->data;
	else
		cout<<"Empty Queue...\n";
}

int Queue::size()
{
	int c=0;
	if(isEmpty())
		return c;
	else
	{
		Node *t=first;
		while(t!=NULL)
		{
			c++;
			t=t->next;
		}
		return c;
	}
}

bool Queue::makeEmpty()
{
	Node *t=first;
	while(t!=NULL)
	{
		first=first->next;
		delete t;
		t=first;
	}
	first=NULL;
	return true;
}

void Queue::displayQueue()
{
	if(isEmpty())
		cout<<"Queue Empty ... Nothing to display...\n";
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
		{
			cout<<temp->data->real<<" + "<<temp->data->imaginary<<"i"<<" -> ";
			temp=temp->next;
		}
	cout<<temp->data->real<<" + "<<temp->data->imaginary<<"i"<<endl;
	}
}
