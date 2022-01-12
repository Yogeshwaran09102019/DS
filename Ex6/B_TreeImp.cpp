#include"B_Tree.h"
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

void Travel::getInput()
{
	//string n,s,d;
	cout<<"Enter the P_id:";
	cin>>P_id;
	cout<<"Enter the name:";
	//cin>>n;
	//name=new char[sizeof(n)];
	/*cin>>name;
	cout<<"Enter the Source:";
	cin>>source;
	cout<<"Enter the destination:";
	cin>>dest;
	cout<<"Enter the Amount:";
	cin>>amount;*/
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
Node::Node()
{
	
	left=NULL;
	right=NULL;
}

Node::Node(Travel d,Node *l,Node *r)
{
	data=d;
	left=l;
	right=r;
}

Node::Node(const Node& n)
{
	data=n.data;
	left=n.left;
	right=n.right;
}



BST::BST()
{
	root=NULL;
}

BST::BST(Node *r)
{
	root =r;
}

BST::BST(const BST &b)
{
	root=b.root;
}

bool BST::isEmpty()
{
	if(root==NULL)
		return true;
	else
		return false;
}

Node* BST::getRoot()
{
	return root;
}

bool BST::insertElement(Node *newNode)
{
	if(root==NULL)
	{
		root=newNode;
		cout<<"p";
		return true;
	}
	else
	{
		Node *temp=root;
		Node *parent;
		while(temp!=NULL)
		{
			cout<<temp->data.getID();
			cout<<newNode->data.getID();
			if(temp->data<newNode->data)
			{
				cout<<"R";
				parent=temp;
				temp=temp->right;
			}
			else if(temp->data>newNode->data)
			{
				cout<<"L";
				parent=temp;
				temp=temp->left;
			}
			else
				return false;
		}
		if (parent -> data < newNode -> data) 
		{
        parent -> right = newNode;
		return true;
		}
		else if (parent -> data > newNode -> data) 
		{
		parent -> left = newNode; 
		return true;
		}
		else //Duplicate element
        return false;
	}
}

bool BST::searchElement(Travel ele)
{
	Node *temp=root;
	while(temp!=NULL)
	{
		if (temp->data<ele)
			temp=temp->right;
		else if(temp->data>ele)
			temp=temp->left;
		else
			return true;
	}
	return false;
}

Travel BST::findMax(Node *temp)
{
	if(temp->right!=NULL)
		findMax(temp->right);
	else
		return temp->data;
}

Travel BST::findMin(Node *temp)
{
	if(temp->left!=NULL)
		findMin(temp->left);
	else
		return temp->data;
}

void BST::inOrder(Node *temp)
{
	if(temp!=NULL)
	{
		inOrder(temp->left);
		cout<<temp->data;
		inOrder(temp->right);
	}
}


void BST::preOrder(Node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		preOrder(temp->left);
		preOrder(temp->right);
	}
}

void BST::postOrder(Node *temp)
{
	if(temp!=NULL)
	{
		postOrder(temp->left);
		postOrder(temp->right);
		cout<<temp->data;
	}
}

Travel BST::deleteElement(Travel j)
{
	Travel test;
	if((root->data==j)&&(root->right==NULL&&root->left==NULL))
	{
	   Travel ret=root->data;	
       root=NULL;
       //root=NULL;	   
	   return ret;	   
	}
	else
	{	
	   Node *temp=root;
	   Node *parent=NULL;
	
		while(temp!=NULL)
		{   
		    if(temp->data==j)
			{
			    Travel ret=temp->data;
			    if(temp->left==NULL&&temp->right==NULL)
				{
					if(parent->left==temp)
					   parent->left=NULL;
					else
					   parent->right=NULL;					   
				}
				else if(temp->left==NULL&&temp->right!=NULL)
				{
				  if(temp==root)
				  {
					  root=temp->right;
				  }
				  else
				  {
					if(parent->left==temp)
					   parent->left=temp->right;
					else
					   parent->right=temp->right;
				  }
				}
				else if(temp->left!=NULL&&temp->right==NULL)
				{
				  if(temp==root)
				  { 
				      root=temp->left;
				  }
				  else
				  {
					if(parent->left==temp)
					   parent->left=temp->left;
					else
					   parent->right=temp->left;
				  }
				}
				else if(temp->right!=NULL&&temp->left!=NULL)
				{
					Node *temp1=temp->right;
					Node *parent1=temp;
					while(temp1->left!=NULL)
					{
						  parent1=temp1;
					      temp1=temp1->left;
					}
			        temp->data=temp1->data;
					if(temp1->right==NULL&&temp1->left==NULL)
					{
						if(parent1->right==temp1)
						   parent1->right=NULL;
						else
						   parent1->left=NULL;
					}
					else
					{
						parent1->right=temp1->right;
					}
				}
				return ret;
			}
			else if(temp->data>j)
			{
				parent=temp;
			    temp=temp->left;	
			}
			else
			{
				parent=temp;
				temp=temp->right;
			}
		}
	}
	return test;
}

