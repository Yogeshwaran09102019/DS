#include"Stack.h"
int main()
{
	Stack s,s1;
	Node *n;
	Complex *c;
	int ch; bool x; char ch1;
	int c1=0;
	do
	{
		cout<<"Enter \n";
		cout<<"		1IsEmpty \n";
		cout<<"		2.Insert a number \n";
		cout<<"		3.Delete a number \n";
		cout<<"		4.Size \n";
		cout<<"		5.Peak \n";
		cout<<"		6.MakeEmpty \n";
		cout<<"		7.Display \n";
		cout<<"Enter your Choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
					c1=s.isEmpty();
					if(c1==1)
						cout<<"\nStack Empty...\n";
					else
						cout<<"Stack has some Elements..\n";
					break;
			case 2:
					n=new Node();
					n->getInput();
					c1=s.push(n);
					if(c1==1)
						cout<<"\nSuccess....\n";
					else
						cout<<"Not Inserted....\n";
					break;
			case 3:
					c1=s.pop();
					if(c1==1)
						cout<<"\nDeletion Success....\n";
					else
						cout<<"Not Deleted....\n";
					break;
			case 4:
					c1=s.size();
					cout<<"\nSize of Stack:"<<c1<<endl;
					break;
			case 5:
					c=s.peek();
					cout<<"\nThe Peak Element is:";
					c->display();
					break;
			case 6:
					x=s.makeEmpty();
					if(x==true)
						cout<<"Stack Emptied..\n";
					else
						cout<<"Stack not Emptied...\n";
					break;
			case 7:
					s.displayStack();
					break;
			default:
					cout<<"Wrong Input... Try Again!!!\n";
					break;
		}
	cout<<"Enter 'y' to continue...\n";
	cin>>ch1;
	}while(ch1=='y');
	return 0;
}
					