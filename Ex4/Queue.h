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
			~Complex(); // Destructors
			void getInput(); // Get Input
			void display(); // Display 
	friend class Queue; // Queue is the friend of this class
};

class Queue
{
	private:
			Complex *data; // To hold List of Complex Numbers in Queue
			int front; // Front End Of the Queue
			int rear; // Rear End of the Queue
			int capacity; // Total Capacity of the Queue
	public:
			Queue(); //Constructors
			Queue(Complex*,int,int,int);
			Queue(const Queue&);
			~Queue(); // Destructors
			int enQueue(Complex); // Insertion at rear End
			Complex deQueue(); // Deletion at front End
			int isFull(); // Full or Not
			int isEmpty(); // Empty or not
			Complex peak(); // Peak Element of Queue
			int size(); // Current Size of the Queue
			bool makeEmpty(); // Make Complete Queue Empty
			void displayQueue(); // Display Queue
};
