#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // Real Value
			int imaginary; // Imaginary Value
	public:
			Complex();
			Complex(int,int); // Constructor
			Complex(const Complex&); 
			~Complex(); // Destructor
			void getInput(); // Get Input
			void display(); // Display Complex
	friend class Queue; // Queue is a friend of this class
};

class Node
{
	private:
			Complex *data; // A list of Complex Numbers in Queue
			Node *next; // Self-referencing pointer
	public:
			Node();
			void gettInput();
	friend class Queue; // Queue is the friend of this class
};

class Queue
{
	private:
			Node *first; // Address of First Node
	public:
			Queue(); // Constructor 
			Queue(Node*);
			Queue(const Queue&);
			~Queue(); // Destructor
			int enQueue(Node*); // Insert Element at Last
			int deQueue(); // Delete Element at First
			int isEmpty(); // Check for Empty or Not
			Complex* peak(); // Peak Element of Queue
			int size(); // Current Size of the Queue
			bool makeEmpty(); // Make complete Queue Empty
			void displayQueue(); // Display all Element in Queue
};
