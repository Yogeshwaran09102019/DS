#include<iostream>
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
	friend class BinHeap;
};

class BinHeap	//bin heap tree
{
	private:
			Travel *arr;		//Details
			int capacity;	//capcity of binary heap
			int hsize;		//heap size
	public:
			BinHeap();				//default constructor
			int isEmpty();			//check if heap is empty
			int isFull();			//to check if heap is full
			int enqueue(Travel);		//insert an element
			Travel dequeue();			//remove an element (delete min)			
			Travel findMin();			//find minimum element
			int search(int);		//search an element
			void displayHeap();		//display the heap
};
