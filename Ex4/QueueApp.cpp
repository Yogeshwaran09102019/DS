#include"Queue.h"
int main()
{
	int f,cap,r,c=0;
	bool x;
	char ch1;
	Complex c1,c2,c3;
	cout<<"Enter the Capacity:";
	cin>>cap;
	cout<<"\nEnter the front value:";
	cin>>f;
	cout<<"\nEnter the rear Value:";
	cin>>r;
	cout<<"\nEnter the elements:";
	Complex *c11=new Complex[cap];
	for(int i=f;i<r;i++)
		c11[i].getInput();
	Queue q(c11,f,r,cap);
	int ch;
	do
	{
		cout<<"Enter \n";
		cout<<"		1.IsFull \n";
		cout<<"		2.IsEmpty \n";
		cout<<"		3.EnQueue \n";
		cout<<"		4.DeQueue \n";
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
					c=q.isFull();
					if(c==1)
						cout<<"The Queue is Full...\n";
					else
						cout<<"The Queue is not Full...\n";
					break;
			case 2:
					c=q.isEmpty();
					if(c==1)
						cout<<"The Queue is Empty...\n";
					else
						cout<<"The Queue is not Empty...\n";
					break;
			case 3:
					cout<<"Enter the new Complex Number to insert:";
					c1.getInput();
					c=q.enQueue(c1);
					if(c==1)
						cout<<"Inserted Successfully...\n";
					else
						cout<<"Not Success....\n";
					break;
			case 4:
					c2=q.deQueue();
					cout<<"\nThe deleted item is:";
					c2.display();
					cout<<endl;
					break;
			case 5:
					c=q.size();
					cout<<"The Size of Queue:"<<c<<endl;
					break;
			case 6:
					c3=q.peak();
					cout<<"\nThe Peak Element is:";
					c3.display();
					break;
			case 7:
					x=q.makeEmpty();
					if(x==true)
						cout<<"Queue Emptied...\n";
					else
						cout<<"Queue is Not Emptied...\n";
					break;
			case 8:
					q.displayQueue();
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
