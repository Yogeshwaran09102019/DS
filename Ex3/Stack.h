#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // To store Real Value
			int imaginary; // To store Imaginary Value
	public:
			Complex();
			Complex(int,int); // Constructors
			Complex(const Complex&);
			~Complex(); // Destructor
			void getInput(); // Get Input 
			void display(); // Display Single Complex Number
	friend class Stack; // Stack class is a friend of this Class
};

class Stack
{
	private:
			Complex *data; // A complete array of Complex data
			int top; // Top value of Stack
			int capacity; // Total Capacity of Stack
	public:
			Stack(); // Constructors
			Stack(Complex*,int,int);
			Stack(const Stack&);
			~Stack(); // Destructor
			int isEmpty(); // To check whether the Stack is Empty or not
			int isFull(); // To check whether Stack is Full or not
			int push(Complex); // Insert at top 
			Complex pop(); // Delete at top
			int size(); // Current Size of the Stack
			Complex peek(); // Peak Value of the stack
			bool makeEmpty(); // Make Stack Empty
			void displayStack(); // Display Elements of the Stack
};
