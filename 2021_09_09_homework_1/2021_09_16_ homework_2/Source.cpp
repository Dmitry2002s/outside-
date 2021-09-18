#include <iostream>

using namespace std;

struct DNode
{
	int data; // элемент данных 
	DNode* next; //ссылка на след 
	DNode* prev;// ссылка на пред 
	DNode(int d = 0, DNode* n = nullptr, DNode*p = nullptr) : 
		data(d),next (n), prev(p) {} // конструктор 
};

struct DList
{
	DNode* head, * tail;
	DList() {
		head = nullptr;
		tail = nullptr;
		// Конструктор создающий пустой список
	}
	void add_first(int d)
	{
		if (head == nullptr)
		{
			DNode* t = new DNode(d, nullptr, nullptr);
			head = t; 
			tail = t; 
		}
		else
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

	void print_reverse() //печать в обратном порядке
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
	void add_last(int d) // добавить в конец 
	{
		//DNode* p = new DNode(d, nullptr, tail);
		DNode* p = new DNode; 
		p->data = d; 
		
		p->next = nullptr; 
		p->prev = tail; 
		tail->next = p;
			tail = p; 
	}
	void add_after_first(int d)
	{
		DNode* p = new DNode; 
		DNode* k = head->next;  
		k->prev = p;
		p->next = k; 
		head->next = p; 
		p->prev = head; 
		p->data = d; 
	}
	void dell_first()
	{
		DNode* p = head; 
		p = p->next;  
		p->prev = nullptr; 
		delete[] head; 
		p = head; 
	}
	void del_last()
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
		if (head == tail->prev) //случай списка из двух элементов 
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
	int lenght()
	{
		int i = 0;
		DNode* p = head; 
		while (p != nullptr)
		{
			++i;
			p = p->next; 
		}
		return i; 
	}
	bool insertp(int place, int element)
	{
		if (place<0 || place > lenght() - 1)
		{
			return false;
		}
		else if (place == 0)
		{
			add_first(element);
		}
		 else if (place == lenght() - 1)
		{
			add_last(element);
		}
		 else 
		{
			DNode* k = head; 
			for (int i = 0; i < place; i++)
			{
				k = k->next; 
			}
			DNode* c = k->next; 
			DNode* p = new DNode; 
			p->data = element;
			k->next = p; 
			p->prev = k; 
			p->next = c; 
			c->prev = p; 
		}
		return true; 
	}
	bool Delp(int place)
	{
		if (place<0 || place > lenght() - 1)
		{
			return false; 
		}
		else if (place == 0)
		{
			dell_first();
			 
		}
		else if (place == lenght() - 1)
		{
			del_last();
		}
		return true;
	}
	void reverse()
	{
		DNode* p = head; 
		DNode* k = head->next; 
		while (k != nullptr)
		{
			p->prev = k; 
			k->next = p; 
		}
	}
	void del()
	{
		while (head != nullptr)
		{
			dell_first();
		}
	}
};

int main()
{

	DList l;  
	for (int i = 0; i < 10;i++)
	{
		l.add_first(i);
	}
	l.Print(); // показать собранный список 
	cout << l.tail->data;
	l.add_last(123); // Добавить в конец 123 
	l.Print();
	l.add_after_first(981273); // Добавить сразу после первого 
	l.Print(); 
	l.del_last(); //удаление последнего 
	l.Print();

	l.del_second(); // удаление второго 
	l.Print();
	l.insertp(5, 123123);//вставка в 5-ю позицию числа 
	l.Print();
	cout << l.lenght();
	l.Delp(10);
	l.Print();


}