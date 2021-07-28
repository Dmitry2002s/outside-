#include<iostream>
#include<string>
using namespace std; 

int lenght(string a, int c = 0)
{
	if (a[c] == '\0')
	{
		return c;
	}
	else
	{
		return lenght(a, c + 1);
	}
}

string adding(string a, int n = 0, string p = ""s)
{
	if (lenght(p) < (2 * lenght(a)))
	{
		p+=a[n];
		p+='*';
			return adding(a,n+1,p);
	}
	else
	{
		return p; 
	}
}

int main()
{
	string a; 
	getline(cin, a);
	cout << lenght(a) << endl << endl;
	cout << adding(a); 
}