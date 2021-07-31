#include<iostream>

using namespace std; 

int GCD(int a, int b)
{
	int n = a % b; 
	if (n != 0)
	{
		return GCD(b, n);
	}
	else
	{
		return b; 
	}
 
}

int main()
{
	int a;
	int b; 
	cin >> a >> b; 
	cout << "Greatest Common divisior "<< a << " and " << b << " = " << GCD(a, b);
	return 0; 
}