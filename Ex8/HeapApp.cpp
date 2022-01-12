#include"Heap.h"
int main()
{
	int ch,a,id;
	BinHeap b;
	Travel T,T1;
	do
	{
		cout<<"Enter"<<endl;
		cout<<"		1:Check for empty"<<endl;
		cout<<"		2:Insert a TravelPoint"<<endl;
		cout<<"		3:Delete a TravelPoint"<<endl;
		cout<<"		4:Find the min TravelPoint"<<endl;
		cout<<"		5:Search a TravelPoint"<<endl;
		cout<<"		6:Display All TravelPoint"<<endl;
		cout<<"		7.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			a=b.isEmpty();
			if(a==1)
				cout<<"Empty..\n";
			else
				cout<<"Not Empty...\n";
		}
		else if(ch==2)
		{
			cout<<"Enter details to insert...\n";
			cin>>T;
			a=b.enqueue(T);
			if(a==1)
				cout<<"Inserted Successfully..\n";
			else
				cout<<"Not Inserted...\n";
		}
		else if(ch==3)
		{
			T=b.dequeue();
			if(T.getID()==0)
				cout<<"Empty... Nothing to delete \n";
			else
			{
				cout<<"Deleted Element is:";
				cout<<endl;
				cout<<T;
			}
		}
		else if(ch==4)
		{
			T=b.findMin();
			cout<<"Minimum Element is:";
			cout<<endl;
			cout<<T;
		}
		else if(ch==5)
		{
			cout<<"Enter the P_ID to search:";
			cin>>id;
			a=b.search(id);
			if(a==1)
				cout<<"Element found \n";
			else
				cout<<"Element not found \n";
		}
		else if(ch==6)
		{
			b.displayHeap();
		}
		else if(ch==7)
			return 0;
		else
			cout<<"Enter a valid option ... Try Again !!! \n";
	}while(ch!=7);
}