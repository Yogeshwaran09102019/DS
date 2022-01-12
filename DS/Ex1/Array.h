#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // To Store the real number Value
			int imaginary; //  To store Imaginary Number
	public:
			Complex();
			Complex(int,int); // Constructors 
			Complex(const Complex&);
			~Complex(); // Destructor
			void getInput(); // Function to get Complex Number from user
	friend class arrayADT; // arrayADT is a Friend of this class 
};

class arrayADT
{
	private:
			Complex *c; // A pointer to store complex number
			int capacity; // Total capacity of the array
			int size; // Within capacity , size occupied
	public:
			arrayADT(); // Constructors
			arrayADT(Complex*,int,int);
			arrayADT(const arrayADT&);
			~arrayADT(); // Destructor
			int isEmpty(); // To Check the array is Empty
			int isFull(); // To check the array is Full
			void Display(); // Display the array Content
			Complex* insertAtFirst(Complex); // Insertion based on requirement
			Complex* insertAtLast(Complex);
			Complex* insertByPos(int,Complex);
			void deleteAtfirst(); // Deletion based on requirement
			void deleteAtLast();
			void deleteByPos(int);
			void makeEmpty(); // Making the complete array Empty
};
