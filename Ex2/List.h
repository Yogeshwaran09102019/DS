#include<iostream>
using namespace std;
class Complex
{
	private:
			int real; // To Store the real number Value
			int imaginary; //  To store Imaginary Number
	public:
			Complex();
			Complex(int,int);// Constructors 
			Complex(const Complex&);
			~Complex(); // Destructor
			void gettInput();  // Function to get Complex Number from user
	friend class L_List; // L_List is a Friend of this class 
};

class Node
{
	private:
			Complex *c; // To store Complex number
			Node *next; // Self-Referencing Pointer
	public:
			Node();
			void getInput(); 
	friend class L_List; // L_List is also friend of this class
};

class L_List
{
	public:
		L_List(); // Constructor
		L_List(Node*);
		L_List(const L_List&);
		~L_List(); // Destructor
		int isEmpty(); // To check whether the list is Empty or Not
		void insertAtFirst(Node*); // Insertion based on requirement
		void insertAtLast(Node*);
		void insertBeforeElt(Node*,Complex*);
		void insertAfterElt(Node*,Complex*);
		void deleteAtFirst(); // Deletion based on requirement
		void deleteBeforeElt(Complex*);
		void deleteAfterElt(Complex*);
		void makeEmpty(); // Make the List Empty
		void Display(); // Display the List
	private:
		Node *first; // Address of first node
};
