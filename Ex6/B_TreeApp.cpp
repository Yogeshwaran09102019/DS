#include"B_Tree.h"
int main()
{
	int ch;
	bool a;
	BST t;
	Travel T,T1;
	do
	{
		cout<<"Enter"<<endl;
		cout<<"		1:Check for empty"<<endl;
		cout<<"		2:Insert a TravelPoint"<<endl;
		cout<<"		3:Display a TravelPoint by Inorder"<<endl;
		cout<<"		4:Display a TravelPoint by Preorder"<<endl;
		cout<<"		5:Display a TravelPoint by Postorder"<<endl;
		cout<<"		6:Search a TravelPoint"<<endl;
		cout<<"		7:Find a Max TravelPoint"<<endl;
		cout<<"		8:Find a Min TravelPoint"<<endl;
		cout<<"		9:Delete a TravelPoint"<<endl;
		cout<<"		10:Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
					a=t.isEmpty();
					if(a==true)
						cout<<"No element in tree...\n";
					else
						cout<<"Tree is not Empty...\n";
					break;
			case 2:
					cin>>T;
					Node *s;
					s=new Node(T,NULL,NULL);
					a=t.insertElement(s);
					if(a==true)
						cout<<"Successfully Inserted\n";
					else
						cout<<"Not Inserted\n";
					break;
			case 3:
					cout<<"Inorder Display\n";
					t.inOrder(t.getRoot());
					break;
			case 4:
                    cout<<"Preorder Display\n";
                    t.preOrder(t.getRoot());
                    break;
			case 5:
					cout<<"postorder Display\n";
                    t.postOrder(t.getRoot());
                    break;
			case 6:
					cin>>T;
					a=t.searchElement(T);
					if(a==true)
						cout<<"Element found\n";
					else
						cout<<"Not Found \n";
					break;
			case 7:
					T=t.findMax(t.getRoot());
					cout<<T;
					break;
			case 8:
					T=t.findMin(t.getRoot());
					cout<<T;
					break;
			case 9:
					cout<<"Enter the details to delete:/n";
					cin>>T;
					a=t.searchElement(T);
					if(a==false)
						cout<<"No such Details found Try Again..\n";
					else
					{
						T1=t.deleteElement(T);
						cout<<"Deleted Successfully...\n";
					}
					break;
			case 10:
					return 0;
					break;
			default:
					cout<<"Enter a valid case...\n";
					break;
		}
	}while(ch!=10);
}
