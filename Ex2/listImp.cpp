#include"List.h"
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

Node::Node()
{
	c=new Complex();
	next=NULL;
}

void Node::getInput()
{
	c->gettInput();
}

L_List :: L_List()
{
	first = NULL; // Initially List is empty 
}

L_List :: L_List(Node *f)
{
	first = f; 
}

L_List :: L_List(const L_List&f)
{
	first = f.first; 
}

L_List :: ~L_List()
{
	first = NULL;
	delete first;
}

int L_List::isEmpty()
{
	if(first==NULL)
		return 1;
	else
		return 0;
}

void L_List::insertAtFirst(Node *n)
{
	if(isEmpty())
	{
		first=n;
		cout<<"Inserted As it is Empty.....\n";
	}
	else
	{
		n->next=first;
		first=n;
		cout<<"Inserted ...\n";
	}
}

void L_List::insertAtLast(Node *n1)
{
	if(isEmpty())
		insertAtFirst(n1);
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=n1;
	}
	cout<<"Added at Last...\n";
}

void L_List::insertAfterElt(Node *n,Complex *c1)
{
	if(isEmpty())
		cout<<"List Empty ... Before Element cannot be inserted...\n";
	else
	{
		Node *temp=first;
		while(temp->next!=NULL && ((temp->c->real!=c1->real) && (temp->c->imaginary!=c1->imaginary)))
		{
			temp=temp->next;
		}
		n->next=temp->next;
		temp->next=n;
		cout<<"Inserted Successfully....\n";
	}
}

void L_List::insertBeforeElt(Node *n,Complex *c1)
{
	if(isEmpty())
		cout<<"List Empty ... Before Element cannot be inserted...\n";
	else
	{
		Node *temp=first;
		Node *prev=first;
		while(temp->next!=NULL && ((temp->c->real!=c1->real) && (temp->c->imaginary!=c1->imaginary)))
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=n;
		n->next=temp;
		cout<<"Inserted Successfully....\n";
	}
}

void L_List::deleteAtFirst()
{
	if(isEmpty())
		cout<<"List Empty Nothing to delete...\n";
	else
	{
		Node *temp=first;
		first=first->next;
		delete temp;
		temp=NULL;
		cout<<"Deleted Successfully....\n";
	}
}


void L_List::deleteBeforeElt(Complex *c1)
{
	if(isEmpty())
		cout<<"List Empty...\n";
	else
	{
		Node *t=first;
		Node *temp=first;
		Node *prev=first;
		while(temp->next!=NULL && !((temp->c->real==c1->real) && (temp->c->imaginary==c1->imaginary)))
		{
			t=prev;
			prev=temp;
			temp=temp->next;
		}
		
		t->next=temp;
		delete prev;
		prev=NULL;
		cout<<"Deleted Successfully....\n";
	}
}

void L_List::deleteAfterElt(Complex *c1)
{
	if(isEmpty())
		cout<<"List Empty...\n";
	else
	{
		Node *temp=first;
		Node *n=first;
		while(temp->next!=NULL && ((temp->c->real!=c1->real) && (temp->c->imaginary!=c1->imaginary)))
		{
			temp=temp->next;
			n=temp->next;
		}
		temp->next=n->next;
		delete n;
		n=NULL;
		cout<<"Deleted Successfully....\n";
	}
}

void L_List::makeEmpty()
{
	while(!isEmpty())
	{
		deleteAtFirst();
	}
}

void L_List::Display()
{
	Node *temp=first;
	if(isEmpty())
	{
		cout<<"List Empty .... Nothing to display\n";
		goto x;
	}
	while(temp->next!=NULL)
	{
		cout<<temp->c->real<<" + "<<temp->c->imaginary<<"i"<<" -> ";
		temp=temp->next;
	}
	cout<<temp->c->real<<" + "<<temp->c->imaginary<<"i";
	x:
	cout<<"\n";
}

