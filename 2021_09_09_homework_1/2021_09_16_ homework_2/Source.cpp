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
		//  онструктор создающий пустой список
	}
	~DList()
	{
		del();
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
	void del()
	{
		while (head != nullptr)
		{
			dell_first();
		}
	}
	void print_reverse() //печать в обратном пор€дке
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
		head->next = nullptr; 
		delete head; 
		head = p; 
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
			delete tail; 
		} //next->prev= nullptr 
		else
		{
			DNode* p = head->next->next;
			DNode* k = head->next;
			k->next = nullptr;
			k->prev = nullptr;
			delete k;
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
		else
		{
			DNode* p = head;
			for (int i = 0; i < place; i++)
			{
				p = p->next;  
			}
			p->prev->next = p->next; 
			p->next->prev = p->prev; 
			delete p; 
		}
		return true;
	}
	/*void reverse()
	{
		DNode* p = head; 
		DNode* k = head->next; 
		while (k != nullptr)
		{
			p->prev = k; 
			k->next = p; 
		}
	}*/
	void del()
	{
		while (head != nullptr)
		{
			dell_first();
		}
	}
	void reverse()
	{
		if (lenght() == 2)
		{
			tail->next = head; 
			head->next = nullptr;
			head->prev = tail; 
			head = tail;  
			tail = head->next;
		}
		else if (lenght() <= 1)
		{
			
		}
		else
		{
			DNode* p = head; //ѕервый элемент цепочки 
			tail = p; 
			DNode* k = head->next; // второй элемент цепочки 
			p->next = nullptr;
			p->prev = k; 
			DNode* c = k->next; //третий элемент цепочки 
			while (c->next != nullptr) // ≈сли 3-ий элемент цепочки не последний - следующий цикл 
			{
				k->next = p;
				k->prev = c; 
				p = k;
				k = c;
				c = c->next;
			}
			k->next = p;
			p->prev = k;
			c->next = k;
			c->prev = nullptr;
			k->prev = c; 
			head = c;
		}
		
		
	}
	bool remove_if(bool function(int k))
	{
		DNode* k = head;
		int len = lenght();
		int i = 0; 
		while (k!=nullptr)
		{
			if (k == tail)
			{
				if (function(k->data) == true)
				{
					del_last();
				}
				return 1; 
			}
			else {
				k = k->next;
				if (function(k->prev->data) == true)
				{
					Delp(i);
				}
				else
				{
					i++;
				}
			}
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

	DList l;  
	for (int i = 0; i < 10;i++)
	{
		l.add_first(i);
	}
	l.Print(); // показать собранный список 
	cout << l.tail->data;
	l.add_last(123); // ƒобавить в конец 123 
	l.Print();
	l.add_after_first(981273); // ƒобавить сразу после первого 
	l.Print(); 
	l.del_last(); //удаление последнего 
	l.Print();

	l.del_second(); // удаление второго 
	l.Print();
	l.insertp(5, 123123);//вставка в 5-ю позицию числа 
	l.Print();
	cout << l.lenght();
	cout << "delete *10*" << endl; 
	l.Delp(10);
	l.Print();
	l.Delp(4);
	cout << "delete *4*" << endl;
	l.Print();
	cout << "Reverse" << endl; 
	l.reverse();
	l.Print();
	cout << "„истим от нечетных" << endl; 
	l.Delp(0);
	l.Print(); 
	l.remove_if(odd_number);
	l.Print();
}