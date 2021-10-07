#include <iostream>
#include <list>
#include <cstdlib>

using namespace std; 

static int c = 0; 
struct Subscriber
{
	 
	 int order;
	string name;
	string adress;
	string number;
	Subscriber(int x = c++ , string a = "Name", string b = "adress", string c = "000000") :
		order(x) ,name(a), adress(b), number(c) {}
	
}; 


std::ostream& operator << (ostream &cout , const Subscriber& S) 
{
	cout << S.order << endl; 
	cout << "Name - " << S.name    <<endl;
	cout << "Adress - " << S.adress<<endl;
	cout << "Number - " << S.number<<endl;
	cout << "___________" << endl; 
	return cout;
}

std::istream& operator >> (istream &cin, Subscriber& S)
{
	cout << "enter in the order of 'name' 'address' 'number' " << endl; 
	cin >> S.name;

	cin >> S.adress;
	cin >> S.number;
	
	return cin ;
}
int lenght(list<Subscriber>& k)
{
	list<Subscriber> ::iterator i;
	int lenght = 0; 
	for (i = k.begin(); i != k.end(); ++lenght,++i)
	return lenght;
}
void print(list<Subscriber> k)
{
	list <Subscriber> ::iterator i;
	for (i = k.begin(); i != k.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl; 
}
void add_abonent(list<Subscriber> &k)
{
	Subscriber abonent; 
	cout << "enter name , adress and number" << endl; 
	cin >> abonent.name >> abonent.adress >> abonent.number; 
	k.push_back(abonent);
	
}
bool delete_abonent(list<Subscriber>& k)
{
	int place = 0; 
	cout << "enter number" << endl; 
	cin >> place; 
	if (place < 0 || place > lenght(k))
	{
		return false;
	}
	else
	{
		list<Subscriber>::iterator i = k.begin();
		for (int k = 0; k < place; ++k, i++)
		{

		}
		k.erase(i);
		return true; 
	}

}
void search_number(list<Subscriber>& k)
{
	string number; 
	cout << "enter the search number" << endl; 
	cin >> number; 
	int x = 0; 
	list <Subscriber> ::iterator i;
	for (i = k.begin(); i != k.end(); ++i)
	{
		if (number == i->number)
		{
			cout << *i;
			x++;
		};
	}
	if (x == 0)
	{
		cout << "not found" << endl; 
	}
}
void Menu(list<Subscriber>& k)
{
	int p = 0;
	while (p != 4)
	{
		cout << "0 - print list" << endl;
	cout << "1 - add abonent" << endl;
	cout << "2 - delete abonent" << endl;
	cout << "3 - search abonent" << endl;
	cout << "4 - exit" << endl;
		cin >> p;
		if (p == 0)
		{
			print(k);
		}
		else if (p == 1)
		{
			add_abonent(k);
		}
		else if (p == 2)
		{
			delete_abonent(k);
		}
		else if (p == 3)
		{
			search_number(k);
		}
		else if (p == 4);
		else
		{
			cout << "enter the correct number" << endl; 
		}

	}
 }

std::istream& operator >>(istream& cin, list<Subscriber>& k)
{
	add_abonent(k);
	return cin; 
}
std::ostream& operator <<(ostream& cout , list<Subscriber>& k)
{
	print(k);
	return cout;
}
int main()
{
	const int c = 0; 
	setlocale(LC_ALL, "Russian");
	Subscriber k;
	Subscriber k1;
	Subscriber k2;
	Subscriber k3;
	
	list<Subscriber> l1;
	l1.push_back(k);
	l1.push_back(k1);
	l1.push_back(k2);
	l1.push_back(k3);
	print(l1); 
	Menu(l1);
	cin >> l1; 
	cout << l1; 
}

