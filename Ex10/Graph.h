#include<iostream>
using namespace std;
class Travel
{
	private:
		int P_id;
		string name;
		string source;
		string dest;
		long amount;
	public:
		Travel();
		Travel(int,string,string,string,long);
		Travel(const Travel&);
		void getInput();
		void Display();
		int getID();
		bool operator>(Travel);
		bool operator<(Travel);
		bool operator==(Travel);
		Travel operator=(Travel);
		friend istream& operator>>(istream&,Travel&);
		friend ostream& operator<<(ostream&,Travel&);
	friend class Graph;
};

class Graph//graph class
{
	public:
			Graph(int);									//parameterised constructor
			~Graph();   								// destructor
			void performDFS();							//perform Depth first traversal
			void dfs(int);								// perform DFS on adjacent vertices
			void getData();								//get application data for each vertices
			void createGraph();							//create adjacency matrix (create vertices by getting edges)
			void printAdjacent();						//to print adjacency matrix
			void displayAll();   						//to Display Detail of all vertices
			int display();
	private:
			Travel *vertices;								//vertices pointer
			int noOfVertices;							//number of vertuices in the graph
			bool* visited;								//to denote which vertices are visited
			int** adjMatrix;							//adjacency matrix
};