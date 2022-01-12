#include"Graph.h"

int main()
{
	int n,ch;
	cout<<"Enter no of Vertices: ";
	cin>>n;
	Graph g(n);
	g.getData();
	g.createGraph();
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1 - Perform DFS Traversal\n";
		cout<<"2 - Display all Travel details\n";
		cout<<"3 - To Display Adjacent Matrix\n";
		cout<<"4- to exit\n\n";
		cin>>ch;
		cout<<"\n";
		if(ch==4)
			break;
		switch(ch)
		{
			case 1:
			{
				g.performDFS();
				break;
			}
			case 2:
			{
				g.displayAll();
				break;
			}
			case 3:
			{
				g.printAdjacent();
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
			}
		}
	}
}