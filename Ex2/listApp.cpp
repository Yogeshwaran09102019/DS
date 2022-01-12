#include"List.h"
int main()
{
	L_List list;
	Node *n;
	Complex *c11;
	int ch;
	do
	{
		cout<<"-----------------  OPERATIONS  -----------------\n";
		cout<<"    	1.INSERT AT FIRST              \n";
		cout<<" 	2.INSERT AT LAST                \n";
		cout<<"	    	3.INSERT BEFORE GIVEN ELEMENT	        \n";
		cout<<"	    	4.INSERT AFTER GIVEN ELEMENT             \n";
		cout<<"	    	5.DELETE AT FIRST                         \n";
		cout<<" 	6.DELETE BEFORE GIVEN ELEMENT	    \n";
		cout<<"	    	7.DELETE AFTER GIVEN ELEMENT	     \n";
		cout<<" 	8.MAKE EMPTY				          \n";
		cout<<"	    	9.DISPLAY \n";
		cout<<"--------------------------------------------------      \n";
		cout<<"Enter your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
					n=new Node();
					n->getInput();
					list.insertAtFirst(n);
					break;
			case 2:
					n=new Node();
					n->getInput();
					list.insertAtLast(n);
					break;
			case 3:
					cout<<"Enter the element to be searched for before insertion:\n";
					c11=new Complex();
					c11->gettInput();
					cout<<"Enter the Element to be inserted:\n";
					n=new Node();
					n->getInput();
					list.insertBeforeElt(n,c11);
					break;
			case 4:
					cout<<"Enter the element to be searched for after insertion:\n";
					c11=new Complex();
					c11->gettInput();
					cout<<"Enter the Element to be inserted:\n";
					n=new Node();
					n->getInput();
					list.insertAfterElt(n,c11);
					break;
			case 5:
					list.deleteAtFirst();
					break;
			/*case 6:
					list.deleteAtLast();
					break;*/
			case 6:
					cout<<"Enter the element to be searched for before deletion:\n";
					c11=new Complex();
					c11->gettInput();
					list.deleteBeforeElt(c11);
					break;
			case 7:
					cout<<"Enter the element to be searched for after deletion:\n";
					c11=new Complex();
					c11->gettInput();
					list.deleteAfterElt(c11);
					break;
			case 8:
					list.makeEmpty();
					break;
			case 9:
					list.Display();
					break;
			default:
					cout<<"Not an proper choice.. Try Again....\n";
					break;
			
		}
		cout<<"Enter 1 to continue...\n";
		cin>>ch;
	}while(ch==1);
	return 0;
}
