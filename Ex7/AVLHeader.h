//Header
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
		Travel operator=(Travel);
		friend istream& operator>>(istream&,Travel&);
		friend ostream& operator<<(ostream&,Travel&);
	friend class Node;
	friend class AVL;
};

class Node
{
	private:
		Travel data;
		Node *left;
		Node *right;
		int height;
	public:
		Node();
		Node(Travel,int,Node*,Node*);
		Node(const Node&);
		void getNode();
	friend class AVL;
};

class AVL
{
	private:
		Node *root;
	public:
		AVL();
		AVL(Node*);
		AVL(const AVL&);
		bool isEmpty();
		int height(Node*);
		int BF(Node*);
		Node* insertElement(Node*,Node*);
		bool searchElement(Travel);
		int maximum(int,int);
		Node* getRoot();
		void inorder(Node*);
		void preorder(Node*);
		void postorder(Node*);
		Node* LLRotate(Node*);
	    Node* RRRotate(Node*);
	    Node* LRRotate(Node*);
	    Node* RLRotate(Node*);
};


