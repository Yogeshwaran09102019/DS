#include"Stack.h"
int main()
{
	int t,cap,c=0;
	bool x;
	char ch1;
	Complex c1,c2,c3;
	cout<<"Enter the Capacity:";
	cin>>cap;
	cout<<"\nEnter the top Value:";
	cin>>t;
	cout<<"\nEnter the elements:";
	Complex *c11=new Complex[cap];
	for(int i=0;i<t;i++)
		c11[i].getInput();
	Stack s(c11,t,cap);
	int ch;
	do
	{
		cout<<"Enter \n";
		cout<<"		1.IsFull \n";
		cout<<"		2.IsEmpty \n";
		cout<<"		3.Push \n";
		cout<<"		4.Pop \n";
		cout<<"		5.Size \n";
		cout<<"		6.Peak \n";
		cout<<"		7.MakeEmpty \n";
		cout<<"		8.Display \n";
		cout<<"Enter your Choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
					c=s.isFull();
					if(c==1)
						cout<<"The Stack is Full...\n";
					else
						cout<<"The Stack is not Full...\n";
					break;
			case 2:
					c=s.isEmpty();
					if(c==1)
						cout<<"The Stack is Empty...\n";
					else
						cout<<"The Stack is not Empty...\n";
					break;
			case 3:
					cout<<"Enter the new Complex Number to insert:";
					c1.getInput();
					c=s.push(c1);
					if(c==1)
						cout<<"Inserted Successfully...\n";
					else
						cout<<"Not Success....\n";
					break;
			case 4:
					c2=s.pop();
					cout<<"\nThe deleted item is:";
					c2.display();
					cout<<endl;
					break;
			case 5:
					c=s.size();
					cout<<"The Size of Stack:"<<c<<endl;
					break;
			case 6:
					c3=s.peek();
					c3.display();
					break;
			case 7:
					x=s.makeEmpty();
					if(x==true)
						cout<<"Stack Emptied...\n";
					else
						cout<<"Stack is Not Emptied...\n";
					break;
			case 8:
					s.displayStack();
					break;
			default:
					cout<<"Wrong Input.... Try Again!!!\n";
					break;
		}
		cout<<"Enter 'y' to continue...\n";
		cin>>ch1;
	}while(ch1=='y');		
return 0;
}
