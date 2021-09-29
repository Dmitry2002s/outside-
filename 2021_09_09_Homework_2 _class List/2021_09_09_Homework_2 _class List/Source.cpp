#include <iostream>
#include <list>

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



int main()
{
	const int c = 0; 
	setlocale(LC_ALL, "Russian");
	Subscriber k;
	Subscriber k1;
	Subscriber k2;
	Subscriber k3;
	list<Subscriber> l1;

	
	cout << k << k1 << k2 << k3 ; 
	
}

