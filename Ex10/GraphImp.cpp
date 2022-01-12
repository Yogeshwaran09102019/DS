#include"Graph.h"
Travel::Travel()
{
	P_id=0;
	name="";
	source="";
	dest="";
	amount=0;
}

Travel::Travel(int p,string na,string s,string d,long amt)
{
	P_id=p;
	name=na;
	source=s;
	dest=d;
	amount=amt;
}

Travel::Travel(const Travel&t)
{
	P_id=t.P_id;
	name=t.name;
	source=t.source;
	dest=t.dest;
	amount=t.amount;
}

void Travel::Display()
{
	cout<<P_id<<name<<source<<dest<<amount;
}

int Travel::getID()
{
	return P_id;
}
istream& operator>>(istream &in,Travel &t)
{
		cout<<" Enter the p Id   : ";
        in>>t.P_id;
        cout<<" Enter the Name : ";
        in>>t.name;
        cout<<" Enter the Vechicle Type : ";
        in>>t.source;

		cout<<" Enter the Vechicle Type : ";
        in>>t.dest;
        cout<<" Enter the Amount_Of_Toll : ";
        in>>t.amount;
        return in;
}

ostream& operator<<(ostream &out,Travel &t)
{
		cout<<" Enter the p Id   : ";
        out<<t.P_id;
        cout<<"\n Name : ";
        out<<t.name;
        cout<<"\n Source : ";
        out<<t.source;
		cout<<"\n Destination : ";
        out<<t.dest;
        cout<<"\nAmount : ";
        out<<t.amount;
        return out;
}

bool Travel::operator>(Travel t1)
{
	return (getID()>t1.getID());
}
bool Travel::operator<(Travel t1)
{
        return (getID()<t1.getID());
}
bool Travel::operator==(Travel j)
{
	if(getID()==j.getID())
	    return true;
	return false;
}
Travel Travel::operator=(Travel x)
{
	P_id=x.P_id;
	name=x.name;
	source=x.source;
	dest=x.dest;
	amount=x.amount;
	return *this;
}

Graph::Graph(int n)										//parameterised constructor
{
	noOfVertices=n;
	vertices=new Travel[n];
	adjMatrix = new int*[noOfVertices];

	for( int i=0; i<noOfVertices; i++ )
		adjMatrix[i] = new int[noOfVertices];
	
	visited = new bool[noOfVertices];
	for( int i=0;i<noOfVertices ; i++)
		for( int j=0; j<noOfVertices ; j++)
			adjMatrix[i][j] = 0;
}

void Graph::getData()	//input details for every vertices
{
	int i;
	Travel T;
	for(i=0;i<noOfVertices;i++)
	{
		cin>>T;
		vertices[i]=T;
	}
}

void Graph::createGraph()	//to create a graph
{
	int i,num_edge,v,w,weight;
	cout<<"\nEnter No of Edges in graph: ";
	cin>>num_edge;
	for(i=0;i<num_edge;i++)
	{
		cout<<"\nEnter the Vertices numbers one after one that form an edge:\n";
		cin>>v>>w;
		adjMatrix[v-1][w-1] = 1;
		adjMatrix[w-1][v-1] = 1;		
	}
}

void Graph::performDFS()		//DFS traversal
{
	int i;
	for(i=0;i<noOfVertices;i++)
		if(visited[i]==false)
			dfs(i);
}

void Graph::dfs(int i)
{
	int j;
	cout<<"\nVertex : "<<i+1<<"\n";
	cout<<vertices[i];
	visited[i] = true;
	for(j=0;j<noOfVertices;j++)
		if(adjMatrix[i][j]==1 && visited[j]==false)
			dfs(j);
}

void Graph::displayAll()		//to display all the vertices details
{
	int i;
	for(i=0;i<noOfVertices;i++)
	{
		cout<<vertices[i];
	}
}

void Graph::printAdjacent()		//to display the adjacent matrix
{
	int i,j;
	cout<<"\n Adjacent Matrix :\n";
	for(i=0;i<noOfVertices;i++)
		cout<<"\t"<<i+1;
	cout<<"\n";
	for(i=0;i<noOfVertices;i++)
		cout<<"--------";
	cout<<"\n";
	for(i=0;i<noOfVertices;i++)
	{
		cout<<i+1<<" |\t";
		for(j=0;j<noOfVertices;j++)
			cout<<adjMatrix[i][j]<<"\t";
		cout<<"\n";
	}
}

Graph::~Graph()			//destructor
{
	int i;
	for(i=0;i<noOfVertices;i++)
		adjMatrix[i]=NULL;
	noOfVertices = 0;
	vertices=NULL;
	visited=NULL;
}