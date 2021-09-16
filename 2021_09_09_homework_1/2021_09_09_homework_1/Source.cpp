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
		if (head == nullptr)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			Node* p = head;
			while (p != nullptr)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
	Node* last()
	{
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}
	Node* prelast()
	{
		Node* p = head;
		Node* k = p;
		while (p ->next!= nullptr)
		{
			k = p;
			p = p->next;
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
	void insertp(int place, int element)
	{
		if (place = 0)
		{
			add_first(element);
		}
		Node* p;
		p = head;
		for (int i = 0; i < place; i++)
		{
			p = p->next;
		}
		p->next = new Node(element, p->next);
	}
	void delete_first()
	{
		Node* p = head->next;
		head->next = nullptr;
		delete head;
		head = p;
	}
	void delp(int place)
	{
		Node* p = head;
		for (int i = 0; i < place - 1; i++)
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
		Node* p = head; //Первый элемент тройки 

		Node* k = head->next; // 
		p->next = nullptr;
		Node* c = k->next; //?????? ??????? ??????? 
		while (c->next != nullptr) // ???? 3-?? ??????? ??????? ?? ????????? - ????????? ???? 
		{
			k->next = p;
			p = k;
			k = c;
			c = c->next;
		}
		k->next = p;
		head = c;
		c->next = k;
	}
	void del()
	{
		while (head != nullptr)
		{
			delete_first();
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
void del(Node*& x)
{

}


int main()
{
	List l;
	for (int i = 0; i < 5; i++) // ????????? ?????? 5-? ?????????? 
	{
		l.add_after_first(i);
		l.print();
	}
	l.print(); // ?????????? ?????? 
	cout << l.last()->data; // ????????? ???????? 
	cout << l.prelast()->data; // ????????????? 
	cout << endl;
	l.add_after_first(9); // ???????? ????? 1-??? 
	l.print();
	l.add_last(22); // ???????? ? ????? 22 
	l.print();
	l.add_first(123); // ???????? ? ?????? 123 
	l.print();
	cout << endl << endl;
	l.insertp(3, 123); // ???????? ? 3? ??????? 123 
	l.print();
	cout << endl << endl;
	l.delp(3); // ??????? 3-?? ??????? 
	l.print();
	cout << odd_number(3) << " " << odd_number(2); // ???????? ?? ???????? ????? 3 ? 2  
	cout << endl;
	l.remove_if(odd_number); // ??????? ???????? ???????? 
	l.print();
	cout << "will be a reverse " << endl;
	l.reverse(); // ????????? ??????. 
	l.print();
	l.del();
	l.print();
}