#include"HashHeader.h"
int main()
{
	int ch,a,id;
	HashTable h;
	Travel T,T1;
	do
	{
		cout<<"Enter"<<endl;
		cout<<"		1:Insert a TravelPoint"<<endl;
		cout<<"		2:Delete a TravelPoint"<<endl;
		cout<<"		3:Find the  TravelPoint"<<endl;
		cout<<"		4:Search a TravelPoint"<<endl;
		cout<<"		5:Display All TravelPoint"<<endl;
		cout<<"		6.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the Details:";
			cout<<endl;
			cin>>T;
			a=h.insert(T);
			if(a==1)
					cout<<"Travel details inserted\n";
			else if(a==-1)
				cout<<"List is Full, can't insert\n";
			else
				cout<<"Duplicate Travel details is not allowed\n";
		}
		else if(ch==2)
		{
			cout<<"Enter the P_ID to remove:";
			cin>>id;
			a=h.remove(id);
			if(a==-1)
				cout<<"List is Empty\n";
			else if(a==-2)
				cout<<"Bank Account not found\n";
			else
				cout<<"Account details deleted\n";
		}
		else if(ch==3)
		{
			cout<<"Enter the P_ID to find:";
			cin>>id;
			T=h.findElement(id);
			if(T.getID()==0)
				cout<<"No such detail found...\n";
			else
				cout<<T;
		}
		else if(ch==4)
		{
			cout<<"Enter the P_ID to search:";
			cin>>id;
			int temp=h.search(id);
			if(temp==-1)
				cout<<"List is Empty\n";
			else if(temp==-2)
				cout<<"Travel Details not found\n";
			else
				cout<<"Travel Details found\n";
		}
		else if(ch==5)
		{
			h.display();
		}
		else if(ch==6)
			return 0;
		else
			cout<<"Enter a valid option..\n";
	}while(ch!=6);
}