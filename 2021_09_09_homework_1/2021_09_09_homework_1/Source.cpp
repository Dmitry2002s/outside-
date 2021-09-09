#include <iostream>

using namespace std;  

struct Node
{
	int data; 
	Node* next; 

	Node(int d = 0, Node* n = nullptr) :
		data(d), next(n) {}
};

struct List
{
	Node* head; 
	Node* tail; 

	List()
	{
		head = tail = nullptr; 
	}
	void add_first(int d)
	{
		
			Node* tmp;
			tmp = new Node(d, head);
			head = tmp;
	}
	void add_after_first(int d)
	{
		if (head == nullptr)
		{
			add_first(d);
		}
		else if (head->next == nullptr)
		{
			tail = head->next = new Node(d, head->next);
		}
		else 
		{
			head->next = new Node(d, head->next);
		}
	}
	void add_last(int d)
	{
		tail->next = new Node(d, nullptr);
		tail = tail->next;
	}
	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next; 
		}
		cout << endl;
	}
	Node* last()
	{
		Node* p = head; 
		while (p != nullptr)
		{
			p = p->next; 
		}
		return p; 
	}
	Node* prelast()
	{
		Node* p = head;
		Node* k = p; 
		while (p != nullptr)
		{
			p = p->next;
			k = p; 
		}
		return k;
	}
	Node* get_ptr(int n)
	{
		Node* temp;
		for (; n > 0; n--)
		{
			temp = temp->next; 
		}
		return temp; 
	}
	
};



int main()
{
	List l; 
	for (int i = 0; i < 5; i++)
	{
		l.add_after_first(i);
		l.print();
	}
	l.print();
	cout << l.last();
	cout << l.prelast();
	cout << endl; 
	l.add_after_first(9);
	l.print();
	l.add_last(22);
	l.print();
	l.add_first(123);
	l.print();
}