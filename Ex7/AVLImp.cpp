// IMP
#include"AVLHeader.h"
#include<string>
using namespace std;
Travel::Travel()
{
	P_id=0;
	//name=new char[20];
	name="";
	//source=new char[20];
	source="";
	//dest=new char[20];
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
        cout<<"\n       VechicleName : ";
        out<<t.name;
        cout<<"\n       VechiceType : ";
        out<<t.source;
		cout<<" Enter the Vechicle Type : ";
        out<<t.dest;
        cout<<"\n       Gate_Amount : ";
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
Node::Node()
{
	height=0;
	left=NULL;
	right=NULL;
}

Node::Node(Travel d,int h,Node *l,Node *r)
{
	data=d;
	height=h;
	left=l;
	right=r;
}

Node::Node(const Node& n)
{
	data=n.data;
	height=n.height;
	left=n.left;
	right=n.right;
}

AVL::AVL()
{
	root=NULL;
}

AVL::AVL(Node *r)
{
	root =r;
}

AVL::AVL(const AVL &b)
{
	root=b.root;
}

bool AVL::isEmpty()
{
	if(root==NULL)
		return true;
	else
		return false;
}

Node* AVL::getRoot()
{
	return root;
}

int AVL::height(Node *n)
{
	if(n==NULL)
		return -1;
	else
		return n->height;
}

int AVL::BF(Node *n)
{
	if(n==NULL)
		return -1;
	else
		return (height(n->left)-height(n->right));
}

int AVL::maximum(int height1,int height2)
{
	if(height1>height2)
	   return  height1;
	else if(height1<height2)
	   return height2;
	return height1;
}

Node* AVL::LLRotate(Node *k3)
{
	//k3 - root node
	Node *k2=k3->left;
	Node *temp=k2->right;
	k2->right=k3;
	k3->left=temp;

	//height update
	k3->height=max(height(k3->left),height(k3->right))+1;
	k2->height=max(height(k2->left),height(k2->right))+1;

	return k2;
}

Node* AVL::RRRotate(Node *k1)
{
	//k1- root node
	Node *k2=k1->right;
	Node *temp=k2->left;
	k2->left=k1;
	k1->right=temp;

	k1->height=max(height(k1->left),height(k1->right))+1;
	k2->height=max(height(k2->left),height(k2->right))+1;

	return k2;
}

Node* AVL::LRRotate(Node *k3)
{
	//k3- root node
	k3->left=RRRotate(k3->left);	//RR rotate
	return  LLRotate(k3);
}

Node* AVL::RLRotate(Node *k1)
{
    //k3- root node
	k1->right=LLRotate(k1->right);	//RR rotate
	return  RRRotate(k1);
}

void AVL::inorder(Node* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data;
		inorder(temp->right);
	}
}

void AVL::preorder(Node* temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void AVL::postorder(Node* temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data;
	}
}

Node* AVL::insertElement(Node *temp,Node *newNode)
{
	//temp-root
	//newNode-node to insert
	if(temp==NULL)
	{
		root=newNode;
		return root;
	}
	else if(temp->data > newNode->data)
	{
		if(temp->left==NULL)
			temp->left=newNode;
		else
			temp->left=insertElement(temp->left,newNode);
	}
	else if(temp->data < newNode->data)
	{
		if(temp->right==NULL)
			temp->right=newNode;
		else
			temp->right=insertElement(temp->right,newNode);
	}
	else
		cout<<"Duplicate ID can't be inserted\n";

	temp->height = max(height(temp->left),height(temp->right)) + 1;
	int bal=BF(temp);

	if(bal>1)
	{
		if(newNode->data < temp->left->data)
			return LLRotate(temp);
		else
			return LRRotate(temp);
		cout<<"inserted\n";
	}
	if(bal<-1)
	{
		if(newNode->data > temp->right->data)
			return RRRotate(temp);
		else
			return RLRotate(temp);
		cout<<"inserted\n";
	}
	return temp;
}

bool AVL::searchElement(Travel key)
{
	Node *temp=root;
	while(temp!=NULL)
	{
		if(temp->data>key)
		   temp=temp->left;
		else if(temp->data<key)
		   temp=temp->right;
		else
		   return true;
	}
	return false;
}
