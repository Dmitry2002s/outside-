#include<iostream>

using namespace std; 

int GCD(int a, int b)
{
	int n = a % b; 
	if (n == 0)
	{
		return b;
	}
	return GCD(b, n);
}

int main()
{
	int a;
	int b; 
	cin >> a >> b; 
	cout << GCD(a, b);
	return 0; 
}