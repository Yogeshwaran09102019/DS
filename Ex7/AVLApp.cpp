// APP
#include"AVLHeader.h"
int main()
{
	int ch;
	bool a;
	AVL t;
	Travel T,T1;
	Node *temp;
	do
	{
		cout<<"Enter"<<endl;
		cout<<"		1:Check for empty"<<endl;
		cout<<"		2:Insert a TravelPoint"<<endl;
		cout<<"		3:Display a TravelPoint by Inorder"<<endl;
		cout<<"		4:Display a TravelPoint by Preorder"<<endl;
		cout<<"		5:Display a TravelPoint by Postorder"<<endl;
		cout<<"		6:Search a TravelPoint"<<endl;
		cout<<"		7:Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch==1)
		{
			a=t.isEmpty();
			if(a==true)
				cout<<"No element in tree...\n";
			else
				cout<<"Tree is not Empty...\n";
		}
		else if(ch==2)
		{
			cout<<"Enter the details...\n";
			cin>>T;
			Node *newnode = new Node(T,0,NULL,NULL);
			temp=t.insertElement(t.getRoot(),newnode);
			if(temp!=NULL)
				cout<<"\nInsertion Successsful!\n";
			else
				cout<<"\nDuplicate Are Not Allowed!\n";
		}
		else if(ch==3)
		{
			cout<<"Inorder Display\n";
			t.inorder(t.getRoot());
		
		}
		else if(ch==4)
		{
			
            cout<<"Preorder Display\n";
            t.preorder(t.getRoot());
                   
		}
		else if(ch==5)
		{
			cout<<"postorder Display\n";
			t.postorder(t.getRoot());
		}		
		else if(ch==6)
		{
			cout<<"Enter the element to be searched:";
			cin>>T;
			a=t.searchElement(T);
			if(a==true)
				cout<<"Element found\n";
			else
				cout<<"Not Found \n";
		}
		else if(ch==7)
		{
			return 0;
		}
		else
			cout<<"Choose a valid option";
	}while(ch!=7);
}