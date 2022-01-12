#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // Real Value
			int imaginary; // Imaginary Value
	public:
			Complex();
			Complex(int,int); // Constructors
			Complex(const Complex&);
			~Complex(); // Destructor
			void gettInput(); // Get Input
			void display(); // Display Complex Number
	friend class Stack; // Stack is the friend of this class
};

class Node
{
	private:
			Complex *c; // List of Complex Number
			Node *next; // Self-Referencing pointer
	public:
			Node();
			void getInput();
	friend class Stack; // Stack is also friend of this class
};

class Stack
{
	private:
			Node *top; // Top value of Stack
	public:
			Stack(); // Constructors 
			Stack(Node*);
			Stack(const Stack&);
			~Stack(); // Destructor
			int isEmpty(); // Empty or Not
			int push(Node*); // Insert at Top
			int pop(); // Delete at Top
			int size(); // Current Size
			Complex* peek(); // Peak Element of Stack
			bool makeEmpty(); // Make Complete Stack Empty
			void displayStack(); // Display all the Stack Content
};
