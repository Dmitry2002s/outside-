#include<iostream>
#include<string>
using namespace std; 
int lenght(string a,int �=0)
{
	if (a[�] != '\0')
	{
		return lenght(a, � + 1);
	}
	else
	{
		return �; 
	}
}
string simmetry(string a, int n,string p = ""s)
{
	if (n == -1)
	{
		return p; 
	}
	else if (a[n] == '(')
	{
		return simmetry(a, n - 1, p += ')');
	}
	else
	{
		return simmetry(a, n - 1, p += a[n]);
	}
}

int main()
{
	string a; 
	getline(cin, a);
	int k = lenght(a);
	cout << k << endl;
	cout << a + simmetry(a, k); 
	return 1;
}