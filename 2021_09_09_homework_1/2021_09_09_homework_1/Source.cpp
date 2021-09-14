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
	void insertp(int place,int element)
	{
		Node* p;
		p = head; 
		for (int i = 0; i < place; i++)
		{
			p = p->next; 
		}
		p->next = new Node(element, p->next);
	}
	void delp(int place)
	{
		Node* p = head; 
		for (int i = 0; i < place-1; i++)
		{
			p = p->next; 
		}
		Node* k = p; 
		k = k->next; 
		p->next = k->next; 
		delete[] k; 
	}
	void remove_if(bool k(int i))
	{
		Node* element; 
		element = head; 
		while (element->next != nullptr)
		{
			if (k(element->next->data) == true)
			{
				Node* p = element; 
				Node* v = element;
				v = v->next;
				p->next = v->next;
				delete[] v;
			}
			element = element->next; 
		}
	}
	void reverse()
	{
		Node* p = head; 
		Node* k = head->next; 
		Node* c = k->next; 
		while (k->next != nullptr)
		{
			k->next = p; 
			p = p->next; 
			k = k->next; 
		}

	}
};
bool odd_number(int element)
{
	if (element % 2 == 0)
	{
		return false;
	}
	return true;
}



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
	cout << endl << endl; 
	l.insertp(3, 123);
	l.print();
	cout << endl << endl; 
	l.delp(3);
	l.print();
	cout << odd_number(3) << " " << odd_number(2);
	cout << endl; 
	l.remove_if(odd_number);
	l.print(); 
}