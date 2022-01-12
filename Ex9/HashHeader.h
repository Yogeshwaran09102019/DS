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
	friend class HashTable;
};

class HashTable	//hashtable class (linear probing)
{
	private:
			int capacity;	//bucket size
			int size;		//filled size
			Travel *arr;		//Travel details
	public:
			HashTable();						//default constructor
			int hash(int);						//hash function
			int insert(Travel);					//insert an element
			int remove(int);					//remove an element
			int search(int);					//search for an element
			Travel findElement(int);				//find an element
			void display();						//display all elements
};
