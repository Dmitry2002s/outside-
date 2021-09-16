#include <iostream>

using namespace std;

struct DNode
{
	int data; // ������� ������ 
	DNode* next; //������ �� ���� 
	DNode* prev;// ������ �� ���� 
	DNode(int d = 0, DNode* n = nullptr, DNode*p = nullptr) : 
		data(d),next (n), prev(p) {} // ����������� 
};

struct DList
{
	DNode* head, * tail;
	DList() {
		head = nullptr;
		tail = nullptr;
		// ����������� ��������� ������ ������
	}
	void add_first(int d)
	{
		DNode* t;
		t = new DNode(d, head, nullptr);
		if (head == nullptr)
		{
			head = t;
			tail = t;
		}
		else
		{
			head->prev = t;
			head = t;
		}
	}
	void print()
	{
		DNode* p = head;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	void print_reverse() //������ � �������� �������
	{
		DNode* p = tail;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
	void Print()
	{
		print();
		print_reverse();
		cout << endl; 
	}
	void add_last(int d) // �������� � ����� 
	{
		//DNode* p = new DNode(d, nullptr, tail);
		DNode* p = new DNode; 
		p->data = d; 
		tail->next = p; 
		p->next = nullptr; 
		p->prev = tail; 
			tail = p; 
	}
	void add_after_first(int d)
	{
		DNode* p = new DNode; 
		DNode* k = head->next->next;  
		k->prev = p;
		p->next = k; 
		head->next = p; 
		p->prev = head; 
		p->data = d; 
	}
	void dell_first()
	{
		delete[] head; 
	}
	void dell_last()
	{
		if (tail == head)
		{
			dell_first();
		}
		DNode* k = tail; 
		k = k->prev; 
		k->next = nullptr; 
		tail->prev = nullptr; 
		delete[] tail; 
		tail = k; 
	}
	void del_second()
	{
		if (head == tail->prev) //������ ������ �� ���� ��������� 
		{
			tail->prev = nullptr; 
			head->next = nullptr; 
			delete[] tail; 
		} //next->prev= nullptr 
		else
		{
			DNode* p = head->next->next;
			DNode* k = head->next;
			k->next = nullptr;
			k->prev = nullptr;
			delete[] k;
			head->next = p;
			p->prev = head;
		}
	}
};

int main()
{

	DList l;  
	for (int i = 0; i < 5;i++)
	{
		l.add_first(i);
	}
	l.Print(); // �������� ��������� ������ 
	l.add_last(123); // �������� � ����� 123 
	l.print();
	l.add_after_first(981273); // �������� ����� ����� ������� 
	l.print(); 
	l.dell_last(); //�������� ���������� 
	l.Print();

	l.del_second();
	l.print();

}