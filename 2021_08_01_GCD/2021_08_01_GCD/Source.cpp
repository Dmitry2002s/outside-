#include <iostream>

using namespace std; 

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b; 
	}
	return(GCD(b, a % b));
}

int main()
{
	int a = 0; 
	int b = 0; 
	cin >> a >> b; 
	cout << GCD(a, b) << endl; 
}