#include <iostream>
#include <list>

using namespace std; 


struct Subscriber
{
	string name ; 
	string adress ; 
	string number;
	Subscriber(string a = "Name", string b = "adress", string c = "000000") :
		name(a), adress(b), number(c) {}
	
};

std::ostream& operator << (ostream &cout , const Subscriber& S)
{
	cout << "Name - " << S.name    <<endl;
	cout << "Adress - " << S.adress<<endl;
	cout << "Number - " << S.number<<endl;
	cout << "___________" << endl; 
	return cout;
}

std::istream& operator >> (istream &cin, const Subscriber& S)
{
	cin >> S.name >> S.adress >> S.number;

	if (!cin)
	{
		Subscriber s;
	}
	
	return cin ;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Subscriber k;
	cout << k; 
	cin >> k; 
	cout << k; 
}

