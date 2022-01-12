#include<iostream>
#include<string>
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
		friend istream& operator>>(istream&,Travel&);
		friend ostream& operator<<(ostream&,Travel&);
	friend class Node;
	friend class BST;
};

class Node
{
	private:
		Travel data;
		Node *left;
		Node *right;
	public:
		Node();
		Node(Travel,Node*,Node*);
		Node(const Node&);
		void getNode();
	friend class BST;
};

class BST
{
	private:
		Node *root;
	public:
		BST();
		BST(Node*);
		BST(const BST&);
		bool isEmpty();
		bool insertElement(Node*);
		Travel deleteElement(Travel);
		bool searchElement(Travel);
		Travel findMax(Node*);
		Travel findMin(Node*);
		Node* getRoot();
		void inOrder(Node*);
		void preOrder(Node*);
		void postOrder(Node*);
};
