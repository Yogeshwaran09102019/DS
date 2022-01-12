#include "Array.h"
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
