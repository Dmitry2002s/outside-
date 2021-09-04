#include<iostream>

using namespace std; 

int LCD(int a, int b)
{
	int L; 
	if (a % b == 0)
	{
		return b; 
	}
	else
	{
		return LCD(b, a % b);
	}
}

int main()
{
	int a; 
	int b; 
	cin >> a >> b; 
	if (a > b)
	{
		cout << LCD(a, b);
	}
	else
	{
		cout << LCD(b, a);
	}
}