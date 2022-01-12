#include"Stack.h"

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

void Complex::gettInput()
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
	c=new Complex();
	next=NULL;
}

void Node::getInput()
{
	c->gettInput();
}

Stack::Stack()
{
	top=NULL;
}

Stack::Stack(Node *t)
{
	top=t;
}

Stack::Stack(const Stack &s)
{
	top=s.top;
}

Stack::~Stack()
{
	delete top;
	top=NULL;
}

int Stack::isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int Stack::push(Node *n)
{
	if(isEmpty())
	{
		top=n;
	}
	else
	{
		n->next=top;
		top=n;
	}
	return 1;
}

int Stack::pop()
{
	if(isEmpty())
		return 0;
	else
	{
		Node *temp=top;
		top=top->next;
		delete temp;
		temp=NULL;
		return 1;
	}
}

int Stack::size()
{
	int c=0;
	if(isEmpty())
		return c;
	else
	{
		Node *temp=top;
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
		return c;
	}
}

Complex* Stack::peek()
{
	if(!isEmpty())
		return top->c;
}

bool Stack::makeEmpty()
{
	int k=0;
	while(!isEmpty())
		k=pop();
	if(isEmpty())
		return true;
	else
		return false;
}


void Stack::displayStack()
{
	Node *temp=top;
	if(isEmpty())
		cout<<"Stack Empty ... Nothing to Display..\n";
	else
	{
		while(temp->next!=NULL)
		{
			cout<<temp->c->real<<" + "<<temp->c->imaginary<<"i"<<" -> ";
			temp=temp->next;
		}
	cout<<temp->c->real<<" + "<<temp->c->imaginary<<"i"<<endl;
	}
}
